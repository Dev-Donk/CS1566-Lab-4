#include "myLib.h"
#include <stdio.h>
#include <math.h>

// REMEMBER, WE DO NOT CARE ABOUT PERFORMANCE FOR THIS CLASS
// GET IT WORKING, THEN MAYBE YOU CAN THINK ABOUT HOW YOU CAN
// IMPOVE YOUR CODE. JUST DO IT!!!

// *** Vector Operations ***

void print_v4(vec4 v) {
    printf("[ %7.4f %7.4f %7.4f %7.4f ]\n", v.x, v.y, v.z, v.w);
}

vec4 sc_mul_v4(vec4 v, float a) {
    vec4 ret;
    
    ret.x = a * v.x;
    ret.y = a * v.y;
    ret.z = a * v.z;
    ret.w = a * v.w;

    return ret;
}

/*
    Goes from v1 + v2
    So..
    x1 + x2
    y1 + y2
    ... and so on
*/
vec4 add_v4_to_v4(vec4 v1, vec4 v2) {
    vec4 ret;

    ret.x = v1.x + v2.x;
    ret.y = v1.y + v2.y;
    ret.z = v1.z + v2.z;
    ret.w = v1.w + v2.w;

    return ret;
}
/*
    Goes from v1 - v2
    So..
    x1 - x2
    y1 - y2
    ... and so on
*/
vec4 sub_v4_to_v4(vec4 v1, vec4 v2) {
    vec4 ret;

    ret.x = v1.x - v2.x;
    ret.y = v1.y - v2.y;
    ret.z = v1.z - v2.z;
    ret.w = v1.w - v2.w;

    return ret;
}

float mag_of_v4(vec4 v) {
    float ret = sqrtf(powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2) + powf(v.w, 2));
    return fabs(ret);
}

vec4 normalize_v4(vec4 v) {
    vec4 ret;
    float mag = mag_of_v4(v);

    ret.x = v.x / mag;
    ret.y = v.y / mag;
    ret.z = v.z / mag;
    ret.w = v.w / mag;

    return ret;
}

float dot_product_of_v4_v4(vec4 v1, vec4 v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
}

vec4 cross_product_of_v4_v4(vec4 v1, vec4 v2) {
    vec4 ret;

    ret.x = (v1.y * v2.z) - (v1.z * v2.y);
    ret.y = (v1.z * v2.x) - (v1.x * v2.z);
    ret.z = (v1.x * v2.y) - (v1.y * v2.x);
    ret.w = 0.0;

    return ret;
}

// ********************

// *** Matrix Operations ***

vec4 get_row_x(mat4 m) {
    vec4 ret_x = {m.x.x, m.y.x, m.z.x, m.w.x};
    return ret_x;
}
vec4 get_row_y(mat4 m) {
    vec4 ret_y = {m.x.y, m.y.y, m.z.y, m.w.y};
    return ret_y;
}
vec4 get_row_z(mat4 m) {
    vec4 ret_z = {m.x.z, m.y.z, m.z.z, m.w.z};
    return ret_z;
}
vec4 get_row_w(mat4 m) {
    vec4 ret_w = {m.x.w, m.y.w, m.z.w, m.w.w};
    return ret_w;
}

void print_m4(mat4 m) {
    print_v4(get_row_x(m));
    print_v4(get_row_y(m));
    print_v4(get_row_z(m));
    print_v4(get_row_w(m));
}

mat4 sc_mul_m4(mat4 m, float a) {
    mat4 ret;

    vec4 x = sc_mul_v4(m.x, a);
    vec4 y = sc_mul_v4(m.y, a);
    vec4 z = sc_mul_v4(m.z, a);
    vec4 w = sc_mul_v4(m.w, a);

    ret.x = x;
    ret.y = y;
    ret.z = z;
    ret.w = w;

    return ret;
}

mat4 add_m4_to_m4(mat4 m1, mat4 m2) {
    mat4 ret;

    vec4 x = add_v4_to_v4(m1.x, m2.x);
    vec4 y = add_v4_to_v4(m1.y, m2.y);
    vec4 z = add_v4_to_v4(m1.z, m2.z);
    vec4 w = add_v4_to_v4(m1.w, m2.w);

    ret.x = x;
    ret.y = y;
    ret.z = z;
    ret.w = w;

    return ret;
}

