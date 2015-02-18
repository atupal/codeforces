#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

n = 2000
m = 2000

from random import choice

print n, m

for i in xrange(n):
  s = []
  while len(s) < m-1:
    s.append( choice(['..', '*']) )
  if len(s) == m-1:
    s.append('.')
  print ''.join(s)
