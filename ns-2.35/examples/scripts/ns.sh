#!/bin/bash
echo " #  ,  Seconds" > nsOnly.csv
#echo "________________" >> afile
for i in `seq 1 1`
do

#echo "###############Executing Test '$i' ##################"

#rm -f lantest_example.nam
#rm -f out


Start=`date +%s.%N`
#echo -e "Start Program NS : " ; 
date +%c-%H:%M:%S,%N; 
echo -e "\n"; 
/home/ali/apps/ns2-master/ns-2.35/ns /home/ali/apps/ns2-master/ns-2.35/examples/test01/01lantest_example.tcl ; 
#/home/ali/apps/ns2-master/ns-2.35/ns /home/ali/apps/ns2/ns-allinone-2.35/ns-2.35/tcl/ex/lantest_example.tcl ;
#echo -e "\nEnd Program : " ;
date +%c-%H:%M:%S,%N
End=`date +%s.%N`
# Nanoseconds to milliseconds - first 3 decimal places
Second=`echo "$End - $Start" | bc | awk -F"." '{print $1"."substr($2,1,3)}'`
echo "Time in seconds: $Second"
echo " $i  ,  $Second" >> nsOnly.csv
done
