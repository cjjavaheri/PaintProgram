/***************************************************************************//**
 * @file Rectangle.cpp
 *
 * @par Description
 *    OOP example illustrating inheritance and late binding via virtual
 *    functions in C++.
 *
 *    Inheritance is used to derive various shape classes (Point, Line, Circle,
 *    Rectangle, Square) from a base Shape class.
 *
 *    This file contains the Rectangle class implementation.
 *
 * @author John M. Weiss, Ph.D. , Cameron Javaheri
 *
 * @par Class:
 *    CSC300 Data Structures
 *
 * @date Fall 2015
 *
 * @par Modifications:
 *  * Added doxygen style comments                               PJH : 9/5/2016
 *  * Added function headers and parameter descriptions          PJH : 9/5/2016
 ******************************************************************************/
// include files
#include <iostream>
using namespace std;

#include "Rectangle.h"

// Rectangle class implementation

/**************************************************************************//**
 * @author John Weiss
 *
 * @brief Rectangle class implementation constructor
 *
 * @param[in] x - x-coordinate of the center of the rectangle
 * @param[in] y - y-coordinate of the center of the rectangle
 * @param[in] c - the color of the rectangle boundary
 * @param[in] w - width of the rectangle
 * @param[in] h - height of the rectangle
 *****************************************************************************/
Rectangle::Rectangle( float x, float y, ColorType c, float w, float h ) :
	Shape( x, y, c ), width( w ), height( h )
{

}

/**************************************************************************//**
 * @author John Weiss
 * @brief Rectangle class implementation destructor
 *****************************************************************************/
Rectangle::~Rectangle( )
{

}

/**************************************************************************//**
 * @author John Weiss
 *
 * @brief Rectangle class change radius
 *
 * @par Description
 *    mutator method for Rectangle class
 *
 * @param[in] w - the new width for the rectangle
 * @param[in] h - the new height for the rectangle
 *****************************************************************************/
void Rectangle::changeDimensions( float w, float h )
{

	width = w;
	height = h;
}

/**************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief Rectangle class draw
 *
 * @par Description
 *   Draws a rectangle.
 *
 *****************************************************************************/
void Rectangle::draw( ) const
{
	DrawRectangle(locX - width / 2, locY - height / 2, locX + width / 2,
	              locY + height / 2, glutColor.at(color).data());
}

/**************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief Rectangle class erase
 *
 * @par Description
 *    must override pure virtual Shape::erase() method to instantiate class
 *
 *****************************************************************************/
void Rectangle::erase( ) const
{
	cout << "Erase Rectangle: (" <<
	locX << "," << locY << ") = " << color << ", width " << width << " x height " << height << endl;
}

/**************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief Rectangle class print
 *
 * @par Description
 *    must override pure virtual Shape::erase() method to instantiate class
 *
 *****************************************************************************/
void Rectangle::print( ostream& out ) const
{
	out << ( width == height ? "square" : "rectangle" ) << " at position (" << locX << "," << locY << ")"
	    << " with sides " << width << " and " << height << endl;
}

