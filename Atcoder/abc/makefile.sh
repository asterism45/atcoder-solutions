for i in $(seq -w 312 350)
do
    if [ ! -d "abc"$i ]; then
        mkdir "abc"$i
    fi
    for j in {a..f}
    do
        if [ ! -f "abc"$i/$j".cpp" ]; then
            touch "abc"$i/$j".cpp"
        fi
    done
done
