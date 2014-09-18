#!/bin/bash

echo -e "Start Program NS : " ; 
date +%c-%H:%M:%S,%3N; 
echo -e "\n"; 
/home/ali/Downloads/ns2/ns-2.35/ns test_ns.tcl ; 
echo -e "\nEnd Program : " ;
date +%c-%H:%M:%S,%3N
