/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:49 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/24 16:01:35 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int argc, char **argv)
{
	char	*mapa;
	int		r;

	mapa = NULL;
	r = error(argc, argv);
	if (r == 0)
		return (0);
	if (argc > 0)
	{
		mapa = arg2(mapa, argv);
	}
	fil_col(mapa);
}
