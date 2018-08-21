#include <math.h>
#include <GL/glut.h>
#include <time.h>

#include "Shay.h"

// USE THESE STTEINGS TO CHANGE SPEED (on different spec computers)
// Set speed (steps)
GLdouble movementSpeed = 10.0;
GLdouble rotationSpeed = 0.005;

// 224 Next #define

//--------------------------------------------------------------------------------------

Shay shaysWorld;

// ratio of screen
float ratio;
// screen width and height
int width, height;

// initializes setting
void myinit();

// display functions
void Display();
void reshape(int w, int h);
void keys(unsigned char key, int x, int y);

// keyboard and mouse functions
void releaseKeys(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void mouseMove(int x, int y);

//--------------------------------------------------------------------------------------
//  Main function 
//--------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,500);
	glutCreateWindow("Murdoch University Campus Tour");

	myinit();
	shaysWorld.Init();

	glutIgnoreKeyRepeat(1);
	glutKeyboardUpFunc(releaseKeys);
	glutKeyboardFunc(keys);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);

	glutMouseFunc(Mouse);
	
	// ONLY USE IF REQUIRE MOUSE MOVEMENT
	//glutPassiveMotionFunc(mouseMove);
	//ShowCursor(FALSE);

	glutReshapeFunc(reshape);
	glutMainLoop();
	return(0);
}

//--------------------------------------------------------------------------------------
//  Initialize Settings
//--------------------------------------------------------------------------------------
void myinit()
{
	// set background (sky colour)
	glClearColor(97.0/255.0, 140.0/255.0, 185.0/255.0, 1.0);
	
	// set perpsective
	gluLookAt(0.0, 1.75, 0.0, 
		      0.0, 1.75, -1,
			  0.0f,1.0f,0.0f);

}

//--------------------------------------------------------------------------------------
//  Main Display Function
//--------------------------------------------------------------------------------------
void Display()
{
	shaysWorld.Draw();

	// clear buffers
	glFlush();
	glutSwapBuffers();
}

//--------------------------------------------------------------------------------------
void reshape(int w, int h)
{
	width = w;
	height = h;
	shaysWorld.SetWidthHeight(w, h);
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) h = 1;
	ratio = 1.0f * w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,1,250000);	
	glMatrixMode(GL_MODELVIEW);
}

//--------------------------------------------------------------------------------------
// Keyboard Functions
//--------------------------------------------------------------------------------------
void keys(unsigned char key, int x, int y)
{
	shaysWorld.DownKey(key, x, y);
}

//--------------------------------------------------------------------------------------
void releaseKeys(unsigned char key, int x, int y)
{
	shaysWorld.UpKey(key, x, y);
}

//--------------------------------------------------------------------------------------
//  Mouse Buttons
//--------------------------------------------------------------------------------------
void Mouse(int button, int state, int x, int y)
{
	shaysWorld.MouseClick(button, state, x, y);
}
/*
//--------------------------------------------------------------------------------------
//  Mouse Movements (NOT USED)
//  Can be used to rotate around screen using mouse, but keyboard used instead
//--------------------------------------------------------------------------------------
void mouseMove(int x, int y)
{
		if (x < 0)
			cam.DirectionRotateLR(0);
		else if (x > width)
			cam.DirectionRotateLR(0);
		else if (x > width/2.0)
		{
			cam.DirectionRotateLR(1);
			Display();
			glutWarpPointer(width/2.0,height/2.0);
		}
		else if (x < width/2.0)
		{
			cam.DirectionRotateLR(-1);
			Display();
			glutWarpPointer(width/2.0,height/2.0);
		}
		else
			cam.DirectionRotateLR(0);
		if (y < 0 || y > height)
			cam.DirectionLookUD(0);

		else if (y > height/2.0) {
			cam.DirectionLookUD(-1);
			Display();
			glutWarpPointer(width/2.0,height/2.0);
		}
		else if (y < height/2.0) {
			cam.DirectionLookUD(1);
			Display();
			glutWarpPointer(width/2.0,height/2.0);
		}
		else
			cam.DirectionLookUD(0);
}*/

