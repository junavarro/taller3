#!/bin/bash



# for i in 1 2 3 4
# do
# done
# opens terminal but then I can't control terminal afterwards
# make sample
# sleep 2
gcc factorial.c -o factorial.o -lgmp &&
echo "Pruebas en C" &&
sudo nice -n  20   ./factorial.o 1500     && 

sudo nice -n  15   ./factorial.o 1500     &&

sudo nice -n   1   ./factorial.o 1500     &&

sudo nice -n  -5   ./factorial.o 1500     &&

sudo nice -n -10   ./factorial.o 1500     &&

echo "Pruebas en Python" &&
sudo nice -n  20   python factorial.py 1500     &&

sudo nice -n  15   python factorial.py 1500     &&

sudo nice -n   1   python factorial.py 1500     &&

sudo nice -n  -5   python factorial.py 1500     &&

sudo nice -n -10   python factorial.py 1500     


#exit 0
# didn't do anything
#exit 0

# didn't do anything except make me type exit an extra time where I executed my shell script
#$SHELL
