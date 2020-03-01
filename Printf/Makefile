
CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = char_trans.c trans_tools.c str_trans.c ft_ulltoa_base.c pos_trans.c int_trans.c unsign_trans.c ft_itoa_base.c hex_trans.c percent_trans.c flags_utils.c ft_printf.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
		cd Libft && $(MAKE)
		cp Libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./Libft
fclean : clean
		rm -f $(NAME)
		rm -f libft.a
		$(MAKE) fclean -C ./Libft
re : fclean all

%.o: %.c
	$(CC) $(FLAGS) -I ft_printf.h -c $<  -o $(<:.c=.o)
