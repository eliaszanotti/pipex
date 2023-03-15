/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:42:23 by elias             #+#    #+#             */
/*   Updated: 2023/03/15 15:42:42 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_get_stack_size(char ***stack)
{
	int	size;

	size = 0;
	while (stack[size])
		size++;
	return (size);
}
