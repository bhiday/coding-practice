#!/usr/bin/python

cases = input()
for i in range(cases):
    expr = raw_input()
    expr = list(expr)
    while len(expr) != 1:
        lastopen = 0
        for i in range(len(expr)):
            if expr[i] == "(":
                lastopen = i

        newtoken = expr[lastopen+1] + expr[lastopen+3] + expr[lastopen+2]
        tmpexpr = expr[:lastopen]
        tmpexpr.append(newtoken)
        tmpexpr.extend(expr[lastopen+5:])
        expr = tmpexpr
    print expr[0]
