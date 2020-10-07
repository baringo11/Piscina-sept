/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:36:49 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/25 14:31:45 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int argc, char **argv)
{
/*
	char	*mapa;
	int		r;
	int i;
	i = 1;
	printf("numero de argumentos: %d\n", argc);
	mapa = NULL;
	r = error(argc, argv);
	if (r == 0)
		return (0);
    if (r == 2)
    {
        mapa = arg0(mapa, argv); //nadaa
        if (mapa[0] != 'A')
            printf("%s", mapa);
    }
    else if (argc > 0)
    {
        mapa = arg2(mapa, &argv[1+i], i); //jaja estaba como argv
        if (mapa[0] != 'A')
            printf("%s", mapa);
    }
	fil_col(mapa);
*/	
	int i;
//	int j;
	printf("numero argc: %d\n", argc);
	i = 1;
	if ( argc > 0)
	{
		while (i < argc)
		{
			char	*mapa;
			int		r;
	
			printf("numero de argumentos: %d\n", argc);
			mapa = NULL;
			r = error(argc, argv);
			if (r == 0)
				return (0);
  			  if (r == 2)
   			 {
     			  mapa = arg0(mapa, argv); //nadaa
      			  if (mapa[0] != 'A')
					  printf("%s", mapa);
  			  }
  			  else if (argc > 0)
  			  {
				  mapa = arg2(mapa, &argv[i], i); // estaba como argv
      			  if (mapa[0] != 'A')
         		 	 printf("%s", mapa);
			  }
			  fil_col(mapa);
			  i++;
		}
	}

}
		/*	j = 0;
			while (argv[i][j] != '\0')
				j++;
			write(1, &(*argv[i]), j);
			printf("\n");
*/

char        *arg0(char *mapa, char **argv)
{
    int    fd;
    int h;
	int i;
    
	i = 0;
    h = 0;
    fd = open("example_file", O_RDONLY);
    if (fd >= 0)
    {
        mapa = readfile(fd, mapa, argv, h, i);
        return (mapa);
    }
    else
    {
        ft_putchar("DICT ERROR");
        return ("A");
    }
}
void    mapa_valido(char *mapa, int filas, int k)
{
    int i;
    int i_igual;
    int num;
    int contador;
   
   // if(mapa[0] != 'v')
     //   printf("f");
    
    num = filas;
    i = 0;
    while (mapa[i] != '\n')
        i++;
    
    i_igual = i - 3;

    contador = 1;
    while(num/10>0)
    {
        num=num/10;
        contador++;
    }
   // printf("valor contador: %d\n", contador);
   // printf("valor i_igual: %d\n", i_igual);
    
    if (i_igual == contador)
        printf("mapa valido\n");
    else
    {
        printf("map error\n");
        exit (1);
    }
    if ((mapa[i-3] != mapa[i-2]) && (mapa[i-3] != mapa[i-1]) && (mapa[i-2] != mapa[i-1]))
        printf("mapa valido\n");
    else
    {
        printf("mapa error(caracteres iguales)\n");
        exit (1);
    }
  
	int twof;
	int m;
	//printf("caracter obstaculo: %c \n", mapa[i-2]);
	//printf("mapa k: %c\n", mapa[k + 4]);	
	if (k == 1)
	{
		if (mapa[k + 4] == mapa[i-2] ||(mapa[k+4] != mapa[k]) )
		{
			printf("map error (1 caracter solo como obstaculo)");
			exit (1);
		}
		printf("map valido (un caracter)\n");
		mapa[k + 4] = mapa [i -1];
		printf("%c", mapa[k + 4]);
		exit (1);
	}
	else
	{
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
			//printf("valor m: %d\n", m);
			//printf("valor k: %d\n", k);
			if (k != m)
			{
				printf("map error (lineas diferentes)");
				exit (1);
			}
			if (mapa[i-4] == '2')
				fallo2 ++;
			//printf("valor mf: %d\n", m);
			//printf("valor kf: %d\n", k);
			m++;	
			twof++;
		}
	}
}
