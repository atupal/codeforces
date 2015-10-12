#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

# raw_input

import string
import sys

n, m = map(int, raw_input().split())
s = raw_input()
d = [_ for _ in string.lowercase]

for i in xrange(m):

    x, y = raw_input().split()
    for k in xrange(20000):
        for j in xrange(26):
            if d[j] == x:
                d[j] = y
            elif d[j] == y:
                d[j] = x

b = {}
cnt = 0
for i in string.lowercase:
    b[i]= cnt
    cnt += 1

for i in s:
    sys.stdout.write(d[ b[i] ])

print
