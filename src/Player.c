#include "../headers/headers.h"

/**
 * collisionDetect - detects wall collision
 * @x: position x
 * @y: position y
 * Return: 0 if true, 1 if false
 */
int collisionDetect(float x, float y)
{
    int mapGridIndexX, mapGridIndexY;

    if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT) {
        return (FALSE);
    }
    mapGridIndexX = floor(x / TILE_SIZE);
    mapGridIndexY = floor(y / TILE_SIZE);
    return (map[mapGridIndexY][mapGridIndexX] != 0);
}

/**
 * displayPlayer - display the player
 * @instance: sdl instance
 * Returns: nothing
 */
void displayPlayer(SDL_Instance instance)
{
    SDL_SetRenderDrawColor(instance.renderer, 255, 255, 255, 255);
    SDL_Rect playerRect = {
        p.x * MINIMAP_SCALE_FACTOR,
        p.y * MINIMAP_SCALE_FACTOR,
        p.width * MINIMAP_SCALE_FACTOR,
        p.height * MINIMAP_SCALE_FACTOR
    };
    SDL_RenderFillRect(instance.renderer, &playerRect);

    SDL_RenderDrawLine(
        instance.renderer,
        MINIMAP_SCALE_FACTOR * p.x,
        MINIMAP_SCALE_FACTOR * p.y,
        MINIMAP_SCALE_FACTOR * (p.x + cos(p.rotationAngle) * 40),
        MINIMAP_SCALE_FACTOR * (p.y + sin(p.rotationAngle) * 40)
    );
}
