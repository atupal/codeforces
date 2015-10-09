#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

# raw_input

n = int(raw_input())

a1 = map(int, raw_input().split())
a2= map(int, raw_input().split())
b = map(int, raw_input().split())


ans = 10**9

for i in xrange(n-1):
    for j in xrange(i+1, n):
        s = b[i]+b[j]
        s += sum(a1[:i]) + sum(a2[i:]) + sum(a1[:j]) + sum(a2[j:])
        ans = min(ans, s)

print ans
