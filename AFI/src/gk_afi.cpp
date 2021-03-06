#include <iostream>
#include "zpr.h"
#include <GL/glut.h>
#include <osg/Matrix>
#include <osg/Vec3>
#include <osg/Quat>


int i = 0;
static GLfloat V_table[][3] = {  {-1.22f, 0.0f, 0.64f}, //v0
						{1.22f, 0.0f, 0.64f},	//v1
						{1.22f, 0.0f, -0.64f}, //v2
						{-1.22f, 0.0f, -0.64f}, //v3
						{-1.22f, -0.40f, 0.64f}, //v4
						{1.22f, -0.40f, 0.64f}, //v5
						{1.22f, -0.40f, -0.64f}, //v6
						{-1.22f, -0.40f, -0.64f}, //v7

						{-0.82f, -0.40f, 0.44f}, //v8
						{0.82f, -0.40f, 0.44f}, //v9
						{0.82f, -0.40f, -0.44f}, //v10
						{-0.82f, -0.40f, -0.44f}, //v11
						{-0.82f, -1.00f, 0.44f}, //v12
						{0.82f, -1.0f, 0.44f}, //v13
						{0.82f, -1.0f, -0.44f}, //v14
						{-0.82f, -1.0f, -0.44f}}; //v15

static int S_table[][3] = { {0,3,1}, //s1
							{1,3,2}, //s2
							{4,0,5}, //s3
							{0,1,5}, //s4
							{5,1,6}, //s5
							{1,2,6}, //s6
							{6,2,7}, //s7
							{2,3,7}, //s8
							{4,3,7}, //s9
							{0,3,4}, //s10
							{4,5,8}, //s11
							{5,8,11}, //s12
							{5,6,9}, //s13
							{6,9,10}, //s14
							{6,7,10}, //s15
							{7,10,11}, //s16
							{4,7,11}, //s17
							{4,8,11}, //s18
							{8,9,12}, //s19
							{9,12,13}, //s20
							{9,10,13}, //s21
							{10,13,14}, //s22
							{10,14,15}, //s23
							{10,11,15}, //s24
							{11,12,15}, //s25
							{8,11,12}, //s26
							{12,13,14}, //s27
							{12,13,15}}; //s28
	


void DrawFigure(int n, GLfloat v[][3], int s[][3])
{
	static GLfloat col[3] = {1.0f, 0.0f, 0.0f};
  glBegin(GL_TRIANGLES);
    for(int i = 0; i < n; i ++){      // tworzymy n �cian tr�jk�tnych
       
		glColor3fv(col);             // kolor wg numeru �ciany
       for(int j = 0; j < 3; j++)
         glVertex3fv(v[ s[i][j] ]); 
	}
  glEnd();

}


//! TODO
//! Tutaj inicjalizowane s� pierwsze pozycje obiekt�w
void initObjects()
{
	/*
  glViewport(0, 0, 800, 600);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)800/(GLfloat)600,0.1f,300.0f);
  glTranslatef(0.0f,0.0f,0.0f);   // przesuwamy pocz�tkowy uk�ad w ty� o 6 jednostek
  glMatrixMode(GL_MODELVIEW);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);  // w��cza bufor g��boko�ci
  glDepthFunc(GL_LEQUAL);
  glEnable(GL_CULL_FACE);   // w��cza opcj� eliminacji �cian
  glFrontFace(GL_CW);       // �ciany o wierzcho�kach u�o�onych zgodnie z ruchem wskaz�wek
                            // zegara b�d� traktowane jako zwr�cone przodem
  glCullFace(GL_BACK);      // pomija rysowanie �cian odwr�conych ty�em
   */
	
}



//! \param objectMatrix Macierz pisuj�ca pozycj� 3D obiektu na scenie
void refreshObject(const osg::Matrix & objectMatrix)
{
	auto t = objectMatrix.getTrans();
	glTranslated(t.x(), t.y(), t.z());

	auto s = objectMatrix.getScale();
	glScaled(s.x(), s.y(), s.z());

	double angle, x, y, z;
	objectMatrix.getRotate().getRotate(angle, x, y, z);
	glRotated(osg::RadiansToDegrees(angle), x, y, z);
}



// Drawing (display) routine.
void drawScene()
{
	// Clear screen to background color.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	DrawFigure(28, V_table, S_table);
  glMatrixMode(GL_MODELVIEW);
glLoadIdentity;
	//Tworzenie Kuli bia�ej:)
glPushMatrix();
glTranslatef(0,0.05,0);
glColor3d(1.0,1.0,1.0);
glScalef(0.05, 0.05, 0.05);
glutSolidSphere(1,20,10);

glPopMatrix();

	// Swap buffers for double buffering
	glutSwapBuffers();
}

//! Metoda realizuj�ca obliczenia na potrzeby kolejnych klatek, generuje animacj�
void animate() {
	
	
	
	
	glutPostRedisplay();
}
//! Zmienne opisuj�ce materia� i �wiat�o OpenGL
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 

// Initialization routine.
void setup() 
{
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.5, 0.5, 0.5, 0.5);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);

	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 

	// Register display routine.
	glutDisplayFunc(drawScene);
	// Register idle routine
	glutIdleFunc(animate);
	// Initialize camera manipulator
	zprInit();
	// Initialize first object positions
	initObjects();
}

// Main routine: defines window properties, creates window,
// registers callback routines and begins processing.
int main(int argc, char **argv) 
{  
	// Initialize GLUT.
	glutInit(&argc, argv);

	// Set display mode as double-buffered, RGB color and depth.
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 

	// Set OpenGL window size.
	glutInitWindowSize(800, 800);

	// Set position of OpenGL window upper-left corner.
	glutInitWindowPosition(50, 50); 

	// Create OpenGL window with title.
	glutCreateWindow("Bilard 3D5");

	// Initialize.
	setup(); 

	// Begin processing.
	glutMainLoop(); 
		
	return 0;  
}