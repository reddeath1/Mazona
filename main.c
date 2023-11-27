#include "../inc/headers.h"


struct Player p;
struct Ray rays[_RAYS];
int ticksLastFrame;
uint32_t *colorBuffer = NULL;
SDL_Texture *colorBufferTexture;
Uint32 *wallTexture = NULL;
Uint32 *textures[NUM_TEXTURES];

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

	/* Loop */
	while ()
	{
		SDL_RenderClear(instance.renderer);

		/* Retrieving Input Events */
		if (poll_events() == 1)
			break;

		/* Rendering */
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255);
		SDL_RenderClear(instance.renderer);

		renderColorBuffer(instance);
		clearColorBuffer(0xFF000000);

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