/**************************************************************************//**
 * @file FilledEllipse.h
 *
 * @brief A class for drawing filled ellipses
 *
 * @par Description
 *    OOP example illustrating inheritance and late binding via virtual
 *    functions in C++.
 *
 *    Inheritance is used to derive various shape classes (Point, Line, Ellipse,
 *    Rectangle, Square) from a base Shape class.
 *
 *    This file contains the FilledEllipse class interface.
 *
 *    This file has been modified for use in a paint program by M.S.
 *
 * @author John M. Weiss, Ph.D., Matthew Schallenkamp
 *
 * @par Class:
 *    CSC300 Data Structures
 *
 * @date Fall 2016
 *
 *****************************************************************************/
// guard against multiple inclusions
#ifndef _FILLEDELLIPSE_H_
#define _FILLEDELLIPSE_H_

#include "Ellipse.h"

/***************************************************************************//**
 * @class FilledEllipse
 *
 * @brief a class to represent and draw Filled in Ellipses
 *
 ******************************************************************************/
class FilledEllipse : public Ellipse
{
protected:
	/**
	 * @brief a variable ts fill o hold the Ellipses fill color
	 */
	ColorType fill_color;
public:
	FilledEllipse( float x = 0.0, float y = 0.0, ColorType c = ColorType( 0 ), ColorType f = ColorType( 0 ), float r_x = 1.0, float r_y = 1.0 );
	~FilledEllipse( );

	void draw( ) const;
	void print( ostream& out ) const;
};

#endif