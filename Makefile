# Mandatory part
NAME		:=	libftprintf.a
INCLUDES	:=	-I includes
SOURCE		:=	./source/ft_print_hex.c \
				./source/ft_print_char.c \
				./source/ft_print_uint.c \
				./source/ft_printf.c \
				./source/ft_print_ptr.c \
				./source/ft_print_str.c \
				./source/ft_print_int.c
OBJS 		:=	$(SOURCE:.c=.o)
HEADER		:=	./includes/ft_printf.h

# Bonus part
BONUSNAME	:=	$(NAME:.a=_bonus.a)
BONUSSOURCE	:=	$(SOURCE:./source/%.c=./bonus_part/%_bonus.c) \
				./bonus_part/ft_flag_parser_bonus.c \
				./bonus_part/utils_bonus.c
BONUSOBJS	:=	$(BONUSSOURCE:.c=.o)
BONUSHEADER	:=	./bonus_part/ft_printf_bonus.h

# General use
LIBFT		:= libft.a
CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra
AR			:=	ar
ARFLAGS		:=	-rcs
RM			:=	rm -rf

$(NAME):	./libft/$(LIBFT) $(OBJS) $(HEADER)
			cp ./libft/$(LIBFT) .
			$(AR) -rcs $(LIBFT) $(OBJS)
			cp $(LIBFT) $(NAME)

$(BONUSNAME):	./libft/$(LIBFT) $(BONUSOBJS) $(BONUSHEADER)
				cp ./libft/$(LIBFT) $(BONUSNAME)
				$(AR) -rcs $(BONUSNAME) $(BONUSOBJS)
				cp $(BONUSNAME) $(NAME)

./libft/$(LIBFT):
					make -C libft/

%.o:		%.c
			$(CC) -c $(CFLAGS) -o $@ $<

all: 		$(NAME)

bonus:		$(BONUSNAME)

clean:
			$(RM) $(OBJS) $(BONUSOBJS)
			make -C libft/ clean

fclean:		clean
			$(RM) $(NAME) $(BONUSNAME) $(LIBFT)
			make -C libft/ fclean

re:		fclean all

.PHONY: all clean fclean re
