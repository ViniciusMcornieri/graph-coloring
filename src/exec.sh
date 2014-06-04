#!/bin/bash

caminho=$1
data=$2
mkdir results/$data
saida=results/$data/saida.$2
echo $data "seq"
echo "seq" >> $saida
i=0
for i in 1 2 3
do
psrun -c intel.xml -o $data -F text ./a.out $caminho >> $saida
done
mkdir results/$data/seq
mv $data.* results/$data/seq

echo $data "p2"
echo "----------------------------------------------------------- " >> $saida
echo "p2" >> $saida
for i in 1 2 3
do
psrun -c intel.xml -o $data -F text ./a.out $caminho 2 >> $saida
done
mkdir results/$data/p2
mv $data.* results/$data/p2

echo $data "p4"
echo "----------------------------------------------------------- " >> $saida
echo "p4" >> $saida
for i in 1 2 3
do
psrun -c intel.xml -o $data -F text ./a.out $caminho 4 >> $saida
done
mkdir results/$data/p4
mv $data.* results/$data/p4

echo $data "p8"
echo "----------------------------------------------------------- " >> $saida
echo "p8" >> $saida
for i in 1 2 3
do
psrun -c intel.xml -o $data -F text ./a.out $caminho 8 >> $saida
done
mkdir results/$data/p8
mv $data.* results/$data/p8
