#!/usr/bin/python

import operator

for i in range(10):
    total = input()
    flag = False
    if operator.mod(total, 2) == 1:
        flag = True
    more = input()
    total = total / 2
    more = more / 2
    if flag:
        print (total + more + 1)
    else:
        print (total + more)
    print (total - more)
