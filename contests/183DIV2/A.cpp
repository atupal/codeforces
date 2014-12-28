
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int cnt = 0;
    for (int i = 5; i <= n; ++ i) {
        for (int a = 1; a < sqrt(i*i / 2.) + 1; ++ a) {
            int t = (int) sqrt(i*i - a*a);
            if (t >= a and t * t + a * a == i * i) 
                ++ cnt;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
