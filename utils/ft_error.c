/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:22 by elias             #+#    #+#             */
/*   Updated: 2023/03/22 19:15:34 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_command(char *path)
{
	ft_printf_fd("\e[1;31m[ERROR]\e[0m ", STDERR_FILENO);
	ft_printf_fd("%s : Command not found\n", STDERR_FILENO, path);
	free(path);
	return (1);
}

int	ft_error(int error_code)
{
	if (error_code)
		ft_printf_fd("\e[1;31m[ERROR:%d]\e[0m ", STDERR_FILENO, error_code);
	if (error_code == 2)
		ft_printf_fd("Wrong amount of arguments\n", STDERR_FILENO);
	else if (error_code == 3)
		ft_printf_fd("Failed to pipe fd\n", STDERR_FILENO);
	else if (error_code == 4)
		ft_printf_fd("Failed to create fork\n", STDERR_FILENO);
	else if (error_code == 5)
		ft_printf_fd("Failed to duplicate fd (dup2 error)\n", STDERR_FILENO);
	else if (error_code == 10)
		ft_printf_fd("Can't open file\n", STDERR_FILENO);
	else if (error_code == 11)
		ft_printf_fd("Can't create file\n", STDERR_FILENO);
	else if (error_code == 99)
		ft_printf_fd("Malloc cannot be created\n", STDERR_FILENO);
	else
		ft_printf_fd("Undefined\n", STDERR_FILENO);
	return (1);
}
