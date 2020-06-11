/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:52:31 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/03/15 15:21:35 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#include "SDL2/SDL.h"

# define WOLF3D_H
# define WIN_SIZE		512
# define WIN_SIZE_W		640
# define WIN_SIZE_H		480
# define WIN_POS_X		512
# define WIN_POS_Y		512
# define WIN_TITLE		"Wolf 3D"
# define	FD_ERR		2
# define	NO_ERR		0
# define	SIZE_ERR	-1
# define	MEM_ERR		-2
# define	VERSION_ERR	-3
# define	SDL_ERR		-4
# define	MAP_ERR		-5
# define	PLY_ERR		-6

typedef double		numeric;

typedef enum		e_game_state {
	G_QUIT = 0,
	G_PROCESS = 1,
	G_MENU = 2,
	G_PAUSE = 3
}					t_game_state;

typedef struct		s_player {
	numeric			pos_x;
	numeric			pos_y;
	numeric			watch_x;
	numeric			watch_y;
	numeric			watch_z;
}					t_player;

typedef	struct		s_map {
	int				size_x;
	int				size_y;
	char			*array;
	int				startpos;
	int				endpos;
	int				version;
}					t_map;

typedef struct		s_game {
	SDL_Window		*wnd;
	SDL_Renderer	*rnd;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Rect		*rect;
	t_game_state	state;
	t_player		*player;
	t_map			*level;
}					t_game;

t_map	*load_map_from_file(char const *filename);

#endif //WOLF3D_H
