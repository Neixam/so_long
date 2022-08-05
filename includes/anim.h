/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:07:45 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 13:18:18 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIM_H
# define ANIM_H
# define ATT_R_MONS "ressources/assets/character/monster/right-attack/\
right-attack-0.xpm"

# define ATT_L_MONS "ressources/assets/character/monster/left-attack/\
left-attack-0.xpm"

# define ATT_U_MONS "ressources/assets/character/monster/up-attack/\
up-attack-0.xpm"

# define ATT_D_MONS "ressources/assets/character/monster/down-attack/\
down-attack-0.xpm"

# define IDL_MONS "ressources/assets/character/monster/idle/idle-0.xpm"
# define IDL_R_PLA "ressources/assets/character/main/idle/right_idle/\
right-idle-0.xpm"

# define IDL_L_PLA "ressources/assets/character/main/idle/left_idle/\
left-idle-0.xpm"

# define IDL_U_PLA "ressources/assets/character/main/idle/up_idle/\
up-idle-0.xpm"

# define IDL_D_PLA "ressources/assets/character/main/idle/down_idle/\
down-idle-0.xpm"

# define PUP_R_PLA "ressources/assets/character/main/pickup/pickup-right/\
pickup-right-0.xpm"

# define PUP_L_PLA "ressources/assets/character/main/pickup/pickup-left/\
pickup-left-0.xpm"

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct s_anim
{
	t_img	**attack_monster;
	t_img	*idle_monster;
	t_img	**idle_player;
	t_img	**pickup_player;
}	t_anim;

int		init_anim(t_anim *a, void *mlx);

void	destroy_anim(t_anim *a, void *mlx);

int		alloc_all_anim(t_anim *a);

#endif
