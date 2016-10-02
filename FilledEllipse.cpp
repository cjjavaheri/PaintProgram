/***************************************************************************//**
 * @file FilledEllipse.cpp
 * 
 * @brief The file used for implementing the filled ellipse class.
 *
 * @author John M. Weiss, Ph.D., Matthew Schallenkamp
 *
 * @par Class:
 *    CSC300 Data Structures
 * @date Fall 2016
 *
 ******************************************************************************/
#include <iostream>
using namespace std;

#include "FilledEllipse.h"

/**************************************************************************//**
 * @author Matthew Schallenkamp
 *
 * @brief FilledEllipse class implementation constructor
 *
 * @param[in] x - x-coordinate of the center of the FilledEllipse
 * @param[in] y - y-coordinate of the center of the FilledEllipse
 * @param[in] c - the color of the FilledEllipse boundary
 * @param[in] f - the color of the FilledEllipse filler
 * @param[in] r_x - x radius of the FilledEllipse
 * @param[in] r_y - y radius of the FilledEllipse
 *
 *****************************************************************************/
FilledEllipse::FilledEllipse( float x, float y, ColorType c, ColorType f, float r_x, float r_y)
	: Ellipse(x, y, c, r_x, r_y), fill_color(f)
{

}

/**************************************************************************//**
 * @author Matthew Schallenkamp
 *
 * @brief FilledEllipse class implementation destructor
 *****************************************************************************/
FilledEllipse::~FilledEllipse( )
{

}

/**************************************************************************//**
 * @author Matthew Schallenkamp
 *
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
}

/**************************************************************************//**
 * @author Matthew Schallenkamp
 *
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
