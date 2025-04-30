# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 09:37:05 by ljudd             #+#    #+#              #
#    Updated: 2025/04/30 14:23:38 by ljudd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
NAME			= test
#NAME			= libftprintf.a
SOURCES			= ft_printf.c \
	ft_printf_type1.c \
	ft_printf_type2.c \
	ft_printf_conv1.c \
	ft_printf_conv2.c
HEADER			= ft_printf.h
INCLUDES		= ft_printf.h -Ilibft
OBJECTS			= $(SOURCES:.c=.o)

LIBFT			= libft.a
LIBFT_FLAGS		= -Llibft -lft
#LIBFT_FLAGS		= -lft
LIBFT_DIR		= ./libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAGS) -o $(NAME)
#	cp $(LIBFT_DIR)/$(LIBFT) ./
#	mv $(LIBFT) $(NAME)
#	ar rcs $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all --no-print-directory
	make -C $(LIBFT_DIR) bonus --no-print-directory

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus $(LIBFT)