/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:32 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/25 20:54:25 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*arg2(char *mapa, char *argv)
{
	int		fd;
	int		h;
	char	t;
	int		c;
	int		f2;

	h = 1;
	fd = open(argv, O_RDONLY);
	if (fd >= 0)
	{
		t = 0;
		c = 0;
		f2 = fd;
		while (read(fd, &t, 1))
			c++;
		mapa = malloc(c * sizeof(char));
		close(fd);
		if (mapa == NULL)
		{
			ft_putchar("no se puede crear la memoria");
			return ("A");
		}
		if (h == 1)
			fd = open(argv, O_RDONLY);
		else
			fd = open("example_file", O_RDONLY);
		mapa = fill(mapa, fd, t);
		free(mapa);
		return (mapa);
	}
	else
	{
		ft_putchar("map error");
		return ("A");
	}
}

char	*fill(char *mapa, int fd, int t)
{
	int c;

	c = 0;
	while (read(fd, &t, 1))
	{
		mapa[c] = t;
		c++;
	}
	return (mapa);
}

int		error(int argc)
{
	if (argc == 1)
	{
		ft_putchar("Entrada Estandar:");
		return (2);
	}
	else
		return (1);
}

void	ft_putchar(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
