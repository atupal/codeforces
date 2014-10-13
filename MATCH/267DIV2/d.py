
m = int(raw_input())

s = raw_input().lower().split()

n = int(raw_input())

d={}
vis={}
r={}
l={}

for i in xrange(n):
    k,v = raw_input().lower().split()
    d[k]=v
    vis[k]=0
    r[k] = 10000000
    l[k] = 10000000


for i in d:
    k = i
    if not vis[k]:
        flag = 0
        vis[k] = 1
        li = [k]
        while 1:
            if not k in d:
                flag = 1
                break
            else:
                if vis[k]:
                    flag = 2
                    break
                else:
                    k = d[k]
                    vis[k] = 1
                    li.append(d[k])

        if flag==1:
            m = ( li[-1].count('r'), len(li[-1]) )
            for k in li[-2:-1:-1]:
                m = min(m, (k.count('r'), len(k)))
                r[k],l[k] = m
        elif flag==2:
            m = ( li[-1].count('r'), len(li[-1]) )
            for k in li:
                m = min(m, (k.count('r'), len(k)))
            for k in li:
                r[k],l[k] = m



rc = 0
lc = 0
for ss in s:
    if ss in r and ss.count('r')>=r[ss]:
        rc += r[ss]
        lc += l[ss]
    else:
        rc += ss.count('r')
        lc += len(ss)

print rc, lc

