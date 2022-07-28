/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <hejang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:20:48 by hejang            #+#    #+#             */
/*   Updated: 2022/07/29 00:45:46 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <memory.h>
# include "./philo_def.h"
# include "./utils.h"

int		create_philo(t_data *data);
void	*ft_philo(void *arg);

#endif