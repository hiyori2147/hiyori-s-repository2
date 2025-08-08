#ifndef VECTOR3F_H
#define VECTOR3F_H
typedef struct{
    float x;
    float y;
    float z;
} Vector3f;
Vector3f vec3_add(Vector3f a, Vector3f b);
Vector3f vec3_sub(Vector3f a, Vector3f b);
float vec3_dot(Vector3f a, Vector3f b);
float vec3_length(Vector3f v);
#endif // VECTOR3F_H