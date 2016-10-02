/**************************************************************************//**
 * @file Shape.h
 * 
 * @brief The header file for the shape class.
 *
 * @par Description
 *    OOP example illustrating inheritance and late binding via virtual
 *    functions in C++.
 *
 *    Inheritance is used to derive various shape classes (Point, Line, Circle,
 *    Rectangle, Square) from a base Shape class.
 *
 *    This file contains the Point class interface.
 *
 * @author John M. Weiss, Ph.D. , Cameron Javaheri, Matthew Schallenkamp
 *
 * @par Class:
 *    CSC300 Data Structures
 *
 * @date Fall 2015
 *
 * Modifications:
 *  * Added doxygen style comments                              PJH : 9/5/2016
 *  * Added doxygen style function blocks and parameter desc    PJH : 9/5/2016
 *****************************************************************************/
#ifndef _Shape_H_
#define _Shape_H_

// include files
#include <iostream>
#include "Graphics.h"
#include <map>
#include <vector>
using namespace std;

/// Color name enum
enum ColorType
{
	/// Black Color
	BLACK,
	/// Blue Color
	BLUE,
	/// Green Color
	GREEN,
	/// Cyan Color
	CYAN,
	/// Red Color
	RED,
	/// Magenta Color
	MAGENTA,
	/// Brown Color
	BROWN,
	/// Light Gray Color
	LIGHTGRAY,
	/// Dark Gray Color
	DARKGRAY,
	/// Light Blue Color
	LIGHTBLUE,
	/// Light Green Color
	LIGHTGREEN,
	/// Light Cyan Color
	LIGHTCYAN,
	/// Light Red Color
	LIGHTRED,
	/// Light Magenta Color
	LIGHTMAGENTA,
	/// Yellow Color
	YELLOW,
	/// Grey Color
	GREY,
	/// White Color
	WHITE
};


/***************************************************************************//**
 * @class Shape
 *
 * @brief a class to represent and draw shapes.
 *
 ******************************************************************************/
class Shape
{

protected:
	/// a map used to recover the color values from the colortype enum
	static const map<ColorType, vector<float> > glutColor;
	/// x-location of the shape
	float locX;
	/// y-location of the shape
	float locY;
	/// Color of the shape
	ColorType color;

	/// public methods
public:
	float getX();
	float getY();
	/// constructor
	Shape( float x = 0.0, float y = 0.0, ColorType c = ColorType( 0 ) );

	/// destructor
	virtual ~Shape( );

	/// move object
	void moveTo( float x, float y );

	/// change color of object
	void changeColor( ColorType c );

	// pure virtual methods that must be overridden in non-abstract derived classes
	/// pure virtual print
	virtual void print( ostream& ) const = 0;
	/// pure virtual draw
	virtual void draw() const = 0;
};

#endif

