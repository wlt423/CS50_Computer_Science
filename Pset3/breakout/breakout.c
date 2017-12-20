//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 500
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

double y;
// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);


int main(void)
{
    
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
    srand48((long int) time(NULL));
    double hvelocity =  2;
    double wvelocity =  2*drand48();
    waitForClick();
    while (lives > 0 && points < 50)
    {
        GLabel initScoreboard(GWindow window);
        GEvent event = getNextEvent(MOUSE_EVENT);// TODO
        if (event != NULL)
        {
            if (getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event) - getWidth(paddle) ;
                if (x < 50)                
                    setLocation(paddle, 0, 480);
                else
                    setLocation(paddle, x, 480);
            }
        }
        
        move(ball, wvelocity, hvelocity);
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            
            wvelocity = -wvelocity;       
        }
        else if (getX(ball) <= 0)
        {
            
            wvelocity = -wvelocity;
        }
        else if (getY(ball) <= 0)
        {
            hvelocity = -hvelocity;
            
        }
        else if (getY(ball) >= getHeight(window))
        {
            lives = lives - 1;
            waitForClick();
            setLocation(ball, 200 - 25/2, 300 - 25/2);
            setLocation(paddle, 175, 480);
        }
        GObject object = detectCollision(window, ball);
        if (object == paddle)
        {
            hvelocity = - hvelocity;
        }
        if (strcmp(getType(object), "GRect") == 0 && object != label && object !=paddle)          
        {
        removeGWindow(window, object);
        hvelocity = -hvelocity;
        points = points + 1;
        updateScoreboard(window, label, points);
        }
        
        pause(5);
        
   
    }
if(points == 50)
        {
        GLabel Wlabel = newGLabel("You Win!");
        add(window, label);
        setLocation(label, 196, 300);  
        setLabel(label, "You Win!");
        removeGWindow(window, ball);
       
        }
        else if(lives == 0)
        {
        GLabel Llabel = newGLabel("You Lose!");
        add(window, label);
        setLocation(label, 196, 300);  
        setLabel(label, "You Lose!");
        removeGWindow(window, ball);
        }                        
    
    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    for (int j = 0; j < ROWS; j++)
    {
        int h = j * 18;   
        for (int i=0; i < COLS; i++)
        {
            int w = 1 + (i * (400 / COLS ));
            GRect Brick= newGRect(w, h, 37, 15);
            setFilled(Brick, true);  
            add(window, Brick);
            
        }
    }
    
   
   
    // TODO
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball= newGOval(200 - 25/2, 300 - 25/2, 25, 25);
            setFilled(ball, true);  
            add(window, ball);
            return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect(175, 480, 50, 20);
    setFilled(paddle, true);
   
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel(" ");
    add(window, label);
    setLocation(label, 200, 300);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
