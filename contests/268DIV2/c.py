
n = int(raw_input())

if n<4:
    print "NO"
    exit(0)

p = [
"""
1 * 2 = 2
2 * 3 = 6
6 * 4 = 24
""",

"""
5 - 1 = 4
4 - 2 = 2
2 * 3 = 6
6 * 4 = 24
""", 
"""
6 - 5 = 1
1 * 1 = 1
1 * 2 = 2
2 * 3 = 6
6 * 4 = 24
""",

"""
7 - 6 = 1
1 * 1 = 1
5 - 1 = 4
4 - 2 = 2
2 * 3 = 6
6 * 4 = 24
"""
]

print "YES"

p = [_.strip() for _ in p]

if n == 4:
    print p[0]
    exit(0)

b = (n-4)%4+5
for i in xrange( (n-4)/4 ):
    i = i*4
    print b+i+1, '-' , b+i, '=', '1'
    print b+i+2, '-' , b+i+3, '=', '-1'
    print '1 + -1 = 0'

for i in xrange ((n-4)/4-1):
    print '0 + 0 = 0'

if (n-4)/4>0:
    print '0 + 1 = 1'

print p[(n-4)%4]
