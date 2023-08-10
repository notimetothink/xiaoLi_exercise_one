#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int INF = 0x3f3f3f3f;

int minFallingPathSum(int** grid, int gridSize){
    int n = gridSize;
    // 定义二维数组d
    int d[n][n];
    // 初始化d数组元素
    memset(d, 0x3f, sizeof(d));
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         printf("%d and %d ",i,j);
    //         printf("%d\n", d[i][j]);
    //     }      
    // }
    // d第一行赋值所给矩阵第一行数据
    for (int i = 0; i < n; i++) {
        d[0][i] = grid[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j == k) {
                    continue;
                }
                d[i][j] = fmin(d[i][j], d[i - 1][k] + grid[i][j]);
                // printf("%d\n", d[i][j]);
            }
        }
    }
    int res = INT_MAX;
    for (int j = 0; j < n; j++) {
        res = fmin(res, d[n - 1][j]);
    }
    return res;
}

int main(){
    int gridSize = 3;
    int** arr = (int**)malloc(gridSize * sizeof(int*));  
    for (int i = 0; i < gridSize; i++) {      
        arr[i] = (int*)malloc(gridSize * sizeof(int));  
    };
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;
    arr[2][0] = 7;
    arr[2][1] = 8;
    arr[2][2] = 9;
    int result = minFallingPathSum(arr,3);
    printf("%d", result);
    return 0;
}