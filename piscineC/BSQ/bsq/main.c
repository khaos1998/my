/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:22:56 by cciobanu          #+#    #+#             */
/*   Updated: 2016/08/22 16:50:56 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int i;
	char *buf;

	i = 1;
	if (argc < 2)
		return(0);
	//	convert_input();
	else
	{
		while (i < argc)
		{
			buf=malloc(sizeof(char)*size(argv[i]));
			buf=open_and_read(argv[i]);
			if (validare(buf) == 0)
				return (0);
			i++;
			free(buf);
		}
	//	i=1;
	//	while (i > ac)
	//		solve(argv[i])
	}
}	
