#include "../headers/headers.h"

/**
 * mapWall - detects wall collision
 * @x: position x
 * @y: position y
 * Return: 0 if true, 1 if false
 */
int mapWall(float x, float y)
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
* displayMap - display the map
* @instance: sdl instance
*/
void displayMap(SDL_Instance instance)
{
	int i, j;
	int tileX, tileY, tileColor;

	for (i = 0; i < MAP_ROWS; i++)
	{
		for (j = 0; j < MAP_COLS; j++)
		{
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			tileColor = map[i][j] != 0 ? 255 : 0;

			SDL_SetRenderDrawColor(instance.renderer, tileColor, tileColor, tileColor, 255);
			SDL_Rect mapTileRect = {
				tileX * MINIMAP_SCALE_FACTOR,
				tileY * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR
			};
			SDL_RenderFillRect(instance.renderer, &mapTileRect);
		}
	}
}
