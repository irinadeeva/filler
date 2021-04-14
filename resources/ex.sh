#!/bin/bash
max=10
c=0
rm traceresult
for i in `seq 2 $max`
do
	./filler_vm -f $1  -p1 $2 -p2 $3 -f > result
	cat filler.trace >> traceresult	 
done
	cat traceresult | grep "won"
