/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 01:08:00 by hece              #+#    #+#             */
/*   Updated: 2023/05/09 01:09:08 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "global.h"

void	signal_ctrlc(int sig);
void	signal_ctrlc_heredoc(int sig);
int		termios_change(bool echo_ctl_chr);

#endif
