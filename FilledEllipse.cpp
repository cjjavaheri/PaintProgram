/***************************************************************************//**
 * @file FilledEllipse.cpp
 *
 * @par Description
 *    OOP example illustrating inheritance and late binding via virtual
 *    functions in C++.
 *
 *    Inheritance is used to derive various shape classes (Point, Line, FilledEllipse,
 *    Rectangle, Square) from a base Shape class.
 *
 *    This file contains the FilledEllipse class implementation.
 *
 * @author John M. Weiss, Ph.D., Matthew Schallenkamp
 *
 * @par Class:
 *    CSC300 Data Structures
 * @date Fall 2015
 *
 * @par Modifications:
 *  * Added doxygen style comments                       PJH : 9/5/2016
 *  * Added function headers and parameter descriptions  PJH : 9/5/2016
 *  * Changed from Ellipse to FilledEllipse              MJS : 9/27/16
 ******************************************************************************/
#include <iostream>
using namespace std;

#include "FilledEllipse.h"

/**************************************************************************//**
 * @brief FilledEllipse class implementation constructor
 *
 * @param[in] x - x-coordinate of the center of the FilledEllipse
 * @param[in] y - y-coordinate of the center of the FilledEllipse
 * @param[in] c - the color of the FilledEllipse boundary
 * @param[in] r - radius of the FilledEllipse
 *
 *****************************************************************************/
FilledEllipse::FilledEllipse( float x, float y, ColorType c, ColorType f, float r_x, float r_y)
	: Ellipse(x, y, c, r_x, r_y), fill_color(f)
{
	cout << "FilledEllipse constructor: ("
	     <<	x << "," << y << ") = " << c
	     << ", radius = " << radius_x << endl;
}

/**************************************************************************//**
 * @brief FilledEllipse class implementation destructor
 *****************************************************************************/
FilledEllipse::~FilledEllipse( )
{
	cout << "FilledEllipse destructor: ("
	     << locX << "," << locY << ") = " << color
	     << ", r_x = " << radius_x << ", r_y = " << radius_y << endl;
}

/**************************************************************************//**
 * @brief FilledEllipse class draw
 *
 * @par Description
 *   must override pure virtual Shape::draw() method to instantiate class
 *
 *****************************************************************************/
void FilledEllipse::draw( ) const
{
	DrawFilledEllipse( radius_x, radius_y, locX, locY, glutColor.at(fill_color).data() );
	DrawEllipse( radius_x, radius_y, locX, locY, glutColor.at(color).data() );
	glutSwapBuffers();
	cout << "Draw  FilledEllipse: ("
	     << locX << "," << locY << ") = " << color
	     << ", r_x = " << radius_x << ", r_y = " << radius_y << endl;
}

/**************************************************************************//**
 * @brief FilledEllipse class erase
 *
 * @par Description
 *    must override pure virtual Shape::erase() method to instantiate class
 *
 *****************************************************************************/
void FilledEllipse::erase( ) const
{
	cout << "Erase FilledEllipse: ("
	     << locX << "," << locY << ") = " << color
	     << ", r_x = " << radius_x << ", r_y = " << radius_y << endl;
}


/**************************************************************************//**
 * @brief FilledEllipse class print
 *
 * @par Description
 *    must override pure virtual Shape::print() method to instantiate class
 *
 * @param[in] out - the stream where the print occurs
 *****************************************************************************/
void FilledEllipse::print( ostream& out ) const
{
	out << "FilledEllipse at position (" << locX << "," << locY << ")"
	    << " with r_x = " << radius_x << ", r_y = " << radius_y << endl;
}
