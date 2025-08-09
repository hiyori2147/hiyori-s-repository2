#include<string.h>
#include<stdint.h>
#include<stdio.h>
int main(){
    float a =59.622f;
    float b =92.6327f;
    char buffer[4];
    const float scale = 100.0f;
    int16_t a_scaled = (int16_t)(a * scale);
    int16_t b_scaled =(int16_t)(b * scale);
    memcpy(buffer, &a_scaled, sizeof(int16_t));
    memcpy(buffer + sizeof(int16_t), &b_scaled, sizeof(int16_t));
    int16_t a_read,b_read;
    memcpy(&a_read, buffer, sizeof(int16_t));
    memcpy(&b_read, buffer + sizeof(int16_t), sizeof(int16_t));
    float a_final = (float)a_read / scale;
    float b_final = (float)b_read / scale;
    printf("a_final: %.3f\n", a_final);
    printf("b_final: %.4f\n", b_final);
    printf("\n%.3f %.4f",a-a_final,b-b_final);
    getchar();
}
