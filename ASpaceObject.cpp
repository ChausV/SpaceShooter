// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ASpaceObject.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 06:41:57 by vchaus            #+#    #+#             //
//   Updated: 2018/06/24 06:41:58 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ASpaceObject.hpp"

ASpaceObject::ASpaceObject() {}

ASpaceObject::ASpaceObject(const ASpaceObject & src)
{
	*this = src;
}

ASpaceObject::~ASpaceObject() {}

ASpaceObject &	ASpaceObject::operator=(const ASpaceObject & src)
{
	this->_y = src._y;
	this->_x = src._x;
	return *this;
}

int		ASpaceObject::getYPos() const
{
	return this->_y;
}
int		ASpaceObject::getXPos() const
{
	return this->_x;
}

void	ASpaceObject::setYPos(int y)
{
	this->_y = y;
}
void	ASpaceObject::setXPos(int x)
{
	this->_x = x;
}

