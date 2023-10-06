#include "objects.h"

int main()
{
    /////////////////////////////////////////
    /* Create the window (Window dimensions)
     * @param1 is the width
     * @param2 is the height
     * @param3 is the name of the window
     */
    InitWindow(window_width, window_height, "Jump Game Ver 1.0");

    // Create the objects
    Object rectangle = {(Vector2){window_width - 25, window_height - 100}, (Vector2){25, 100}, RED};
    Object ball = {(Vector2){100, window_height - 25}, 25, BLUE};
    Object ball_lives = {(Vector2){10, 20}, 10, RED};

    // Boolean variables
    bool is_over{true},    // Variable to check if the game is over or not
        is_restart{false}; // Variable to check if the game is restarting

    // Variable to store score and lives
    int score{0};
    static int highest_score{score};
    int live_score{3};

    // Set the target Frame Per Second
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Start drawing
        BeginDrawing();
        ClearBackground(BLACK);
        // Start the game if press ENTER
        if (is_over)
        {
            // Start screen
            DrawText("Press ENTER to start the game!", window_width / 2 - 170, window_height / 2 - 100, 20, GREEN);
            if (IsKeyPressed(KEY_ENTER))
            {
                is_over = false;
            }
        }
        else if (is_restart)
        {
            is_restart = false;
            is_over = true;
        }
        else if (!ball.is_collision(rectangle, live_score))
        {
            DrawText(TextFormat("Score: %d", score), window_width / 2 - 50, window_height / 2 - 10, 20, YELLOW);
            DrawText(TextFormat("Highest Score: %d", highest_score), window_width / 2 - 50, window_height / 2 - 30, 20, YELLOW);
            if (rectangle.get_position().x <= 0)
            {
                ++score;
                if (score > highest_score)
                {
                    highest_score = score;
                }
            }
            // Draw the ball
            DrawCircleV(ball.get_position(), ball.get_radius(), ball.get_color());
            // Press SPACE to jump
            ball.ball_jump();
            // Draw the rectangle
            DrawRectangleV(rectangle.get_position(), rectangle.get_size(), rectangle.get_color());
            // Update rectangle position overtime
            rectangle.update_rec();
        }
        else
        {
            DrawText("LOST", window_width / 2 - 130, window_height / 2 - 50, 100, RED);
            DrawText("Press SPACE to restart the game!", window_width / 2 - 170, window_height / 2 + 100, 20, GREEN);
            if (IsKeyPressed(KEY_SPACE))
            {

                is_restart = true;
                score = 0;
                rectangle.set_position_rec(Vector2{window_width - 25, window_height - 100});
                ball.set_position_ball((Vector2){100, window_height - 25});
            }
        }

        // End drawing
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

/* Notes for restarting the game!!!!!!!!!!!!!!!!!!!!!
 * The reason why your program goes straight to the "LOST" phase and doesn't restart the game is
 * that you don't reset the ball's position and velocity when the game is restarted.
 * The ball stays at its last position, and the velocity of the ball remains the same as before,
 * causing the ball to collide with the rectangle again and immediately end the game.
 * To fix this, you can reset the ball's position and velocity when the game is restarted.
 */