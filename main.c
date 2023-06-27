#include "./suficiencia.h"
#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/freeglut.h>
#include <math.h>

int main(int argc, char** argv) {
    printf("Examen de suficiencia de %s \n",get_carnet());
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(700, 700);
    glutCreateWindow(get_carnet());
    glClearColor(0.8, 0, 0, 1);
    inicializar_suficiencia();
    glutDisplayFunc(dibujar_suficiencia);
    glutKeyboardFunc(rotar_suficiencia);
    glutMainLoop();
    printf("=== fin === %s",get_carnet());
    return (EXIT_SUCCESS);
}
