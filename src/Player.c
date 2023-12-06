#include "../headers/headers.h"
#include "../headers/textures.h"

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

/**
 * Player - sets characteristics of player
 * Return: Nothing
 */
void playerConfig(SDL_Instance instance)
{
    p.x = WIN_WIDTH / 2;
    p.y = WIN_HEIGHT / 2;
    p.width = 10;
    p.height = 10;
    p.turnDirection = 0;
    p.walkDirection = 0;
    p.rotationAngle = PI / 2;
    p.walkSpeed = 100;
    p.turnSpeed = 45 * (PI / 180);

    /* Allocating the total amount of bytes in memory to hold the color buffer */
    colorBuffer = (Uint32*) malloc(sizeof(Uint32) * (Uint32)WIN_WIDTH * (Uint32)WIN_HEIGHT);

    /* Creating an SDL_Texture to display the colorbuffer */
    colorTexture = SDL_CreateTexture(
        instance.renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WIN_WIDTH,
        WIN_HEIGHT
    );

    /* loading textures from the textures.h */
    textures[0] = (Uint32 *) TEXTURE4;
    textures[1] = (Uint32 *) TEXTURE3;
    textures[2] = (Uint32 *) TEXTURE4;
    textures[3] = (Uint32 *) TEXTURE1;
    textures[4] = (Uint32 *) TEXTURE1;
    textures[5] = (Uint32 *) TEXTURE2;
    textures[6] = (Uint32 *) TEXTURE4;
    textures[7] = (Uint32 *) TEXTURE4;
}

/**
 * update - updating the game movements
 * Return: nothing
 */
void update(void)
{
    float deltaTime;

    while (
        !SDL_TICKS_PASSED(SDL_GetTicks(),
        ticksLastFrame + FRAME_TIME_LENGTH)
    );

    deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    ticksLastFrame = SDL_GetTicks();
    move(deltaTime);
    displayAllRays();
}

/**
 * move - mova a player
 * @deltaTime: time
 * Return: nothing
 */
void move(float deltaTime)
{
    float moveStep, newPlayerX, newPlayerY;

    //deltaTime = 0.0010;
    p.rotationAngle += p.turnDirection * p.turnSpeed * 1.10 * deltaTime;

    moveStep = p.walkDirection * p.walkSpeed * deltaTime;

    newPlayerX = p.x + cos(p.rotationAngle) * moveStep;
    newPlayerY = p.y + sin(p.rotationAngle) * moveStep;

    if (!mapWall(newPlayerX, newPlayerY))
    {
        p.x = newPlayerX;
        p.y = newPlayerY;
    }
}
