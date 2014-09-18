#!/bin/bash
echo -e "Start Program Gridlab: " ; 
date +%c-%H:%M:%S,%3N; 
echo -e "\n"; 
gridlabd test_gl.glm ; 
echo -e "\nEnd Program : " ;
date +%c-%H:%M:%S,%3N
