#!/bin/bash
echo " #  ,  Seconds" > glOnly.csv
#echo "________________" >> glOnly.csv
for i in `seq 1 1000`
do
#echo "###############Executing Test '$i' ##################"
#rm -f TEST_*
#rm -f gridlabd.xml


Start=`date +%s.%N`
#echo -e "Start Program Gridlab: " ; 
date +%c-%H:%M:%S,%N; 
echo -e "\n"; 
gridlabd /home/apps/ns2-master/ns-2.35/examples/test01/02_test_PMSG_windturb_GCU.glm ; 
#echo -e "\nEnd Program : " ;
date +%c-%H:%M:%S,%N

End=`date +%s.%N`
# Nanoseconds to milliseconds - first 3 decimal places
Second=`echo "$End - $Start" | bc | awk -F"." '{print $1"."substr($2,1,3)}'`
echo "Time in seconds: $Second"
echo " $i  ,  $Second" >> glOnly.csv


done
