#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = *(matrixColSize) * matrixSize;
    int* res = (int*)calloc(*returnSize, sizeof(int));

    int rowSt = 0, colSt = 0;
    int rowEnd = matrixSize - 1, colEnd = *(matrixColSize) - 1;

    int ind = 0;

    while (rowSt <= rowEnd && colSt <= colEnd) {
        for (int i = colSt; i <= colEnd; i++)
            res[ind++] = matrix[rowSt][i];
        rowSt++;

        for (int i = rowSt; i <= rowEnd; i++)
            res[ind++] = matrix[i][colEnd];
        colEnd--;

        if (rowSt <= rowEnd) {
            for (int i = colEnd; i >= colSt; i--)
                res[ind++] = matrix[rowEnd][i];
            rowEnd--;
        }

        if (colSt <= colEnd) {
            for (int i = rowEnd; i >= rowSt; i--)
                res[ind++] = matrix[i][colSt];
            colSt++;
        }
    }

    return res;
}

int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* matrix1Ptrs[3] = {matrix1[0], matrix1[1], matrix1[2]};
    int matrix1ColSize = 3;
    int returnSize1;
    int* result1 = spiralOrder(matrix1Ptrs, 3, &matrix1ColSize, &returnSize1);
    printf("Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]\n");
    printf("Output: [");
    for (int i = 0; i < returnSize1; ++i) {
        printf("%d", result1[i]);
        if (i < returnSize1 - 1) printf(",");
    }
    printf("]\n");
    free(result1);

    int matrix2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int* matrix2Ptrs[3] = {matrix2[0], matrix2[1], matrix2[2]};
    int matrix2ColSize = 4;
    int returnSize2;
    int* result2 = spiralOrder(matrix2Ptrs, 3, &matrix2ColSize, &returnSize2);
    printf("Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n");
    printf("Output: [");
    for (int i = 0; i < returnSize2; ++i) {
        printf("%d", result2[i]);
        if (i < returnSize2 - 1) printf(",");
    }
    printf("]\n");
    free(result2);

    return 0;
}
