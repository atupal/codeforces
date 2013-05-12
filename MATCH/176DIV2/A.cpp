
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char A[4][5];

int has() {
    for (int i = 0; i <3; ++ i){
        for (int j = 0; j <3; ++j){
            char t = A[i][j]+A[i][j +1]+A[i + 1][j]+A[i +1][j +1];
            if (t == 4 ||t == 0)
                return 1;
        }
    }
    return 0;
}

int main() {
    for (int i = 0; i < 4; ++i)
        scanf("%s", A[i]);

    for (int i = 0; i <4; ++i){
        for (int j = 0; j <4; ++ j){
            A[i][j] = A[i][j] == '#' ? 1 : 0;
        }
    }

    if (has()){
        printf("YES\n");
        return 0;
    }

    for (int i = 0; i <4; ++i){
        for (int j = 0; j <4; ++ j){
            A[i][j] = !A[i][j];
            if (has()){
                printf("YES\n");
                return 0;
            }
            A[i][j] = !A[i][j];
        }
    }
    printf("NO\n");

    return 0;
}

