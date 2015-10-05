#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''


n, t = map(int, raw_input().split())

if t == 10:
    if n == 1:
        print -1
    else:
        print 10**(n-1)
else:
    print t * 10**(n-1)
