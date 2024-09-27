/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:14:53 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/27 11:35:25 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

int ft_special_char(char c)
{
    return (c == '>' || c == '<' || c == '|' || c == ' ' || c == '\t');
}

static size_t   word_count(const char *str)
{
    size_t  i;
    size_t  w_count;
    
    i = 0;
    w_count = 0;
    while (str[i])
    {
        while (str[i] && ft_isspace(str[i]))
            i++;
        if (str[i] && !ft_special_char(str[i]))
        {
            w_count++;
            while (str[i] && !ft_special_char(str[i]))
                i++;
        }
        while (str[i] && ft_special_char(str[i]))
            i++;
    }
    return (w_count);
}

char	**ft_toksplit(const char *str)
{
    size_t  i;
    size_t  j;
    size_t  w_len = 0;
    int     k;
    char    **out;

    out = malloc(sizeof(char *) * (w_len + 1));
    if (!out)
        return (NULL);
    i = 0;
    k = 0;
    w_len = word_count(str);
    while (str[i])
    {
        while (str[i] && ft_isspace(str[i]))
            i++;
        j = i;
        while (str[i] && !ft_special_char(str[i]))
            i++;
        if (i > j)
        {
            out[k] = malloc(sizeof(char) * ((i - j) + 1));
            if (!out)
                return (NULL);
            ft_strncpy(out[k++], &str[j], i - j);
        }
        while (str[i] && ft_special_char(str[i]))
            i++;
    }
    out[k] = NULL;
    return (out);
}

