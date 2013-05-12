n = int(raw_input())
A = raw_input().split(' ')
A = [int(_) for _ in A]
cnt = [0 for i in xrange(n)]

ans = 0
for x,i in enumerate(A):
    for j in A:
        if i != 0 and j == i:
            cnt[x] += 1


for i in cnt:
    if i != 0 and i != 2 and i != 1:
        print '-1'
        exit()
    if i == 2:
        ans +=1

print ans / 2
