#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''


n = int(raw_input())


l = [map(int, raw_input().split()) for i in xrange(n)]

l.sort()

z = len( filter(lambda i:i[0]<0, l) )


if z > n-z:
    print sum([ i for _, i in  l[z-(n-z)-1:z] ]) + sum( [i for _, i in l[z:]] )
elif z < n-z:
    print sum([ i for _, i in  l[:z] ]) + sum( [i for _, i in l[z:z+1] ])
else:
    print sum([ i for _, i in l ])
