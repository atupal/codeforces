
n,m,k = map(int, raw_input().split())

p = map(int, raw_input().split())
p.append(0)


mo=[]
for i in xrange((n+1)):
    mo.append([-1]*(k+2))

def dfs(begin, ind):
    ret = 0
    if ind>k:
        return 0

    s = sum(p[begin:begin+m])
    for i in xrange(begin, n-(k-ind+1)*m+1):
        if mo[i+m][ind+1] != -1:
            t = mo[i+m][ind+1]
        else:
            t = dfs(i+m, ind+1)

        ret = max(t+s, ret)
        s -= p[i]
        s += p[i+m]

    mo[begin][ind] = ret
    return ret

print dfs(0, 1)


'''
7 1 3
2 10 7 18 5 33 0
'''
