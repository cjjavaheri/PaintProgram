/***************************************************************************//**
 * @file Line.cpp
 *
 * @brief The file used for implementing the line class.
 *
 * @par Description
 *    OOP example illustrating inheritance and late binding via virtual
 *    functions in C++.
 *
 *    Inheritance is used to derive various shape classes (Point, Line, Circle,
 *    Rectangle, Square) from a base Shape class.
 *
 *    This file contains the line class implementation.
 *
 * @author Cameron Javaheri
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

#include "Line.h"

// Rectangle class implementation

/**************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief Line class implementation constructor
 *
 * @param[in] x - x-coordinate of the center of the line
 * @param[in] y - y-coordinate of the center of the line
 * @param[in] c - the color of the line
 * @param[in] l - Difference in x-coordinates of the line.
 * @param[in] h - Difference in y-coordinates of the line.
 *****************************************************************************/
Line::Line( float x, float y, ColorType c, float l, float h ) :
	Shape( x, y, c ), length(l), height(h)
{

}

/**************************************************************************//**
 * @author Cameron Javaheri
 * @brief Line class implementation destructor
 *****************************************************************************/
Line::~Line( )
{

}

/**************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief Line class draw
 *
 * @par Description
 *   Draws a line.
 *
 *****************************************************************************/
void Line::draw( ) const
{
	DrawLine(locX - length / 2, locY - height / 2, locX + length / 2, locY + height / 2,
	         glutColor.at(color).data());
}


/**************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief Line class print
 *
 * @par Description
 *    must override pure virtual Shape::erase() method to instantiate class
 *
 *****************************************************************************/
void Line::print( ostream& out ) const
{
	out << ( length == height ? "square" : "rectangle" ) << " at position (" << locX << "," << locY << ")"
	    << " with sides " << length << " and " << height << endl;
}

