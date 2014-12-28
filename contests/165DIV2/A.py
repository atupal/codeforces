
import math

def main():
    n = raw_input()
    n = int(n)
    for i in xrange(n):
        a = raw_input()
        a = int(a)
        if 360.0 / (180 - a) != 360 / (180 - a):
            print "NO"
        else:
            print "YES"


main()
