#ifndef TETROMINO_H
#define TETROMINO_H

#include "stdafx.h"

using namespace sf;

const float tetroScaleConstant = 40.f;

struct MinoBlock
{
	RectangleShape shape;
	Vector2u coord;

	MinoBlock()
		: shape(), coord(Vector2u(0, 0))
	{}

	void move(const Vector2f &offset)
	{
		shape.move(offset);

		coord.x += 1 * offset.x / tetroScaleConstant;
		coord.y += -1 * offset.y / tetroScaleConstant; // Multiply -1 because the y direction is opposite in window and grid plane
	}
};

class Tetromino
{
public:
	Tetromino();
	Tetromino(Vector2f pos, Vector2u coords, unsigned int type);
	~Tetromino();
	
	void move(float offsetX, float offsetY);
	void rotate();
	void draw(RenderWindow* target);

	// Accessors
	unsigned int getBottomY(); // Returns the y coordinate of the bottom piece
	unsigned int getLefmosttX();
	unsigned int getRightmostX();

	void printCoords()
	{
		printf("[%u,%u] [%u,%u] [%u,%u] [%u,%u]\n", blocks[0].coord.x, blocks[0].coord.y, blocks[1].coord.x, blocks[1].coord.y, blocks[2].coord.x, blocks[2].coord.y, blocks[3].coord.x, blocks[3].coord.y);
	}
private:
	MinoBlock* blocks;
	unsigned int type;
	unsigned int rotationState;

	void initShape(Vector2f pos, Vector2u coords);
};

#endif
