#include "callbacks.h"

/***************************************************************************//**
 * @author Paul Hinker
 *
 * @brief A callback function for refreshing the display
 ******************************************************************************/


void Color_Palette()
{
    DrawFilledRectangle(0, 0, 50, 50, Grey);
    DrawFilledRectangle(0, 50, 50, 100, Red);
    DrawFilledRectangle(0, 100, 50, 150, Green);
    DrawFilledRectangle(0, 150, 50, 200, Blue);
    DrawFilledRectangle(0, 200, 50, 250, Magenta);
    DrawFilledRectangle(0, 250, 50, 300, Cyan);
    DrawFilledRectangle(0, 300, 50, 350, Yellow);
    DrawFilledRectangle(0, 350, 50, 400, White);

}

void Choose_Color(int button, int state, int x, int y)
{
    if (x >= 0 && x <= 50 && y >= 0 && y < 50)
    {
        DrawFilledRectangle(200, 200, 300, 300, Grey);
        glutSwapBuffers();
    }
    else if (x >= 0 && x <= 50 && y >= 50 && y < 100)
    {
        DrawFilledRectangle(200, 200, 300, 300, Red);
        glutSwapBuffers();
    }
    else if (x >= 0 && x <= 100 && y >= 100 && y < 150)
    {
        DrawFilledRectangle(200, 200, 300, 300, Green);
        glutSwapBuffers();
    }
    else if (x >= 0 && x <= 50 && y >= 150 && y < 200)
    {
        DrawFilledRectangle(200, 200, 300, 300, Blue);
        glutSwapBuffers();
    }
    else if (x >= 0 && x <= 50 && y >= 200 && y < 250)
    {
        DrawFilledRectangle(200, 200, 300, 300, Magenta);
        glutSwapBuffers();
    }
    else if (x >= 0 && x <= 50 && y >= 250 && y < 300)
    {
        DrawFilledRectangle(200, 200, 300, 300, Cyan);
        glutSwapBuffers();
    }
    else if (x >= 0 && x <= 50 && y >= 300 && y < 350)
    {
        DrawFilledRectangle(200, 200, 300, 300, Yellow);
        glutSwapBuffers();
    }
    else if (x >= 0 && x <= 50 && y >= 350 && y < 400)
    {
        DrawFilledRectangle(200, 200, 300, 300, White);
        glutSwapBuffers();
    }

}


void display()
{
    // Clear the window
    glClear(GL_COLOR_BUFFER_BIT);

    glutInitWindowSize(1024, 999);
    glutInitWindowPosition(100, 100);

    Color_Palette();

    // DrawLine( 10, 20, glutGet(GLUT_WINDOW_WIDTH) - 10,
    //         glutGet(GLUT_WINDOW_HEIGHT) - 20, Yellow );
    // DrawRectangle( 500, 400, 700, 500, Cyan );
    // DrawFilledRectangle( 200, 100, 300, 300, Red );
    //  DrawEllipse( 100, 50, 600, 200, Green );
    // DrawFilledEllipse( 100, 50, 250, 450, Magenta );

    // label display with text
    DrawTextString( "OpenGL Demo", 32, 800 - 32, White );

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
void keyboard(unsigned char key, int x, int y)
{
    // Pressing the ESCAPE Key will exit from the main glut loop

    int ScreenHeight = glutGet(GLUT_WINDOW_HEIGHT);

    y = ScreenHeight - y;

    if (key == ESCAPE_KEY)
        glutLeaveMainLoop();
    else
        cout << "Key " << (char)key << " press detected at ["
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
void mouseClick(int button, int state, int x, int y)
{
    static int x_coordinate1;
    static int y_coordinate1;
    static int x_coordinate2;
    static int y_coordinate2;

    y = glutGet(GLUT_WINDOW_HEIGHT) - y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x_coordinate1 = x;
        y_coordinate1 = y;
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        x_coordinate2 = x;
        y_coordinate2 = y;
        Rectangle rect((x_coordinate1 + x_coordinate2) / 2, (y_coordinate1 + 	y_coordinate2) / 2, MAGENTA , x_coordinate2 - x_coordinate1, y_coordinate2 - y_coordinate1);
        Shape * some_shape = &rect;
        some_shape->draw();

    }
    // Mouse functionality for color palette.
    Choose_Color(button, state, x, y);
    cout << "MouseClick: Button = " << ButtonName[button] << " : State = "
         << ButtonState[state] << " : Location [" << x << ", " << y << "]\n";
}

/***************************************************************************//**
 * @brief A callback function for handling reshape events
 *
 * @param[in] w      - the width of the newly reshaped window
 * @param[in] h      - the height of the newly reshaped window
 ******************************************************************************/
void reshape(int w, int h)
{
    glMatrixMode( GL_PROJECTION );      // use an orthographic projection
    glLoadIdentity();                   // initialize transformation matrix
    gluOrtho2D( 0.0, w, 0.0, h );       // make OpenGL coordinates
    glViewport( 0, 0, w, h );           // the same as the screen coordinates
}
