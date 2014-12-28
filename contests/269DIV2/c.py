n = int(raw_input())


md = n / 3
mm = n % 3

def check(x):
    xx = x*3 + (3-mm)
    # s = (1 + xx)/2 *  xx
    s = (1 + xx) *  xx / 2
    if (md+1+x) < s:
        return 0
    return 1


low = 0
height = 10**12+1

while low < height:
    mid = (low + height) / 2
    if check(mid):
        low = mid+1
    else:
        height = mid - 1

if not check(low):
    low -= 1

print low+1
