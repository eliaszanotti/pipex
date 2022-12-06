/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:53:11 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/06 14:53:33 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_args(t_args *args)
{
	int	i;

	i = 0;
	while (args->tab_cmd1[i])
		free(args->tab_cmd1[i++]);
	free(args->tab_cmd1);
	i = 0;
	while (args->tab_cmd2[i])
		free(args->tab_cmd2[i++]);
	free(args->tab_cmd2);
}
