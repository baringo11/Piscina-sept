/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:16 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/25 21:56:08 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int			fil_col(char *mapa)
{
	int	i;
	int	j;
	int	filas;
	int	columnas;
	int k;
	int	fallo;

	k = 0;
	filas = 0;
	j = 0;
	i = 0;
	while (mapa[i] != '\n')
		i++;
	i++;
	while (mapa[i] != '\n')
	{
		k++;
		i++;
	}
	while (mapa[j] != '\0')
	{
		if (mapa[j] == '\n')
			j++;
		filas++;
		j++;
	}
	filas = filas / k;
	columnas = k;
	fallo = mapa_valido(mapa, filas, k);
	if (fallo == 1)
		return (1);
	fallo = matriz(mapa, filas, columnas, k, j);
	return (0);
}

int			matriz(char *mapa, int filas, int columnas, int i, int j)
{
	char	matriz[filas][columnas];
	int		w;
	int		a;
	char	result;
	int		def_i;
	int		def_j;
	int		posi;
	int		posj;
	int		p;
	int		pp;

	w = 0;
	while (mapa[w] != '\n')
		w++;
	i = 0;
	a = w + 1;
	while (i < filas)
	{
		j = 0;
		while (j < columnas)
		{
			if (mapa[a] == '\n')
				a++;
			if (mapa[a] == mapa[w - 3])
				mapa[a] = '1';
			else if (mapa[a] == mapa[w - 2])
				mapa[a] = '0';
			else
			{
				ft_putchar("map error (caracter no dado)");
				return (1);
			}
			matriz[i][j] = mapa[a];
			j++;
			a++;
		}
		i++;
	}
	i = 1;
	result = '0';
	while (i < filas)
	{
		j = 1;
		while (j < columnas)
		{
			if (matriz[i][j] != '0')
			{
				if (matriz[i - 1][j - 1] <= matriz[i - 1][j] &&
						(matriz[i - 1][j - 1] <= matriz[i][j - 1]))
					matriz[i][j] = '1' + matriz[i - 1][j - 1] - 48;
				else if (matriz[i - 1][j] <= matriz[i - 1][j - 1] &&
						(matriz[i - 1][j] <= matriz[i][j - 1]))
					matriz[i][j] = '1' + matriz[i - 1][j] - 48;
				else if (matriz[i][j - 1] <= matriz[i - 1][j - 1] &&
						(matriz[i][j - 1] <= matriz[i - 1][j]))
					matriz[i][j] = '1' + matriz[i][j - 1] - 48;
				else
					matriz[i][j] = '1' + matriz[i][j] - 48;
				if (matriz[i][j] > result)
				{
					result = matriz[i][j];
					def_i = i;
					def_j = j;
				}
			}
			j++;
		}
		i++;
	}
	posi = (def_i - (result - 1)) + 48;
	posj = (def_j - (result - 1)) + 48;
	p = posj;
	pp = posi;
	result = ((int)result) - 48;
	while (posi < (result + pp))
	{
		posj = p;
		while (posj < (result + p))
		{
			matriz[posi][posj] = 'x';
			posj++;
		}
		posi++;
	}
	i = 0;
	while (i < filas)
	{
		j = 0;
		while (j < columnas)
		{
			if (matriz[i][j] == '0')
				matriz[i][j] = 'o';
			else if (matriz[i][j] != 'x')
				matriz[i][j] = '.';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < filas)
	{
		j = 0;
		while (j < columnas)
		{
			if (matriz[i][j] == 'o')
				matriz[i][j] = mapa[w - 2];
			else if (matriz[i][j] != 'x')
				matriz[i][j] = mapa[w - 3];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < filas)
	{
		j = 0;
		while (j < columnas)
		{
			if (matriz[i][j] == 'x')
				matriz[i][j] = mapa[w - 1];
			j++;
		}
		i++;
	}
	//ft_putchar2(*matriz, columnas);
	i = 0;
	while (i < filas)
	{
		j = 0;
		while (j < columnas)
		{
			printf("%c", matriz[i][j]);
			//ft_putchar2(&matriz[i][j], columnas);
			j++;
		}
		printf("\n");
		//ft_putchar("");
		i++;
	}
	return (0);
}
/*
void		ft_putchar2(char *c, int columnas)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (c[i] != '\0')
	{
		j = 0;
		while (j < columnas && c[i] != '\0')
		{
			if (c[i] != '\0')
			{
				write(1, &c[i], 1);
				i++;
				j++;
				if (j == columnas)
					write(1, "\n", 1);
			}
		}
	}
}
*/
