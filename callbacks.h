/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef __CALLBACKS_H
#define __CALLBACKS_H
#include <iostream>
#include <GL/freeglut.h>
#include <string>
#include "graphics.h"
#include "shape.h"
#include "rectangle.h"
#include "FilledRectangle.h"
#include "ellipse.h"
#include "FilledEllipse.h"
#include "line.h"
#include <vector>

using namespace std;

#define DEBUGPRINT(x)	cout << x << endl;

/// A mnemonic name for the ascii value of the escape key
#define ESCAPE_KEY 27

enum ShapeType
{
	EMPTY,
	RECTANGLE,
	FILLED_RECTANGLE,
	ELLIPSE,
	FILLED_ELLIPSE,
	LINE
};

void Color_Palette();
ShapeType Choose_Shape ( int x, int y, ShapeType shape );
ColorType Choose_Color ( int x, int y, ColorType color );
void Preview_Box(ShapeType shape, ColorType boundary, ColorType fill);
void display();
void keyboard(unsigned char key, int x, int y);
void mouseClick(int button, int state, int x, int y);
void reshape(int w, int h);
#endif
