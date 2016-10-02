/***************************************************************************//**
 * @file callbacks.h
 *
 * @brief Definition of callback functions for Paint program
 *
 ******************************************************************************/
#ifndef __CALLBACKS_H
#define __CALLBACKS_H
#include <iostream>
#include <GL/freeglut.h>
#include <string>
#include "Graphics.h"
#include "Shape.h"
#include "Rectangle.h"
#include "FilledRectangle.h"
#include "Ellipse.h"
#include "FilledEllipse.h"
#include "Line.h"
#include <vector>
#include <cmath>

using namespace std;

/// A mnemonic name for the ascii value of the escape key
#define ESCAPE_KEY 27

/**
 * @brief A list of Shape types, for the purpose of controlling which is selected
 */
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
void Insert_Shape(ShapeType shape, vector<Shape *> &items, ColorType boundary, ColorType fill,
                  float ix, float iy, float fx, float fy);
void display();
void keyboard(unsigned char key, int x, int y);
void mouseClick(int button, int state, int x, int y);
void reshape(int w, int h);
#endif
