#include "callbacks.h"



/***************************************************************************//**
 * @author Cameron Javaheri, Matthew Schallenkamp
 *
 * @brief A function that is used to display the color palette.
 *
 ******************************************************************************/
void Color_Palette()
{
	//color boxes
	DrawFilledRectangle ( 0, 0, 50, 50, Grey );
	DrawFilledRectangle ( 0, 50, 50, 100, Red );
	DrawFilledRectangle ( 0, 100, 50, 150, Green );
	DrawFilledRectangle ( 0, 150, 50, 200, Blue );
	DrawFilledRectangle ( 0, 200, 50, 250, Magenta );
	DrawFilledRectangle ( 0, 250, 50, 300, Cyan );
	DrawFilledRectangle ( 0, 300, 50, 350, Yellow );
	DrawFilledRectangle ( 0, 350, 50, 400, White );

	//to draw preview
	DrawRectangle ( 1, 400, 50, 450, White );

	//open rectangle
	DrawRectangle ( 50, 0, 100, 50, White );
	DrawRectangle ( 65, 15, 85, 35, Yellow );
	//filled rectangle
	DrawRectangle ( 100, 0, 150, 50, White );
	DrawFilledRectangle ( 115, 15, 134, 35, Grey );
	DrawRectangle ( 115, 15, 135, 35, Yellow );
	//open ellipse
	DrawRectangle ( 50, 50, 100, 100, White );
	DrawEllipse ( 15, 10, 75, 75, Yellow );

}

/***************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief A function that will determine the type of shape to be drawn based
 * on the location of a mouse click.
 *
 * @param[in] x - The x-coordinate of the mouse click.
 * @param[in] y - The y-coordinate of the mouse click.
 * @param[in] shape - The type of shape the object is before entering the function.
 *
 * @returns The type of shape the object is.
 ******************************************************************************/

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
	else if ( x >= 50 && x < 100 && y >= 50 && y < 100 )
	{
		return ELLIPSE;
	}
	else
	{
		return shape;
	}
}

/***************************************************************************//**
 * @author Cameron Javaheri
 *
 * @brief This function determines the color of the shape based on the location
 * of a mouse click.
 *
 * @param[in] x - x-coordinate of the mouse click.
 * @param[in] y - y-coordinate of the mouse click.
 * @param[in] color - The color of the object before the choose_color function
 * was called.
 *
 * @returns The type of color the object is.
 ******************************************************************************/
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


/***************************************************************************//**
 * @author Cameron Javaheri, Matthew Schallenkamp
 *
 * @brief An event function that handles mouse events from the user. It dynamically
 * allocates new shapes using inheritance and draws them to the screen.
 *
 * @param[in] key - the key that the user pressed. if none, \0
 * @param[in] button - The button the user pressed.
 * @param[in] state - Tells whether the user clicked or released the mouse button.
 * @param[in] x - The x-coordinate of the mouse click.
 * @param[in] y - The y-coordinate of the mouse click.
 *
 ******************************************************************************/
