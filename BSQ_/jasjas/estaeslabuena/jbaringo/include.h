/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:52:42 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/25 21:56:44 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchar(char *c);
char	*arg2(char *mapa, char *argv);
char	*fill(char *mapa, int fd, int t);
int		error(int argc);
int		matriz(char *mapa, int filas, int columnas, int i, int j);
int		fil_col(char *mapa);
char	*arg0(char *mapa);
int		mapa_valido(char *mapa, int filas, int k);
int		mapa_valido_2(char *mapa, int i, int k, int contador);
int		mapa_valido_3(char *mapa, int i, int k);
void	argumentos(int argc, char **argv);
void	ft_putchar2(char *c, int columnas);

#endif
