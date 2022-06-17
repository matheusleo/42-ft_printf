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

LIBFT		:= libft.a
FT_PRINTF	:= ft_printf.a

CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra
AR			:=	ar
ARFLAGS		:=	-rcs
RM			:=	rm -rf

$(NAME): 	./libft/$(LIBFT) $(OBJS)
			$(AR) -rcs ./libft/$(LIBFT) $(OBJS)
			mv ./libft/$(LIBFT) $(NAME)

./libft/$(LIBFT):
			make -C libft/

$(FT_PRINTF):	$(OBJS)
				$(AR) $(ARFLAGS) $(FT_PRINTF) $(OBJS)

%.o:		%.c $(INCLUDES)
			$(CC) -c $(CFLAGS) -o $@ $<

all: 		$(NAME)

clean:
			$(RM) $(OBJS)
			make -C libft/ clean

fclean:		clean
			$(RM) $(NAME)
			make -C libft/ fclean

re:		fclean all

.PHONY: all clean fclean re
