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

# Bonus part
BONUSNAME	:=	$(NAME:.a=_bonus.a)
BONUSSOURCE	:=	./bonus_part/ft_print_hex_bonus.c \
				./bonus_part/ft_print_char_bonus.c \
				./bonus_part/ft_print_uint_bonus.c \
				./bonus_part/ft_printf_bonus.c \
				./bonus_part/ft_print_ptr_bonus.c \
				./bonus_part/ft_print_str_bonus.c \
				./bonus_part/ft_print_int_bonus.c \
				./bonus_part/ft_flag_parser_bonus.c \
				./bonus_part/utils.c
BONUSOBJS	:= $(BONUSSOURCE:.c=.o)

# General use
LIBFT		:= libft.a
CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra
AR			:=	ar
ARFLAGS		:=	-rcs
RM			:=	rm -rf

$(NAME):	./libft/$(LIBFT) $(OBJS)
			cp ./libft/$(LIBFT) .
			$(AR) -rcs $(LIBFT) $(OBJS)
			cp $(LIBFT) $(NAME)

$(BONUSNAME):	./libft/$(LIBFT) $(BONUSOBJS)
				cp ./libft/$(LIBFT) $(BONUSNAME)
				$(AR) -rcs $(BONUSNAME) $(BONUSOBJS)
				cp $(BONUSNAME) $(NAME)

./libft/$(LIBFT):
					make -C libft/

%.o:		%.c $(INCLUDES)
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
