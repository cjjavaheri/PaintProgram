/***************************************************************************//**
 * @file Shape.cpp
 * 
 * @brief The file used for implementing the shape class.
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
 * @author John M. Weiss, Ph.D. , Cameron Javaheri, Matthew Schallenkamp
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
#include <iostream>
using namespace std;

#include "Shape.h"

/**************************************************************************//**
 * @author John Weiss
 *
 * @brief Shape class implementation constructor
 *
 * @param[in] x - x-coordinate of the center of the shape
 * @param[in] y - y-coordinate of the center of the shape
 * @param[in] c - the color of the shape boundary
 *****************************************************************************/
Shape::Shape( float x, float y, ColorType c ) : locX( x ), locY( y ), color( c )
{

}

/**************************************************************************//**
 * @author John Weiss
 * @brief Shape class implementation destructor
 *****************************************************************************/
Shape::~Shape( )
{
	
}

/**************************************************************************//**
 * @author Cameron Javaheri

 * @brief Shape class change radius
 *
 * @par Description
 *    mutator method for Shape class
 *
 * @param[in] x - x-coordinate of the new position
 * @param[in] y - y-coordinate of the new position
 *****************************************************************************/
void Shape::moveTo( float x, float y )
{

	locX = x;
	locY = y;
}

// change color of object

/**************************************************************************//**
 * @author Matthew Schallenkamp

 * @brief Shape class change radius
 *
 * @par Description
 *    mutator method for Shape class
 *
 * @param[in] c - the new color of the shape
 *****************************************************************************/

void Shape::changeColor( ColorType c )
{
	color = c;
}


/**************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief Shape class accessor for the center x-coordinate of the shape.
 *
 * @par Description
 *    accessor method for Shape class
 *
 * @returns the center x-coordinate of the shape.
 *****************************************************************************/

float Shape::getX()
{
	return locX;
}

/**************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief Shape class accessor for the center y-coordinate of the shape.
 *
 * @par Description
 *    accessor method for Shape class.
 *
 * @returns the center y-coordinate of the shape.
 *****************************************************************************/

float Shape::getY()
{
	return locY;
}


const map<ColorType, vector<float> > Shape::glutColor =
{
	{
		BLACK,
		{
			0.00,
			0.00,
			0.00,
		}
	},
	{
		RED,
		{
			1.00,
			0.00,
			0.00,
		}
	}, {
		GREEN,
		{
			0.00,
			1.00,
			0.00,
		}
	}, {
		BLUE,
		{
			0.00,
			0.00,
			1.00,
		}
	}, {
		MAGENTA,
		{
			1.00,
			0.00,
			1.00,
		}
	}, {
		GREY,
		{
			0.50,
			0.50,
			0.50,
		}
	}, {
		CYAN,
		{
			0.00,
			1.00,
			1.00,
		}
	}, {
		YELLOW,
		{
			1.00,
			1.00,
			0.00,
		}
	}, {
		WHITE,
		{
			1.00,
			1.00,
			1.00,
		}
	}, {
		GREY,
		{
			0.50,
			0.50,
			0.50,
		}
	}
};