mat4 sub_m4_to_m4(mat4 m1, mat4 m2) {
    mat4 ret;

    vec4 x = sub_v4_to_v4(m1.x, m2.x);
    vec4 y = sub_v4_to_v4(m1.y, m2.y);
    vec4 z = sub_v4_to_v4(m1.z, m2.z);
    vec4 w = sub_v4_to_v4(m1.w, m2.w);

    ret.x = x;
    ret.y = y;
    ret.z = z;
    ret.w = w;

    return ret;
}

float get_product_from_mul_mat4(vec4 v1, vec4 v2) {
    float ret = 0;

    ret += v1.x * v2.x;
    ret += v1.y * v2.y;
    ret += v1.z * v2.z;
    ret += v1.w * v2.w;

    return ret;
}

mat4 mul_m4_to_m4(mat4 m1, mat4 m2) {
    mat4 ret;
    
    // c11, c21, c31, c41
    ret.x.x = get_product_from_mul_mat4(get_row_x(m1), m2.x);
    ret.x.y = get_product_from_mul_mat4(get_row_y(m1), m2.x);
    ret.x.z = get_product_from_mul_mat4(get_row_z(m1), m2.x);
    ret.x.w = get_product_from_mul_mat4(get_row_w(m1), m2.x);

    // c12, c22, c32, c42
    ret.y.x = get_product_from_mul_mat4(get_row_x(m1), m2.y);
    ret.y.y = get_product_from_mul_mat4(get_row_y(m1), m2.y);
    ret.y.z = get_product_from_mul_mat4(get_row_z(m1), m2.y);
    ret.y.w = get_product_from_mul_mat4(get_row_w(m1), m2.y);

    // c13, c23, c33, c43
    ret.z.x = get_product_from_mul_mat4(get_row_x(m1), m2.z);
    ret.z.y = get_product_from_mul_mat4(get_row_y(m1), m2.z);
    ret.z.z = get_product_from_mul_mat4(get_row_z(m1), m2.z);
    ret.z.w = get_product_from_mul_mat4(get_row_w(m1), m2.z);

    // c14, c24, c34, c44
    ret.w.x = get_product_from_mul_mat4(get_row_x(m1), m2.w);
    ret.w.y = get_product_from_mul_mat4(get_row_y(m1), m2.w);
    ret.w.z = get_product_from_mul_mat4(get_row_z(m1), m2.w);
    ret.w.w = get_product_from_mul_mat4(get_row_w(m1), m2.w);

    return ret;
}

vec4 mul_v4_to_m4(vec4 v, mat4 m) {
    vec4 ret;

    ret.x = get_product_from_mul_mat4(get_row_x(m), v);
    ret.y = get_product_from_mul_mat4(get_row_y(m), v);
    ret.z = get_product_from_mul_mat4(get_row_z(m), v);
    ret.w = get_product_from_mul_mat4(get_row_w(m), v);

    return ret;
}

mat4 transpose_m4(mat4 m) {
    mat4 ret;

    ret.x = get_row_x(m);
    ret.y = get_row_y(m);
    ret.z = get_row_z(m);
    ret.w = get_row_w(m);

    return ret;
}

float minor_element(mat4 m, int row, int col) {
    float vals[9]; // 3x3 submatrix
    int index = 0;

    vec4 rows[4] = { get_row_x(m), get_row_y(m), get_row_z(m), get_row_w(m) };

    // Loop rows
    for (int r = 0; r < 4; r++) {
        if (r == row) continue; // Will skip row based on arg

        vec4 curr_r = rows[r]; 
        float v[4] = { curr_r.x, curr_r.y, curr_r.z, curr_r.w }; // Get columns from row

        // Loop cols
        for (int c = 0; c < 4; c++) {
            if (c == col) continue; // Will skip col based on arg
            vals[index++] = v[c];
        }
    }

    // Easier to read (brain hurts)
    float a = vals[0], b = vals[1], c = vals[2];
    float d = vals[3], e = vals[4], f = vals[5];
    float g = vals[6], h = vals[7], i = vals[8];

    return a * (e * i - f * h)
         - b * (d * i - f * g)
         + c * (d * h - e * g);
}

