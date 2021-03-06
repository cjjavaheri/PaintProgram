/**************************************************************************//**
 * @file FilledRectangle.h
 *
 * @brief The header file for the filled rectangle class.
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
 * @author John M. Weiss, Ph.D. , Cameron Javaheri
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
#ifndef _FilledRectangle_H_
#define _FilledRectangle_H_

#include "Rectangle.h"

/***************************************************************************//**
 * @class FilledRectangle
 *
 * @brief a class to represent and draw filled rectangles.
 *
 ******************************************************************************/
class FilledRectangle : public Rectangle
{

protected:
	/**
	 * @brief a variable to hold the filledrectangle's fill color.
	*/
	ColorType fill_color;

public:
	/// Constructor
	FilledRectangle( float x = 0.0, float y = 0.0, ColorType c = ColorType( 0 ), ColorType f = ColorType(0), float w = 1.0, float h = 1.0 );
	/// Destructor
	~FilledRectangle( );

	/// Implementation of the base class pure virtual function draw
	void draw( ) const;
	/// Implementation of the base class pure virtual function print
	void print( ostream& out ) const;
};

#endif

