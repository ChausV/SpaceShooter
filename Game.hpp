// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 22:00:52 by vchaus            #+#    #+#             //
//   Updated: 2018/06/23 22:00:52 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_H
# define GAME_H

# include <iostream>
# include <curses.h>
# include <unistd.h>

# include "Space.hpp"
# include "ASpaceObject.hpp"

class Game
{
	public:
		Game(int height, int width);
		~Game();

		int			getHeight() const;
		int			getWidth() const;

		void		cursInit();
		WINDOW *	getMainWin() const;
		WINDOW *	getTopWin() const;
		void		mainLoop(Space & space);

		int 		getScore() const;
		int 		getFrames() const;
	protected:
	private:
		Game();
		Game(const Game &);
		Game &	operator=(const Game &);

		int			_win_height;
		int			_win_width;
		WINDOW *	_main_win;
		WINDOW *	_top_win;
		int 		_counter;
		int 		_score;
		int 		_health;
};

#endif
