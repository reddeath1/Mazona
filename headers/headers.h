#ifndef _HEADER_
#define _HEADER_

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
#define RAYS WIN_WIDTH
#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define MINIMAP_SCALE_FACTOR 0.20

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
} rays[RAYS];

extern struct Ray rays[RAYS];
extern int ticksLastFrame;
extern Uint32 *colorBuffer;
extern SDL_Texture *colorTexture;
extern Uint32 *wallTexture;
extern Uint32 *textures[TEXTURES_NUM];

void render(SDL_Instance instance);
void close(SDL_Instance instance);
int init(SDL_Instance *);
void Projection(void);
void displayMap(SDL_Instance instance);
void playerConfig(SDL_Instance instance);
void displayPlayer(SDL_Instance instance);
void displayRays(SDL_Instance instance);
void displayAllRays(void);
void clearColorBuffer(Uint32 color);
void castRay(float rayAngle, int counter);
int collisionDetect(float x, float y);
float distanceBetweenPoints(float x1, float y1, float x2, float y2);
void displayColorBuffer(SDL_Instance instance);
int events(void);
void update(void);
void move(float deltaTime);
int mapWall(float x, float y);

#endif /* _HEADER_ */
