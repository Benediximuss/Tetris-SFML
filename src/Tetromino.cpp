#include "stdafx.h"
#include "Tetromino.h"

Tetromino::Tetromino()
	: blocks(nullptr), type(0), rotationState(0) {}

Tetromino::Tetromino(Vector2f pos, Vector2u coords, unsigned int type)
{
	rotationState = 0;
	this->type = type;
	blocks = new MinoBlock[4];
	initShape(pos, coords);
}

Tetromino::~Tetromino()
{
	// No need to free memory
}

void Tetromino::initShape(Vector2f pos, Vector2u coords)
{	
	int k = 0;
	while (k < 4)
	{
		blocks[k].shape = RectangleShape(Vector2f(39.f, 39.f));
		blocks[k].shape.setOutlineThickness(1.f);
		blocks[k].shape.setOutlineColor(Color(86, 101, 115, 255));
		k++;
	}

	if (type == 0) // Type "I"
	{
		blocks[0].shape.setPosition(pos);
		blocks[0].coord = coords;

		blocks[1].shape.setPosition(pos.x + tetroScaleConstant, pos.y);
		blocks[1].coord.x = coords.x + 1;
		blocks[1].coord.y = coords.y;

		blocks[2].shape.setPosition(pos.x + 2 * tetroScaleConstant, pos.y);
		blocks[2].coord.x = coords.x + 2;
		blocks[2].coord.y = coords.y;

		blocks[3].shape.setPosition(pos.x + 3 * tetroScaleConstant, pos.y);
		blocks[3].coord.x = coords.x + 3;
		blocks[3].coord.y = coords.y;

		blocks[0].shape.setFillColor(Color::Cyan);
		blocks[1].shape.setFillColor(Color::Cyan);
		blocks[2].shape.setFillColor(Color::Cyan);
		blocks[3].shape.setFillColor(Color::Cyan);
	}
	else if (type == 1) // Type "J"
	{
		blocks[0].shape.setPosition(pos.x, pos.y - tetroScaleConstant);
		blocks[0].coord.x = coords.x;
		blocks[0].coord.y = coords.y + 1;

		blocks[1].shape.setPosition(pos);
		blocks[1].coord = coords;

		blocks[2].shape.setPosition(pos.x + tetroScaleConstant, pos.y);
		blocks[2].coord.x = coords.x + 1;
		blocks[2].coord.y = coords.y;

		blocks[3].shape.setPosition(pos.x + 2 * tetroScaleConstant, pos.y);
		blocks[3].coord.x = coords.x + 2;
		blocks[3].coord.y = coords.y;

		blocks[0].shape.setFillColor(Color::Blue);
		blocks[1].shape.setFillColor(Color::Blue);
		blocks[2].shape.setFillColor(Color::Blue);
		blocks[3].shape.setFillColor(Color::Blue);
	}
	else if (type == 2) // Type "L"
	{
		blocks[0].shape.setPosition(pos);
		blocks[0].coord = coords;

		blocks[1].shape.setPosition(pos.x + tetroScaleConstant, pos.y);
		blocks[1].coord.x = coords.x + 1;
		blocks[1].coord.y = coords.y;

		blocks[2].shape.setPosition(pos.x + 2 * tetroScaleConstant, pos.y);
		blocks[2].coord.x = coords.x + 2;
		blocks[2].coord.y = coords.y;

		blocks[3].shape.setPosition(pos.x + 2 * tetroScaleConstant, pos.y - tetroScaleConstant);
		blocks[3].coord.x = coords.x + 2;
		blocks[3].coord.y = coords.y + 1;

		blocks[0].shape.setFillColor(Color(255, 165, 0, 255)); // ORANGE
		blocks[1].shape.setFillColor(Color(255, 165, 0, 255));
		blocks[2].shape.setFillColor(Color(255, 165, 0, 255));
		blocks[3].shape.setFillColor(Color(255, 165, 0, 255));
	}
	else if (type == 3) // Type "O"
	{
		// Offset of shape "O" in 2x4 Tetromino Grid  
		pos.x += tetroScaleConstant;
		coords.x += 1;

		blocks[0].shape.setPosition(pos.x, pos.y - tetroScaleConstant);
		blocks[0].coord.x = coords.x;
		blocks[0].coord.y = coords.y + 1;

		blocks[1].shape.setPosition(pos.x + tetroScaleConstant, pos.y - tetroScaleConstant);
		blocks[1].coord.x = coords.x + 1;
		blocks[1].coord.y = coords.y + 1;

		blocks[2].shape.setPosition(pos);
		blocks[2].coord = coords;

		blocks[3].shape.setPosition(pos.x + tetroScaleConstant, pos.y);
		blocks[3].coord.x = coords.x + 1;
		blocks[3].coord.y = coords.y;

		blocks[0].shape.setFillColor(Color::Yellow);
		blocks[1].shape.setFillColor(Color::Yellow);
		blocks[2].shape.setFillColor(Color::Yellow);
		blocks[3].shape.setFillColor(Color::Yellow);
	}
	else if (type == 4) // Type "S"
	{
		blocks[0].shape.setPosition(pos);
		blocks[0].coord = coords;

		blocks[1].shape.setPosition(pos.x + tetroScaleConstant, pos.y);
		blocks[1].coord.x = coords.x + 1;
		blocks[1].coord.y = coords.y;

		blocks[2].shape.setPosition(pos.x + tetroScaleConstant, pos.y - tetroScaleConstant);
		blocks[2].coord.x = coords.x + 1;
		blocks[2].coord.y = coords.y + 1;

		blocks[3].shape.setPosition(pos.x + 2 * tetroScaleConstant, pos.y - tetroScaleConstant);
		blocks[3].coord.x = coords.x + 2;
		blocks[3].coord.y = coords.y + 1;

		blocks[0].shape.setFillColor(Color::Green);
		blocks[1].shape.setFillColor(Color::Green);
		blocks[2].shape.setFillColor(Color::Green);
		blocks[3].shape.setFillColor(Color::Green);
	}
	else if (type == 5) // Type "T"
	{
		blocks[0].shape.setPosition(pos);
		blocks[0].coord = coords;

		blocks[1].shape.setPosition(pos.x + tetroScaleConstant, pos.y);
		blocks[1].coord.x = coords.x + 1;
		blocks[1].coord.y = coords.y;

		blocks[2].shape.setPosition(pos.x + tetroScaleConstant, pos.y - tetroScaleConstant);
		blocks[2].coord.x = coords.x + 1;
		blocks[2].coord.y = coords.y + 1;

		blocks[3].shape.setPosition(pos.x + 2 * tetroScaleConstant, pos.y);
		blocks[3].coord.x = coords.x + 2;
		blocks[3].coord.y = coords.y;

		blocks[0].shape.setFillColor(Color::Magenta);
		blocks[1].shape.setFillColor(Color::Magenta);
		blocks[2].shape.setFillColor(Color::Magenta);
		blocks[3].shape.setFillColor(Color::Magenta);
	}
	else if (type == 6) // Type "Z"
	{
		blocks[0].shape.setPosition(pos.x, pos.y - tetroScaleConstant);
		blocks[0].coord.x = coords.x;
		blocks[0].coord.y = coords.y + 1;

		blocks[1].shape.setPosition(pos.x + tetroScaleConstant, pos.y - tetroScaleConstant);
		blocks[1].coord.x = coords.x + 1;
		blocks[1].coord.y = coords.y + 1;

		blocks[2].shape.setPosition(pos.x + tetroScaleConstant, pos.y);
		blocks[2].coord.x = coords.x + 1;
		blocks[2].coord.y = coords.y;

		blocks[3].shape.setPosition(pos.x + 2 * tetroScaleConstant, pos.y);
		blocks[3].coord.x = coords.x + 2;
		blocks[3].coord.y = coords.y;

		blocks[0].shape.setFillColor(Color::Red);
		blocks[1].shape.setFillColor(Color::Red);
		blocks[2].shape.setFillColor(Color::Red);
		blocks[3].shape.setFillColor(Color::Red);
	}
}

