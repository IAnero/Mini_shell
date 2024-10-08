/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:48:52 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/27 18:43:37 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int built_in_command(char **av)
{
    if (!av[0])
        return (1);
    if (ft_strcmp(av[0], "cd") == 0)
        return (ft_cd(av));
    else if (ft_strcmp(av[0], "exit") == 0)
        return (ft_exit(av));
    return (0);
}
