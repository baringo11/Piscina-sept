/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:16 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/24 17:01:54 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	fil_col(char *mapa)
{
	int i;
	int	j;
	int	a;
	int	filas;
	int	columnas;
    int k;

    k = 0;
	a = 0;
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
	while(mapa[j] != '\0')
	{
		if (mapa[j] == '\n')
			j++;
		a++;
		j++;
	}
	filas = a / k;
	columnas = k;
    printf("filas: %d\n", filas);
    printf("columnas: %d\n", columnas);
    mapa_valido(mapa, filas, k);
	matriz(mapa, filas, columnas, a, k, j);
}

void		matriz(char *mapa, int filas, int columnas, int a, int i, int j)
{
	char	matriz[filas][columnas];
    int w;
    char lleno;
    char vacio;
    char obstaculo;
    
    w = 0;
    while (mapa[w] != '\n')
        w++;
    lleno = mapa[w - 1];
    vacio = mapa[w - 3];
    obstaculo = mapa[w - 2];

	i = 0;
	a = w + 1;
	while (i < filas)
	{
		j = 0;
		while (j < columnas)
		{
			if (mapa[a] == '\n')
				a++;
			if (mapa[a] == vacio)
				mapa[a] = '1';
			else if (mapa[a] == obstaculo)
				mapa[a] = '0';
            else
            {
                printf("map error (caracter no dado)");
                exit (1);
            }
			matriz[i][j] = mapa[a];
			j++;
			a++;
		}
		i++;
	}

	char	result;
	int		def_i;
	int		def_j;

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
				else if	(matriz[i - 1][j] <= matriz[i - 1][j - 1] &&
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
	//reemplazar(matriz[filas][columnas], i, j, result);
//}

//int		reemplazar(char matriz[filas][columnas], int i, int j, int result)
	int posi;
	int posj;
	int p;
	int pp;
    
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
            matriz[posi][posj] = lleno; //mapa[w - 1];
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
				matriz[i][j] = obstaculo;
			else if (matriz[i][j] != lleno)
				matriz[i][j] = vacio;
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
