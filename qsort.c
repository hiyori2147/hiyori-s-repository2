#include <stdio.h>
#include <stdlib.h>
int compare_float(const void *a, const void *b) {
    float fa = *(const float *)a;
    float fb = *(const float *)b;
    if (fa < fb) return -1;
    if (fa > fb) return 1; 
    return 0;            
}
int main() {
    int n;
    printf("请输入数据个数: ");
    scanf("%d", &n);

    float *arr = malloc(n * sizeof(float)); 
    if (arr == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    printf("请输入 %d 个 float 类型数据:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    qsort(arr, n, sizeof(float), compare_float);

    printf("从小到大排序结果:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    free(arr); 
    return 0;
}