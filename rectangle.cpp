/***************************************************************************//**
 * @file rectangle.cpp
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
 * @author John M. Weiss, Ph.D.
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

#include "rectangle.h"

// Rectangle class implementation

/**************************************************************************//**
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
    cout << "Rectangle constructor: (" <<
         x << "," << y << ") = " << c << ", width " << w << " x height " << h << endl;
}

/**************************************************************************//**
 * @brief Rectangle class implementation destructor
 *****************************************************************************/
Rectangle::~Rectangle( )
{
    cout << "Rectangle destructor: (" <<
         locX << "," << locY << ") = " << color << ", width " << width << " x height " << height << endl;
}

/**************************************************************************//**
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
    cout << "Change Rectangle dimensions from " << width << " x " << height << " to " << w << " x " << h << endl;
    width = w;
    height = h;
}

/**************************************************************************//**
 * @brief Rectangle class draw
 *
 * @par Description
 *   must override pure virtual Shape::draw() method to instantiate class
 *
 *****************************************************************************/
void Rectangle::draw( ) const
{
	DrawFilledRectangle(locX - width / 2, locY - height / 2, locX + width / 2, 
	locY + height / 2, some_color);
	glutSwapBuffers();
    cout << "Draw  Rectangle: (" <<
         locX << "," << locY << ") = " << color << ", width " << width << " x height " << height << endl;
}

/**************************************************************************//**
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
