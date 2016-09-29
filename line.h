/**************************************************************************//**
 * @file line.h
 *
 * @par Description
 *    OOP example illustrating inheritance and late binding via virtual
 *    functions in C++.
 *
 *    Inheritance is used to derive various shape classes (Point, Line, Ellipse,
 *    Rectangle, Square) from a base Shape class.
 *
 *    This file contains the line class interface.
 *
 * @author Cameron Javaheri
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
// guard against multiple inclusions
#ifndef _LINE_H_
#define _LINE_H_

#include "shape.h"

/***************************************************************************//**
 * @class Line
 ******************************************************************************/
class Line : public Shape
{
protected:
	/// Difference in x-coordinates from start to end.
	float length;
	/// Difference in y-coordinates from start to end.
	float height;

public:
	/// Constructor
	Line( float x = 0.0, float y = 0.0, ColorType c = ColorType(0), float l = 0.0, float h = 0.0 );
	/// Destructor
	~Line( );

	/// Implementation of the base class pure virtual function draw
	void draw( ) const;
	/// Implementation of the base class pure virtual function erase
	void erase( ) const;
	/// Implementation of the base class pure virtual function print
	void print( ostream& out ) const;
};

#endif
