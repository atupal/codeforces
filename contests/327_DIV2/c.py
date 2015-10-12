#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

from itertools import groupby

n = int(raw_input())
s = map(int, raw_input().split())
a = [_ for _ in s]
s = [  [i, len(list(j)), 0] for i , j in groupby(s) ]
cnt = 0
for i in s:
    i[2] = cnt
    cnt += i[1]

ans = 0

i = 0
while i < len(s)-1:
    j = i+1
    while j < len(s)-1 and s[j][1] == 1:
        j += 1
    ans = max(ans, (j-i)/2)
    if s[i][0] == 1 and s[j][0] == 1:
        for x in xrange( s[i][2]+s[i][1], s[j][2] ):
            a[x] = 1
    if s[i][0] == 1 and s[j][0] == 0:
        for x in xrange( s[i][2]+s[i][1], s[i][2]+s[i][1]+(s[j][2]-s[i][2]-s[i][1])/2 ):
            a[x] = 1
        for x in xrange( s[i][2]+s[i][1]+(s[j][2]-s[i][2]-s[i][1])/2, s[j][2]):
            a[x] = 0
    if s[i][0] == 0 and s[j][0] == 1:
        for x in xrange( s[i][2]+s[i][1], s[i][2]+s[i][1]+(s[j][2]-s[i][2]-s[i][1])/2 ):
            a[x] = 0
        for x in xrange( s[i][2]+s[i][1]+(s[j][2]-s[i][2]-s[i][1])/2, s[j][2]):
            a[x] = 1
    if s[i][0] == 0 and s[j][0] == 0:
        for x in xrange( s[i][2]+s[i][1], s[j][2] ):
            a[x] = 0
    i = j

print ans
print ' '.join([str(_) for _ in a])

