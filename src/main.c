#include "../headers/headers.h"

const int map[MAP_ROWS][MAP_COLS] = {
    {7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 8, 8, 8, 8, 8},
    {7, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8},
    {7, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 8, 8, 8, 0, 1, 0, 8},
    {7, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 8, 0, 0, 0, 1, 0, 8},
    {7, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 8, 0, 1, 1, 1, 0, 8},
    {2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 8, 0, 1, 0, 0, 0, 8},
    {2, 2, 2, 2, 2, 0, 1, 0, 8, 8, 8, 8, 8, 0, 1, 0, 7, 7, 7},
    {2, 0, 0, 0, 2, 0, 1, 0, 8, 0, 0, 0, 0, 0, 1, 0, 7, 0, 7},
    {2, 0, 2, 0, 2, 1, 1, 0, 8, 0, 8, 8, 8, 8, 8, 0, 7, 0, 7},
    {2, 0, 2, 0, 2, 0, 0, 0, 8, 0, 0, 0, 0, 0, 8, 0, 7, 0, 7},
    {2, 0, 2, 0, 2, 0, 1, 0, 8, 8, 8, 8, 8, 0, 8, 0, 7, 0, 7},
    {2, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 8, 0, 7, 0, 7},
	{2, 0, 2, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 8, 0, 7, 0, 7},
	{2, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 7, 0, 7},
	{2, 0, 2, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 7, 0, 7},
	{2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 7},
	{2, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 7},
	{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
	{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
};

struct Player p;
struct Ray rays[RAYS];
int ticksLastFrame;
uint32_t *colorBuffer = NULL;
SDL_Texture *colorTexture;
Uint32 *wallTexture = NULL;
Uint32 *textures[TEXTURES_NUM];

/**
* main - main function
* Return: always 0.
*/
int main(void)
{
	SDL_Instance instance;

	/* Initializing the Window and Render */
	if (init(&instance) != 0)
		return (1);

    /* Setting up Player */
    playerConfig(instance);

	/* Loop */
	while ("is running")
	{
		SDL_RenderClear(instance.renderer);

		/* Retrieving Input Events */
		if (events() == 1)
			break;

        update();

		/* Rendering */
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255);
		SDL_RenderClear(instance.renderer);

        Projection();

		displayColorBuffer(instance);
		clearColorBuffer(0xFF000000);

        displayPlayer(instance);
		displayMap(instance);
        displayRays(instance);

		SDL_RenderPresent(instance.renderer);
	}
	free(wallTexture);
	free(colorBuffer);
	/* Render and Window destroy before quitting */
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}
