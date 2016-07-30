#include <GL/glut.h>

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-_cameraAngle, 01.0, 01.0, 01.0);
	glTranslatef(-1.0, -1.0, -9.0);

    glPushMatrix();
	glRotatef(_angle, 01.0, 01.0, 01.0);
/*
	glColor3ub(255,255,255);
	glBegin(GL_LINES);
		glVertex3f(10,10,10);
		glVertex3f(-10,-10,-10);
	glEnd();
*/
	glColor3ub(255,23,68);
	glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(2,0,0);
		glVertex3f(2,2,0);
		glVertex3f(0,2,0);
	glEnd();

	glRotatef(90, 0.0, -1.0, 00.0);
	glColor3ub(213,0,249);
	glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(2,0,0);
		glVertex3f(2,2,0);
		glVertex3f(0,2,0);
	glEnd();

    glTranslatef(2.0, 0.0, -2.0);

	glRotatef(90, 0.0, -1.0, 0.0);
	glColor3ub(61,90,254);
	glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(2,0,0);
		glVertex3f(2,2,0);
		glVertex3f(0,2,0);
	glEnd();

	glRotatef(90, 0.0, -1.0, 00.0);
	glColor3ub(0,229,255);
	glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(2,0,0);
		glVertex3f(2,2,0);
		glVertex3f(0,2,0);
	glEnd();

	glRotatef(90, -1.0, 0.0, 0.0);
	glColor3ub(118,255,3);
	glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(2,0,0);
		glVertex3f(2,2,0);
		glVertex3f(0,2,0);
	glEnd();

	glTranslatef(0.0, 2.0, 2.0);
	glRotatef(90, 1.0, 0.0, 00.0);
	glRotatef(90, 1.0, 0.0, 00.0);
	glColor3ub(255,61,0);
	glBegin(GL_POLYGON);
		glVertex3f(0,0,0);
		glVertex3f(2,0,0);
		glVertex3f(2,2,0);
		glVertex3f(0,2,0);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(15, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 600);

	glutCreateWindow("Transformations");
	initRendering();

	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);

	update(0);

	glutMainLoop();
	return 0;
}
