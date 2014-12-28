#!/bin/bash
python dp.py>in.dat
ts<in.dat >a.out
B<in.dat >b.out
diff a.out b.out
