/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:47:53 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/12/14 14:50:26 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_isinf(long double nb)
{
	if (nb == (1.0 / 0.0) || nb == (-1.0 / 0.0))
		return (1);
	return (0);
}
