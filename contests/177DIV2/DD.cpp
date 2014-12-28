#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[8];
int max;
int ans;

void f(int index, int num) {
    A[index] = num;
    int flag = 0;
    if (index == max) {
        for (int i = 0; i < num; ++ i) {
            int t = A[i];
            if (i == 0 && A[0] == 0) 
                flag = 1;
            else for (int j = 0; j < 8; ++ j) {
                t = A[t];
                if (t == 0) 
                    break;
            }
            if  ( t != 0) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            ans += 1;
        }

    }
    else {
        for (int i = 0; i < 8; ++ i) 
            f(index + 1, i);
    }
}

int main() {
    for (int i  = 0; i < 8; ++ i) {
        max = i;
        ans = 0;
        f(0, i);
        printf("%d, ", ans + 1);
    }

    return 0;
}

