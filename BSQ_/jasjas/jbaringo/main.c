/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:49 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/25 20:28:41 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		main(int argc, char **argv)
{
	int		i;
	int		fallo;
	char	*mapa;
	int		r;

	i = 1;
	if (argc > 0)
	{
		while (i < argc)
		{
			mapa = NULL;
			r = error(argc);
			if (argc > 0)
				mapa = arg2(mapa, argv[i]);
			if (mapa[0] != 'A')
				fallo = fil_col(mapa);
			if (argc > 2 && i < (argc - 1))
				ft_putchar("");
			i++;
		}
		if (argc == 1)
		{
			mapa = NULL;
			r = error(argc);
			mapa = arg0(mapa);
			if (mapa[0] != 'A')
				fallo = fil_col(mapa);
		}
	}
}

char	*arg0(char *mapa)
{
	int fd;
	int h;
	int c;
	int t;

	c = 0;
	h = 0;
	fd = open("example_file", O_RDONLY);
	if (fd >= 0)
	{
		while (read(fd, &t, 1))
			c++;
		mapa = malloc(c * sizeof(char));
		close(fd);
		fd = open("example_file", O_RDONLY);
		mapa = fill(mapa, fd, t);
		return (mapa);
	}
	else
	{
		ft_putchar("DICT ERROR");
		return ("A");
	}
}

int		mapa_valido(char *mapa, int filas, int k)
{
	int i;
	int i_igual;
	int num;
	int contador;
	int r;

	num = filas;
	i = 0;
	while (mapa[i] != '\n')
		i++;
	i_igual = i - 3;
	contador = 1;
	while (num / 10 > 0)
	{
		num = num / 10;
		contador++;
	}
	r = mapa_valido_2(mapa, i, k, contador);
	if (r == 1)
		return (1);
	return (0);
}

int		mapa_valido_2(char *mapa, int i, int k, int contador)
{
	if ((!((mapa[i - 3] != mapa[i - 2]) &&
			(mapa[i - 3] != mapa[i - 1]) && (mapa[i - 2] != mapa[i - 1]))) ||
			((i - 3) != contador))
	{
		ft_putchar("mapa error");
        //return (0);
	}
	if (k == 1)
	{
		if (mapa[k + 4] == mapa[i - 2] || (mapa[k + 4] != mapa[k]))
		{
			ft_putchar("map error (1 caracter solo como obstaculo)");
			return (1);
		}
		mapa[k + 4] = mapa[i - 1];
	}
	else
	{
		contador = mapa_valido_3(mapa, i, k);
	}
	return (0);
}

int		mapa_valido_3(char *mapa, int i, int k)
{
	int twof;
	int m;
	int fallo2;

	fallo2 = 1;
	twof = ((i + k) + 2);
	while (mapa[twof] != '\0' && fallo2 != 2)
	{
		m = 0;
		while (mapa[twof] != '\n')
		{
			twof++;
			m++;
		}
		if (k != m)
		{
			ft_putchar("map error (lineas diferentes)");
			//return (1);
		}
		if (mapa[i - 4] == '2')
			fallo2++;
		m++;
		twof++;
	}
	return (0);
}
