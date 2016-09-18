/**************************************************************************//**
 * @file rectangle.h
 *
 * @par Description
 *    OOP example illustrating inheritance and late binding via virtual 
 *    functions in C++.
 *    
 *    Inheritance is used to derive various shape classes (Point, Line, Circle,
 *    Rectangle, Square) from a base Shape class.
 *
 *    This file contains the Point class interface.
 *
 * @author John M. Weiss, Ph.D.
 * 
 * @par Class:  
 *    CSC300 Data Structures
 * 
 * @date Fall 2015
 *
 * Modifications:
 *  * Added doxygen style comments                              PJH : 9/5/2016
 *  * Added doxygen style function blocks and parameter desc    PJH : 9/5/2016
 *****************************************************************************/
#ifndef _Rectangle_H_
#define _Rectangle_H_

#include "shape.h"

/***************************************************************************//**
 * @class Rectangle
 ******************************************************************************/
class Rectangle : public Shape
{
    private:
        /// Rectangle width
        float width;
        /// Rectangle height;
        float height;

    public:
        /// Constructor
        Rectangle( float x = 0.0, float y = 0.0, ColorType c = ColorType( 0 ), float w = 1.0, float h = 1.0 );
        /// Destructor
        ~Rectangle( );

        /// Mutator to change the dimensions of the rectangle
        void changeDimensions( float w, float h );
        /// Implementation of the base class pure virtual function draw
        void draw( ) const;
        /// Implementation of the base class pure virtual function erase
        void erase( ) const;
        /// Implementation of the base class pure virtual function print
        void print( ostream& out ) const;
};

#endif

