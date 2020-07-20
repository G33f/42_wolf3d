/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:32:38 by hgreenfe          #+#    #+#             */
/*   Updated: 2020/06/13 21:56:53 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"

t_menu_button	*create_menu(t_game *game)
{
	t_menu_button	*menu;
	int				i;

	menu = ft_memalloc(sizeof(t_menu_button) * (int)G_MENU);
	menu[0].text = "QUIT";
	menu[1].text = "GAME";
	menu[2].text = "MAP_EDITOR";
	menu[3].text = "PAUSE";
	i = 0;
	while (i < (int)G_MENU)
	{
		menu[i].rect.w = game->font->letter_w * (int)ft_strlen(menu[i].text);
		menu[i].rect.h = game->font->letter_h;
		menu[i].rect.x = (game->rect->w - menu[i].rect.w) / 2;
		menu[i].rect.y = game->rect->h / 2 -
			(G_MENU - 2 * i) * game->font->letter_h;
		menu[i].state = (t_game_state)i;
		++i;
	}
	return (menu);
}

void			destroy_menu(t_game *game)
{
	ft_bzero(game->menu, sizeof(t_menu_button) * (int)G_MENU);
	ft_memdel((void**)&(game->menu));
}

int				event_keyup_menu(SDL_Event *event, t_game *game)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
	{
		if (game->state == G_MENU)
			game->state = G_QUIT;
	}
	if (event->key.keysym.sym == SDLK_RETURN)
	{
		game->state = G_PROCESS;
		SDL_ShowCursor(1);
	}
	return (NO_ERR);
}

int				event_mouse_menu(SDL_Event *event, t_game *game)
{
	SDL_Point	cursor;
	int			i;

	if (event->type == SDL_MOUSEBUTTONUP
	&& event->button.button == SDL_BUTTON_LEFT)
	{
		cursor = set_to(event->motion.x, event->motion.y);
		i = 0;
		while (i < (int)G_MENU)
		{
			if (SDL_PointInRect(&cursor, &(game->menu[i].rect)))
				game->state = game->menu[i].state;
			++i;
		}
	}
	return (NO_ERR);
}

int				render_menu_game(t_game *game)
{
	int		i;

	i = 0;
	while (i < G_MENU)
	{
		print_str(game, set_to(game->menu[i].rect.x, game->menu[i].rect.y),
			game->font, game->menu[i].text);
		++i;
	}
	return (NO_ERR);
}
