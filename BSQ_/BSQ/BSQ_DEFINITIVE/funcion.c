/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:37:50 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/24 11:44:45 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>


void funcion(char c_matriz[][3], int filas, int lc,int lf)
{
	if ( lf == 0 && lc == 0)
		printf("--------fila 0----------\n");

	printf("\n");
	printf("---vuelta %d--\n", lc);

	int tope;
	int i;
	int j;
	int t;

	tope = 11;
	i = 0 + lf;

//	printf("%c\n", c_matriz[5][8]);
	
	while(i < filas)
	{
		printf("valor i: %d\n", i);
		j = 0 + lc;
		t = 0;
		while (j < 3)
		{
			if (c_matriz[i][j] != '.')
			{
				tope = t;
				printf("valor tope: %d\n", tope);
			}
			if (tope == 0)
				break;

			j++;
			t++;
		}
		if (tope == 0)
			break;

		i++;
	}




	printf("\n");
	printf("\n");
	lc++;

	if (lc <= 3)
	{
		if (lc == 3 && lf < filas)
		{
			lc = 0;
			lf++;
			printf("----------fila %d-----------\n", lf);
		}
		if (lf < filas)
			funcion(c_matriz, filas, lc, lf);
		else
			printf("\n fin \n");
	}
}
