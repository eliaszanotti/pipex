/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:51:47 by elias             #+#    #+#             */
/*   Updated: 2023/02/02 16:52:09 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_stack(char ***stack)
{
	int	i;
	int	j;

	i = -1;
	while (stack[++i])
	{
		j = -1;
		while (stack[i][++j])
			free(stack[i][j]);
		free(stack[i]);
	}
	free(stack);
}
