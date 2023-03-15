/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:16:06 by elias             #+#    #+#             */
/*   Updated: 2023/03/15 15:46:26 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_add_pid(t_args *args, pid_t pid)
{
	int	i;
	int	size;

	size = ft_get_stack_size(args->stack);
	i = 0;
	while (args->pid_tab[i] != -1 && i < size)
		i++;
	if (i < size)
	{
		args->close_tab[i] = args->fdd;
		args->pid_tab[i] = pid;
	}
	return (0);
}

int	ft_wait_and_close(t_args *args)
{
	int	size;

	size = ft_get_stack_size(args->stack);
	while (--size >= 0)
	{
		waitpid(args->pid_tab[size], NULL, 0);
		close(args->close_tab[size]);
	}
	return (0);
}

