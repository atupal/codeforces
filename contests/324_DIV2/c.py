#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

import string
import sys

n, t = map(int, raw_input().split())
t = n-t
s1 = raw_input()
s2 = raw_input()
s = sum(map(lambda x: 1 if x[0]==x[1] else 0, zip(s1, s2)))

if t <= s:
    for a, b in zip(s1, s2):
        if t and a==b:
            sys.stdout.write(a)
            t -= 1
        else:
            if a != 'a' and b != 'a':
                sys.stdout.write('a')
            elif a != 'b'and b != 'b':
                sys.stdout.write('b')
            else:
                sys.stdout.write('c')
    print
elif (n-s)>=(t-s)*2:
    cnt1 = 0
    cnt2 = 0
    for a, b in zip(s1, s2):
        if a == b:
            sys.stdout.write(a)
        else:
            if cnt1 < t-s:
                sys.stdout.write(a)
                cnt1 += 1
            elif cnt2 < t-s:
                sys.stdout.write(b)
                cnt2 += 1
            else:
                if a != 'a' and b != 'a':
                    sys.stdout.write('a')
                elif a != 'b'and b != 'b':
                    sys.stdout.write('b')
                else:
                    sys.stdout.write('c')
    print
else:
    print -1
