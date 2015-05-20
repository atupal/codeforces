#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

n = int(raw_input())

A = []

for i in xrange(n):
    A.append(map(int, raw_input().split()))


out = []
for i, a in enumerate(A):

    if a.count(1) == 0 and a.count(3) == 0:
        out.append(i+1)

print len(out)

for i in out:
    print i,
