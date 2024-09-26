/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:29:11 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/26 18:44:35 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strnlen(const char *str, size_t maxlen)
{
    size_t i;

    i = 0;
    while (i < maxlen && str[i] != '\0')
        i++;
    return (i);
}