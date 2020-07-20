cmake_minimum_required(VERSION 3.14)
project(wolf3d C)
set(CMAKE_C_STANDARD 99)

find_library(SDL_LIB SDL2
        PATHS
        libs/SDL2/VisualC/Win32/Debug)
#find_library(FT_LIB libft
#        PATHS
#        libs/libft)


include_directories(incs)
add_subdirectory(libs/libft)
add_subdirectory(libs/SDL2/SDL2-2.0.12)

link_directories(libs/SDL2/build/.libs libs/libft)
link_libraries(SDL2 libft)
# link_directories(test_level libs/libft)
# link_libraries(test_level libft)
# link_libraries(${SDL_LIB})

# link_libraries(../libs/libft/libft.lib ../libs/SDL2/VisualC/Win32/Debug/SDL2.lib)
message(VERBOSE, ${SDL_LIB})
message(VERBOSE, ${FT_LIB})

# add_executable(test_level test.c incs/wolf3d.h srcs/level.c)
add_executable(wolf3d srcs/main.c incs/wolf3d.h srcs/level.c srcs/player.c srcs/game.c srcs/window.c srcs/event.c srcs/map.c srcs/render.c srcs/utils.c srcs/utils2.c srcs/fonts.c srcs/process_game.c srcs/game_menu.c srcs/ray.c srcs/editor.c srcs/texture.c srcs/map_reader.c incs/reader.h srcs/loops.c)