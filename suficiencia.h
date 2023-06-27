#ifndef SUFICIENCIA_H
#define SUFICIENCIA_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif 
/**
* Se encarga de inicializar (si es necesario) su invocacion
* esta llamada se realizara una sola vez al inicio de la ejecucion
*/
void inicializar_suficiencia(void);
/**
* Dibuja su entrega de esfera  mediante la invocacion del callback
de glut tal y como se mostro en clase.
*/
void dibujar_suficiencia();

/**
* retorne su numero de carnet en la invocacion, en base a esto se asignara su nota de forma automatica 
*/
const char* get_carnet(void);

/**
* se encarga de rotar la esfera, w y s para el eje x, 
* a y d para eje y, 
* j y k para eje z. 
*/
void rotar_suficiencia(unsigned char,int,int);

#endif /* SUFICIENCIA_H */
