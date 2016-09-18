
#include "callbacks.h"

/***************************************************************************//**
 * @author Paul Hinker
 *
 * @brief A callback function for refreshing the display
 ******************************************************************************/


void Color_Palette()
{
    DrawFilledRectangle ( 0, 0, 50, 50, Grey );
    DrawFilledRectangle ( 0, 50, 50, 100, Red );
    DrawFilledRectangle ( 0, 100, 50, 150, Green );
    DrawFilledRectangle ( 0, 150, 50, 200, Blue );
    DrawFilledRectangle ( 0, 200, 50, 250, Magenta );
    DrawFilledRectangle ( 0, 250, 50, 300, Cyan );
    DrawFilledRectangle ( 0, 300, 50, 350, Yellow );
    DrawFilledRectangle ( 0, 350, 50, 400, White );
    DrawRectangle ( 50, 1, 100, 50, White );
    DrawRectangle ( 65, 15, 85, 35, Yellow );
    DrawRectangle ( 100, 1, 150, 50, White );
    DrawRectangle ( 115, 15, 135, 35, Yellow );
    DrawFilledRectangle ( 115, 15, 134, 34, Grey );
    DrawRectangle ( 1, 400, 50, 450, White );
    
}

ShapeType Choose_Shape ( int x, int y, ShapeType shape )
{
    if ( x >= 50 && x < 100 && y >= 1 && y < 50 )
    {
        return RECTANGLE;
    }
    else if ( x >= 100 && x < 150 && y >= 1 && y < 50 )
    {
        return FILLED_RECTANGLE;
    }
    else
    {
        return shape;
    }
    
}

ColorType Choose_Color ( int x, int y, ColorType color )
{
    if ( x >= 0 && x <= 50 && y >= 0 && y < 50 )
    {
        return GREY;
    }
    else if ( x >= 0 && x <= 50 && y >= 50 && y < 100 )
    {
        return RED;
    }
    else if ( x >= 0 && x <= 100 && y >= 100 && y < 150 )
    {
        return GREEN;
    }
    else if ( x >= 0 && x <= 50 && y >= 150 && y < 200 )
    {
        return BLUE;
    }
    else if ( x >= 0 && x <= 50 && y >= 200 && y < 250 )
    {
        return MAGENTA;
    }
    else if ( x >= 0 && x <= 50 && y >= 250 && y < 300 )
    {
        return CYAN;
    }
    else if ( x >= 0 && x <= 50 && y >= 300 && y < 350 )
    {
        return YELLOW;
    }
    else if ( x >= 0 && x <= 50 && y >= 350 && y < 400 )
    {
        return WHITE;
    }
    else
    {
        return color;
    }
    
}

void MouseEvent ( int button, int state, int x, int y )
{

    static int x_initial;
    static int y_initial;
    static int x_final;
    static int y_final;
    static ColorType boundary = BLACK;
    static ColorType fill = BLACK;
    static ShapeType shape = EMPTY;
    static ShapeType check_shape = EMPTY;
    Shape * rect;
    Shape * filled_rect;
    
    
    if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    {
        boundary = Choose_Color ( x, y, boundary );
        shape = Choose_Shape ( x, y, shape );
        x_initial = x;
        y_initial = y;
        
        if ( boundary != BLACK && ( shape == RECTANGLE || shape == FILLED_RECTANGLE ) )
        {
            if ( shape == RECTANGLE )
            {
                rect = new Rectangle ( ( 16 + 35 ) / 2.0, ( 415 + 435 ) / 2.0, 				boundary, 16 - 35, 415 - 435 );
                rect->draw();
		delete rect;
            }
            else if ( fill != BLACK && shape == FILLED_RECTANGLE )
            {
                filled_rect = new FilledRectangle ( ( 16 + 35 ) / 2.0, ( 415 + 435 ) / 			2.0, fill, 16 - 35, 415 - 435 );
                rect = new Rectangle ( ( 16 + 35 ) / 2.0,( 415 + 435 ) / 				2.0,boundary, 16 - 35, 415 - 435 );
		filled_rect->draw();
                rect->draw();
                delete rect;
                delete filled_rect;
            }
        }
    }
    else if ( button == GLUT_LEFT_BUTTON && state == GLUT_UP )
    {
        x_final = x;
        y_final = y;
        
        if ( boundary != BLACK && shape == RECTANGLE )
        {
            rect = new Rectangle ( ( x_initial + x_final ) / 2.0, ( y_initial 				+y_final ) /2.0,boundary, x_initial - x_final, y_initial - y_final );
            rect->draw();
            delete rect;
        }
        else if ( fill != BLACK && shape == FILLED_RECTANGLE )
        {
            filled_rect = new FilledRectangle ( ( x_initial + x_final ) / 2.0,( y_initial 			+ y_final ) / 2, fill, x_initial - x_final,y_initial - y_final );
            rect = new Rectangle ( ( x_initial + x_final ) / 2.0,( y_initial +  			y_final ) / 2.0,boundary, x_initial - x_final, y_initial - y_final );
	    filled_rect->draw();
            rect->draw();
            delete filled_rect;
            delete rect;
        }
        
    }
    
    else if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
    {
        fill = Choose_Color ( x, y, fill );
        shape = Choose_Shape ( x, y, shape );
        
        if ( shape == FILLED_RECTANGLE )
        {
            check_shape = FILLED_RECTANGLE;
        }
        
        if ( check_shape == FILLED_RECTANGLE )
        {
            if ( fill != BLACK && ( shape == FILLED_RECTANGLE || shape == RECTANGLE ) )
            {
                if ( boundary != BLACK )
                {
                    rect = new Rectangle ( ( 16 + 35 ) / 2.0, ( 415 + 435 ) /  2.0, 				boundary, 16 - 35, 415 - 435 );
                    rect->draw();
                }
                
                filled_rect = new FilledRectangle ( ( 16 + 35 ) / 2.0,
                        ( 415 + 435 ) /  2.0, fill, 16 - 35, 415 - 435 );
                filled_rect->draw();
		delete rect;
                delete filled_rect;
            }
        }
        
        
    }
    else if ( button == GLUT_RIGHT_BUTTON && state == GLUT_UP )
    {
    
    }
}

