/***************************************************************************//**
 * @file Line.cpp
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
	//cout << "Line constructor: (" <<
	//     x << "," << y << ") = " << c << endl;
}

/**************************************************************************//**
 * @author Cameron Javaheri
 * @brief Line class implementation destructor
 *****************************************************************************/
Line::~Line( )
{
	//cout << "Line destructor: (" <<
	//     locX << "," << locY << ") = " << color << endl;
}

/**************************************************************************//**
 * *@author Cameron Javaheri
 *
 * @brief Line class change location function
 *
 * @par Description
 *    mutator method for Line class
 *
 * @param[in] x - the new center x-location for the line
 * @param[in] y - the new center y-location for the line
 *****************************************************************************/



//void Line::changeDimensions( float x, float y )
//{
//cout << "Change line dimensions from [" << locX << "," << locY << "]"
//<< "to [" << x << "," << "y]" << endl;
//locX = x;
//locY = y;
//}




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
	//cout << "Draw  Line: (" <<
	//     locX << "," << locY << ") = " << color << ", length " << length << " height " << height << endl;
}

/**************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief Line class erase
 *
 * @par Description
 *    must override pure virtual Shape::erase() method to instantiate class
 *
 *****************************************************************************/
void Line::erase( ) const
{
	//DrawRectangle(locX - width / 2, locY - height / 2, locX + width / 2,
	//         locY + height / 2,  Black);
	//glutSwapBuffers();
	//cout << "Erase Rectangle: (" <<
	//locX << "," << locY << ") = " << color << ", width " << width << " x height " << height << endl;
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

