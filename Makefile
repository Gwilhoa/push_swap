# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:12:30 by gchatain          #+#    #+#              #
#    Updated: 2022/02/09 10:41:51 by gchatain         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

ERASE		=	\033[2K\r
GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
BOLD		=	\033[1m
UNDER		=	\033[4m
SUR			=	\033[7m
END			=	\033[0m

LST_SRCS =   main.c push_swap_utils.c push_swap_display.c basic_function.c tri.c lst_high_low.c
INC = 0
LST_OBJS = ${LST_SRCS:.c=.o}
AR_LIBFT := libft/libft.a
DIR_LIBFT	:= libft
SRCS = $(addprefix sources/,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))
INCLUDES    = includes/push_swap.h libft/includes/libft.h
DIR_INCLUDES = $(sort $(addprefix -I, $(dir $(INCLUDES))))
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
NAME        = push_swap
RM          = rm -f
NORM        = $(shell norminette sources | grep -c 'Error!')

ifeq ($(NORM), 0)
	NORM_RET = "${ERASE}${GREEN}[DONE]${END} ${NAME}"
else
	NORM_RET = "${ERASE}${RED}[NORM]${END} ${NAME}"
endif
all:        ${NAME}

.objects/%.o:	sources/%.c ${INCLUDES} | .objects
			${CC} ${CFLAGS} -c $< -o $@ ${DIR_INCLUDES}
			printf "${ERASE}${BLUE}[BUILD]${END} $<"

${NAME}:	${OBJS} ${INCLUDES} Makefile ${LIBRARY} $(AR_LIBFT)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${AR_LIBFT} ${DIR_INCLUDES}
			printf $(NORM_RET)

clean:
			${RM} ${OBJS}
			@make fclean -s -C libft
			printf "${RED}[DELETE]${END} directory .objects"

fclean:	clean
			${RM} -r ${NAME} .objects
			printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:			fclean all

.objects:
			mkdir -p .objects

$(AR_LIBFT):
	$(MAKE) -C libft

.PHONY:	all clean fclean re compilation

.SILENT:
