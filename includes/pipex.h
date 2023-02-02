/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:51:08 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/02 16:52:44 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_args
{
	char	***stack;
	char	**envp;
	char	*infile_name;
	char	*outfile_name;
	int		infile;
	int		outfile;
	int		fdd;
	int		heredoc;
}	t_args;

void	ft_putstr(char *str);
int		ft_error(int error_code);
int		ft_open(t_args *args);

int		ft_struct_init(t_args *args, char **argv, char **envp);
int		ft_pipe(t_args *args);
char	*ft_get_path(char *cmd);

void	ft_free_str(char **str);
void	ft_free_stack(char ***stack);

#endif
