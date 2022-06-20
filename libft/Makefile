## PROGRAM ##

NAME = libft.a

## COMPILER ##

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = -rcs

## PATHS ##

SRCS_PATH = srcs

## SOURCES ##

SRCS_LIBFT = 	ft_isalpha.c \
	    		ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_striteri.c \

SRCS_PRINTF = 	printf.c \
				format.c \
				charstr.c \
				integer.c \

SRCS_FILES = $(SRCS_LIBFT)	$(SRCS_PRINTF)

OBJS = $(SRCS:%.c=%.o)

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

## CLEAN ##

RM  = rm -rf

## RULES ##

.PHONY: all clean fclean re

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

## ALL
all: $(NAME)

## NAME 
$(NAME): $(OBJS)
		@echo "Compiling $(NAME)..."
		ar $(ARFLAGS) $(NAME) $(OBJS)

## CLEAN
clean: 
	$(RM) $(OBJS)
	@echo -e "object fies deleted!"

## FCLEAN
fclean: clean
	$(RM) $(NAME)
	@echo -e "all files deleted!"

## RE
re: fclean all