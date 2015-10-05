#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''


n = int(raw_input())

MOD = 10**9+7

def exp(a, x):
    ret = 1
    b = a
    while x:
        if x&1:
            ret *= b
            ret %= MOD
        b *= b
        b %= MOD
        x >>= 1

    return ret

a = exp(3, 3*n) + MOD
b = exp(7, n)

print (a-b)%MOD
