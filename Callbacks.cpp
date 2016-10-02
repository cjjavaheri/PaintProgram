/**************************************************************************//**
 * @file Callbacks.cpp
 * 
 * @brief This file contains all of the callback functions.
 *
 * @author: Paul Hinker (initial), Cameron Javaheri, Matthew Schallenkamp
 *
 * @par Class:
 * CSC300 Data Structures
 *
 * @date:   Fall 2016
 *
 ******************************************************************************/
#include "Callbacks.h"


/**
 * @brief A list of strings representing button type codes
 */
const string ButtonName[] =
{
	"Left",
	"Middle",
	"Right",
	"Trackball Fwd",
	"Trackball Bkwd"
};

/**
 * @brief A list of strings representing button state codes
 */
const string ButtonState[] =
{
	"Down",
	"Up"
};

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
	//filled ellipse
	DrawRectangle ( 100, 50, 150, 100, White );
	DrawFilledEllipse( 15, 10, 125, 75, Grey );
	DrawEllipse ( 15, 10, 125, 75, Yellow );
	// line
	DrawRectangle(50, 100 , 100, 150, White);
	DrawLine(65, 115, 85, 135, Yellow);
}

/***************************************************************************//**
 * @author Cameron Javaheri, Matthew Schallenkamp
 *
 * @brief A function that will determine the type of shape to be drawn based
 * on the location of a mouse click.
 *
 * @param[in] x - The x-coordinate of the mouse click.
 * @param[in] y - The y-coordinate of the mouse click.
 * @param[in] shape - The type of shape the object is before entering the function.
 *
 * @returns The new type of shape the object is.
 *
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
	else if ( x >= 100 && x < 150 && y >= 50 && y < 100 )
	{
		return FILLED_ELLIPSE;
	}
	else if ( x >= 50 && x < 100 && y >= 100 && y < 150)
	{
		return LINE;
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
 *
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
	else if ( x >= 0 && x <= 50 && y >= 100 && y < 150 )
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
 * @brief A function that is used to display the preview box.
 *
 * @param[in] shape - The type of shape to be displayed.
 * @param[in] boundary - The color of the boundary of the shape.
 * @param[in] fill - The filled color of the shape.
 *
 ******************************************************************************/
void Preview_Box(ShapeType shape, ColorType boundary, ColorType fill)
{
	const float display_rect[4] = { (16 + 35) / 2.0, (415 + 435) / 2.0, 16 - 35, 415 - 435};
	const FilledRectangle preview_back( 25, 425, BLACK, BLACK, 48, 48 );
	//clear the old selection
	preview_back.draw();

	//prep to draw the new selection
	Shape *temp_shape;
	switch (shape)
	{
	case RECTANGLE:
		temp_shape = new Rectangle ( display_rect[0], display_rect[1], boundary, display_rect[2], display_rect[3] );
		break;
	case FILLED_RECTANGLE:
		temp_shape = new FilledRectangle ( display_rect[0], display_rect[1], boundary, fill, display_rect[2], display_rect[3] );
		break;
	case ELLIPSE:
		temp_shape = new Ellipse( 25, 425, boundary, 15, 10 );
		break;
	case FILLED_ELLIPSE:
		temp_shape = new FilledEllipse( 25, 425, boundary, fill, 15, 10 );
		break;
	case LINE:
		temp_shape = new Line(25, 425, boundary, 19, 20);
		break;
	default:
		temp_shape = nullptr;
		break;
	}

	//draw the new selection
	if (temp_shape != nullptr)
	{
		temp_shape->draw();
		delete temp_shape;
		temp_shape = nullptr;
	}
}


