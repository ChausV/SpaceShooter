// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vchaus <marvin@42.fr>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 14:04:58 by vchaus            #+#    #+#             //
//   Updated: 2018/06/23 14:04:59 by vchaus           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ft_retro.h"

int		main()
{
	while(mainMenu())
	{
		gameIteration();

	}
	return 0;
}