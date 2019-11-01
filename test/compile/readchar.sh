#!/bin/bash

echo -n 0 | $1
if [ $? -ne 0 ] 
then 
  
  exit 1
  
fi

echo -n 9 | $1
if [ $? -ne 9 ] 
then 
  
  exit 1
  
fi
