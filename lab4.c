/*
 * triangle.c
 *
 *  Created on: Aug 28, 2017
 *      Author: Thumrongsak Kosiyatrakul
 */


#ifdef __APPLE__  // include Mac OS X verions of headers

#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

#else // non-Mac OS X operating systems

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

#endif  // __APPLE__

#include <stdlib.h>
#include <time.h>
#include "initShader.h"
#include "myLib.h"

#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

vec4 vertices[33] =
{{ 0.0,  0.5,  0.0, 1.0},	
 {-0.25, 0.0,  0.0, 1.0},	
 { 0.25, 0.0,  0.0, 1.0}};

vec4 colors[33];

int num_vertices = 33;

// Could this have been simplified? Yes, yes it could've.
void generate_tris() {
    float unit_x = -0.1;
    float unit_y = -0.1;
    float unit_z = 0.1;
    float scale_factor = 0.9;

    int curr_pos = 3;
    mat4 curr_m;

    float r;
    float g;
    float b;

    srand((unsigned int)time(NULL));

    // Load random color into first tri
    r = ((float)rand()/(float)(RAND_MAX)) * 1;
    g = ((float)rand()/(float)(RAND_MAX)) * 1;
    b = ((float)rand()/(float)(RAND_MAX)) * 1;

    vec4 color = {r, g, b, 1.0};

    colors[0] = color;
    colors[1] = color;
    colors[2] = color;
    
    // Front Tris
    for (int i = 0; i < 5; i++) {

        // Do translations and store
        curr_m = mul_m4_to_m4(translate_m4(unit_x, unit_y, unit_z), scale_m4(scale_factor, scale_factor, scale_factor));
        // Using translation from first tri
        vertices[curr_pos] = mul_v4_to_m4(vertices[0], curr_m);
        vertices[curr_pos + 1] = mul_v4_to_m4(vertices[1], curr_m);
        vertices[curr_pos + 2] = mul_v4_to_m4(vertices[2], curr_m);

        // Get rand colors and store
        r = ((float)rand()/(float)(RAND_MAX)) * 1;
        g = ((float)rand()/(float)(RAND_MAX)) * 1;
        b = ((float)rand()/(float)(RAND_MAX)) * 1;

        vec4 color = {r, g, b, 1.0};
        
        colors[curr_pos] = color;
        colors[curr_pos + 1] = color;
        colors[curr_pos + 2] = color;

        // Ready translations for next tri
        unit_x += -0.1;
        unit_y += -0.1;
        unit_z += 0.1;
        scale_factor += -0.1;

        curr_pos+=3;
    }

    // Ready for back tris
    unit_x = 0.1;
    unit_y = 0.1;
    unit_z = -0.1;
    scale_factor = 1.1;

    // Back Tris
    for (int i = 0; i < 5; i++) {

        // Do translations and store
        curr_m = mul_m4_to_m4(translate_m4(unit_x, unit_y, unit_z), scale_m4(scale_factor, scale_factor, scale_factor));
        // Using translation from first tri
        vertices[curr_pos] = mul_v4_to_m4(vertices[0], curr_m);
        vertices[curr_pos + 1] = mul_v4_to_m4(vertices[1], curr_m);
        vertices[curr_pos + 2] = mul_v4_to_m4(vertices[2], curr_m);

        // Get rand colors and store
        r = ((float)rand()/(float)(RAND_MAX)) * 1;
        g = ((float)rand()/(float)(RAND_MAX)) * 1;
        b = ((float)rand()/(float)(RAND_MAX)) * 1;

        vec4 color = {r, g, b, 1.0};

        colors[curr_pos] = color;
        colors[curr_pos + 1] = color;
        colors[curr_pos + 2] = color;

        // Ready translations for next tri
        unit_x += 0.1;
        unit_y += 0.1;
        unit_z += -0.1;
        scale_factor += 0.1;

        curr_pos+=3;
    }
}

void init(void)
{
    GLuint program = initShader("vshader.glsl", "fshader.glsl");
    glUseProgram(program);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    GLuint vColor = glGetAttribLocation(program, "vColor");
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *) sizeof(vertices));

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glDepthRange(1,0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, num_vertices);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int mousex, int mousey)
{
    if(key == 'q')
    	glutLeaveMainLoop();

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Triangle");
    glewInit();
    generate_tris();
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
