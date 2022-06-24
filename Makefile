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
BONUSSOURCE	:=	./bonus/ft_print_hex_bonus.c \
				./bonus/ft_print_char_bonus.c \
				./bonus/ft_print_uint_bonus.c \
				./bonus/ft_printf_bonus.c \
				./bonus/ft_print_ptr_bonus.c \
				./bonus/ft_print_str_bonus.c \
				./bonus/ft_print_int_bonus.c \
				./bonus/ft_flag_parser_bonus.c \
				./bonus/utils.c
BONUSOBJS	:= $(BONUSSOURCE:.c=.o)

# General use
LIBFT		:= libft.a
CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra
AR			:=	ar
ARFLAGS		:=	-rcs
RM			:=	rm -rf

$(NAME): 	./libft/$(LIBFT) $(OBJS)
			$(AR) -rcs ./libft/$(LIBFT) $(OBJS)
			cp ./libft/$(LIBFT) .
			mv $(LIBFT) $(NAME)

bonus:		./libft/$(LIBFT) $(BONUSOBJS)
			$(AR) -rcs ./libft/$(LIBFT) $(BONUSOBJS)
			cp ./libft/$(LIBFT) .
			mv $(LIBFT) $(NAME)

./libft/$(LIBFT):
			make -C libft/

%.o:		%.c
			$(CC) -c $(CFLAGS) -o $@ $<

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUSOBJS)
			make -C libft/ clean

fclean:		clean
			$(RM) $(NAME)
			make -C libft/ fclean

re:		fclean all

.PHONY: all clean fclean re
