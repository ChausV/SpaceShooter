// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Space.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 23:40:33 by vchaus            #+#    #+#             //
//   Updated: 2018/06/23 23:40:33 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Space.hpp"

Space::Space()
{
	for (int i = 0; i < MAX_ENEMIES_NUMBER; i++)
		this->_enemies[i] = NULL;
	for (int i = 0; i < MAX_BULLET_NUMBER; i++)
		this->_bullets[i] = NULL;
}

Space::Space(const Space & src)
{
	*this = src;
}

Space & Space::operator=(const Space & src)
{
	this->_ship = src._ship;
	return *this;
}

Space::~Space()
{
	for (int i = 0; i < MAX_ENEMIES_NUMBER; i++)
	{
		if (this->_enemies[i] != NULL)
			delete this->_enemies[i];
	}
	for (int i = 0; i < MAX_BULLET_NUMBER; i++)
	{
		if (this->_bullets[i] != NULL)
			delete this->_bullets[i];
	}
}


Ship &	Space::getShip()
{
	return this->_ship;
}

void	Space::createEnemy()
{
	for (int i = 0; i < MAX_ENEMIES_NUMBER; i++)
	{
		if (this->_enemies[i] == NULL)
		{
			this->_enemies[i] = new Enemy;
			return;
		}
	}
}

void	Space::createBullet()
{
	for (int i = 0; i < MAX_BULLET_NUMBER; i++)
	{
		if (this->_bullets[i] == NULL)
		{
			this->_bullets[i] = new Bullet((this->_ship.getYPos() - 1), this->_ship.getXPos());
			return;
		}
	}
}

void	Space::moveEnemy(int y_max, int x_max, WINDOW * win)
{
	for (int i = 0; i < MAX_ENEMIES_NUMBER; i++)
	{
		if (this->_enemies[i] != NULL)
		{
			if(!(this->_enemies[i]->move(-1, 0, y_max, x_max, win)))
			{
				delete this->_enemies[i];
				this->_enemies[i] = NULL;
			}
		}
	}
}

void	Space::moveBullet(int y_max, int x_max, WINDOW * win)
{
	for (int i = 0; i < MAX_BULLET_NUMBER; i++)
	{
		if (this->_bullets[i] != NULL)
		{
			if(!(this->_bullets[i]->move(1, 0, y_max, x_max, win)))
			{
				delete this->_bullets[i];
				this->_bullets[i] = NULL;
			}
		}
	}
}

int		Space::bulletCollision(WINDOW * win)
{
	int		res = 0;
	for (int i = 0; i < MAX_BULLET_NUMBER; i++)
	{
		if (this->_bullets[i] != NULL)
		{
			for(int j = 0; j < MAX_ENEMIES_NUMBER; j++)
			{
				if (this->_enemies[j] != NULL &&
					this->_bullets[i]->getXPos() == this->_enemies[j]->getXPos() &&
					(this->_bullets[i]->getYPos() == this->_enemies[j]->getYPos() ||
					this->_bullets[i]->getYPos() + 1 == this->_enemies[j]->getYPos()))
				{
					res += DEAD_ENEMY_POINT;
					mvwprintw(win, this->_bullets[i]->getYPos(), this->_bullets[i]->getXPos(), " ");
					delete this->_bullets[i];
					delete this->_enemies[j];
					this->_bullets[i] = NULL;
					this->_enemies[j] = NULL;
					break;
				}
			}
		}
		
	}
	return res;
}

int		Space::shipCollision(WINDOW * win)
{
	int		xxx	= this->getShip().getXPos();
	int		yyy	= this->getShip().getYPos();
	int		res = 0;
	for(int i = 0; i < MAX_ENEMIES_NUMBER; i++)
	{
		if (this->_enemies[i] != NULL && 
			this->_enemies[i]->getYPos() == yyy &&
			this->_enemies[i]->getXPos() == xxx)
		{
			res += SHIP_COLLISION_DAMAGE;
			delete this->_enemies[i];
			this->_enemies[i] = NULL;
			mvwprintw(win, yyy, xxx, "*");
			break;
		}
	}
	return res;
}

