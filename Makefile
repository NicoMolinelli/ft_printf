# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmolinel <nmolinel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/15 21:49:17 by nmolinel      #+#    #+#                  #
#    Updated: 2021/12/16 16:41:14 by nmolinel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c

CONF_SRCS	=	param.c	\
				ref.c

CONV_SRCS	= 	char.c	\
				signed.c	\
				unsigned.c	\
				string.c

UTIL_SRCS	= 	flag.c	\
				number.c \
				string.c

CONF_DIR	=	config
CONV_DIR	=	conversion
UTIL_DIR	=	util
INCL_DIR	=	includes
OBJS_DIR	=	objs
OBJS_SUBDIR	=	$(OBJS_DIR)/$(CONF_DIR) $(OBJS_DIR)/$(CONV_DIR) $(OBJS_DIR)/$(UTIL_DIR)

SRCS		+=	$(addprefix $(CONF_DIR)/, $(CONF_SRCS))
SRCS		+=	$(addprefix $(CONV_DIR)/, $(CONV_SRCS))
SRCS		+=	$(addprefix $(UTIL_DIR)/, $(UTIL_SRCS))

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC 			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -I $(INCL_DIR)

RM			=	rm -f

all: ${NAME}

${NAME}: $(OBJS_DIR) ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@echo ${NAME} created!

bonus: ${NAME}

$(OBJS_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR):
	@mkdir -p $@ $(OBJS_SUBDIR)

clean:
	${RM} -r $(OBJS_DIR) $(OBJS) $(B_OBJS)

fclean:	clean
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY: all bonus clean fclean re
