/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:22 by elias             #+#    #+#             */
/*   Updated: 2023/03/21 13:38:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(int error_code)
{
	if (error_code)
		ft_printf_fd("\e[1;31m[ERROR:%d]\e[0m ", STDERR_FILENO, error_code);
	if (error_code == 2)
		printf("Wrong amount of arguments\n");
	else if (error_code == 3)
		printf("Failed to pipe fd\n");
	else if (error_code == 4)
		printf("Failed to create fork\n");
	else if (error_code == 5)
		printf("Failed to duplicate fd (dup2 error)\n");
	else if (error_code == 6)
		printf("Command not found\n");
	else if (error_code == 10)
		printf("Can't open file\n");
	else if (error_code == 11)
		printf("Can't create file\n");
	else if (error_code == 99)
		printf("Malloc cannot be created\n");
	else
		printf("Undefined\n");
	return (1);
}
