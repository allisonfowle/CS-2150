#!/bin/bash

#Allison Fowle
# CS 2150-lab 104 (12:30)

#input one: dictionary file name
echo "Enter dictionary file"
read dictFile
#input two: grid file name
echo "Enter grid file"
read gridFile

#run program 5 times using parameters. it will record the time
#of each execution run 
#using `` tells bash to execute what is in between them
running_time1=`./a.out $dictFile $gridFile | tail -1`
running_time2=`./a.out $dictFile $gridFile | tail -1`
running_time3=`./a.out $dictFile $gridFile | tail -1`
running_time4=`./a.out $dictFile $gridFile | tail -1`
running_time5=`./a.out $dictFile $gridFile | tail -1`

#print out average of 5 running times
run=$((running_time1+running_time2+running_time3+running_time4+running_time5))
avg=$((run/5))
echo $avg