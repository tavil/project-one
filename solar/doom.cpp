//
//

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>



GLdouble angle = 0;

static void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    
    
    glTranslatef(0.f, 0.f, -100.f);
    
    
 
    glRotated(angle, 0, 1, 0);
    
    glColor3ub(255, 150, 0);
    //glColor3f(0, 0, 1);
    
    gluSphere( quadric , 4 , 24 , 24 );

    
    glPushMatrix();
    glColor3ub(0, 0, 255);
    glTranslatef(20.f, 0.f, 0.f);
    glRotated(angle, 0, 1, 0);
    gluSphere( quadric , 2 , 24 , 24 );
    
    glPushMatrix();
    glRotated((angle*2), 0, 1, 0);
    glColor3ub(100, 100, 100);
    glTranslatef(4.f, 0.f, 0.f);
    glRotated((angle*2), 0, 1, 0);
    gluSphere( quadric , 1 , 24 , 24 );
    
    glPopMatrix();
    glRotated((angle*(-1)), 0, 1, 0.2);
    glColor3ub(100, 50, 50);
    glTranslatef(6.f, 0.f, 0.f);
    glRotated((angle*2), 0, 1, 0);
    gluSphere( quadric , 1 , 24 , 24 );
    
    glPopMatrix();    
    
    glRotated((angle*(-1.5)), 0, 1, 0);
    glColor3ub(255, 0, 0);
    glTranslatef(40.f, 0.f, 0.f);
    glRotated((angle*4), 0, 1, 0);
    gluSphere( quadric , 2 , 24 , 24 );
    
    glRotated((angle*5), 0, 1, 0.1);
    glColor3ub(50, 50, 50);
    glTranslatef(7.f, 0.f, 0.f);
    glRotated(angle, 0, 1, 0);
    gluSphere( quadric , 0.5 , 24 , 24 );
    
    
    glutSwapBuffers();
    
}

static void timerCallback (int value)
{
 
    angle ++;
    
    //GLfloat light_position[] = { cosf(angle*(M_PI/180) ), 1.0, sinf(angle*(M_PI/180) ), 0.0 };
    //GLfloat light_position[] = { 0.0, 0.0, 0.0, 0.0 };
    
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //glMaterialfv(GL_FRONT,GL_SHININESS, material_shininess);
    
    glutTimerFunc(10, timerCallback, 0);
    glutPostRedisplay();
}

void setupLight(){
    glEnable(GL_LIGHTING);
    //glCullFace(GL_FRONT_AND_BACK);
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    
    
    GLfloat light_position[] = { 0.0, 0.0, -100.0, 1.0 };
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 0.0, 0.0, 0.0, 0.0 };
    
    
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    //GLfloat global_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
    
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_shininess[] = { 0 };
    
    glMaterialfv(GL_FRONT,GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT,GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT,GL_SHININESS, material_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    
    glShadeModel(GL_SMOOTH);
}

int main (int argc, char ** argv)
{

    GLenum type;
    
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	type = GLUT_RGB;
	type |= GLUT_DOUBLE;
	type |= GLUT_DEPTH;
    type |= GLUT_MULTISAMPLE;
	glutInitDisplayMode(type);
	glutCreateWindow("solar");
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    
    
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 800/600, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);

    setupLight();
    

    
    
    timerCallback(0);
    glutDisplayFunc(Draw);
    glutMainLoop();
    std::cout << "Hello, World!\n";
    return 0;
}

