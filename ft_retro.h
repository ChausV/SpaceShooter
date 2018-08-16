/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:45:34 by vchaus            #+#    #+#             */
/*   Updated: 2018/06/24 19:45:34 by vchaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_H
# define FT_RETRO_H

# include <iostream>
// #include <ncurses.h>
# include <curses.h>

// #include <panel.h>
# include <csignal>

# include "Space.hpp"
# include "Game.hpp"

bool	mainMenu();
void 	resizeHandler(int sig);
void	gameIteration();

#endif
