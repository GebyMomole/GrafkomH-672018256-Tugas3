#include<glut.h> 


void display(void) {
	float a1x = 50, a1y = 50, b1x = 150, b1y = 200, a2x = 50, a2y = 200, b2x = 150, b2y = 50,
	a3x = 100, a3y = 50, b3x = 200, b3y = 200, a4x = 100, a4y = 200, b4x = 200, b4y = 50,
	MA1B1,MA2B2,MA3B3,MA4B4,cA1B1,cA2B2,cA3B3,cA4B4,px1,px,py1,py,pz1,pz,pi1,pi;
	glClear(GL_COLOR_BUFFER_BIT);





	glBegin(GL_LINES);//kuning
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(a1x, a1y);
	glVertex2f(b1x, b1y);
	glEnd();

	glBegin(GL_LINES);//biru
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(a2x, a2y);
	glVertex2f(b2x, b2y);
	glEnd();

	glBegin(GL_LINES);// hijau
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(a3x, a3y);
	glVertex2f(b3x, b3y);
	glEnd();
	
	glBegin(GL_LINES);// hitam
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(a4x, a4y);
	glVertex2f(b4x, b4y);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(a2x, a2y, 0);
	glVertex3f(b3x, b3y, 0);
	glVertex3f(b4x, b4y, 0);
	glVertex3f(a1x, a1y, 0);
	glVertex3f(a2x, a2y, 0);
	glEnd();

	//perpotongan
	MA1B1 = (b1y - a1y) / (b1x - a1x);
	MA2B2 = (b2y - a2y) / (b2x - a2x);
	MA3B3 = (b3y - a3y) / (b3x - a3x);
	MA4B4 = (b4y - a4y) / (b4x - a4x);
	cA1B1 = a1y - (a1x * MA1B1);
	cA2B2 = a2y - (a2x * MA2B2);
	cA3B3 = a3y - (a3x * MA3B3);
	cA4B4 = a4y - (a4x * MA4B4);
	//titik potong
	px1 = (cA2B2 - cA1B1) / (MA1B1 - MA2B2);
	px = (MA1B1 * px1) + cA1B1;

	py1 = (cA3B3 - cA2B2) / (MA2B2 - MA3B3);
	py = (MA2B2*py1)+cA2B2;

	pz1 = (cA4B4 - cA3B3) / (MA3B3 - MA4B4);
	pz = (MA3B3 * pz1) + cA3B3;

	pi1 = (cA1B1 - cA4B4) / (MA4B4 - MA1B1);
	pi = (MA4B4 * pi1) + cA4B4;


	//hasil

	glBegin(GL_POINTS);
	glPointSize(2);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(px1, px);
	glEnd();

	glBegin(GL_POINTS);
	glPointSize(2);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(py1, py);
	glEnd();

	glBegin(GL_POINTS);
	glPointSize(2);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(pz1, pz);
	glEnd();

	glBegin(GL_POINTS);
	glPointSize(2);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(pi1, pi);
	glEnd();

	glFlush();
}

void inisialisasi(void) {

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(10.0); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(4.0f);
	gluOrtho2D(0.0, 640.0, 0.0,480.0);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 720);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("titik perpotongan");
	glutDisplayFunc(display);
	inisialisasi();
	glutMainLoop();
}