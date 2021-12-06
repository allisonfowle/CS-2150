
#!/bin/bash

#Allison Fowle
# CS 2150-lab 104 (12:30)

#ask for number of iterations. if input is quit then exit shell
echo "enter the exponent for counter.cpp:"
read input
if [[ $input == "quit" ]]; then 
	exit
fi

#while loop
start=0
total=0
while [[ $start -lt 5 ]]; do
	running_time=`./a.out $input | tail -1`
	echo "Running iteration" $start "..."
	echo "time taken: " $running_time
	total=$((total+running_time)) #add onto itself to print out total time it took to run iterations
	start=$[$start+1] #same as start++
done
#print out average of 5 running times
echo $total
avg=$((total/5))
echo "Average time was " $avg