/***************************************************************************//**
 * @author Cameron Javaheri, Matthew Schallenkamp
 *
 * @brief A function that is used to insert a shape object into a vector.
 *
 * @param[in] shape - The type of shape of the object.
 * @param[in,out] items - A vector of shape pointers.
 * @param[in] boundary - The color of the boundary of the shape.
 * @param[in] fill - The filled color of the shape.
 * @param[in] ix - The initial x-coordinate of the mouse click.
 * @param[in] iy - The initial y-coordinate of the mouse click.
 * @param[in] fx - The final x-coordinate of the mouse click.
 * @param[in] fy - The final y-coordinate of the mouse click.
 *
 ******************************************************************************/
void Insert_Shape(ShapeType shape, vector<Shape *> &items, ColorType boundary, ColorType fill,
                  float ix, float iy, float fx, float fy)
{
	Shape * temp_shape;
	float x_mid, y_mid, x_size, y_size;
	x_mid = ( ix + fx ) / 2.0;
	y_mid = ( iy + fy ) / 2.0;
	x_size = abs( ix - fx );
	y_size = abs( iy - fy );

	switch (shape)
	{
	case RECTANGLE:
		temp_shape = new Rectangle ( x_mid, y_mid, boundary, x_size, y_size );
		break;
	case FILLED_RECTANGLE:
		temp_shape = new FilledRectangle ( x_mid, y_mid, boundary, fill, x_size, y_size );
		break;
	case ELLIPSE:
		temp_shape = new Ellipse( x_mid, y_mid, boundary, x_size / 2, y_size / 2 );
		break;
	case FILLED_ELLIPSE:
		temp_shape = new FilledEllipse( x_mid, y_mid, boundary, fill, x_size / 2, y_size / 2 );
		break;
	case LINE:
		temp_shape = new Line( x_mid, y_mid, boundary, fx - ix, fy - iy );
		break;
	default:
		temp_shape = nullptr;
		break;
	}
	if (temp_shape != nullptr)
	{
		items.push_back(temp_shape);
		temp_shape->draw();
	}
}


/***************************************************************************//**
 * @author Cameron Javaheri, Matthew Schallenkamp
 *
 * @brief A function that determines which shape is currently selected.
 *
 * @param[in,out] items - A vector of shape pointers.
 * @param[in] prev_selection - The previous index for the vector containing shape pointers.
 * @param[in] x - The x-coordinate of the right mouse click.
 * @param[in] y - The y-coordinate of the right mouse click.
 *
 * @returns An index for the shape vector for the newly selected shape.
 *
 ******************************************************************************/
int selection(const vector<Shape *> &items, int prev_selection, int x, int y)
{
	float Centerx;
	float Centery;
	for (int i = items.size() - 1; i >= 0; i--)
	{
		Centerx = items[i]->getX();
		Centery = items[i]->getY();
		if (abs(Centerx - x) <= 20 && abs(Centery - y) <= 20)
		{
			return i;
		}
	}
	return prev_selection;
}

