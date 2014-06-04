#!/bin/bash
for file in ../data/*
do
data=${file:8}
./exec.sh $file $data
done
