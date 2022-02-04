#include <stdio.h>

#define N (5)

int count_solutions(int A[N][N],int mission) {
    int possible_solutions = 0;
    while(mission < N) {
        for (int employee = 0; employee < N; ++employee) {
            if (A[employee][mission] == 0) {
                continue;
            }
            else {
                //mem remembers the origin
                int mem[N] = {0};
                //copy the origin to mem and zero all task in A
                for (int col = 0; col < N; col++) {
                    mem[col] = A[employee][col];
                    A[employee][col] = 0;
                }

                possible_solutions += count_solutions(A,mission+1);

                //back to original
                for (int col = 0; col < N; col++) {
                    A[employee][col] = mem[col];
                }
            }
        }
        return possible_solutions;
    }
    return 1;
}

int main() {
    int possible_solutions = 0, A[N][N] = {{0}};
    printf("Enter the matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    possible_solutions = count_solutions(A, 0);
    printf("The result is %d\n", possible_solutions);
    return 0;0 1 0 1 0 1 0 1 1 0 1 1 1 0 0 0 0 1 1 1 1 0 1 0 1
}


//in1
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 - pass
//in2
//0 1 0 1 0 1 0 1 1 0 1 1 1 0 0 0 0 1 1 1 1 0 1 0 1 - pass
//in3
//1 0 1 0 1 0 0 0 0 0 1 1 1 1 1 0 1 0 1 0 1 1 1 0 0 - pass
//in4
//1 0 1 0 1 0 0 1 0 0 1 0 1 0 1 0 0 0 0 0 1 1 1 0 0 - pass