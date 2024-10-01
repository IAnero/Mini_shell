/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:35:49 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/26 18:44:52 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;
    char	*dest_start;

	dest_start = dest;
    i = 0;
	while (i < n && *src)
    {
		*dest++ = *src++;
        i++;
    }
	*dest = '\0';
	return (dest_start);
}
