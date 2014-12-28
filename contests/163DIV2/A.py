
def main():
    n = raw_input()
    n = int(n)
    s = raw_input()
    s = list(s)
    ans = 0
    for i,j in enumerate(s[:-1]):
        if s[i + 1] == s[i]:
            ans += 1
    print ans


main()
