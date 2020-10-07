/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:16 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/24 15:46:08 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	matriz(char *mapa, int filas, int columnas, int a, int i, int j);
void	funcion(char c_matriz[][3], int filas, int l, int lf);

void	fil_col(char *mapa)
{
	int i;
	int j;
	int a;
	int filas;
	int columnas;

	a = 0;
	j = 0;
	i = 0;
	while(mapa[i] != '\n')
	{
		i++;
	}
	while(mapa[j] != '\0')
	{
		if (mapa[j] == '\n')
			j++;
		a++;
		j++;
	}
	filas = a / i;
	columnas = i;
	matriz(mapa, filas, columnas, a, i, j);
}


void	matriz(char *mapa, int filas, int columnas, int a, int i, int j)
{
	char matriz[filas][columnas];

	i = 0;
	a = 0;
	while (i < filas)
	{
		j = 0;
		while (j < columnas)
		{
			if (mapa[a] == '\n')
				a++;
            if (mapa[a] == '.')
                mapa[a] = '1';
            else
                mapa[a] = '0';
			matriz[i][j] = mapa[a];
			j++;
			a++;
		}
		i++;
	}
	i = 0;
	while (i < filas)
	{
		j = 0;
		while (j < columnas)
		{
			printf("%c", matriz[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	char  result;
	int def_i;
	int def_j;

	i = 1;
	result = '0';
	while ( i < filas )
	{
		j = 1;
		while (j < columnas)
		{
			if (matriz[i][j] != '0')
			{
				if (matriz[i-1][j-1] <= matriz[i-1][j] && (matriz[i-1][j-1] <= matriz[i][j-1]))
					matriz[i][j] = '1' + matriz[i-1][j-1] - 48;
				else if	(matriz[i-1][j] <= matriz[i-1][j-1] && (matriz[i-1][j] <= matriz[i][j-1]))
					matriz[i][j] = '1' + matriz[i-1][j] - 48;
				else if (matriz[i][j-1] <= matriz[i-1][j-1] && (matriz[i][j-1] <= matriz[i-1][j]))
					matriz[i][j] = '1' + matriz[i][j-1] - 48;
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

	int posi = (def_i - (result-1)) +48;
	int posj = (def_j - (result-1)) +48;	
	int p;
	int pp;

	p = posj;
	pp = posi;
	result = ((int)result) - 48;
	while (posi < (result + pp))
	{
		posj = p;
		while (posj < (result + p))
		{
			matriz[posi][posj] = 'X';
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
			else if (matriz[i][j] != 'X')
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
			printf("%c", matriz[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
