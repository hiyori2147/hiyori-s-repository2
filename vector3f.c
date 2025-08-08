#include "vector3f.h"
#include <math.h>
#include <stdlib.h>
Vector3f vec3_add(Vector3f a, Vector3f b) {
    Vector3f result= {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}//加
Vector3f vec3_sub(Vector3f a, Vector3f b) {
    Vector3f result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}//减
float vec3_dot(Vector3f a, Vector3f b) {
    float result = a.x * b.x + a.y * b.y + a.z * b.z;
    return result;
}//点积
float vec3_length(Vector3f v) {
    float length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    return length;
}//长度
Vector3f vec3_cross(Vector3f a, Vector3f b) {
    Vector3f result = {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
    return result;
}//叉积
Vector3f vec3_normalize(Vector3f v) {
    float length = vec3_length(v);
    if (length == 0) {
        return (Vector3f){0, 0, 0}; // Return zero vector if length is zero
    }
    else{
        Vector3f result = {v.x / length, v.y / length, v.z / length};
    return result;
    }
}//单位化
#include<stdio.h>
int main() {
    float h,d;
    Vector3f A ={1.0f,0.0f,1.0f};
    Vector3f C1 ={0.0f,1.0f,0.0f};
    Vector3f B ={1.0f,1.0f,1.0f};
    Vector3f C = {0.0f,1.0f,1.0f};
Vector3f sub1= vec3_sub(A,B);
Vector3f sub2= vec3_sub(B,C1);
Vector3f sub3= vec3_sub(A,C1);
float length1 = vec3_length(sub1);
float length2 = vec3_length(sub2);
float length3 = vec3_length(sub3);
h=length1*length2/length3;
printf("The distance is: %f\n", h);
Vector3f n= vec3_cross(sub2, sub3);
float D= (-1)*vec3_dot(n,A);
d=(vec3_dot(C,n)+D)/vec3_length(n);
if(d<0){
    d = -d;
    printf("The distance is: %f\n", d);
}
else {
    printf("The distance is: %f\n", d);
}
system("pause");
}
