#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

k, n, w = map(int, raw_input().split())


s = (w+1)*w/2*k

print max(0, s-n)
