/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:32 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/24 17:45:50 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char		*arg2(char *mapa, char **argv, int i)
{
	int	fd;
    int h;
    
    h = 1;
	fd = open(argv[i], O_RDONLY); //argv[0]
	if (fd >= 0)
	{
		mapa = readfile(fd, mapa, argv, h, i); // argv
		return (mapa);
	}
	else
	{
		ft_putchar("DICT ERROR");
		return ("A");
	}
    
}

char	*readfile(int fd, char *mapa, char **argv, int h, int i) //i
{
	char	t;
	int		c;
	int		f2;

	t = 0;
	c = 0;
	f2 = fd;
	while (read(fd, &t, 1))
		c++;
	mapa = malloc(c * sizeof(*mapa));
	close(fd);
    if (h == 1)
	fd = open(argv[i], O_RDONLY); //i argv[0]
    else
    fd = open("example_file", O_RDONLY);
	
    mapa = fill(mapa, fd, t);
	free(mapa);
	return (mapa);
}

char	*fill(char *mapa, int fd, int t)
{
	int c;

	c = 0;
	while (read(fd, &t, 1)) // solo tenia 1
	{
		mapa[c] = t;
		c++;
	}
	return (mapa);
}

int	error(int argc, char **argv)
{
	if (argc == 1)
	{
        ft_putchar("Entrada Estandar:");
		return (2);
	}
	else if (argv[1][0] == '\0')
	{
		ft_putchar("Error parámetro vacío");
		return (0);
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
