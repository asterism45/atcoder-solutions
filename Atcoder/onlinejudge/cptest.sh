#!/bin/bash

problem_name=$1
problem_name=${problem_name,,}
problem_name=${problem_name##*/}
test_dir=Atcoder/onlinejudge/test/${problem_name}
base_url=${problem_name%_*}

#joiに関連する処理
if [[ $problem_name =~ "joi" ]]; then
    echo joi
    if [[ $problem_name =~ ^joi([0-9]+)yo([0-9]+)(.*)$ ]]; then
        problem_name=${problem_name//yo/_yo}
    fi
    if [[ $problem_name =~ "open" ]]; then
        problem_name=${problem_name//open_/}
    fi
fi

#aizuに関連する処理
if [[ $problem_name =~ "aizu" ]]; then
    #problem_name から aizu_ を削除
    problem_name=${problem_name//aizu_/}
    code_path=$2
    gen_path=$3
    sol_path=$4

    # make test directory
    if [ ! -e ${test_dir} ]; then
        oj dl -d ${test_dir} https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=${problem_name}
    fi

    # if ! oj login --check https://judge.u-aizu.ac.jp/onlinejudge/signin.jsp; then
    #     oj login https://judge.u-aizu.ac.jp/onlinejudge/signin.jsp
    # fi
    # compile and test
    if [ "$5" = "test" ]; then
        g++ -std=gnu++17 -Wall -Wextra -O2 ${code_path} -o ./a.out && oj test -c "./a.out" -d ${test_dir} --tle 3 --mle 1024 -N
    elif [ "$5" = "submit" ]; then
        # submit if tests pass
        echo "Submitting..."
        oj s --wait=0 https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=${problem_name} ${code_path}
    else
        echo "Invalid option. Use 'test' for testing, 'submit' for submitting, or 'gen-sol' for generating test cases and solving."
    fi
    exit 0
fi


code_path=$2
gen_path=$3
sol_path=$4

# make test directory
if [ ! -e ${test_dir} ]; then
    oj dl -d ${test_dir} https://atcoder.jp/contests/${base_url}/tasks/${problem_name//-/_}
fi

# Check login status and login if necessary
if ! oj login --check https://atcoder.jp/; then
    oj login https://atcoder.jp/
fi
# compile and test
if [ "$5" = "test" ]; then
    g++ -std=gnu++17 -Wall -Wextra -O2 -I/home/klyn0101/ac-library ${code_path} -o ./a.out && oj test -c "./a.out" -d ${test_dir} --tle 2.5 --mle 1024 -N
elif [ "$5" = "submit" ]; then
    # submit if tests pass
    echo "Submitting..."
    oj s --wait=0 https://atcoder.jp/contests/${base_url}/tasks/${problem_name//-/_} ${code_path}
elif [ "$5" = "gen-sol" ]; then
    # run generator and solver
    #python3 ${gen_path}  > ${test_dir}/input.txt
    #g++ ${sol_path} -o sol && ./sol < ${test_dir}/input.txt > ${test_dir}/output.txt
    oj g/i --directory ${test_dir} ${gen_path} 3
    g++ ${sol_path} -o sol
    oj g/o --directory ${test_dir} -c ./sol 
else
    echo "Invalid option. Use 'test' for testing, 'submit' for submitting, or 'gen-sol' for generating test cases and solving."
fi
