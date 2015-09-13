#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''



n, k, x = map(int, raw_input().split())

arr = map(int, raw_input().split())

orsum1 = [0] * (len(arr)+2)
orsum2 = [0] * (len(arr)+2)


for i in xrange(len(arr)):
    orsum1[i+1] = orsum1[i] | arr[i]

for i in xrange(len(arr)-1, -1, -1):
    orsum2[i+1] = orsum2[i+2] | arr[i]

ans = 0

for i in xrange(1, len(arr)+1):
    tmp = orsum1[i-1] | orsum2[i+1] | (arr[i-1]*x**k)
    ans = max(tmp, ans)

print ans
