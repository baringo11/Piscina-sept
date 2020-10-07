/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:49 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/24 15:46:03 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "arg.c"
#include "matriz.c"
#include "funcion.c"
char	*arg2(char *mapa, char **argv);

int	main(int argc, char **argv)
{
	char	*mapa;
	int		r;

	mapa = NULL;
	r = error(argc, argv);
	if (r == 0)
		return (0);
	if (argc == 1)
	{
		mapa = arg2(mapa, argv);
		if (mapa[0] != 'A')
			printf("%s", mapa);
	}
   /* else if (r == 2)
    {
        mapa = arg0(mapa, argv);
        if (mapa[0] != 'A')
            printf("%s", mapa);
    }
    */
	fil_col(mapa);
}
