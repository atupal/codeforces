#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

n = int(raw_input())
t = map(int, raw_input().split())
t.sort()

csum = 0
ans = 0

for i in t:
    if i >= csum:
        csum += i
        ans += 1

print ans
