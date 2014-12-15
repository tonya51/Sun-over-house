#include <Windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RAD60 1.047198

typedef float point[4];

point v[] = {{0.0,0.0,1.0},{0.0,0.942809,-0.33333},{-0.816497,-0.471405,-0.333333},{0.816497,-0.471405,-0.333333}};
int n = 4;
int win;
GLfloat range=80.0,i,j,angle=0.0,SpinSun,rad; 
GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat color_brown[] = { 0.6, 0.4, 0.1, 1.0 };
GLfloat color_grey[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat color_green[] = { 0.1, 0.5, 0.1, 1.0 };
GLfloat no_specular[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat high_shininess[] = { 150.0 };
GLfloat color_emission_yellow[] = {0.0, 0.0, 0.0, 1.0 };



void findAngle()
{
     angle+=0.05;
     SpinSun+=0.5;
     if(angle>360.0) angle-=360.0;
     if(SpinSun>180.0) SpinSun-=180.0;
}

void myinit(void){

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
     
    glEnable(GL_BLEND);
//    glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glShadeModel(GL_SMOOTH);
	


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, 1,10.0, 280.0);
    //glOrtho(-range, range, -range, range, -3*range, 3*range);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
//    gluLookAt(sin(rad)*80.0,80.0,cos(rad)*80.0,0.0,0.0,0.0,0.0,1.0,0.0);
    gluLookAt(80.0,80.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0);    
    
    glShadeModel (GL_FLAT);
    glNewList(1, GL_COMPILE);
		glBegin(GL_POLYGON);
			glNormal3f(0.0, -1.0, 0.0);
			glVertex3f(5.0, 0.0, -10.0);
			glVertex3f(5.0, 0.0, 10.0);
			glVertex3f(-5.0, 0.0, 10.0);
			glVertex3f(-5.0, 0.0, -10.0);
		glEnd();
	glEndList();
	glNewList(2, GL_COMPILE);
		glBegin(GL_POLYGON);
			glNormal3f(0.0, 0.0, 1.0);
			glVertex3f(5.0, 0.0, 0.0);
			glVertex3f(-5.0, 0.0, 0.0);
			glVertex3f(0.0, 5*tan(RAD60), 0.0);
		glEnd();
	glEndList();
	glNewList(3, GL_COMPILE);
		glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(2.5, 0.0, -2.5);
			glVertex3f(2.5, 0.0, 2.5);
			glVertex3f(-2.5, 0.0, 2.5);
			glVertex3f(-2.5, 0.0, -2.5);
		glEnd();
	glEndList();
}
void drawLocation()
{
     //----------or8ogwnio----------
    //glColor3f(0.6, 0.4, 0.1);
    
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_brown);
        glMaterialfv(GL_FRONT, GL_SPECULAR, no_specular);
        //katw
        glCallList(1);
        //de3ia
      	glPushMatrix();
    	glTranslatef(5.0,5.0,0.0);
    	glRotatef(90.0, 0.0, 0.0, 1.0);
    	glCallList(1);
    	glPopMatrix();
    	//panw
    	glPushMatrix();
    	glTranslatef(0.0,10.0,0.0);
    	glCallList(1);
    	glPopMatrix();
    	//aristera
    	glPushMatrix();
    	glTranslatef(-5.0,5.0,0.0);
    	glRotatef(90.0, 0.0, 0.0, 1.0);
    	glCallList(1);
    	glPopMatrix();
	
    	//mprosta
    	glPushMatrix();
    	glTranslatef(0.0, 5.0, 10.0);
    	glRotatef(90.0,1.0,0.0,0.0);
        glScalef(1.0,1.0,0.5);
        glCallList(1);
       	glPopMatrix();
	
    	//pisw
    	glPushMatrix();
    	glTranslatef(0.0, 5.0, -10.0);
    	glRotatef(90.0,1.0,0.0,0.0);
        glScalef(1.0,1.0,0.5);
        glCallList(1);
    	glPopMatrix();
	
	glPopMatrix();
	//---------- skeph----------
	//glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_grey);
            
    glPushMatrix();
	glTranslatef(-2.5, 10.0+2.5*tan(RAD60), 0.0);
	glRotatef(60.0,0.0,0.0,1.0);
    glCallList(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(2.5, 10.0+2.5*tan(RAD60), 0.0);
	glRotatef(-60.0,0.0,0.0,1.0);
    glCallList(1);
	glPopMatrix();
	
    glPushMatrix();
	glTranslatef(0.0, 10.0, 10.0);
	glCallList(2);
	glPopMatrix();
	
    glPushMatrix();
	glTranslatef(0.0, 10.0, -10.0);
	glCallList(2);
	glPopMatrix();
	
	glPopMatrix();
	//---------- Edafos ----------
	//glColor3f(0.1,0.5,0.1);
	glPushMatrix();
	
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_green);
        glMaterialfv(GL_FRONT, GL_SPECULAR, no_specular);
        
	for(j=-90.0;j<0.0;j=j+5.0)
	   for(i=-90.0;i<0.0;i=i+5.0)
	   {
            glPushMatrix();
            glTranslatef(i+2.5,0.0,j+2.5);
            glCallList(3);
            glPopMatrix();                     
       }
	for(j=0.0;j<90.0;j=j+5.0)
	   for(i=-90.0;i<0.0;i=i+5.0)
	   {
            glPushMatrix();
            glTranslatef(i+2.5,0.0,j+2.5);
            glCallList(3);
            glPopMatrix();                     
       }	   
	for(j=0.0;j<90.0;j=j+5.0)
	   for(i=0.0;i<90.0;i=i+5.0)
	   {
            glPushMatrix();
            glTranslatef(i+2.5,0.0,j+2.5);
            glCallList(3);
            glPopMatrix();                     
       }	
	for(j=-90.0;j<0.0;j=j+5.0)
	   for(i=0.0;i<90.0;i=i+5.0)
	   {
            glPushMatrix();
            glTranslatef(i+2.5,0.0,j+2.5);
            glCallList(3);
            glPopMatrix();                     
       }	
	glPopMatrix();
}

