#!/usr/bin/python

cols = input()
while cols != 0:
    enc = raw_input()
    stridx = 0
    even = False
    box = [[]]
    while stridx < len(enc):
        box[-1].append(enc[stridx])
        if len(box[-1]) == cols:
            if even:
                box[-1].reverse()
                even = False
            else:
                even = True
            box.append([])
        stridx = stridx + 1
    box.pop()
    result = ""
    for i in range(cols):
        for j in range(len(box)):
            result = result + box[j][i]
    print result
    cols = input()
