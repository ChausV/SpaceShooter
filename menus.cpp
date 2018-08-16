// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   menus.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 19:44:50 by vchaus            #+#    #+#             //
//   Updated: 2018/06/24 19:44:50 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ft_retro.h"

bool	mainMenu()
{
	initscr();
	curs_set(0);
	noecho();
	refresh();

	WINDOW *	win = newwin(26, 60, 8, 10);
	box(win, 0, 0);
	wrefresh(win);

	keypad(stdscr, true);

	mvwprintw(win, 20, 22, "Arrows to move");
	mvwprintw(win, 21, 23, "Space to fire");
	mvwprintw(win, 22, 25, "P - pause");
	mvwprintw(win, 23, 25, "Q - quit");
	wrefresh(win);

	int 	selector = 1;
	while(1)
	{
		if (selector % 2 == 0)
		{
			mvwprintw(win, 10, 22, "  PLAY GAME  ");
			wattron(win, A_REVERSE);
			mvwprintw(win, 13, 24, "  EXIT  ");
			wattroff(win, A_REVERSE);
			wrefresh(win);

		}
		else
		{
			wattron(win, A_REVERSE); 
			mvwprintw(win, 10, 22, "  PLAY GAME  ");
			wattroff(win, A_REVERSE); 
			mvwprintw(win, 13, 24, "  EXIT  ");
			wrefresh(win);
		}
		switch (getch())
		{
			case KEY_UP:
				selector++;
				break;
			case KEY_DOWN:
				selector++;
				break;
			case 10:
				delwin(win);
				endwin();	
				return (selector % 2);
			default:
				mvwprintw(win, 17, 15, "Up and down arrows to choose");
				mvwprintw(win, 18, 20, "Enter to submit");
				wrefresh(win);
				break;
		}
	}
	return true;
}

void resizeHandler(int sig)
{
	if (sig)
		;
	endwin();
	std::cout << "Resizing is forbidden! exiting..." << std::endl;
	exit(1);
}

void	finalFrame(const Game & game)
{
	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, true);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	refresh();

	WINDOW *	fin_win = newwin(26, 60, 8, 10);
	for (int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 60; j++)
		{
			wattron(fin_win, COLOR_PAIR(1));
			mvwprintw(fin_win, i, j, " ");
			wattroff(fin_win, COLOR_PAIR(1));
		}
	}
	box(fin_win, 0, 0);
	wrefresh(fin_win);

	wattron(fin_win, COLOR_PAIR(2));
	mvwprintw(fin_win, 6, 20, "    GAME OVER !    ");

	wattron(fin_win, COLOR_PAIR(1));
	mvwprintw(fin_win, 10, 8, "You earned");
	wattron(fin_win, COLOR_PAIR(3));
	mvwprintw(fin_win, 10, 20, " %d ", game.getScore());
	wattron(fin_win, COLOR_PAIR(1));
	mvwprintw(fin_win, 10, 25, "  scores");

	wattron(fin_win, COLOR_PAIR(1));
	mvwprintw(fin_win, 11, 8, "During");
	wattron(fin_win, COLOR_PAIR(3));
	mvwprintw(fin_win, 11, 16, " %d ", game.getFrames());
	wattron(fin_win, COLOR_PAIR(1));
	mvwprintw(fin_win, 11, 23, "frames");

	wattron(fin_win, COLOR_PAIR(1));
	mvwprintw(fin_win, 12, 8, "It is");
	wattron(fin_win, COLOR_PAIR(3));
	mvwprintw(fin_win, 12, 15, " %.1f ", static_cast<float>(game.getFrames()) /
									static_cast<float>(game.getScore() / 5));
	wattron(fin_win, COLOR_PAIR(1));
	mvwprintw(fin_win, 12, 21, "frames per enemy");

	wattron(fin_win, COLOR_PAIR(1));
	mvwprintw(fin_win, 18, 17, "press Enter to continue...");

	refresh();
	wrefresh(fin_win);

	while(getch() != 10)
		;
	delwin(fin_win);
	endwin();	
}

void	gameIteration()
{
	Space	space = Space();
	Game	game(40, 80);

	game.cursInit();
	signal(SIGWINCH, resizeHandler);
	game.mainLoop(space);

	delwin(game.getMainWin());
	delwin(game.getTopWin());
	clear();
	endwin();

	finalFrame(game);
}

