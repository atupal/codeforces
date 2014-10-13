
n  = int(raw_input())

ans = 0

for i in xrange(n):
    p,q = map(int, raw_input().split())
    if q-p>=2:
        ans +=1

print ans
