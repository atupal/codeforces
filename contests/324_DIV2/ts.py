#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''


n = 2000

a = [i+1 for i in xrange(n)]

import random
random.shuffle(a)

print n

for i in a:
    print i,

print

for i in xrange(n):
    print i +1,
