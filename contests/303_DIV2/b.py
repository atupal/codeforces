#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''


s = raw_input()
t = raw_input()

p = []

a = 0
b = 0

for i, j in zip(s, t):
    if i == j:
        p.append('0')
    else:
        if a > b:
            p.append(i)
            b += 1
        else:
            p.append(j)
            a += 1

if a == b:
    print ''.join(p)
else:
    print 'impossible'
