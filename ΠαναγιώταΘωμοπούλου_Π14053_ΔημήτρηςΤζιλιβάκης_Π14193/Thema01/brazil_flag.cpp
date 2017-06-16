#include <GL/glut.h>

void rhombus(){
   glClear(GL_COLOR_BUFFER_BIT);
   
   glColor3f(1,0.87,0);
   glBegin(GL_POLYGON);
   glVertex2f(62,252);
   glVertex2f(360,60);
   glVertex2f(660,252);
   glVertex2f(360,443);
   glEnd();
   
   glFlush();
   glutSwapBuffers();
}

int main(int argc, char** argv){
 
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowSize(720,504);
   glutCreateWindow("Brazil");
   glutDisplayFunc(rhombus);
   gluOrtho2D(0,720,0,504);
   glClearColor(0,0.60,0.22,0);
   glutMainLoop();
   return 0;
}
