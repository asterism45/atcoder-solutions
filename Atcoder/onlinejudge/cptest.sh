#!/bin/bash

problem_name=$1
problem_name=${problem_name,,}
problem_name=${problem_name##*/}
problem_name=${problem_name//atcoder\\abc\\/}
test_dir=AtCoder/onlinejudge/test/${problem_name}
base_url=${problem_name%_*}
code_path=$2

# make test directory
if [ ! -e ${test_dir} ]; then
    oj dl -d ${test_dir} https://atcoder.jp/contests/${base_url}/tasks/${problem_name//-/_}
fi

# Check login status and login if necessary
if ! oj login --check https://atcoder.jp/; then
    oj login https://atcoder.jp/
fi
# compile and test
if [ "$3" = "test" ]; then
    g++ -std=gnu++17 -Wall -Wextra -O2 -I/home/klyn0101/ac-library ${code_path} -o ./a.out && oj test -c "./a.out" -d ${test_dir}
elif [ "$3" = "submit" ]; then
    # submit if tests pass
    echo "Submitting..."
    oj s --wait=0 https://atcoder.jp/contests/${base_url}/tasks/${problem_name//-/_} ${code_path}
else
    echo "Invalid option. Use 'test' for testing or 'submit' for submitting."
fi

#echo "Press ENTER to exit..."
#read
