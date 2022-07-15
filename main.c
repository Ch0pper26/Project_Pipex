/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:11:18 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/31 15:26:32 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*p;

	if (ft_check(argc, argv))
		return (0);
	p = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (!p)
		return (ft_print_error("Malloc Error"));
	ft_init_struct(p, argc, argv, envp);
	ft_execute(p, argv, envp);
	return (0);
}
