#include <glut.h>

#include <cmath>

#include <math.h>

#include <stdlib.h>

#include <soil.h>

unsigned int textures[1];//выделяем память для картинки

int Twidth, Theight;

void LoadTextures()

{

	unsigned char* texture1 = SOIL_load_image("example.bmp", &Twidth, &Theight, 0, SOIL_LOAD_RGB);

	glGenTextures(1, &textures[0]);

	glBindTexture(GL_TEXTURE_2D, textures[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, Twidth, Theight, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1);//строим текстуру

}

float rot = 0.0;

void init(void)

{

	LoadTextures();//вызываем текстуру

	glEnable(GL_TEXTURE_2D);// включаем освещение для текстуры

	glClearColor(1.0, 1, 1, 1.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(40, 1, 1, 10);

	glMatrixMode(GL_MODELVIEW);

}

void myDisplay()

{

	glPushMatrix(); //Сохраняем VM = 1

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //вместесочисткойбуферацветапредусмотретьочисткубуфераглубины

	glEnable(GL_DEPTH_TEST); //включение режима удаления невидимых (проверка глубины)

	gluLookAt(3, 3, 5, 0, 0, 0, 0, 1, 0); // позиция наблюдателя

	glPushMatrix();

	glRotatef(rot, 0.0, 1.0, 0.0);

	//glTranslatef(2.3, 0.0, 0.0);


	glBindTexture(GL_TEXTURE_2D, textures[0]);

	glBegin(GL_POLYGON);

	glNormal3f(0, 0, -1);

	glTexCoord2d(-1, 1); glVertex3f(-0.5, 0.5, -0.5);

	glTexCoord2d(1, 1); glVertex3f(0.5, 0.5, -0.5);

	glTexCoord2f(1.5, 0); glVertex3f(0.75, -0.25, -0.5);

	glTexCoord2f(0, -1); glVertex3f(0, -0.5, -0.5);

	glTexCoord2f(-1, 0); glVertex3f(-0.75, -0.25, -0.5);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, textures[0]);

	glBegin(GL_POLYGON);

	glNormal3f(0, 0, 1);

	glTexCoord2d(-1, 1); glVertex3f(-0.5, 0.5, 0.5);

	glTexCoord2d(1, 1); glVertex3f(0.5, 0.5, 0.5);

	glTexCoord2f(1.5, 0); glVertex3f(0.75, -0.25, 0.5);

	glTexCoord2f(0, -1); glVertex3f(0, -0.5, 0.5);

	glTexCoord2f(-1, 0); glVertex3f(-0.75, -0.25, 0.5);

	glEnd();

	glBegin(GL_POLYGON);

	glNormal3f(0, 1, 0);

	glVertex3f(-0.5, 0.5, -0.5);

	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(0.5, 0.5, 0.5);

	glVertex3f(-0.5, 0.5, 0.5);

	glEnd();

	glBegin(GL_POLYGON);

	glNormal3f(1, 0, 0);

	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(0.5, 0.5, 0.5);

	glVertex3f(0.75, -0.25, 0.5);

	glVertex3f(0.75, -0.25, -0.5);

	glEnd();

	glBegin(GL_POLYGON);

	glNormal3f(-1, 0, 0);

	glVertex3f(-0.5, 0.5, -0.5);

	glVertex3f(-0.5, 0.5, 0.5);

	glVertex3f(-0.75, -0.25, 0.5);

	glVertex3f(-0.75, -0.25, -0.5);

	glEnd();

	glBegin(GL_POLYGON);

	glNormal3f(0, -1, 0);

	glVertex3f(0.75, -0.25, -0.5);

	glVertex3f(0.75, -0.25, 0.5);

	glVertex3f(0, -0.5, 0.5);

	glVertex3f(0, -0.5, -0.5);

	glEnd();

	glBegin(GL_POLYGON);

	glNormal3f(0, -1, 0);

	glVertex3f(-0.75, -0.25, -0.5);

	glVertex3f(-0.75, -0.25, 0.5);

	glVertex3f(0, -0.5, 0.5);

	glVertex3f(0, -0.5, -0.5);

	glEnd();

	//звёзды

	//glColor3f(0.4, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glNormal3f(0, 1, 0);

	glVertex3f(-0.5, 0.5, -0.5);

	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(0, 2, 0);

	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(0.5, 0.5, 0.5);

	glVertex3f(0, 2, 0);

	glVertex3f(0.5, 0.5, 0.5);

	glVertex3f(-0.5, 0.5, 0.5);

	glVertex3f(0, 2, 0);

	glVertex3f(-0.5, 0.5, 0.5);

	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(0, 2, 0);

	glEnd();

	//glColor3f(0.4, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glNormal3f(1, 0, 0);

	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(0.5, 0.5, 0.5);

	glVertex3f(2, 0.5, 0);

	glVertex3f(0.5, 0.5, 0.5);

	glVertex3f(0.75, -0.25, 0.5);

	glVertex3f(2, 0.5, 0);

	glVertex3f(0.75, -0.25, 0.5);

	glVertex3f(0.75, -0.25, -0.5);

	glVertex3f(2, 0.5, 0);

	glVertex3f(0.75, -0.25, -0.5);

	glVertex3f(0.5, 0.5, -0.5);

	glVertex3f(2, 0.5, 0);

	glEnd();

	//glColor3f(0.4, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glNormal3f(-1, 0, 0);

	glVertex3f(-0.5, 0.5, -0.5);

	glVertex3f(-0.5, 0.5, 0.5);

	glVertex3f(-2, 0.5, 0);

	glVertex3f(-0.5, 0.5, 0.5);

	glVertex3f(-0.75, -0.25, 0.5);

	glVertex3f(-2, 0.5, 0);

	glVertex3f(-0.75, -0.25, 0.5);

	glVertex3f(-0.75, -0.25, -0.5);

	glVertex3f(-2, 0.5, 0);

	glVertex3f(-0.75, -0.25, -0.5);

	glVertex3f(-0.5, 0.5, -0.5);

	glVertex3f(-2, 0.5, 0);

	glEnd();

	//glColor3f(0.4, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glNormal3f(0, -1, 0);

	glVertex3f(-0.75, -0.25, -0.5);

	glVertex3f(-0.75, -0.25, 0.5);

	glVertex3f(-0.725, -1.75, 0);

	glVertex3f(-0.75, -0.25, 0.5);

	glVertex3f(0, -0.5, 0.5);

	glVertex3f(-0.725, -1.75, 0);

	glVertex3f(-0.75, -0.25, 0.5);

	glVertex3f(0, -0.5, 0.5);

	glVertex3f(-0.725, -1.75, 0);

	glVertex3f(0, -0.5, 0.5);

	glVertex3f(0, -0.5, -0.5);

	glVertex3f(-0.725, -1.75, 0);

	glVertex3f(0, -0.5, -0.5);

	glVertex3f(-0.75, -0.25, -0.5);

	glVertex3f(-0.725, -1.75, 0);

	glEnd();

	//glColor3f(0.4, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glNormal3f(0, -1, 0);

	glVertex3f(0.75, -0.25, -0.5);

	glVertex3f(0.75, -0.25, 0.5);

	glVertex3f(0.725, -1.75, 0);

	glVertex3f(0.75, -0.25, 0.5);

	glVertex3f(0, -0.5, 0.5);

	glVertex3f(0.725, -1.75, 0);

	glVertex3f(0, -0.5, 0.5);

	glVertex3f(0, -0.5, -0.5);

	glVertex3f(0.725, -1.75, 0);

	glVertex3f(0, -0.5, -0.5);

	glVertex3f(0.75, -0.25, -0.5);

	glVertex3f(0.725, -1.75, 0);

	glEnd();
	glPopMatrix();



	glPopMatrix();

	rot += 10.0;

	if (rot >= 360)

		rot -= 360;

	glDisable(GL_LIGHTING); //Выключаем освещение

	glPopMatrix();

	glutSwapBuffers();


	void Timer(int value)

	{

		glutPostRedisplay();

		glutTimerFunc(90, Timer, 0);

	}

	void myReshape(int width, int height)

	{

		if (width / height < 1) glViewport(0, 0, width, width);

		else glViewport(0, 0, height, height);

	}

	int main(int argc, char* argv[])

	{

		glutInit(&argc, argv);

		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //устанавливаярежимдисплеявфункции main(), предусмотреноиспользованиебуфераглубины

		glutInitWindowSize(800, 800);

		glutInitWindowPosition(0, 0);

		glutCreateWindow("My prog");

		glutDisplayFunc(myDisplay);

		glutReshapeFunc(myReshape);

		glutTimerFunc(20, Timer, 0);


		init();

		glutMainLoop();

	}