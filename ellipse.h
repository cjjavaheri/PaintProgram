/**************************************************************************//**
 * @file Ellipse.h
 *
 * @par Description
 *    OOP example illustrating inheritance and late binding via virtual
 *    functions in C++.
 *
 *    Inheritance is used to derive various shape classes (Point, Line, Ellipse,
 *    Rectangle, Square) from a base Shape class.
 *
 *    This file contains the Ellipse class interface.
 *
 * @author John M. Weiss, Ph.D., Matthew Schallenkamp
 *
 * @par Class:
 *    CSC300 Data Structures
 *
 * @date Fall 2015
 *
 * Modifications:
 *  * Added doxygen style comments                              PJH : 9/5/2016
 *  * Added doxygen style function blocks and parameter desc    PJH : 9/5/2016
 *  * Changed from Ellipse to Ellipse                            MJS : 9/27/16
 *****************************************************************************/
// guard against multiple inclusions
#ifndef _ELLIPSE_H_
#define _ELLIPSE_H_

#include "shape.h"

/***************************************************************************//**
 * @class Ellipse
 ******************************************************************************/
class Ellipse : public Shape
{
protected:
	/// Radius of the Ellipse
	float radius_x;
	float radius_y;

public:
	/// Constructor
	Ellipse( float x = 0.0, float y = 0.0, ColorType c = ColorType( 0 ), float r_x = 1.0, float r_y = 1.0 );
	/// Destructor
	~Ellipse( );

	/// Implementation of the base class pure virtual function draw
	void draw( ) const;
	/// Implementation of the base class pure virtual function erase
	void erase( ) const;
	/// Implementation of the base class pure virtual function print
	void print( ostream& out ) const;
};

#endif