'''
9 4
2
2 4
'''

def gcd(a, b):
    if not b:
        return 1
    return b if not a % b  else gcd(b, a % b)


t = raw_input().split(' ')
p = int(t[0])
q = int(t[1])
n = int(raw_input())
t = raw_input().split(' ')
A = [int(_) for _ in t]
A = A[::-1]

s1 = A[0]
s2 = 1

for i in xrange(1, n, 1):
    t1 = s2 + s1 * A[i]
    t = gcd(t1, s1)
    s2 = s1 / t
    s1 = t1 / t

t = gcd(max(p, q), min(p, q))
p /= t
q /= t


if s1 == p and s2 == q:
    print "YES"
else:
    print "NO"


