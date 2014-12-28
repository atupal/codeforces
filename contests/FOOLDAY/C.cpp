
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char s[1000001];

int main() {
    scanf("%s", s);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < (int)strlen(s); ++ i) {
        if (s[i] <='Z' && s[i] >= 'A') {
            s[i] = s[i] + 'a' - 'A';
        }
        if (s[i] < n + 97) {
            s[i] = s[i] + 'A' - 'a';
        }
    }
    printf("%s\n", s);
}

