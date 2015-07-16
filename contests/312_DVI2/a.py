#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

n = int(raw_input())

d = {}
l = [map(int, raw_input().split()) for i in xrange(n)]
"""
for i,j in l:
    if i in d:
        d[i] += j
    else:
        d[i] = j

l = d.items()
"""
l.sort()

z = len( filter(lambda i:i[0]<0, l) )

r = n-z
if z > r:
    print sum([ i for _, i in  l[z-r-1:z] ]) + sum( [i for _, i in l[z:]] )
elif z < r:
    print sum([ i for _, i in  l[:z] ]) + sum( [i for _, i in l[z:z+z+1] ])
else:
    print sum([ i for _, i in l ])