void Tetromino::move(float offsetX, float offsetY)
{
	int k = 0;
	while (k < 4)
	{
		blocks[k].move(Vector2f(offsetX, offsetY));
		k++;
	}
}

void Tetromino::rotate()
{
	if (type == 0) // Type "I"
	{
		if (rotationState == 0)
		{
			blocks[0].move(Vector2f(2 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[1].move(Vector2f(1 * tetroScaleConstant, 0));
			blocks[2].move(Vector2f(0, 1 * tetroScaleConstant));
			blocks[3].move(Vector2f(-1 * tetroScaleConstant, 2 * tetroScaleConstant));
			rotationState = 1;
		}
		else if (rotationState == 1)
		{
			blocks[0].move(Vector2f(1 * tetroScaleConstant, 2 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 1 * tetroScaleConstant));
			blocks[2].move(Vector2f(-1 * tetroScaleConstant, 0));
			blocks[3].move(Vector2f(-2 * tetroScaleConstant, -1 * tetroScaleConstant));
			rotationState = 2;
		}
		else if (rotationState == 2)
		{
			blocks[0].move(Vector2f(-2 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[1].move(Vector2f(-1 * tetroScaleConstant, 0));
			blocks[2].move(Vector2f(0, -1 * tetroScaleConstant));
			blocks[3].move(Vector2f(1 * tetroScaleConstant, -2 * tetroScaleConstant));
			rotationState = 3;
		}
		else if (rotationState == 3)
		{
			blocks[0].move(Vector2f(-1 * tetroScaleConstant, -2 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, -1 * tetroScaleConstant));
			blocks[2].move(Vector2f(1 * tetroScaleConstant, 0));
			blocks[3].move(Vector2f(2 * tetroScaleConstant, 1 * tetroScaleConstant));
			rotationState = 0;
		}
	}
	else if (type == 1) // Type "J"
	{
		if (rotationState == 0)
		{
			blocks[0].move(Vector2f(2 * tetroScaleConstant, 0));
			blocks[1].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[2].move(Vector2f(0, 0));
			blocks[3].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			rotationState = 1;
		}
		else if (rotationState == 1)
		{
			blocks[0].move(Vector2f(0, 2 * tetroScaleConstant));
			blocks[1].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[2].move(Vector2f(0, 0));
			blocks[3].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			rotationState = 2;
		}
		else if (rotationState == 2)
		{
			blocks[0].move(Vector2f(-2 * tetroScaleConstant, 0));
			blocks[1].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[2].move(Vector2f(0, 0));
			blocks[3].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			rotationState = 3;
		}
		else if (rotationState == 3)
		{
			blocks[0].move(Vector2f(0, -2 * tetroScaleConstant));
			blocks[1].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[2].move(Vector2f(0, 0));
			blocks[3].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			rotationState = 0;
		}
	}
	else if (type == 2) // Type "L"
	{
		if (rotationState == 0)
		{
			blocks[0].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[3].move(Vector2f(0, 2 * tetroScaleConstant));
			rotationState = 1;
		}
		else if (rotationState == 1)
		{
			blocks[0].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[3].move(Vector2f(-2 * tetroScaleConstant, 0));
			rotationState = 2;
		}
		else if (rotationState == 2)
		{
			blocks[0].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[3].move(Vector2f(0, -2 * tetroScaleConstant));
			rotationState = 3;
		}
		else if (rotationState == 3)
		{
			blocks[0].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[3].move(Vector2f(2 * tetroScaleConstant, 0));
			rotationState = 0;
		}
	}
	else if (type == 3) // Type "O"
	{
		std::cout << "NO ROTATION!\n";
	}
	else if (type == 4) // Type "S"
	{
		if (rotationState == 0)
		{
			blocks[0].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[3].move(Vector2f(0, 2 * tetroScaleConstant));
			rotationState = 1;
		}
		else if (rotationState == 1)
		{
			blocks[0].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[3].move(Vector2f(-2 * tetroScaleConstant, 0));
			rotationState = 2;
		}
		else if (rotationState == 2)
		{
			blocks[0].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[3].move(Vector2f(0, -2 * tetroScaleConstant));
			rotationState = 3;
		}
		else if (rotationState == 3)
		{
			blocks[0].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[3].move(Vector2f(2 * tetroScaleConstant, 0));
			rotationState = 0;
		}
	}
	else if (type == 5) // Type "T"
	{
		if (rotationState == 0)
		{
			blocks[0].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[3].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			rotationState = 1;
		}
		else if (rotationState == 1)
		{
			blocks[0].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[3].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			rotationState = 2;
		}
		else if (rotationState == 2)
		{
			blocks[0].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[3].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			rotationState = 3;
		}
		else if (rotationState == 3)
		{
			blocks[0].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[1].move(Vector2f(0, 0));
			blocks[2].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[3].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			rotationState = 0;
		}
	}
	else if (type == 6) // Type "Z"
	{
		if (rotationState == 0)
		{
			blocks[0].move(Vector2f(2 * tetroScaleConstant, 0));
			blocks[1].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[2].move(Vector2f(0, 0));
			blocks[3].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			rotationState = 1;
		}
		else if (rotationState == 1)
		{
			blocks[0].move(Vector2f(0, 2 * tetroScaleConstant));
			blocks[1].move(Vector2f(-1 * tetroScaleConstant, 1 * tetroScaleConstant));
			blocks[2].move(Vector2f(0, 0));
			blocks[3].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			rotationState = 2;
		}
		else if (rotationState == 2)
		{
			blocks[0].move(Vector2f(-2 * tetroScaleConstant, 0));
			blocks[1].move(Vector2f(-1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[2].move(Vector2f(0, 0));
			blocks[3].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			rotationState = 3;
		}
		else if (rotationState == 3)
		{
			blocks[0].move(Vector2f(0, -2 * tetroScaleConstant));
			blocks[1].move(Vector2f(1 * tetroScaleConstant, -1 * tetroScaleConstant));
			blocks[2].move(Vector2f(0, 0));
			blocks[3].move(Vector2f(1 * tetroScaleConstant, 1 * tetroScaleConstant));
			rotationState = 0;
		}
	}
}

void Tetromino::draw(RenderWindow* target)
{
	int k = 0;
	while (k < 4)
	{
		target->draw(blocks[k].shape);
		k++;
	}
}

unsigned int Tetromino::getBottomY()
{
	int k = 1;
	int bottomY = blocks[0].coord.y;

	while (k < 4)
	{
		if (blocks[k].coord.y < bottomY)
			bottomY = blocks[k].coord.y;
		k++;
	}

	return bottomY;
}

unsigned int Tetromino::getLefmosttX()
{
	int k = 1;
	int leftmostX = blocks[0].coord.x;

	while (k < 4)
	{
		if (blocks[k].coord.x < leftmostX)
			leftmostX = blocks[k].coord.x;
		k++;
	}

	return leftmostX;
}

unsigned int Tetromino::getRightmostX()
{
	int k = 1;
	int rightmostX = blocks[0].coord.x;

	while (k < 4)
	{
		if (blocks[k].coord.x > rightmostX)
			rightmostX = blocks[k].coord.x;
		k++;
	}

	return rightmostX;
}
