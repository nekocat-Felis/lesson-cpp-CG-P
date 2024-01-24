// my_animation.cpp --- 時計と玉
//
#include<math.h>
#include<windows.h>
#include"GL/glut.h"

void myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	/*ビューポート変換*/
	glViewport(0, 0, w, h);
	/*射影変換*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
}
void display(void)
{
	GLUquadricObj* quad;
	float i;
	//カラーバッファのクリア//
	glClearColor(0, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat white[] = { 0.9f,0.9f,0.9f,1.0f };
	GLfloat gray[] = { 0.5f,0.5f,0.5f,1.0f };

	GLfloat red[] = { 0.8f,0.0f,0.3f,1.0f };
	GLfloat blue[] = { 0.0f,0.0f,0.9f };
	//ビューイング変換//
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10, 7, 10, 0, 0, 0, 10, 10, 10);

	double r = 5; // 半径
	double yNow; // 現在の高度

	for (i = 0; i < 10; i = i + 0.02) {

		yNow = (pow(fmodf(i, 1)-0.5, 2) - 0.25) * -20;

		Sleep(20); // 速度調整
		glClearColor(0.5, 0.5, 0.5, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glTranslatef(0, 0, 0);
		glRotatef(36 * i, 0, 1, 0);
		//動く球の生成//
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
		glTranslatef(0, yNow, -r);
		glRotatef(-36 * i, 0, 1, 0);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		//動かない球の生成//
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, gray);
		glTranslatef(0, -0.5, 0);
		glRotatef(-36 * i, 0, 1, 0);
		glScalef(0.4, 1, 0.4);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		//丸い床の生成//
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
		glTranslatef(0, -1, 0);
		glRotatef(-72 * i, 0, 1, 0);
		glScalef(1, 0.01, 1);
		glutSolidSphere(r+2, 30, 30);
		glPopMatrix();

		//長い柱の生成//
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, gray);
		glRotatef(72 * i, 0, 0.1, 0);
		quad = gluNewQuadric();
		gluCylinder(quad, 0.2, 0.2, r + 1, 100, 1);
		gluDeleteQuadric(quad);
		glPopMatrix();
		
		//短い柱の生成//
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, gray);
		quad = gluNewQuadric();
		gluCylinder(quad, 0.2, 0.4, r - 1, 100, 1);
		gluDeleteQuadric(quad);
		glPopMatrix();

		glPopMatrix();
		glutSwapBuffers();
	}
}
void myinit(void)
{
	/*Diffuse Material Data*/
	GLfloat mat_diffuse[] = { 0.3f,0.7f,0.3f,1.0f };

	/*Diffuse Light Data*/
	GLfloat light_diffuse[] = { 1.0,1.0,1.0,1.0 };
	/*Light Position Data*/
	GLfloat light_position[] = { 1.0f,0.0f,1.0f,0.0f };
	/*Set Material*/
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	/*Set Light0*/
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	/*Light ON*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/*Z Buffer ON*/
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("my_animation");
	myinit();
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glutMainLoop();
	return(0);
}