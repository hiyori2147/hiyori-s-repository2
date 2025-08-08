#include <stdio.h>
#include <stdint.h>
// 大小端转换函数：将32位整数的字节顺序反转
uint32_t swap_endian32(uint32_t value) {
    return ((value & 0x000000FF) << 24) |  // 原最低字节 -> 最高位
           ((value & 0x0000FF00) << 8)  |  // 次低字节 -> 次高位
           ((value & 0x00FF0000) >> 8)  |  // 次高字节 -> 次低位
           ((value & 0xFF000000) >> 24);   // 最高字节 -> 最低位
}
int main() {
    uint32_t value = 0x12253647;
    // 转换大小端并输出
    uint32_t swapped = swap_endian32(value);
    printf("转换后（大小端互换）：0x%08X\n", swapped);
}
