for i in $(seq -w 162 175)
do
    if [ ! -d "arc"$i ]; then
        mkdir "arc"$i
    fi
    for j in {a..e}
    do
        if [ ! -f "arc"$i/$j".cpp" ]; then
            touch "arc"$i/$j".cpp"
        fi
    done
done
