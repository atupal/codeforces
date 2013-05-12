
def main():
    s = raw_input().split(' ')
    n,m = s[0],s[1]
    n = int(n)
    m = int(m)
    m = min(m,n)
    print m + 1
    for i in range(m+1):
        print "%d %d"%(i,m-i)





main()
