#include <iostream>
#include <cstring>      // for memcpy
#include <bitset>       // for binary display
#include <cmath>        // for fabs

void printDiff(float a, float b) {
    std::cout << "原值: " << a << " 提取值: " << b
              << " 差值: " << fabs(a - b) << std::endl;
}

int main() {
    float f1 = 3.14159f;
    float f2 = 2.71828f;
    char buffer[8];

    std::cout << "--- 方法1：使用 memcpy ---" << std::endl;
    std::memcpy(buffer, &f1, 4);
    std::memcpy(buffer + 4, &f2, 4);

    float out1, out2;
    std::memcpy(&out1, buffer, 4);
    std::memcpy(&out2, buffer + 4, 4);
    printDiff(f1, out1);
    printDiff(f2, out2);
 std::cout << "\n--- 方法2：使用联合体 union ---" << std::endl;
    union FloatBytes {
        float f;
        char b[4];
    };
    FloatBytes u1, u2;
    u1.f = f1;
    u2.f = f2;

    // 写入
    for (int i = 0; i < 4; ++i) buffer[i] = u1.b[i];
    for (int i = 0; i < 4; ++i) buffer[4 + i] = u2.b[i];

    // 读取
    for (int i = 0; i < 4; ++i) u1.b[i] = buffer[i];
    for (int i = 0; i < 4; ++i) u2.b[i] = buffer[4 + i];
    printDiff(f1, u1.f);
    printDiff(f2, u2.f);

    std::cout << "\n--- 方法3：使用类型转换 reinterpret_cast ---" << std::endl;
    // 写入
    *reinterpret_cast<float*>(buffer) = f1;
    *reinterpret_cast<float*>(buffer + 4) = f2;

    // 读取
    float* fp1 = reinterpret_cast<float*>(buffer);
    float* fp2 = reinterpret_cast<float*>(buffer + 4);
    printDiff(f1, *fp1);
    printDiff(f2, *fp2);

    return 0;
}