void display()
{
    // Clear the window
    glClear ( GL_COLOR_BUFFER_BIT );
    
    glutInitWindowSize ( 1024, 999 );
    glutInitWindowPosition ( 100, 100 );
    
    Color_Palette();
    
    // DrawLine( 10, 20, glutGet(GLUT_WINDOW_WIDTH) - 10,
    //         glutGet(GLUT_WINDOW_HEIGHT) - 20, Yellow );
    // DrawRectangle( 500, 400, 700, 500, Cyan );
    // DrawFilledRectangle( 200, 100, 300, 300, Red );
    //  DrawEllipse( 100, 50, 600, 200, Green );
    // DrawFilledEllipse( 100, 50, 250, 450, Magenta );
    
    // label display with text
    DrawTextString ( "OpenGL Demo", 32, 800 - 32, White );
    
    // Make sure all the draw functions a complete to the buffer
    glutSwapBuffers();
}


/***************************************************************************//**
 * @brief A callback function for handling keyboard input
 *
 * @param[in] key - the key that was pressed
 * @param[in] x   - the x-coordinate when the key was pressed
 * @param[in] y   - the y-coordinate when the key was pressed
 ******************************************************************************/
void keyboard ( unsigned char key, int x, int y )
{
    // Pressing the ESCAPE Key will exit from the main glut loop
    
    int ScreenHeight = glutGet ( GLUT_WINDOW_HEIGHT );
    
    y = ScreenHeight - y;
    
    if ( key == ESCAPE_KEY )
    {
        glutLeaveMainLoop();
    }
    else
        cout << "Key " << ( char ) key << " press detected at ["
             << x << ", " << y << "]\n";
}

/***************************************************************************//**
 * @brief A callback function for handling mouse click events
 *
 * @param[in] button - the mouse button pushed
 * @param[in] state  - the state of the button (i.e. GLUT_UP, GLUT_DOWN)
 * @param[in] x      - the x-coordinate when the button is pressed
 * @param[in] y      - the y-coordinate when the button is pressed
 ******************************************************************************/
void mouseClick ( int button, int state, int x, int y )
{

    y = glutGet ( GLUT_WINDOW_HEIGHT ) - y;
    
    
    MouseEvent ( button, state, x, y );
    
    
    cout << "MouseClick: Button = " << ButtonName[button] << " : State = "
         << ButtonState[state] << " : Location [" << x << ", " << y << "]\n";
}

/***************************************************************************//**
 * @brief A callback function for handling reshape events
 *
 * @param[in] w      - the width of the newly reshaped window
 * @param[in] h      - the height of the newly reshaped window
 ******************************************************************************/
void reshape ( int w, int h )
{
    glMatrixMode ( GL_PROJECTION );     // use an orthographic projection
    glLoadIdentity();                   // initialize transformation matrix
    gluOrtho2D ( 0.0, w, 0.0, h );      // make OpenGL coordinates
    glViewport ( 0, 0, w, h );          // the same as the screen coordinates
}
	

