#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''


a, b = map(int, raw_input().split())

t = (a+b)/b

if t&1:
    t -=1

if t:
    print (a*1.0 + b)/t
else:
    print -1
