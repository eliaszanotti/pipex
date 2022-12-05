/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:51:08 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 15:49:09 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"

# include <stdio.h>
# include <fcntl.h>

typedef struct s_args
{
	char	**envp;
	char	**tab_cmd1;
	char	**tab_cmd2;
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
}	t_args;


void	ft_file_to_stdin(t_args *args);
char	*ft_get_path(t_args *args, char *cmd);
int     main(int argc, char **argv, char **envp);
t_args	*ft_struct_init(char **argv, char **envp);



#endif
