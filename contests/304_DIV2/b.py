#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''


n = int(raw_input())
a = map(int, raw_input().split())
a.sort()

from itertools import groupby

c = []

for i, it in groupby(a):
    c.append( (i, len(list(it)) ) )


ans = 0
last = 0

for now, nxt in zip( c[:-1], c[1:] ):
    num = now[1]-1+last
    if num > 0:
        tmp = nxt[0] - now[0] - 1
        if num > tmp:
            ans += (1+tmp)*tmp/2
            ans += (tmp+1)*(num-tmp)
            last = num-tmp
        else:
            ans += (1+num)*num/2
            last = 0

tmp = c[-1][1] + last - 1
if tmp > 0:
    ans += (tmp+1)*tmp/2

print ans
