// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 22:58:47 by vchaus            #+#    #+#             //
//   Updated: 2018/06/23 22:58:47 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"

Game::Game() {}
Game::Game(const Game &) {}
Game &	Game::operator=(const Game &) { return *this; }

Game::Game(int height, int width) : _win_height(height), _win_width(width)
{
	srand(time(NULL));
	this->_counter = 0;
	this->_score = 0;
	this->_health = 100;
}

Game::~Game() {}

int		Game::getHeight() const {
	return this->_win_height;
}

int		Game::getWidth() const {
	return this->_win_width;
}

WINDOW *	Game::getMainWin() const
{
	return this->_main_win;
}

WINDOW *	Game::getTopWin() const
{
	return this->_top_win;
}

int 	Game::getScore() const
{
	return this->_score;
}
int 	Game::getFrames() const
{
	return this->_counter;
}

void	Game::cursInit()
{
// init and config ncurses:
	initscr();
	curs_set(0);
	keypad(stdscr, true);
	noecho();
	refresh();
	cbreak();
	nodelay(stdscr, true);

// create two windows:
	this->_main_win = newwin(this->_win_height, this->_win_width, 5, 0);
	box(this->_main_win, 0, 0);
	wrefresh(this->_main_win);
	this->_top_win = newwin(5, this->_win_width, 0, 0);
	box(this->_top_win, 0, 0);
	wrefresh(this->_top_win);

	mvwprintw(this->_top_win, 1, 18, "* * *    AWESOME  SPACE  GAME   * * *");
}

void	Game::mainLoop(Space & space)
{
	bool	loop_flag = true;

// first put of ship:
	space.getShip().setYPos(this->getHeight() * 0.9);
	space.getShip().setXPos(this->getWidth() * 0.5);
	mvwprintw(this->_main_win, space.getShip().getYPos(), space.getShip().getXPos(),
													"%c", space.getShip().getSight());
	wrefresh(this->_top_win);
	wrefresh(this->_main_win);

// main loop:
	while (loop_flag)
	{
		switch (getch())
		{
			case KEY_UP:
				space.getShip().move(1, 0, this->_win_height, this->_win_width, this->_main_win);
				break;
			case KEY_DOWN:
				space.getShip().move(-1, 0, this->_win_height, this->_win_width, this->_main_win);
				break;
			case KEY_LEFT:
				space.getShip().move(0, -1, this->_win_height, this->_win_width, this->_main_win);
				break;
			case KEY_RIGHT:
				space.getShip().move(0, 1, this->_win_height, this->_win_width, this->_main_win);
				break;
			case 'p':	// pause
				nodelay(stdscr, false);
				while(getch() != 'p')
					;
				nodelay(stdscr, true);
				break;
			case 'q':	// quit
				loop_flag = false;
				break;
			case ' ':	// fire
				space.createBullet();
				break;
		}
		this->_counter++;
	// changing scene here:
		if (this->_counter % 2)
		{
			space.createEnemy();
			space.moveEnemy(this->_win_height, this->_win_width, this->_main_win);
		}
		space.moveBullet(this->_win_height, this->_win_width, this->_main_win);
		this->_score += space.bulletCollision(this->_main_win);
		this->_health -= space.shipCollision(this->_main_win);
		wrefresh(this->_main_win);
		if (this->_health <= 0)
			loop_flag = false;

	// printing stats:
		mvwprintw(this->_top_win, 3, 10, "       ", this->_health);
		mvwprintw(this->_top_win, 3, 37, "       ", this->_counter);
		mvwprintw(this->_top_win, 3, 70, "       ", this->_score);
		mvwprintw(this->_top_win, 3, 5, "HEALTH: %d", this->_health);
		mvwprintw(this->_top_win, 3, 32, "FRAMES: %d", this->_counter);
		mvwprintw(this->_top_win, 3, 65, "SCORE: %d", this->_score);
		wrefresh(this->_top_win);

		usleep(50000);
	}
	nodelay(stdscr, false);
	getch();
}




