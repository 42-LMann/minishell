# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmann <lmann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 14:47:34 by lmann             #+#    #+#              #
#    Updated: 2022/06/20 14:47:39 by lmann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## PROGRAM ##

NAME := minishell

## COMPILER ##

CC = gcc

CFLAGS := -Wall -Wextra -Werror

MAKE := make

## PATHS ##

SRCS_PATH := srcs
INCS_PATH := includes
LFT_PATH := libft

## LIBS/PROGRAMS/EXTERN FUNCTIONS##

LINKS :=  -lft
INCS := $(addprefix -I , $(INCS_PATH) $(LFT_PATH)/$(INCS_PATH))
LIBS := $(addprefix -L , $(LFT_PATH)) $(LINKS)
FLAGS := $(CFLAGS) $(INCS) $(LIBS)

## SOURCES ##

SRCS := $(wildcard $(SRCS_PATH)/*/*.c) $(wildcard $(SRCS_PATH)/*.c)

OBJS := $(SRCS:%.c=%.o)

## CLEAN ##

RM = rm -rf

## RULES ##

.PHONY: all clean fclean re

%.o: %.c
	@$(CC) -c $(CFLAGS) $(INCS) $< -o $@

## ALL
all: $(NAME)

## NAME
$(NAME): $(OBJS)
	@$(MAKE) -sC $(LFT_PATH)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	

## CLEAN	
clean:
	@$(MAKE) clean -C $(LFT_PATH)
	@$(RM) $(OBJS)
	@echo "object fies deleted!"

## FCLEAN
fclean: clean
	@$(MAKE) fclean -C $(LFT_PATH) 
	@$(RM) $(NAME)
	@echo "all files deleted!"
	
## RE
re: fclean all

test:
	@echo $(LIBS)

## -The "Test" Rule- ##
## this is Just for testing for what exists in INCS, SRCS and LIBS ##
## e.g make test while set to $(SRCS) will output all .c related to fdf ##

git:
	@clear
	@git add .
	@echo "commit msg" 
	@read COMMIT; \
	git commit -m "$$COMMIT"; \
	git push;