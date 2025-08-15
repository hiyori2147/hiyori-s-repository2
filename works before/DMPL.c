#include<stdint.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct MParam
{
    uint8_t row;
    uint8_t column;
    float **data;
}* Matrix;
  Matrix createMatrix(uint8_t row, uint8_t column) {
   Matrix mat = (Matrix)malloc(sizeof(struct MParam));
   if (!mat) return NULL ;
    mat->row = row;
    mat->column = column;
    mat->data = (float **)malloc(row * sizeof(float *));
    if (!mat->data) {
        free(mat);
        return NULL;
    }   
    for(uint8_t i = 0; i < row; i++) {
        mat->data[i] = (float *)malloc(column * sizeof(float));
        if(!mat->data[i]) {
            for(uint8_t j = 0; j < i; j++) {
                free(mat->data[j]);
            }
            free(mat->data);
            free(mat);
            return NULL;
        }
    }
    return mat;
    }
    void freeMatrix(Matrix mat) {
        if(mat) {
            for(uint8_t i = 0; i < mat->row; i++) {
                free(mat->data[i]);
            }
            free(mat->data);
            free(mat);
        }
    }
    int main()
{
    uint8_t row, col;
    printf("请输入矩阵的行数: ");
    scanf("%hhu", &row);
    printf("请输入矩阵的列数: ");
    scanf("%hhu", &col);
    Matrix m = createMatrix(row, col);
    if (!m) {
        printf("内存分配失败！\n");
        return 1;
    }
    printf("请输入矩阵的每个元素（共 %d 行 %d 列）：\n", row, col);
    for (uint8_t i = 0; i < m->row; i++) {
        for (uint8_t j = 0; j < m->column; j++) {
            printf("元素[%d][%d]: ", i, j);
            scanf("%f", &m->data[i][j]);
        }
    }
    printf("矩阵内容：\n");
    printf("矩阵和它的转置矩阵的乘积：\n");
for (uint8_t i = 0; i < m->row; i++) {
    for (uint8_t j = 0; j < m->row; j++) {
        float sum = 0.0f;
        for (uint8_t k = 0; k < m->column; k++) { 
            sum += m->data[i][k] * m->data[j][k]; 
        }
        printf("%.2f ", sum);
    }
    printf("\n");
}
    freeMatrix(m);
}

