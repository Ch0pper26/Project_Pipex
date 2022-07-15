/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:09:38 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/31 16:09:59 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free_pipe(t_pipex *p)
{
	close(p->fd1);
	close(p->fd2);
	if (p->h_d == 1)
		unlink(".tmpfile");
	free(p->env_p);
	free(p->end);
	ft_print_error("Error : Environment !\n");
	exit(1);
}

void	ft_free_parent_process(t_pipex *p)
{
	int	i;

	i = 0;
	close(p->fd1);
	close(p->fd2);
	if (p->h_d == 1)
		unlink(".tmpfile");
	free(p->env_p);
	while (p->cmd_path[i])
		free(p->cmd_path[i++]);
	free(p->cmd_path);
	free(p->end);
	free(p);
}

void	ft_free_child(t_pipex *p)
{
	int	i;

	i = 0;
	while (p->cmd_arg[i])
		free(p->cmd_arg[i++]);
	free(p->cmd_arg);
	free(p->cmd);
	i = 0;
	while (p->cmd_path[i])
		free(p->cmd_path[i++]);
	free(p->cmd_path);
	free(p->env_p);
	free(p->end);
	free(p);
}
