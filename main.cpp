/*************************************************************************//**
 * @file main.cpp
 * 
 * @brief A paint program.
 *
 * @mainpage SDSMT Paint
 *
 * @section course_section Course Information
 *
 * @author John M. Weiss, Ph.D., Dr. Paul Hinker, Matthew Schallenkamp, Cameron Javaheri
 *
 * @date due 10/02/2016
 *
 * @par Professor:
 *		Paul Hinker
 *
 * @par Course:
 *      CSC 300 - Fall 2016 - M002 - 2pm
 *
 * @par Location:
		McLaury - 310
 *
 *
 * @details This paint program was created based on files originally
 * written by Dr. Paul Hinker and John M. Weiss, Ph.D.. We have now
 * combined those files and some of our own code to make a paint program
 * as a class assignment for CSC 300 with Dr. Paul Hinker. This paint
 * program allows the user to create, move, delete, and reorder several
 * different types of shapes and lines, in various colors.
 * 
 *  @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   % make
   % main
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug none
 *
 * @todo none
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Gitlab Repository: https://gitlab.mcs.sdsmt.edu/7300226/csc300_fall2016_project1.git
   @endverbatim
 *
 *
 ****************************************************************************/


#include <iostream>
#include <GL/freeglut.h>
#include "Callbacks.h"
#include "Graphics.h"
#include "Shape.h"

using namespace std;

void oneTimeInit(int num, char **arrOfStr);

/*************************************************************************//**
 * @brief main function
 *
 * @param[in] argc - number of command line arguments
 * @param[in] argv - array of C strings representing the command line
 *  arguments - only one used is the first as the window title
 *
 * @return main does not return due to the glutMainLoop function not
 * returning
 ****************************************************************************/
int main(int argc, char** argv)
{
	// Call the glut functions to initialize everything
	oneTimeInit(argc, argv);
	glutMainLoop();
	return 0;
}

/*************************************************************************//**
 * @brief A function to call the usual set of initialization routines
 *
 * @par Description
 *   * Initializes the glut system
 *   * Sets the initial display mode
 *   * Sets the initial window size
 *   * Sets the initial window position
 *   * Creates the window and sets the window title
 *   * Sets the DisplayFunc callback
 *   * Sets the KeyboardFunc callback
 *   * Sets the MouseFunc callback
 *   * Sets the clear color
 *
 * @param[in] num      - The number of entries in the arrOfStr parameter
 * @param[in] arrOfStr - The commandline arguments
 *
 ****************************************************************************/
void oneTimeInit(int num, char **arrOfStr)
{
	// Initialize GLUT (OpenGL Utility Toolkit)
	glutInit(&num, arrOfStr);

	// Set the display mode [double buffering, 4-channel red,green,blue,alpha]
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// Make the window 640 columns x 480 rows of pixels
	glutInitWindowSize(640, 480);

	// Start the window at 100 pixels down and 100 pixels right of upper-left
	glutInitWindowPosition(100, 100);

	// Give the window a title
	if (num > 1)
		glutCreateWindow(arrOfStr[1]);
	else
		glutCreateWindow("SDSM&T PAINT");

	// Set the function for the glutMainLoop to call when refreshing window
	glutDisplayFunc(display);

	// Window resize callback
	glutReshapeFunc(reshape);

	// Set the function to call in response to keyboard events
	glutKeyboardFunc(keyboard);

	// Set the function to call for mouse events
	glutMouseFunc(mouseClick);

	// When the window is cleared, use the color that's 0% red, 100% green,
	// 0% blue, 0% alpha
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
