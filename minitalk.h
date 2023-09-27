/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:39:00 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/09/09 15:54:57 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <signal.h>

int		ft_atoi(char *n);
int		ft_printf(const char *str, ...);
int		ft_isdigit(int n);

#endif