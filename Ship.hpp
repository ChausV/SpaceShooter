// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ship.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 22:01:29 by vchaus            #+#    #+#             //
//   Updated: 2018/06/23 22:01:30 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHIP_H
# define SHIP_H

# include <iostream>
# include <curses.h>
# include "ASpaceObject.hpp"

class Ship : public ASpaceObject
{
	public:
		Ship();
		Ship(const Ship &);
		Ship &	operator=(const Ship &);
		~Ship();

		char	getSight() const;
		bool	move(int y, int x, int y_max, int x_max, WINDOW * win);
	protected:
	private:

		char	_sight;
};

#endif
