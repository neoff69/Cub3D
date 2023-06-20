.PHONY:					all $(NAME) clear mkbuild lib minilibx clean fclean re sanitize

NAME					= cub3D

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= cub.h	\
							typedef.h	\

DIR						=	src/
SRC						=	main.c	exit.c	\
							parsing/parsing_cub.c	parsing/p_parameters.c parsing/p_list_utils.c	\
							parsing/p_analyse_list.c parsing/p_map_array.c	parsing/p_map_utils.c parsing/p_utils.c	\
							exec/exec_cub.c \
							exec/init_img.c \
							exec/get_line.c \
							exec/hook/hook.c \
							exec/hook/hook_deplacement.c \
							exec/hook/hook_rotation.c \
							exec/hook/hook_check.c \
							exec/display/utils/display_utils.c \
							exec/display/utils/display_pixel.c \
							exec/display/minimap/display_minimap.c \
							exec/display/minimap/display_minimap_character.c \
							exec/display/minimap/draw_line_algorithm.c \
							exec/display/display_environnement/display_environnement.c \
							exec/display/display_environnement/draw_all_sprites.c \
							exec/display/minimap/draw_line_algorithm_utils.c \
							
OBJECTS					= $(SRC:%.c=$(BUILD_DIR)%.o)
	
LIBFT					= libft.a
LIB_DIR					= libft/

MINILIB					= libmlx.a
MINILIB_DIR				= minilibx-linux/

LINUX 					= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz
GCC						= cc
CFLAGS					= -Wall -Werror -Wextra -g3 -O2
SANITIZE				= $(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)* libft Makefile
						@mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I/usr/include -O3 -c $< -o $@

all: 					clear mkbuild lib minilibx $(HEADER_DIR) $(NAME) 
						
mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)

sanit :					$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)

lib:
						@make -C $(LIB_DIR)

minilibx:
						@make -C $(MINILIB_DIR)
						
clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)

re:						fclean all
						$(MAKE) all
