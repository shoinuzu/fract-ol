NAME	=	fract-ol

SRCS	=	ft_fract-ol.c		\
		ft_fract-ol_utils.c	\
		ft_fract-ol_koch.c	\
		ft_complex.c		\
		ft_mandelbrot.c		\

COMPILE	=	gcc -g -Wall -Wextra -Werror -lm

OBJS	=	$(SRCS:.c=.o)

REMOVE	=	rm -f

%.o: %.c
	$(COMPILE) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(REMOVE) $(OBJS)

fclean:
	$(REMOVE) $(OBJS)
	$(REMOVE) $(NAME)
re:
	make clean
	make
