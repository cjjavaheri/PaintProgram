/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef __CALLBACKS_H
#define __CALLBACKS_H
#include <iostream>
#include <GL/freeglut.h>
#include <string>
#include "graphics.h"

using namespace std;

#define DEBUGPRINT(x)	cout << x << endl;

/// A mnemonic name for the ascii value of the escape key
#define ESCAPE_KEY 27

/// Maps button number to button name
const std::string ButtonName[] =
{
    "Left",
    "Middle",
    "Right",
    "Trackball Fwd",
    "Trackball Bkwd"
};
/// Maps button state# to action
const std::string ButtonState[] =
{
    "Down",
    "Up"
};

void display();
void keyboard(unsigned char key, int x, int y);
void mouseClick(int button, int state, int x, int y);
void reshape(int w, int h);
#endif
