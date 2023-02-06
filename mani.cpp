#include <windows.h>  
#include <GL/glut.h>
#include <gl/freeglut.h>

char title[] = "OpenGL 3D";
GLfloat anglePyramid = 0.0f; 
GLfloat angleCube = 0.0f;     
int refreshMills = 15;        

void initGL() 
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // background negru
    glClearDepth(1.0f);                   
    glEnable(GL_DEPTH_TEST);   
    glDepthFunc(GL_LEQUAL);   
    glShadeModel(GL_SMOOTH);   
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);     

    glLoadIdentity();                 
    glTranslatef(1.5f, 0.0f, -7.0f); 
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f); 

    glBegin(GL_QUADS);    // inceput cub           
       // fata de sus (y = 1.0f)
    glColor3f(0.0f, 1.0f, 0.0f);     // verde
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // fata de jos (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // portocaliu
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // fata din fata  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // rosu
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // fata din spate (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // galben
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // fata stanga (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // albastru
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // fata dreapta (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // magenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // final cub

    glLoadIdentity();                  
    glTranslatef(-1.5f, 0.0f, -6.0f);  
    glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f);  

    glBegin(GL_TRIANGLES);           // inceput piramida 4 fete
       // fata
    glColor3f(1.0f, 0.0f, 0.0f);     // rosu
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // verde
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // albastru
    glVertex3f(1.0f, -1.0f, 1.0f);

    // dreapta
    glColor3f(1.0f, 0.0f, 0.0f);     // rosu
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // albastru
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // verde
    glVertex3f(1.0f, -1.0f, -1.0f);

    // spate
    glColor3f(1.0f, 0.0f, 0.0f);     // rosu
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // verde
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // albastru
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // stanga
    glColor3f(1.0f, 0.0f, 0.0f);       // rosu
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);       // albastru
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);       // verde
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();   // final piramida

    glutSwapBuffers();  

    anglePyramid += 1.0f;
    angleCube -= 0.8f;
}

void timer(int value) 
{
    glutPostRedisplay();      
    glutTimerFunc(refreshMills, timer, 0); 
}

void reshape(GLsizei width, GLsizei height) 
{  
    if (height == 0) height = 1;                
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();            
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);            
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);   // dimensiune fereastra
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);        
    glutDisplayFunc(display);      
    glutReshapeFunc(reshape);       
    initGL();                       // Initializare OpenGL custom
    glutTimerFunc(0, timer, 0);    
    glutMainLoop();                 // event-processing loop
    return 0;
}