/***************************************************************************//**
 * @author Cameron Javaheri, Matthew Schallenkamp
 *
 * @brief An event function that handles mouse events from the user. It dynamically
 * allocates new shapes and draws them to the screen as needed.
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
	static vector<Shape *> items;

	if (key == '\0')
	{
		if( state == GLUT_DOWN )
		{
			//set initials for drags
			x_initial = x;
			y_initial = y;
			shape = Choose_Shape ( x, y, shape );

			if ( button == GLUT_LEFT_BUTTON ) //left button selects boundaries
			{
				boundary = Choose_Color ( x, y, boundary );
			}
			else if ( button == GLUT_RIGHT_BUTTON)
			{
				fill = Choose_Color ( x, y, fill ); //right button selects fill colors
				int index = selection(items, -1, x, y); //and items
				//move selected item to the front
				if(index != -1)
				{
					items.push_back(items[index]);
					items.erase(items.begin() + index);
					index = items.size() - 1;
					items[index]->draw();
				}
			}
			Preview_Box(shape, boundary, fill);
			glutSwapBuffers();
		}
		else if ( state == GLUT_UP )
		{
			if( button == GLUT_LEFT_BUTTON ) //left button up draws a shape
			{
				Insert_Shape(shape, items, boundary, fill, x_initial, y_initial, x, y);
				//need to keep palette on top
				Color_Palette();
				Preview_Box(shape, boundary, fill);
				glutSwapBuffers();
			}
			else if (button == GLUT_RIGHT_BUTTON)
			{
				//if the right click down was on a shape
				if (!items.empty() && abs(x_initial - items.back()->getX()) <= 20
				    && abs(y_initial - items.back()->getY()) <= 20)
				{
					//and we aren't under the pallete
					if(Choose_Shape(x, y, EMPTY) == EMPTY && Choose_Color(x, y, BLACK) == BLACK)
					{
						//move the shape and redraw
						items.back()->moveTo(x, y);
						Event('r', 0, 0, 0, 0);
					}
				}
			}
		}
	}
	else
	{
		//do key stuff
		switch (key)
		{
		case 'c': //clear out all of the items, freeing memory
			for(auto &s : items)
			{
				delete s;
			}
			items.clear();
		case 'd': //delete the currently selected item, from the back of the vector
			if (!items.empty())
			{
				delete items.back();
				items.pop_back();
			}
		case 'r': //redraw the screen
		default:
			//clear the screen
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//draw the screen
			for(auto &s : items)
			{
				s->draw();
			}
			Color_Palette();
			Preview_Box(shape, boundary, fill);
			glutSwapBuffers();
			break;
		}
	}
}

/***************************************************************************//**
 * @author Paul Hinker
 *
 * @brief A callback function for refreshing the display
 *
 ******************************************************************************/
void display()
{
	// Clear the window
	glClear ( GL_COLOR_BUFFER_BIT );
	glutInitWindowSize ( 1024, 999 );
	glutInitWindowPosition ( 100, 100 );
	//redraw using Events as with r keycode
	Event('r', 0, 0, 0, 0);
}


/***************************************************************************//**
 * @author Cameron Javaheri, Matthew Schallenkamp
 *
 * @brief A callback function for handling keyboard input
 *
 * @param[in] key - the key that was pressed
 * @param[in] x - the x-coordinate when the key was pressed
 * @param[in] y - the y-coordinate when the key was pressed
 *
 ******************************************************************************/
void keyboard ( unsigned char key, int x, int y )
{
	// Pressing the ESCAPE Key will exit from the main glut loop
	int ScreenHeight = glutGet ( GLUT_WINDOW_HEIGHT );
	y = ScreenHeight - y;
	if ( key == ESCAPE_KEY || key == 'q' || key == 'Q')
	{
		glutLeaveMainLoop();
		return;
	}
	Event(key, 0, 0, x, y);
}

/***************************************************************************//**
 * @author Cameron Javaheri, Matthew Schallenkamp
 *
 * @brief A callback function for handling mouse click events
 *
 * @param[in] button - the mouse button pushed
 * @param[in] state - the state of the button (i.e. GLUT_UP, GLUT_DOWN)
 * @param[in] x - the x-coordinate when the button is pressed
 * @param[in] y - the y-coordinate when the button is pressed
 *
 ******************************************************************************/
void mouseClick ( int button, int state, int x, int y )
{
	y = glutGet ( GLUT_WINDOW_HEIGHT ) - y;
	// \0 because there is no key pressed
	Event('\0', button, state, x, y);
}

/***************************************************************************//**
 * @author Matthew Schallenkamp
 *
 * @brief A callback function for handling reshape events
 *
 * @param[in] w - the width of the newly reshaped window
 * @param[in] h - the height of the newly reshaped window
 *
 ******************************************************************************/
void reshape ( int w, int h )
{

	glMatrixMode ( GL_PROJECTION ); // use an orthographic projection
	glLoadIdentity();  // initialize transformation matrix
	gluOrtho2D ( 0.0, w, 0.0, h ); // make OpenGL coordinates
	glViewport ( 0, 0, w, h ); // the same as the screen coordinates
	glutPostRedisplay();
}


