#include <iostream>

#include "glew.h"
#include "glut.h"
#include "World.h"

World world;

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
/*
static char* readFile(const char* filename) {
	// Open file
	FILE* fp = fopen(filename, "r");
	fseek(fp, 0, SEEK_END);
	long file_length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char* contents = new char[file_length + 1];
	for (int i = 0; i < file_length + 1; i++)
		contents[i];
	fread(contents, 1, file_length, fp);
	contents[file_length + 1] = '\0';
	fclose(fp);
	return contents;
}



GLuint makeVertxShader(const char* shaderSource){	// funci�n que devuelve la ID del Vertex Shader a partir del .txt

	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);	// Se crea un unsigned int donde se guarda la id del shader
	glShaderSource(vertexShaderID, 1, (const GLchar**)&shaderSource, NULL);
	glCompileShader(vertexShaderID);
	return vertexShaderID;
}


*/


int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	world.Initialize();

	glutMainLoop();

	return 0;
}


void OnDraw(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//Borrado de la pantalla	

	glMatrixMode(GL_MODELVIEW);	//Para definir el punto de vista
	glLoadIdentity();

	world.Draw();

	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	glutPostRedisplay();
}

void OnTimer(int value)
{
	world.Timer();

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
