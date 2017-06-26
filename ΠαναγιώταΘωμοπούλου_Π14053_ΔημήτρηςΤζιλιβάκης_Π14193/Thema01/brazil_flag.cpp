#include <GL/glut.h>
#include <math.h>
#include <cmath>

const int W_HEIGHT = 720;
const int W_WIDTH = 504;
const float PI = 3.14;

void eq_triangle( int base, int height,int x,int y, int i){
    // Each set of 3 vertices form a triangle
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glBegin (GL_POLYGON);
	for( int n = 0; n<3; n++){
	
		float xn1 = x+base * cos(2*PI*n/5);
		float yn1 = y+base * sin(2*PI*n/5);
		glVertex2f(xn1 , yn1);
		if(n==2){
			glVertex2f(xn1+height , yn1+height);
		}
		else{
			glVertex2f(xn1 , yn1);
		}
	}
	glEnd();
	

}
void DrawStar(float fX, float fY) {
	const float kfPi = 3.1415926535897932384626433832795;
	const float kfRadius = 0.0616/2.0;
	const float kfInnerRadius = kfRadius*(1.0/(sin((2.0*kfPi)/5.0)*2.0*cos(kfPi/10.0) + sin((3.0*kfPi)/10.0)));
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(fX, fY, 0.0);
		for (int iVertIndex = 0; iVertIndex < 10; ++iVertIndex) {
			float fAngleStart	= kfPi/2.0 + (iVertIndex*2.0*kfPi)/10.0;
			float fAngleEnd		= fAngleStart + kfPi/5.0;
			if (iVertIndex % 2 == 0) {
				glVertex3f(fX + kfRadius*cos(fAngleStart)/1.9, fY + kfRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + kfInnerRadius*cos(fAngleEnd)/1.9, fY + kfInnerRadius*sin(fAngleEnd), 0.0);
			} else {
				glVertex3f(fX + kfInnerRadius*cos(fAngleStart)/1.9, fY + kfInnerRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + kfRadius*cos(fAngleEnd)/1.9, fY + kfRadius*sin(fAngleEnd), 0.0);
			}
		}
	glEnd();
}
void star(int base, int height,int x,int y){
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	for( int n = 0; n<5; n++){
		float angleCos = cos(2*PI*n/5);
		float angleSin =  sin(2*PI*n/5);
		float xn1 = x+base * cos(2*PI*n/5);
		float yn1 = y+base * sin(2*PI*n/5);
		eq_triangle(base,height,xn1,yn1,n);

		
	}

   
}
void rhombus(){
   glColor3f(1,0.87,0);
   glBegin(GL_POLYGON);
   glVertex2f(-0.83,0);
   glVertex2f(0,0.76);
   glVertex2f(0.83,0);
   glVertex2f(0,-0.76);
   glEnd();

}


void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	rhombus();
	DrawStar(0.3,0.2);
	glFlush();	
    glutSwapBuffers();
}

int main(int argc, char** argv){
 
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowSize(720,504);
   glutInitWindowPosition(100,100);
   glutCreateWindow("Brazil");
   glutDisplayFunc(draw);
   glClearColor(0,0.60,0.22,0);
   glutMainLoop();
   return 0;
}
