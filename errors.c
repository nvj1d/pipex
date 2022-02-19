/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:49:15 by mnajid            #+#    #+#             */
/*   Updated: 2022/02/13 18:02:57 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	simp_msg_ret(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_err_ex(char *err)
{
	perror(err);
	exit(1);
}
