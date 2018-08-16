// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ASpaceObject.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 06:41:50 by vchaus            #+#    #+#             //
//   Updated: 2018/06/24 06:41:51 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef A_SPACE_OBJECT_H
# define A_SPACE_OBJECT_H

# include <iostream>
# include <curses.h>

class ASpaceObject
{
	public:
		ASpaceObject();
		ASpaceObject(const ASpaceObject &);
		virtual ~ASpaceObject();
		ASpaceObject &	operator=(const ASpaceObject &);

		int		getYPos() const;
		int		getXPos() const;
		void	setYPos(int y);
		void	setXPos(int x);
		virtual bool	move(int y, int x, int y_max, int x_max, WINDOW * win) = 0;
	protected:
		int		_y;
		int		_x;
	private:
};

#endif
