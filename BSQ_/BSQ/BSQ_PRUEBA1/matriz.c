/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:16 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/24 11:16:29 by jbaringo         ###   ########.fr       */
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
	printf("numero de filas :%d\n", filas);
	printf("numero de columnas: %d\n", columnas);

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

	int lc;
	int lf;

	lf = 0;
	lc = 0;
//	printf("fuera funcion %c", matriz[1][3]);
	funcion (matriz, filas, lc, lf);
}
