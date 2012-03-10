#!/usr/bin/python

cases = input()
for i in range(cases):
    inp = raw_input()
    l = inp.split()
    x = int(l[0])
    y = int(l[1])
    if x != y and x - 2 != y:
        print "No Number"
        continue
    if x == y:
        if 2 * (x / 2) == x:
            print 2 * x
        else:
            print 2 * x - 1
    else:
        if 2 * (x / 2) == x:
            print 2 * y + 2
        else:
            print 2 * y + 1
