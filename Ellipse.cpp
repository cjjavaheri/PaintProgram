/***************************************************************************//**
 * @file Ellipse.cpp
 *
 * @author John M. Weiss, Ph.D., Matthew Schallenkamp
 *
 * @par Class:
 *    CSC300 Data Structures
 *
 * @date Fall 2016
 *
 ******************************************************************************/
#include <iostream>
using namespace std;

#include "Ellipse.h"

/**************************************************************************//**
 * @brief Ellipse class implementation constructor
 *
 * @param[in] x - x-coordinate of the center of the Ellipse
 * @param[in] y - y-coordinate of the center of the Ellipse
 * @param[in] c - the color of the Ellipse boundary
 * @param[in] r_x - x radius of the Ellipse
 * @param[in] r_y - y radius of the Ellipse
 *
 *****************************************************************************/
Ellipse::Ellipse( float x, float y, ColorType c, float r_x, float r_y)
	: Shape( x, y, c ), radius_x( r_x ), radius_y( r_y )
{
	//cout << "Ellipse constructor: ("
	//     <<	x << "," << y << ") = " << c
	//     << ", radius = " << radius_x << endl;
}

/**************************************************************************//**
 * @brief Ellipse class implementation destructor
 *****************************************************************************/
Ellipse::~Ellipse( )
{
	//cout << "Ellipse destructor: ("
	//     << locX << "," << locY << ") = " << color
	//     << ", r_x = " << radius_x << ", r_y = " << radius_y << endl;
}

/**************************************************************************//**
 * @brief Ellipse class draw
 *
 * @par Description
 *   draws the ellipse on the screen
 *
 *****************************************************************************/
void Ellipse::draw( ) const
{
	DrawEllipse( radius_x, radius_y, locX, locY, glutColor.at(color).data() );
	//cout << "Draw  Ellipse: ("
	//     << locX << "," << locY << ") = " << color
	//     << ", r_x = " << radius_x << ", r_y = " << radius_y << endl;
}

/**************************************************************************//**
 * @brief Ellipse class print
 *
 * @par Description
 *    prints the internal values of the shape
 *
 * @param[in] out - the stream where the print occurs
 *****************************************************************************/
void Ellipse::print( ostream& out ) const
{
	out << "Ellipse at position (" << locX << "," << locY << ")"
	    << " with r_x = " << radius_x << ", r_y = " << radius_y << endl;
}