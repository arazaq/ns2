#!/bin/bash
Start=`date +%s.%N`
echo -e "Start Program NS and GL via NS agent : " ; 
date +%c-%H:%M:%S,%N; 
echo -e "\n"; 
/home/ali/Downloads/ns2/ns-2.35/ns agt.tcl ; 
echo -e "\nEnd Program : " ;
date +%c-%H:%M:%S,%N
End=`date +%s.%N`
# Nanoseconds to milliseconds - first 3 decimal places
Second=`echo "$End - $Start" | bc | awk -F"." '{print $1"."substr($2,1,3)}'`
echo "Time in seconds: $Second"
