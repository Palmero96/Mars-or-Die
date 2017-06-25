#include <iostream>
#include "glut.h"
#include "Coordinator.h"

Coordinator coord;

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnSpecialKeyboardDown(int key, int x, int y);

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1200, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Mars Or Die");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(60.0, 1200 / 600.0f, 0.1, 1200);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(OnSpecialKeyboardDown);

	glutMainLoop();
	return 0;
}


void OnDraw(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//Borrado de la pantalla	

	glMatrixMode(GL_MODELVIEW);	//Para definir el punto de vista
	glLoadIdentity();

	coord.Draw();

	glutSwapBuffers();

}

void OnSpecialKeyboardDown(int key, int x, int y)
{
	coord.ArrowKey(key, x, y);
	glutPostRedisplay();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	coord.Key(key, x_t, y_t);
	glutPostRedisplay();
}

void OnTimer(int value)
{
	coord.Timer();

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

