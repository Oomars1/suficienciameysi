#include "./suficiencia.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265
float x, y;
void rotar_bandera_3d(unsigned char tecla, int x, int y);

float zoom = -5.0f;
float angleX = 0.0f; // Ángulo de rotación en el eje X
float angleY = 0.0f; // Ángulo de rotación en el eje Y
float angleZ = 0.0f; // Ángulo de rotación en el eje Z

//algoritmo de bresham modificado
void Circulo(float radio, int porciones, int pilas) {
    int i, j;

    for (i = 0; i < porciones; i++) {
        float lat0 = PI * (-0.5 + (float) (i + 1) / porciones);
        float z0 = radio * sin(lat0);
        float zr0 = radio * cos(lat0);

        float lat1 = PI * (-0.5 + (float) i / porciones);
        float z1 = radio * sin(lat1);
        float zr1 = radio * cos(lat1);

        glBegin(GL_POINTS);
        for (j = 0; j <= pilas; j++) {
            float lng = 2 * PI * (float) (j - 1) / pilas;
            float x = cos(lng);
            float y = sin(lng);

            glNormal3f(x * zr0, y * zr0, z0);
            glVertex3f(x * zr0, y * zr0, z0);
            glNormal3f(x * zr1, y * zr1, z1);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }
}
// arriba bresham
void Circulo2(float radio, int porciones, int pilas) {
    int i, j;

    for (i = 0; i < porciones; i++) {
        float lng0 = PI * (-0.5 + (float) (i + 1) / porciones);
        float xr0 = radio * sin(lng0);
        float yr0 = radio * cos(lng0);

        float lng1 = PI * (-0.5 + (float) i / porciones);
        float xr1 = radio * sin(lng1);
        float yr1 = radio * cos(lng1);

        glBegin(GL_POINTS);
        for (j = 0; j < pilas; j++) { // Cambio: j < pilas en lugar de j <= pilas
            float lat = PI * (-0.5 + (float) (j + 1) / pilas); // Cambio: Usar j + 1 en lugar de j - 1
            float z = radio * sin(lat);
            float zr = cos(lat);

            glNormal3f(xr0 * zr, yr0 * zr, z);
            glVertex3f(xr0 * zr, yr0 * zr, z);
            glNormal3f(xr1 * zr, yr1 * zr, z);
            glVertex3f(xr1 * zr, yr1 * zr, z);
        }
        glEnd();
    }
}
//abajo bresham
void Circulo3(float radio, int porciones, int pilas) {
    int i, j;

    for (i = 0; i < porciones; i++) {
        float lng0 = PI * (0.5 + (float) (i + 1) / porciones);
        float xr0 = radio * sin(lng0);
        float yr0 = radio * cos(lng0);

        float lng1 = PI * (0.5 + (float) i / porciones);
        float xr1 = radio * sin(lng1);
        float yr1 = radio * cos(lng1);

        glBegin(GL_POINTS);
        for (j = 0; j < pilas; j++) { // Cambio: j < pilas en lugar de j <= pilas
            float lat = PI * (-0.5 + (float) (j + 1) / pilas); // Cambio: Usar j + 1 en lugar de j - 1
            float z = radio * sin(lat);
            float zr = cos(lat);

            glNormal3f(xr0 * zr, yr0 * zr, z);
            glVertex3f(xr0 * zr, yr0 * zr, z);
            glNormal3f(xr1 * zr, yr1 * zr, z);
            glVertex3f(xr1 * zr, yr1 * zr, z);
        }
        glEnd();
    }
}

void inicializar_suficiencia(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
}

void dibujar_suficiencia(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluPerspective(95, 1, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);

    glTranslatef(0, 0, zoom);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Aplica rotación en el eje X
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Aplica rotación en el eje Y
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // Aplica rotación en el eje Z

    glPointSize(2);
    glColor3f(0, 0, 1);
    
    Circulo(2, 12, 500);

    Circulo2(2, 16, 500);

    Circulo3(2, 16, 500);

    glFlush();

    glutSwapBuffers();
}

const char* get_carnet(void) {
    char *name = "RM19021";
}

void rotar_suficiencia(unsigned char tecla, int x, int y){
    switch (tecla) {
        case 'a':
            angleY -= 5.0f; // izquierda
            break;
        case 'd':
            angleY += 5.0f; // derecha
            break;
        case 's':
            angleX -= 5.0f; // Decrementa el ángulo de rotación en el eje X
            break;
        case 'w':
            angleX += 5.0f; // Incrementa el ángulo de rotación en el eje X
            break;
        case 'j':
            zoom += 0.1f; // Zoom in by incrementing zoom variable
            break;
        case 'k':
            zoom -= 0.1f; // Zoom out by decrementing zoom variable
            break;

    }
    glutPostRedisplay();
}
