# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 16:00:35 by aeddi             #+#    #+#              #
#    Updated: 2014/05/18 23:37:03 by aeddi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	client
NAME2			=	serveur
CC				=	cc
GDB				?=	0
ifeq ($(GDB), 1)
	CFLAGS		=	-Wall -Wextra -Werror -pedantic -g3 -I $(LIBFT_DIR) -I $(INCS_DIR)
else
	CFLAGS		=	-Wall -Wextra -Werror -pedantic -O3 -I $(LIBFT_DIR) -I $(INCS_DIR)
endif
LFLAGS			=	-L $(LIBFT_DIR) -lft
LIBFT_DIR		=	./libft
INCS_DIR		=	./includes
OBJS_DIR		=	./objects
SRCS_DIR		=	./sources
OBJS			=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS2			=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS2))
SRCS			=	client.c				\
					local_command.c			\
					get_put_client.c		\
					send_command.c			\
					prompt.c
SRCS2			=	server.c				\
					receive_command.c		\
					get_put_server.c		\
					dist_command.c			\
					dist_command_aux.c

all				:	$(NAME) $(NAME2)

$(NAME)			:	$(OBJS_DIR) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

$(NAME2)		:	$(OBJS_DIR) $(OBJS2)
	$(CC) -o $(NAME2) $(OBJS2) $(LFLAGS)

$(OBJS_DIR)/%.o	:	$(addprefix $(SRCS_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^


$(OBJS_DIR)		:	make_libft
	@mkdir -p $(OBJS_DIR)

make_libft		:
	@$(MAKE) -C $(LIBFT_DIR)

fclean			:	clean
	rm -f $(NAME) $(NAME2)

clean			:
	rm -rf $(OBJS_DIR)

re				:	fclean all

.PHONY: clean all re fclean
