/* Author: Quang Hung Bui
 * Description: This is my first game that I make from scratch.
 * This game is about jumping to avoid any obstacles coming towards players
 * ----------------------------------------------------------------
 * Date Modified: 07/26/2023 (I tried to create lives for players, but failed, I will try later)
 * Number of functions: 12
 * ----------------------------------------------------------------
 * Plan in the future:
 * - Make obstacles have random velocity
 * - Create lives of the player
 * ----------------------------------------------------------------
 */

#ifndef _OBJECT_H_
#define _OBJECT_H_
#include "raylib.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#define window_width 512
#define window_height 380

class Object
{
    // Object attributes
private:
    Vector2 position; // Position of the object (x,y coordinates)
    Vector2 rec_size; // Size of the rectangle (width, height)
    float radius;     // Radius of the ball
    Color color;      // Color of any objects
    int score;        // Score of the object
    int lives;

public:
    /*Constructors*/
    // Rectangles constructor
    Object(Vector2 position, Vector2 size, Color color);

    // Circles constructor
    Object(Vector2 position, float radius, Color color);

    /*Destructor*/
    ~Object();

    /*Methods*/
    // Getters
    Vector2 get_position();
    Vector2 get_size();
    Color get_color();
    float get_radius();

    // Setters
    void set_position_rec(Vector2 pos);
    void set_position_ball(Vector2 pos);

    // Other methods
    void key_pressed_rec();
    void key_pressed_cir();
    void ball_jump();
    void update_rec();
    bool is_collision(Object obj, int &lives);
    void show_points(Object obj);
};

#endif