void Event ( char key, int button, int state, int x, int y )
{
	static int x_initial;
	static int y_initial;
	static ColorType boundary = BLACK;
	static ColorType fill = BLACK;
	static ShapeType shape = EMPTY;
	static ShapeType check_shape = EMPTY;
	const float display_rect[4] = { (16 + 35) / 2.0, (415 + 435) / 2.0, 16 - 35, 415 - 435};
	Shape * new_shape;
	vector<Shape *> items;

	if(key == '\0')
	{
		if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
		{
			boundary = Choose_Color ( x, y, boundary );
			shape = Choose_Shape ( x, y, shape );
			x_initial = x;
			y_initial = y;

			if ( shape == RECTANGLE || shape == FILLED_RECTANGLE )
			{
				if ( shape == RECTANGLE )
				{
					new_shape = new Rectangle ( display_rect[0], display_rect[1], boundary, display_rect[2], display_rect[3] );
					new_shape->draw();
				}
				else if ( shape == FILLED_RECTANGLE )
				{
					new_shape = new FilledRectangle ( display_rect[0], display_rect[1], fill, display_rect[2], display_rect[3] );
					new_shape->draw();
					new_shape = new Rectangle ( display_rect[0], display_rect[1], boundary, display_rect[2], display_rect[3] );
					new_shape->draw();
				}
			}
		}
		else if ( button == GLUT_LEFT_BUTTON && state == GLUT_UP )
		{
			if ( shape == RECTANGLE )
			{
				new_shape = new Rectangle ( ( x_initial + x ) / 2.0, ( y_initial + y ) / 2.0, boundary, x_initial - x, y_initial - y );
				new_shape->draw();
			}
			else if ( shape == FILLED_RECTANGLE )
			{
				new_shape = new FilledRectangle ( ( x_initial + x ) / 2.0, ( y_initial + y ) / 2, fill, x_initial - x, y_initial - y );
				new_shape->draw();
				new_shape = new Rectangle ( ( x_initial + x ) / 2.0, ( y_initial + y ) / 2.0, boundary, x_initial - x, y_initial - y );
				new_shape->draw();
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
				if ( shape == FILLED_RECTANGLE || shape == RECTANGLE )
				{
					new_shape = new FilledRectangle ( display_rect[0], display_rect[1], fill, display_rect[2], display_rect[3] );
					new_shape->draw();
				}
			}
		}
	}
	else
	{
		//do key stuff
		switch(key)
		{
			case 'd':
				break;
			case 'e':
				break;
			default:
				break;
		}
	}
}

/***************************************************************************//**
 * @author Paul Hinker
 *
 * @brief A callback function for refreshing the display
 ******************************************************************************/
void display()
{
	// Clear the window
	glClear ( GL_COLOR_BUFFER_BIT );

	glutInitWindowSize ( 1024, 999 );
	glutInitWindowPosition ( 100, 100 );

	Color_Palette();

	// DrawLine( 10, 20, glutGet(GLUT_WINDOW_WIDTH) - 10,
	// glutGet(GLUT_WINDOW_HEIGHT) - 20, Yellow );
	// DrawRectangle( 500, 400, 700, 500, Cyan );
	// DrawFilledRectangle( 200, 100, 300, 300, Red );
	// DrawEllipse( 100, 50, 600, 200, Green );
	// DrawFilledEllipse( 100, 50, 250, 450, Magenta );

	// label display with text
	DrawTextString ( "OpenGL Demo", 32, 800 - 32, White );

	Event('\0', GLUT_LEFT_BUTTON, GLUT_DOWN, -1, -1);
	Event('\0', GLUT_LEFT_BUTTON, GLUT_UP, -1, -1);

	// Make sure all the draw functions a complete to the buffer
	glutSwapBuffers();
}


/***************************************************************************//**
 * @brief A callback function for handling keyboard input
 *
 * @param[in] key - the key that was pressed
 * @param[in] x - the x-coordinate when the key was pressed
 * @param[in] y - the y-coordinate when the key was pressed
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
	cout << "Key " << ( char ) key << " press detected at ["
	 		 << x << ", " << y << "]\n";
	Event(key, 0, 0, x, y);
}

/***************************************************************************//**
 * @brief A callback function for handling mouse click events
 *
 * @param[in] button - the mouse button pushed
 * @param[in] state - the state of the button (i.e. GLUT_UP, GLUT_DOWN)
 * @param[in] x - the x-coordinate when the button is pressed
 * @param[in] y - the y-coordinate when the button is pressed
 ******************************************************************************/
void mouseClick ( int button, int state, int x, int y )
{

	y = glutGet ( GLUT_WINDOW_HEIGHT ) - y;

	// \0 because there is no key pressed
	Event('\0', button, state, x, y);


	cout << "MouseClick: Button = " << ButtonName[button] << " : State = "
	 << ButtonState[state] << " : Location [" << x << ", " << y << "]\n";
}

/***************************************************************************//**
 * @brief A callback function for handling reshape events
 *
 * @param[in] w - the width of the newly reshaped window
 * @param[in] h - the height of the newly reshaped window
 ******************************************************************************/
void reshape ( int w, int h )
{
	glMatrixMode ( GL_PROJECTION ); // use an orthographic projection
	glLoadIdentity();  // initialize transformation matrix
	gluOrtho2D ( 0.0, w, 0.0, h ); // make OpenGL coordinates
	glViewport ( 0, 0, w, h ); // the same as the screen coordinates
}


