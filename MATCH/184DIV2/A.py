'''
4
100 10 1 0
'''

n = int(raw_input())
t = raw_input().split(' ')


A = [None] * 101

for a in t:
    A[int(a)] = 1

cnt = 0

ans = set()

if A[100]:
    cnt += 1
    ans.add(100)

for i in xrange(1, 10, 1):
    if A[i * 10]:
        cnt += 1
        ans.add(i * 10)
        break

for i in xrange(1, 10, 1):
    if A[i]:
        cnt += 1
        ans.add(i)
        break

if A[0]:
    cnt += 1
    ans.add(0)

if not cnt:
    print 1
    for i in xrange(1, 101, 1):
        if A[i]:
            print i
            exit()

print cnt
for i in ans:
    print i ,

