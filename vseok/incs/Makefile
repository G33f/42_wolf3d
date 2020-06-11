# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgreenfe <hgreenfe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 20:18:14 by hgreenfe          #+#    #+#              #
#    Updated: 2020/03/15 15:49:05 by hgreenfe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# used variables
NAME = wolf3d

SLASH = /

SRCDIR = srcs

OBJDIR = objs

LIBUIDIR = .
LIBDIR = libs/libft

INCDIR1 = incs
INCSDL = ./SDL/include

# PATH_SDL := $(addsuffix /libs, $(shell pwd))

ifeq ($(OS),Windows_NT)
	CD := $(shell cd)
else
	CD := $(shell pwd)
endif

PATH_SDL := $(addsuffix /libs, $(CD))
SDL :=  $(PATH_SDL)/SDL2/build/.libs

# used applications
CC = gcc
CCFLAGS = -Ofast -Wall -Wextra -Werror -pedantic-errors -I $(LIBDIR) -I $(INCDIR1) -I $(INCSDL) -g
AR = ar
ARFLAGS = -rs
RM = rm
RMFLAGS = -rf

#used files
FILES := main \
		level

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

libs:
	make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR1)
	@echo "test" $@ "" $(<) ""
	$(CC) $(CCFLAGS) -c -o $@ $<

$(SDL):
	cd $(PATH_SDL)/SDL2; ./configure --prefix=$(PATH_SDL); make;
	make -sC $(PATH_SDL)/SDL2 install

$(LIBDIR):
	make -sC $(LIBDIR)

$(NAME):libs $(OBJDIR) $(SDL) $(LIBDIR) $(FULL_OBJS)
	@echo $(CC) $(CCFLAGS) -o $(NAME) $(FULL_OBJS) $(LIBFLAGS)
	$(CC) $(CCFLAGS) -o $(NAME) $(FULL_OBJS) $(LIBFLAGS)

clean:
	make -C $(LIBDIR) clean
	$(RM) $(RMFLAGS) $(FULL_OBJS)

clean_sdl:
	echo $(PATH_SDL)
	make -C $(PATH_SDL)/SDL2 clean

fclean: clean clean_sdl
	make -C $(LIBDIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all
