/***************************************************************************//**
 * @file Ellipse.cpp
 *
 * @par Description
 *    OOP example illustrating inheritance and late binding via virtual
 *    functions in C++.
 *
 *    Inheritance is used to derive various shape classes (Point, Line, Ellipse,
 *    Rectangle, Square) from a base Shape class.
 *
 *    This file contains the Ellipse class implementation.
 *
 * @author John M. Weiss, Ph.D.
 *
 * @par Class:
 *    CSC300 Data Structures
 * @date Fall 2015
 *
 * @par Modifications:
 *  * Added doxygen style comments                       PJH : 9/5/2016
 *  * Added function headers and parameter descriptions  PJH : 9/5/2016
 *  * Changed from Ellipse to Ellipse                     MJS : 9/27/16
 ******************************************************************************/
#include <iostream>
using namespace std;

#include "ellipse.h"

/**************************************************************************//**
 * @brief Ellipse class implementation constructor
 *
 * @param[in] x - x-coordinate of the center of the Ellipse
 * @param[in] y - y-coordinate of the center of the Ellipse
 * @param[in] c - the color of the Ellipse boundary
 * @param[in] r - radius of the Ellipse
 *
 *****************************************************************************/
Ellipse::Ellipse( float x, float y, ColorType c, float r_x, float r_y)
	: Shape( x, y, c ), radius_x( r_x ), radius_y( r_y )
{
	cout << "Ellipse constructor: ("
	     <<	x << "," << y << ") = " << c
	     << ", radius = " << radius_x << endl;
}

/**************************************************************************//**
 * @brief Ellipse class implementation destructor
 *****************************************************************************/
Ellipse::~Ellipse( )
{
	cout << "Ellipse destructor: ("
	     << locX << "," << locY << ") = " << color
	     << ", r_x = " << radius_x << ", r_y = " << radius_y << endl;
}

/**************************************************************************//**
 * @brief Ellipse class draw
 *
 * @par Description
 *   must override pure virtual Shape::draw() method to instantiate class
 *
 *****************************************************************************/
void Ellipse::draw( ) const
{
	DrawEllipse( radius_x, radius_y, locX, locY, some_color );
	glutSwapBuffers();
	cout << "Draw  Ellipse: ("
	     << locX << "," << locY << ") = " << color
	     << ", r_x = " << radius_x << ", r_y = " << radius_y << endl;
}

/**************************************************************************//**
 * @brief Ellipse class erase
 *
 * @par Description
 *    must override pure virtual Shape::erase() method to instantiate class
 *
 *****************************************************************************/
void Ellipse::erase( ) const
{
	cout << "Erase Ellipse: ("
	     << locX << "," << locY << ") = " << color
	     << ", r_x = " << radius_x << ", r_y = " << radius_y << endl;
}


/**************************************************************************//**
 * @brief Ellipse class print
 *
 * @par Description
 *    must override pure virtual Shape::print() method to instantiate class
 *
 * @param[in] out - the stream where the print occurs
 *****************************************************************************/
void Ellipse::print( ostream& out ) const
{
	out << "Ellipse at position (" << locX << "," << locY << ")"
	    << " with r_x = " << radius_x << ", r_y = " << radius_y << endl;
}