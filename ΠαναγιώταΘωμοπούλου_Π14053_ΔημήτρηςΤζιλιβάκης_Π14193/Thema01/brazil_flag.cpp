#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

const int W_HEIGHT = 720;
const int W_WIDTH = 504;

void eq_triangle( int base, int height,int x,int y, int i){
    // Each set of 3 vertices form a triangle
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glBegin (GL_POLYGON);
	for( int n = 0; n<3; n++){
	
		float xn1 = x+base * cosf(2.0f*M_PI*n/5.0f);
		float yn1 = y+base * sinf(2.0f*M_PI*n/5.0f);
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
	const float kfRadius = 0.0616f/2.0f;
	const float kfInnerRadius = kfRadius*(1.0f/(sinf((2.0f*M_PI)/5.0f)*2.0f*cosf(M_PI/10.0f) + sinf((3.0f*M_PI)/10.0f)));
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(fX, fY, 0.0f);
		for (int iVertIndex = 0; iVertIndex < 10; ++iVertIndex) {
			float fAngleStart	= M_PI/2.0f + (iVertIndex*2.0f*M_PI)/10.0f;
			float fAngleEnd		= fAngleStart + M_PI/5.0f;
			if (iVertIndex % 2 == 0) {
				glVertex3f(fX + kfRadius*cosf(fAngleStart)/1.9f, fY + kfRadius*sinf(fAngleStart), 0.0f);
				glVertex3f(fX + kfInnerRadius*cosf(fAngleEnd)/1.9f, fY + kfInnerRadius*sinf(fAngleEnd), 0.0f);
			} else {
				glVertex3f(fX + kfInnerRadius*cosf(fAngleStart)/1.9f, fY + kfInnerRadius*sinf(fAngleStart), 0.0f);
				glVertex3f(fX + kfRadius*cosf(fAngleEnd)/1.9f, fY + kfRadius*sinf(fAngleEnd), 0.0f);
			}
		}
	glEnd();
}
void star(int base, int height,int x,int y){
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	for( int n = 0; n<5; n++){
		float angleCos = cosf(2.0f*M_PI*n/5.0f);
		float angleSin =  sinf(2.0f*M_PI*n/5.0f);
		float xn1 = x+base * cosf(2.0f*M_PI*n/5.0f);
		float yn1 = y+base * sinf(2.0f*M_PI*n/5.0f);
		eq_triangle(base,height,xn1,yn1,n);

		
	}

   
}
void rhombus(){
   glColor3f(1.0f,0.87f,0.0f);
   glBegin(GL_POLYGON);
   glVertex2f(-0.83f,0.0f);
   glVertex2f(0.0f,0.76f);
   glVertex2f(0.83f,0.0f);
   glVertex2f(0.0f,-0.76f);
   glEnd();

}


void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	rhombus();
	DrawStar(0.3f,0.2f);
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
   glClearColor(0.0f,0.60f,0.22f,0.0f);
   glutMainLoop();
   return 0;
}
