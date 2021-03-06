#include "Sierpinski.h"
using namespace std;

/**
 * Draws a triangle with the specified corners in the specified window. Feel free
 * to edit this function as you see fit to change things like color, fill style,
 * etc. in whatever way you'd like!
 *
 * @param window The window in which to draw the triangle.
 * @param p0 The first corner of the triangle.
 * @param p1 The second corner of the triangle.
 * @param p2 The third corner of the triangle.
 */
void drawTriangle(GWindow& window,
                  GPoint p0, GPoint p1, GPoint p2) {
    window.setColor("black");
    window.fillPolygon({ p0.getX(), p0.getY(),
                         p1.getX(), p1.getY(),
                         p2.getX(), p2.getY() });
}

/* TODO: Refer to Sierpinski.h for more information about what this function should do.
 * Then, delete this comment.
 */

void drawSierpinskiTriangle(GWindow& window,
                            GPoint p0, GPoint p1, GPoint p2,
                            int order) {
    /* TODO: Delete this comment, these next lines of code, and implement this function. */
    //(void) window;
    //(void) p0;
    //(void) p1;
    //(void) p2;
    //(void) order;

    if(order < 0){
        error("Order should be at leats 0!");
    }
    if(order == 0){
        drawTriangle(window, p0, p1, p2);
    }
    else {
        //create 3 triangles
        GPoint p_0 = p0;
        GPoint p_1 = {(p0.getX()+p1.getX())/2, (p0.getY()+p1.getY())/2};
        GPoint p_2 = {(p2.getX()+p0.getX())/2, (p2.getY()+p0.getY())/2};

        drawSierpinskiTriangle(window, p_0, p_1, p_2, order-1);
        p_0 = p_1;
        p_1 = p1;
        p_2 = {(p2.getX()+p1.getX())/2, (p2.getY()+p1.getY())/2};
        drawSierpinskiTriangle(window, p_0, p_1, p_2, order-1);
        p_0 = {(p2.getX()+p0.getX())/2, (p2.getY()+p0.getY())/2};;
        p_1 = p_2;
        p_2 = p2;
        drawSierpinskiTriangle(window, p_0, p_1, p_2, order-1);
    }
}
