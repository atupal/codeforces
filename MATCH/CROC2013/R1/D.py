'''
6 5
1 2
5 4
2 3
3 1
3 6
6
1 3
2 5
1 5
5 5
2 4
3 3
'''

t = raw_input().split(' ')
n = int(t[0])
m = int(t[1])

dic = dict()
g = [[] for i in xrange(n + 1)]

for i in xrange(m):
    t = raw_input().split(' ')
    if not dic.has_key(t[0] + '#' + t[1]):
        dic[t[0] + '#' + t[1]] = [i + 1]
    else:
        dic[t[0] + '#' + t[1]].append(i + 1)

    if not dic.has_key(t[1] + '#' + t[0]):
        dic[t[1] + '#' + t[0]] = [i + 1]
    else:
        dic[t[1] + '#' + t[0]].append(i + 1)

    g[int(t[0])].append(int(t[1]))
    g[int(t[1])].append(int(t[0]))

def dfs(x):
    v[x] = 1
    for i in g[x]:
        if not v[i]:
            t = dic[str(i) + '#' + str(x)]
            for xx in t:
                if xx < l or xx > r:
                    v[i] = 1
                    dfs(i)
                    break

m = int(raw_input())
for i in xrange(m):
    t = raw_input().split(' ')
    l = int(t[0])
    r = int(t[1])
    v = [0 for i in xrange(n + 1)]
    cnt = 0
    for i in xrange(1, n + 1, 1):
        if not v[i]:
            cnt +=1
            dfs(i)
    print cnt