void triangle(point a, point b, point c){
	
	glBegin(GL_POLYGON);
		glNormal3fv(a);
		glVertex3fv(a);
		glNormal3fv(b);
		glVertex3fv(b);
		glNormal3fv(c);
		glVertex3fv(c);
	glEnd();

}

void normal(point p){
	
	float d = 0.0;
    int i;
    for(i=0; i<3; i++) 
		d = d + p[i]*p[i];
    d = sqrt(d);
    if(d>0.0)
		for(i=0; i<3; i++)
			p[i] = p[i]/d;

}

void divide_triangle(point a, point b, point c, int m){
	
	point v1, v2, v3;
	int j;
	if(m>0){
		for(j=0; j<3; j++)
			v1[j] = a[j] + b[j];
		normal(v1);
        for(j=0; j<3; j++)
			v2[j] = a[j] + c[j];
		normal(v2);
        for(j=0; j<3; j++)
			v3[j] = b[j] + c[j];
		normal(v3);

		divide_triangle(a, v1, v2, m-1);
        divide_triangle(c, v2, v3, m-1);
        divide_triangle(b, v3, v1, m-1);
        divide_triangle(v1, v3, v2, m-1);
    }
    else
		triangle(a,b,c);

}

void tetrahedron(){
	
	divide_triangle(v[0], v[1], v[2], n);
	divide_triangle(v[3], v[2], v[1], n);
	divide_triangle(v[0], v[3], v[1], n);
	divide_triangle(v[0], v[2], v[3], n);

}

void drawSun()
{
    // glColor3f(0.0,0.9,0.9);
     glPushMatrix();
     glMaterialfv(GL_FRONT, GL_EMISSION, color_emission_yellow);
     tetrahedron();
     glPopMatrix();
}

void scene()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
     findAngle();
     
     glPushMatrix();
     glRotatef(angle,0.0,1.0,0.0);
     drawLocation();
    glPushMatrix();
     glRotatef(-SpinSun,0.0,0.0,1.0);
     glTranslatef(-50.0,0.0,0.0);
     /*
	*/
    
    // 
      glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glDisable (GL_LIGHTING);
     drawSun();
     glEnable (GL_LIGHTING);
     glPopMatrix();
     
     
     glPopMatrix();
     
     glutSwapBuffers();
}
void main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(0,0);
	glutCreateWindow("House 1");
	glutDisplayFunc(scene);
	glutIdleFunc(scene);
	glEnable(GL_DEPTH_TEST); 
	myinit();
	glutMainLoop();

}