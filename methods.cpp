#include "objects.h"
#define MOVESPEED 5

/*Constructors*/
// Rectangle constructor
Object::Object(Vector2 position, Vector2 size, Color color)
    : position{position}, rec_size{size}, color{color} {}

// Circle constructor
Object::Object(Vector2 position, float radius, Color color)
    : position{position}, radius{radius}, color{color} {}

/*Destructor*/
Object::~Object() {}

/*Methods*/
/*Function to get object position*/
Vector2 Object::get_position()
{
    return position;
}

/*Function to get rectangle size*/
Vector2 Object::get_size()
{
    return rec_size;
}

/*Function to get object color*/
Color Object::get_color()
{
    return color;
}

/*Function to get ball radius*/
float Object::get_radius()
{
    return radius;
}

/*Function to set rectangle position*/
void Object::set_position_rec(Vector2 pos)
{
    position.x = pos.x;
}

/*Function to set ball position*/
void Object::set_position_ball(Vector2 pos)
{
    position.y = pos.y;
}

/********Key pressed event********/
/*Function to move the rectangle*/
void Object::key_pressed_rec()
{
    if (IsKeyDown(KEY_A))
    {
        position.x -= MOVESPEED;
    }
    if (IsKeyDown(KEY_D))
    {
        position.x += MOVESPEED;
    }
    if (IsKeyDown(KEY_W))
    {
        position.y -= MOVESPEED;
    }
    if (IsKeyDown(KEY_S))
    {
        position.y += MOVESPEED;
    }
}

/*Function to move the ball*/
void Object::key_pressed_cir()
{
    if (IsKeyDown(KEY_A) && position.x - radius > 0)
    {
        position.x -= MOVESPEED;
    }
    if (IsKeyDown(KEY_D) && position.x + radius < window_width)
    {
        position.x += MOVESPEED;
    }
    if (IsKeyDown(KEY_W) && position.y - radius > 0)
    {
        position.y -= MOVESPEED;
    }
    if (IsKeyDown(KEY_S) && position.y + radius < window_height)
    {
        position.y += MOVESPEED;
    }
}

/**************************/
/*Variable for ball_jump()*/
float jump_velocity{0.0};
const float gravity{1.0};
bool is_jumping{false};
/**************************/
void Object::ball_jump()
{
    // Ground checking
    if (position.y + radius >= window_height)
    {
        // Ball is on the ground
        position.y = window_height - radius;
        jump_velocity = 0.0;
        is_jumping = false;
    }
    else
    {
        // Ball is in the air
        // Apply gravity
        jump_velocity += gravity;
        is_jumping = true;
    }

    // Jumping
    if (IsKeyPressed(KEY_SPACE) && !is_jumping)
    {
        jump_velocity = -20.0;
    }

    // Update ball position
    position.y += jump_velocity;
}

/*Function to update rectangle position and size*/
void Object::update_rec()
{
    srand((unsigned)time(NULL));
    float random_height = (4 + (rand() % 10)) * 10;
    if (position.x < 0)
    {
        position.x = window_width - 25;
        position.y = window_height - random_height;
        rec_size.y = window_height - random_height;
    }
    position.x -= 11.5;
}

// Check for collisions
bool Object::is_collision(Object obj, int &lives)
{
    if (CheckCollisionCircleRec(position, radius, { obj.get_position().x, obj.get_position().y, obj.get_size().x, obj.get_size().y }))
    {
        return true;
    }
    return false;
}
