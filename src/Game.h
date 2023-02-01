#ifndef GAME_H
#define GAME_H

#include "stdafx.h"
#include "Tetromino.h"

using namespace sf;

class Game
{
public:
	Game();
	~Game();

	bool isRunning();

	void update();
	void render();
private:

	int shapeRotation;

	// Engine Variables
	VideoMode mainVideoMode;
	RenderWindow* mainWindow;
	Event ev;

	// Clock
	Clock mainClock;

	float dt;

	// GUI
	VertexArray grid;

	// Initializers
	void initVariables();
	void initWindow();
	void initGrid();

	// Engine Functions
	void pollEvents();

	// Game Logic
	const int speed;
	int timer;
	float dropRate;
	bool held;
	bool pause;

	// Game Objects
	Tetromino* currentTetromino;

	// Game Functions
	void spawnTetromino();
	void fallTetromino();

	// Collision
	bool isCollideBottom();
	bool isCollideLeftSide();
	bool isCollideRightSide();

	// DESKTOP

	Vector2f gridCordtoPos(int x, int y)
	{
		return Vector2f(x * tetroScaleConstant, mainVideoMode.height - (y + 1) * tetroScaleConstant);
	}

	Vector2u postoGridCord(Vector2f pos)
	{
		return Vector2u(pos.x / tetroScaleConstant, (mainVideoMode.height - pos.y) / tetroScaleConstant - 1);
	}
};


/*
void posReport(const RectangleShape& shape)
{
	std::cout << "Pos: [" << shape.getPosition().x << "," << shape.getPosition().y << "] Left: "
		<< shape.getGlobalBounds().left << " Top: " << shape.getGlobalBounds().top << " Width: "
		<< shape.getGlobalBounds().width << " Height: " << shape.getGlobalBounds().height << std::endl;
}
*/

#endif
