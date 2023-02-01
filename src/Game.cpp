#include "stdafx.h"
#include "Game.h"

Game::Game()
	: speed(40)
{
	initVariables();
	initWindow();
	initGrid();
}

Game::~Game()
{
	delete mainWindow;
	delete currentTetromino;
	std::cout << "Game Destructed!\n";
}

bool Game::isRunning()
{
	return mainWindow->isOpen();
}

void Game::initVariables()
{
	shapeRotation = 0;

	mainVideoMode.width = 400;
	mainVideoMode.height = 800;

	timer = 0;
	dropRate = 1.f;
	held = false;

	pause = false;

	currentTetromino = nullptr;

	mainClock.restart();
}

void Game::initWindow()
{
	mainWindow = new sf::RenderWindow(mainVideoMode, "SFML Window", sf::Style::Titlebar | sf::Style::Close);
	mainWindow->setFramerateLimit(60);

}

void Game::initGrid()
{
	int rows = 20, cols = 10;

	// initialize values
	int numLines = rows + cols - 2;
	grid = VertexArray(Lines, 2 * (numLines));

	mainWindow->setView(mainWindow->getDefaultView());
	Vector2f size = mainWindow->getView().getSize();
	float rowH = size.y / rows;
	float colW = size.x / cols;
	// row separators
	for (int i = 0; i < rows - 1; i++) {
		int r = i + 1;
		float rowY = rowH * r;
		grid[i * 2].position = { 0, rowY };
		grid[i * 2 + 1].position = { size.x, rowY };
	}
	// column separators
	for (int i = rows - 1; i < numLines; i++) {
		int c = i - rows + 2;
		float colX = colW * c;
		grid[i * 2].position = { colX, 0 };
		grid[i * 2 + 1].position = { colX, size.y };
	}

	size_t k = 0;
	while (k < grid.getVertexCount())
	{
		grid[k].color = Color(255, 255, 255, 50);
		k++;
	}
}

void Game::pollEvents()
{
	while (mainWindow->pollEvent(ev))
	{
		if (ev.type == Event::Closed)
			mainWindow->close();
		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
			mainWindow->close();

		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::P)
		{
			if (pause)
			{
				std::cout << "Unpaused!\n";
				pause = false;
			}
			else
			{
				std::cout << "Paused!\n";
				pause = true;
			}
		}

		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Enter)
			spawnTetromino();

		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Backspace)
		{
			delete currentTetromino;
			currentTetromino = nullptr;
		}

		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Left && !isCollideLeftSide())
			currentTetromino->move(-speed * 1.f, 0);
		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Right && !isCollideRightSide())
			currentTetromino->move(speed * 1.f, 0);

		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Up)
		{
			if (!held)
			{
				currentTetromino->rotate();
				held = true;
			}
		}
		else
		{
			held = false;
		}

		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::O)
			currentTetromino->printCoords();
	}
}

void Game::update()
{
	pollEvents();

	if (!pause && currentTetromino != nullptr)
		fallTetromino();
}

void Game::spawnTetromino()
{
	delete currentTetromino;
	currentTetromino = new Tetromino(gridCordtoPos(3, 19), Vector2u(3, 19), shapeRotation % 6);
	mainClock.restart();
	shapeRotation++;
}

void Game::fallTetromino()
{
	// SOFT DROP
	if (Keyboard::isKeyPressed(Keyboard::Down)) 
	{
		if (mainClock.getElapsedTime().asSeconds() >= 0.05f)
		{
			currentTetromino->move(0.f, speed * 1.f);
			std::cout << mainClock.restart().asSeconds() << std::endl;
		}
	}
	// GRAVITY FALL
	else 
	{
		if (mainClock.getElapsedTime().asSeconds() >= 1.f)
		{
			currentTetromino->move(0.f, speed * 1.f);
			std::cout << mainClock.restart().asSeconds() << std::endl;
		}
	}

	// Collision Detection
	if (isCollideBottom() && !pause)
	{
		std::cout << "GROUND\n";
		std::cout << "PAUSED!\n";
		pause = true;
	}
}

bool Game::isCollideBottom()
{
	return (currentTetromino->getBottomY() == 0) ? true : false;
}

bool Game::isCollideLeftSide()
{
	return (currentTetromino->getLefmosttX() == 0) ? true : false;
}

bool Game::isCollideRightSide()
{
	return (currentTetromino->getRightmostX() == 9) ? true : false;
}

void Game::render()
{
	mainWindow->clear();

	mainWindow->draw(grid);
	if (currentTetromino != nullptr)
		currentTetromino->draw(mainWindow);

	mainWindow->display();
}