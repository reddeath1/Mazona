#ifndef _MAZONA_
#define _MAZONA_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define FALSE 0
#define TRUE 1

#define PI 3.14159265
#define PI2 6.28318530

#define WIN_WIDTH (MAP_COLS * TILE_SIZE)
#define WIN_HEIGHT (MAP_ROWS * TILE_SIZE)

#define TILE_SIZE 64
#define MAP_ROWS 19
#define MAP_COLS 19
#define TEXTURES_NUM 8
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64
#define ANGLE (60 * (PI / 180))
#define _RAYS WIN_WIDTH
#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define MINIMAP_SCALE_FACTOR 0.20

/* Declaration of Global Variables */

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

extern const int map[MAP_ROWS][MAP_COLS];

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern int isRunning;

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

struct Player
{
	float x;
	float y;
	float width;
	float height;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
};
extern struct Player p;

struct Ray {
    float rayAngle;
    float wallHitX;
    float wallHitY;
    float distance;
    int wasHitVertical;
    int isRayFacingUp;
    int isRayFacingDown;
    int isRayFacingLeft;
    int isRayFacingRight;
    int wallHitContent;
} rays[_RAYS];

extern struct Ray rays[_RAYS];
extern int ticksLastFrame;
extern Uint32 *colorBuffer;
extern SDL_Texture *colorBufferTexture;
extern Uint32 *wallTexture;
extern Uint32 *textures[TEXTURES_NUM];

/* methods */

int init(SDL_Instance *);
void render(SDL_Instance instance);
void displayRays(SDL_Instance instance);
void displayMap(SDL_Instance instance);
void castRays(float rayAngle, int counter);
int collisionDetect(float x, float y);
float distanceBetweenPoints(float x1, float y1, float x2, float y2);
void displayPlayer(SDL_Instance instance);

#endif /* _MAZONA_ */
