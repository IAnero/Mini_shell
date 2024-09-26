# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 10:26:08 by hrasolof          #+#    #+#              #
#    Updated: 2024/09/26 10:27:21 by hrasolof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS_C = -Wall -Werror -Wextra -g --lreadline

RM = rm -rf

SRCS = 	first_draft.c \
		src/simple_command.c

LIBFT_PATH = Libft

LIBFT = $(LIBFT_PATH)/libft.a

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME)..."
	cc $(FLAGS_C) $(SRCS) $(LIBFT) -o $(NAME)

all: $(NAME)

$(LIBFT) :
		@make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all