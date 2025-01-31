/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:38:15 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/31 03:09:18 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	error(char *str, int exit_code)
{
	ft_putstr_fd("\033[1;31m[ERROR]\033[0m : ", 2);
	ft_putstr_fd(str, 2);
	exit(exit_code);
}