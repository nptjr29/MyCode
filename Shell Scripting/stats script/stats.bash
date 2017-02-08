#!/bin/bash


touch output.txt
echo -n "Enter a number (negative to quit): "
read num
echo "">>output.txt

sum=0
count=0

while [ $num -ge 0 ]
do
        for (( i = 0; i < $num; ++i ))
        do
                echo -n "#">>output.txt
        done

        echo "">>output.txt
        count=`expr 1 + $count`
        sum=`expr $num + $sum`
        echo -n "Enter a number (negative to quit): "
        read num
done

echo "">>output.txt
echo -n "There are $count numbers with an average of ">>output.txt
echo "scale=1; $sum / $count" | bc -l>>output.txt