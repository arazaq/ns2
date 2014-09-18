#!/bin/bash

echo -e "Start Program NS and GL via NS agent : " ; 
date +%c-%H:%M:%S,%3N; 
echo -e "\n"; 
/home/ali/Downloads/ns2/ns-2.35/ns agt.tcl ; 
echo -e "\nEnd Program : " ;
date +%c-%H:%M:%S,%3N
