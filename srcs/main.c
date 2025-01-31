/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:30:44 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/31 03:19:20 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **argv, char **env)
{
	int	i;
	int	infile;
	int	outfile;

	infile = 0;
	outfile = 0;
	if (ac <= 4)
		error("not enough arguments (./pipex infile {COMMANDS} outfile)\n", 1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		outfile = open_file(argv[ac - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		infile = open_file(argv[1], 0);
		dup2(infile, 0);
	}
	dup2(infile, 0);
	while (i < ac - 2)
		my_pipe(argv[i++], env);
	if (outfile == 0)
		outfile = open_file(argv[ac - 1], 1);
	dup2(outfile, 1);
	exec(argv[ac - 2], env);
}
