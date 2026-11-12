#ifndef _MYLIB_H_
#define _MYLIB_H_

#include <GL/gl.h>

typedef struct {
    float x;
    float y;
    float z;
    float w;
} vec4;

typedef struct {
    vec4 x;
    vec4 y;
    vec4 z;
    vec4 w;
} mat4;

// Insert function signatures after this line

// ! = Not Started | ~ = In Progress | ^ = Completed | ^~ = Needs Debugged

// *** Vector Operations ***
void print_v4(vec4);
vec4 sc_mul_v4(vec4, float);                    // ^
vec4 add_v4_to_v4(vec4, vec4);                  // ^
vec4 sub_v4_to_v4(vec4, vec4);                  // ^
float mag_of_v4(vec4);                          // ^
vec4 normalize_v4(vec4);                        // ^
float dot_product_of_v4_v4(vec4, vec4);         // ^
vec4 cross_product_of_v4_v4(vec4, vec4);        // ^

// *** Matrix Operations ***
void print_m4(mat4);                            // ^
mat4 sc_mul_m4(mat4, float);                    // ^
mat4 add_m4_to_m4(mat4, mat4);                  // ^
mat4 sub_m4_to_m4(mat4, mat4);                  // ^
mat4 mul_m4_to_m4(mat4, mat4);                  // ^
vec4 mul_v4_to_m4(vec4, mat4);                  // ^
mat4 transpose_m4(mat4);                        // ^
mat4 inverse_m4(mat4);                          // ^

// *** Translation junk ***
mat4 identity();
mat4 translate_m4(GLfloat, GLfloat, GLfloat);   // ^~
mat4 scale_m4(GLfloat, GLfloat, GLfloat);       // ^~
mat4 rot_x_m4(float);                           // ~
mat4 rot_y_m4(float);                           // ^~
// mat4 rot_z_m4(float);                           // ~



// Do not put anything after this line

#endif
