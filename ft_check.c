/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:04:28 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/31 10:04:30 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_check(int argc, char **argv)
{
	int	i;

	i = 2;
	if (argc < 5)
		return (ft_print_error("Wrong number of arguments were given"));
	if (argv[argc - 1][0] == '\0')
		return (ft_print_error("Empty name outfile"));
	if (argv[1][0] == '\0')
		return (ft_print_error("Empty name infile"));
	while (argv[i] < argv[argc - 1])
	{
		if (argv[i][0] == '\0')
			return (ft_print_error("Empty cmd"));
		i++;
	}
	return (0);
}
