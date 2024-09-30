#include "Display.h"
#include <cassert>

// DO NOT MODIFY THE DISPLAY CLASS!

Display::Display(int display_width, int display_height) : display_width_(display_width),
                                                          display_height_(display_height),
                                                          window_(display_width, display_height, "Graph Plotter")
{
    window_.SetTargetFPS(30);
}

void Display::drawLine(PointPair end_points, Colour colour)
{
    auto line_start = end_points.first();
    auto line_end = end_points.second();

    DrawLine(line_start.x, line_start.y, line_end.x, line_end.y, convertToRaylib(colour));
}

void Display::drawDot(Point point, Colour colour)
{
    DrawCircle(point.x, point.y, RADIUS, convertToRaylib(colour));
}

void Display::clear()
{
    window_.ClearBackground();
}

void Display::startDrawing()
{
    window_.BeginDrawing();
}

void Display::endDrawing()
{
    window_.EndDrawing();
}

void Display::pause()
{

    // Pause display until user presses the space bar to continue
    // or the escape key to end the program
    while (!IsKeyPressed(KEY_SPACE))
    {
        // continue rendering the display (swapping buffers)
        window_.BeginDrawing();
        window_.EndDrawing();

        // End the program if the Escape key is pressed to close the window
        // or the window close button is pressed
        if (IsKeyPressed(KEY_ESCAPE) || window_.ShouldClose())
        {
            window_.Close();
            break;
        }
    }
}

raylib::Color Display::convertToRaylib(Colour colour) const
{
    auto drawing_colour = raylib::Color{};
    switch (colour)
    {
    case (Colour::Red):
        drawing_colour = raylib::Color::Red();
        break;
    case (Colour::Green):
        drawing_colour = raylib::Color::Green();
        break;
    case (Colour::Blue):
        drawing_colour = raylib::Color::Blue();
        break;
    default:
        assert(false);
    }
    return drawing_colour;
}
