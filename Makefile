# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 20:18:14 by hgreenfe          #+#    #+#              #
#    Updated: 2020/06/17 08:45:49 by hgreenfe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# used variables
NAME = wolf3d

SLASH = /

SRCDIR = srcs

OBJDIR = objs

LIBUIDIR = .
LIBDIR = ./libs/libft/

LIB_OBJS		= $(addprefix $(LIBDIR), $(LIB_OBJ))
LIB_OBJ			= *.o
LIB_H			= libft.h
LIB_INC			= $(addprefix $(LIBDIR), $(LIB_H))
WOLF_HED		= reader.h \
				wolf3d.h \
				libft.h
WOLF_INC		= $(addprefix $(INCDIR1), $(WOLF_HED))

INCDIR1 = ./incs/
INCSDL = ./SDL/include

# PATH_SDL := $(addsuffix /libs, $(shell pwd))

ifeq ($(OS),Windows_NT)
	CD := $(shell cd)
else
	CD := $(shell pwd)
endif

PATH_SDL := $(addsuffix /libs/SDL2/SDL2-2.0.12, $(CD))
SDL :=  $(PATH_SDL)/build/.libs

# used applications
CC = gcc
CCFLAGS = -Ofast -Wall -Wextra -Werror -pedantic-errors -g
AR = ar
ARFLAGS = -rs
RM = rm
RMFLAGS = -rf
INCFLAGS = -I$(LIBDIR) -I$(INCDIR1) -I$(INCSDL)
#used files
FILES := editor \
	event \
	fonts \
	game \
	game_menu \
	level \
	main \
	map \
	player \
	process_game \
	ray \
	render \
	texture \
	utils \
	utils2 \
	map_reader \
	loops \
	window

HEADERS = $(INCDIR1)/SDL2/SDL.h

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

FULL_SRCS = $(addprefix $(SRCDIR)/, $(SRCS))
FULL_OBJS = $(addprefix $(OBJDIR)/, $(OBJS))

FRAMEWORK = -framework OpenGL -framework Cocoa
#  -framework iconv

LIBFLAGS = -lm -L$(LIBDIR) -lft -L$(SDL) -lSDL2
# -L $(LIBSDIR)$(LIBUIDIR) -l$(LIBUI)
# -L $(SDLIMGDIR) -lSDL2_image

# vpath %.c $(SRCDIR)/
# vpath %.o $(OBJDIR)/

.PHONY: all re clean fclean

all: $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(LIBDIR)%.o: $(LIBDIR)%.c $(LIB_INC)
	make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(WOLF_INC)
	@echo "test" $@ "" $(<) ""
	$(CC) $(CCFLAGS) $(INCFLAGS) -c -o $@ $<

$(SDL):
	cd $(PATH_SDL); ./configure --prefix=$(PATH_SDL)/..; make;
	make -sC $(PATH_SDL) install

$(NAME): $(LIB_OBJS) $(OBJDIR) $(SDL) $(FULL_OBJS)
	@echo $(CC) $(CCFLAGS) $(INCFLAGS) -o $(NAME) $(FULL_OBJS) $(LIBFLAGS)
	$(CC) $(CCFLAGS) $(INCFLAGS) -o $(NAME) $(FULL_OBJS) $(LIBFLAGS)

clean:
	make -C $(LIBDIR) clean
	$(RM) $(RMFLAGS) $(FULL_OBJS)

clean_sdl:
	echo $(PATH_SDL)
	make -C $(PATH_SDL)$(SLASH) clean

fclean: clean clean_sdl
	make -C $(LIBDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

# test:
# 	$(CC) $(CCFLAGS) -o test_$(NAME) objs/level.o test.c $(LIBFLAGS)