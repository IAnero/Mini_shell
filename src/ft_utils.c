/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:49:40 by herrakot          #+#    #+#             */
/*   Updated: 2024/11/04 13:54:05 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int     ft_search_until_egal(char *str, char *str_tocompare)
{
    int i;
    char *tmp = NULL;

    i = 0;
    while (str_tocompare[i] != '=')
        i++;
    tmp = malloc(sizeof(char *) * i);
    tmp = ft_strncpy(tmp, str_tocompare, i);
    if (ft_strcmp(tmp, str))
        return (0);
    else
        return (1);
}