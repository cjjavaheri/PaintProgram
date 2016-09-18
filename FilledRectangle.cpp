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

#include "FilledRectangle.h"

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
FilledRectangle::FilledRectangle( float x, float y, ColorType c, float w, float h ) :
    Rectangle( x, y, c, w, h )
{
    cout << "FilledRectangle constructor: (" <<
         x << "," << y << ") = " << c << ", width " << w << " x height " << h << endl;
}

/**************************************************************************//**
 * @brief Rectangle class implementation destructor
 *****************************************************************************/
FilledRectangle::~FilledRectangle( )
{
    cout << "FilledRectangle destructor: (" <<
         locX << "," << locY << ") = " << color << ", width " << width << " x height " << height << endl;
}


/**************************************************************************//**
 * @brief Rectangle class draw
 *
 * @par Description
 *   must override pure virtual Shape::draw() method to instantiate class
 *
 *****************************************************************************/
void FilledRectangle::draw( ) const
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
void FilledRectangle::erase( ) const
{
	DrawFilledRectangle(locX - width / 2, locY - height / 2, locX + width / 2, 
	locY + height / 2, Black);
	DrawRectangle(locX - width / 2, locY - height / 2, locX + width / 2,
	locY + height / 2,  Black);
	glutSwapBuffers();
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
void FilledRectangle::print( ostream& out ) const
{
    out << ( width == height ? "square" : "rectangle" ) << " at position (" << locX << "," << locY << ")"
        << " with sides " << width << " and " << height << endl;
}

