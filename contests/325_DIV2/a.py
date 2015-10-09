#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

# raw_input


n = int(raw_input())

a = map(int, raw_input().split())

ans = a[0]

for i in xrange(1, n):
    if a[i] == 1:
        ans += 1
    else:
        if a[i-1] == 1 and i+1 < n and a[i+1]==1:
            ans += 1

print ans
