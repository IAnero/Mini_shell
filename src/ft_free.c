/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:16:37 by herrakot          #+#    #+#             */
/*   Updated: 2024/11/04 12:17:18 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void free_tab(char **str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        free (str[i]);
        i++;
    }
    free (str);
}

void free_tab_struct(t_datatok *data)
{
    while (data->tab_i > 0)
        free (data->out[--data->index2]);
    free (data->out);
}