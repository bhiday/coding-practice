#!/usr/bin/python

cases = input()
while cases > 0:
    num = input()
    fact = 1
    for i in range(num):
        fact = fact * (i + 1)
    print fact
    cases = cases - 1

