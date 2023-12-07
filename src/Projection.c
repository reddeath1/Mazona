#include "../headers/headers.h"

/**
 * Projection - projection creation
 * Return: Nothing
 */
void Projection(void)
{
    int i, y;
    float perDistance, distanceProjPlane, projectedWallHeight;
    int wallStripHeight, wallTopPixel, wallBottomPixel;
    int textureOffsetX;
    int distanceFromTop, textureOffsetY;
    Uint32 texelColor;
    (void)texelColor;
    int texNum;

    for (i = 0; i < RAYS; i++)
    {
        perDistance = rays[i].distance * cos(rays[i].rayAngle - p.rotationAngle);
        distanceProjPlane = (WIN_WIDTH / 2) / tan(ANGLE / 2);
        projectedWallHeight = (TILE_SIZE / perDistance) * distanceProjPlane;

        wallStripHeight = (int)projectedWallHeight;

        wallTopPixel = (WIN_HEIGHT / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

        wallBottomPixel = (WIN_HEIGHT / 2) + (wallStripHeight / 2);
        wallBottomPixel = wallBottomPixel > WIN_HEIGHT ? WIN_HEIGHT : wallBottomPixel;

        /* Ceiling */
        for (y = 0; y < wallTopPixel; y++)
            colorBuffer[(WIN_WIDTH * y) + i] = 0x006400;

        /* calculate texture offset X */
        if (rays[i].wasHitVertical)
            textureOffsetX = (int)rays[i].wallHitY % TEXTURE_HEIGHT;
        else
            textureOffsetX = (int)rays[i].wallHitX % TEXTURE_WIDTH;

        /* getting the correct texture id number from the map */
        texNum = rays[i].wallHitContent - 1;

        /* rendering the wall from wallTopPixel to wallBottomPixel */
        for (y = wallTopPixel; y < wallBottomPixel; y++)
        {
            /* calculating texture offset Y */
            distanceFromTop = y + (wallStripHeight / 2) - (WIN_HEIGHT / 2);
            textureOffsetY = distanceFromTop * ((float) TEXTURE_HEIGHT / wallStripHeight);

            /* setting the color of the wall based on the color from the texture */
            Uint32 texelColor = textures[texNum][(TEXTURE_WIDTH * textureOffsetY) + textureOffsetX];
            colorBuffer[(WIN_WIDTH * y) + i] = texelColor;
        }

        /* set the color of the floor */
        for (y = wallBottomPixel; y < WIN_HEIGHT; y++){
            colorBuffer[(WIN_WIDTH * y) + i] = 0x555555;
        }

        /* This For Having No Sky and Replacing It With Taller Walls */
        for (y = 0; y < wallTopPixel; y++)
        {
            colorBuffer[(WIN_WIDTH * y) + i] = rays[i].wasHitVertical ? 0xFF87CEEB : 0xFF87CEEB;
        }
    }
}

