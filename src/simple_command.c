/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:15:50 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/26 10:24:40 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int ft_cd(char **av)
{
    if (av[1] == NULL)
    {
        printf("minishell: cd: expected argument\n");
        return (1);
    }
    else
    {
        if (chdir(av[1] != 0))
            perror("minishell");
    }
    return (0);
}

int ft_echo(char **av)
{
    int i;
    int newline;

    i = 1;
    newline = 1;
    if (av[1] && ft_strcmp(av[1], "-n") == 0)
    {
        newline = 0;
        i = 2;
    }
    while (av[i])
    {
        printf("%s", av[i]);
        if (av[i + 1] == NULL)
            printf(" ");
        i++;
    }
    if (newline)
        printf("\n");
    return (0);
}

int ft_pwd()
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);
    else
        perror("minishell");
    return (0);
}

int ft_exit()
{
    printf("exit\n");
    exit(0);
    return (0);
}
