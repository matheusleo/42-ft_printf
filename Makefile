# Mandatory part
NAME		:=	libftprintf.a
INCLUDES	:=	./includes/libft.h \
				./includes/ft_printf.h
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
				./bonus/ft_flag_parser_bonus.c
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
			mv ./libft/$(LIBFT) $(NAME)

bonus:		./libft/$(LIBFT) $(BONUSOBJS)
			$(AR) -rcs ./libft/$(LIBFT) $(BONUSOBJS)
			mv ./libft/$(LIBFT) $(NAME)

./libft/$(LIBFT):
			make -C libft/

%.o:		%.c $(INCLUDES)
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
