/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:25:29 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/26 18:50:56 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strndup(const char *str, size_t n)
{
    size_t  len;
    char    *dup;

    len = ft_strnlen(str, n);
    dup = malloc(len + 1);

    if (!dup)
        return (NULL);
    ft_strncpy(dup, str, len);
    dup[len] = '\0';
    return (dup);
}