mat4 minor_m4(mat4 m) {
    mat4 ret;

    // c11, c21, c31, c41
    ret.x.x = minor_element(m, 0, 0);
    ret.x.y = minor_element(m, 1, 0);
    ret.x.z = minor_element(m, 2, 0);
    ret.x.w = minor_element(m, 3, 0);

    // c12, c22, c32, c42
    ret.y.x = minor_element(m, 0, 1);
    ret.y.y = minor_element(m, 1, 1);
    ret.y.z = minor_element(m, 2, 1);
    ret.y.w = minor_element(m, 3, 1);

    // c13, c23, c33, c43
    ret.z.x = minor_element(m, 0, 2);
    ret.z.y = minor_element(m, 1, 2);
    ret.z.z = minor_element(m, 2, 2);
    ret.z.w = minor_element(m, 3, 2);

    // c14, c24, c34, c44
    ret.w.x = minor_element(m, 0, 3);
    ret.w.y = minor_element(m, 1, 3);
    ret.w.z = minor_element(m, 2, 3);
    ret.w.w = minor_element(m, 3, 3);

    return ret;
}

mat4 cofactor_m4(mat4 m) {
    mat4 ret;

    // c11, c21, c31, c41
    ret.x.x = m.x.x;
    ret.x.y = -m.x.y;
    ret.x.z = m.x.z;
    ret.x.w = -m.x.w;

    // c12, c22, c32, c42
    ret.y.x = -m.y.x;
    ret.y.y = m.y.y;
    ret.y.z = -m.y.z;
    ret.y.w = m.y.w;

    // c13, c23, c33, c43
    ret.z.x = m.z.x;
    ret.z.y = -m.z.y;
    ret.z.z = m.z.z;
    ret.z.w = -m.z.w;

    // c14, c24, c34, c44
    ret.w.x = -m.w.x;
    ret.w.y = m.w.y;
    ret.w.z = -m.w.z;
    ret.w.w = m.w.w;

    return ret;
}

float determinant(mat4 m) {
    float cf_x_x =  minor_element(m, 0, 0);
    float cf_x_y = -minor_element(m, 0, 1);
    float cf_x_z =  minor_element(m, 0, 2);
    float cf_x_w = -minor_element(m, 0, 3);

    return (get_row_x(m).x * cf_x_x) + (get_row_x(m).y * cf_x_y)
         + (get_row_x(m).z * cf_x_z) + (get_row_x(m).w * cf_x_w);
}

mat4 inverse_m4(mat4 m) {
    mat4 minor = minor_m4(m);
    mat4 cofactor = cofactor_m4(minor);
    mat4 transpose = transpose_m4(cofactor);
    float d = determinant(m);

    mat4 ret = sc_mul_m4(transpose, 1/d);

    return ret;
}

// ********************

// *** Translation junks ***

mat4 identity() {
    mat4 ret = {
        .x = {1, 0, 0, 0},
        .y = {0, 1, 0, 0},
        .z = {0, 0, 1, 0},
        .w = {0, 0, 0, 1}
    };
    return ret;
}

// so he uses identity
mat4 translate_m4(GLfloat ax, GLfloat ay, GLfloat az) {
    mat4 ret = identity();
    ret.w.x = ax;
    ret.w.y = ay;
    ret.w.z = az;

    return ret;
}

mat4 scale_m4(GLfloat bx, GLfloat by, GLfloat bz) {
    mat4 ret = identity();
    ret.x.x = bx;
    ret.y.y = by;
    ret.z.z = bz;

    return ret;
}

float convert_degree_to_radian(float degree) {
    return (degree * M_PI) / 180.0;
}

mat4 rot_x_m4(float d) {
    mat4 ret = identity();
    float r = convert_degree_to_radian(d);

    ret.y.y = cos(r);
    ret.z.y = -(sin(r));

    ret.y.z = sin(r);
    ret.z.z = cos(r);

    return ret;
}

mat4 rot_y_m4(float d) {
    mat4 ret = identity();
    float r = convert_degree_to_radian(d);

    ret.x.x = cos(r);
    ret.z.x = sin(r);

    ret.x.z = -(sin(r));
    ret.z.z = cos(r);

    return ret;
}

mat4 rot_z_m4(float d) {
    mat4 ret = identity();
    float r = convert_degree_to_radian(d);

    ret.x.x = cos(r);
    ret.y.x = -(sin(r));

    ret.x.y = sin(r);
    ret.y.y = cos(r);

    return ret;
}

// ********************
