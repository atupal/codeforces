#!/bin/sh
# -*- coding: utf-8 -*-
''''which python2 >/dev/null && exec python2 "$0" "$@" # '''
''''which python  >/dev/null && exec python  "$0" "$@" # '''

# raw_input

l = int(raw_input()) * 1.0
p = int(raw_input()) * 1.0
q = int(raw_input()) * 1.0

print l * p/(p+q)
