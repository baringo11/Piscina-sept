/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaringo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:52:42 by jbaringo          #+#    #+#             */
/*   Updated: 2019/09/24 16:07:02 by jbaringo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchar(char *c);
char	*arg2(char *mapa, char **argv);
char	*readfile(int fd, char *mapa, char **argv);
char	*fill(char *mapa, int fd, int t);
int		error(int argc, char **argv);
void	matriz(char *mapa, int filas, int columnas, int a, int i, int j);
void	fil_col(char *mapa);

#endif

