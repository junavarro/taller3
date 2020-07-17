#!/usr/bin/python
import os 
import sys
import time

sys.setrecursionlimit(2000)
start_time = time.time()


def factorial(val):
    # print "Valor a calcular: ", (int(val) + 1 )
    if(val == 1):
        return val
    else: 
        return val * factorial(val-1)

pid = os.getpid() 
#print("Process id:", pid)
factorial(int(sys.argv[1]))
print(" Process id %s duration %s ms factorial of %s"  % (pid , (time.time() - start_time)*1000, int(sys.argv[1])))   
