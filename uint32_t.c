#include <stdio.h>
#include <stdlib.h>  // 包含 rand() 和 srand()
#include <time.h>    // 包含 time()
#include <stdint.h>
void print_binary(uint32_t b) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (b >> i) & 1);
    }
    printf("\n");
}
uint32_t a;
int main() {
    uint32_t result = 0; 
    // 设置随机数种子（根据当前时间）
    srand(time(NULL));

    printf("生成的 32 个随机整数（范围 0~100）：\n");

    for (int i = 0; i < 32; i++) {
        int num = rand() % 101;  // rand() % 101 生成 0~100 的整数
        printf("%d ", num);
        if (num>50){
        result = result | (1 << i);       
        }
    }
    printf("最终结果 (二进制): ");
    print_binary(result);
}
