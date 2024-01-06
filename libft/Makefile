NAME = libft.a
SRC_FILES = ft_atoi.c \
	    	ft_bzero.c \
			ft_calloc.c \
	    	ft_isalnum.c \
	    	ft_isalpha.c \
	    	ft_isascii.c \
	    	ft_isdigit.c \
	    	ft_isprint.c \
			ft_itoa.c \
	    	ft_memchr.c \
	    	ft_memcmp.c \
	    	ft_memcpy.c \
	    	ft_memmove.c \
	    	ft_memset.c \
	    	ft_putchar_fd.c \
	    	ft_putendl_fd.c \
	    	ft_putnbr_fd.c \
	    	ft_putstr_fd.c \
	    	ft_split.c \
	    	ft_strchr.c \
			ft_strcmp.c \
			ft_strcpy.c \
	    	ft_strdup.c \
			ft_striteri.c \
			ft_strjoin_nl.c \
			ft_strjoin.c \
	    	ft_strlcat.c \
	    	ft_strlcpy.c \
	    	ft_strlen.c \
			ft_strmapi.c \
	    	ft_strncmp.c \
	    	ft_strnstr.c \
	    	ft_strrchr.c \
			ft_strtrim.c \
	    	ft_substr.c \
			ft_tolower.c \
	    	ft_toupper.c \
			ft_printnbrs.c \
			ft_putstrs.c \
			ft_printhexa.c \
			ft_printpointer.c \
			ft_printf.c \
			ft_realloc.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			./sprintf/ft_sprintf_hexa.c \
			./sprintf/ft_sprintf_itoa.c \
			./sprintf/ft_sprintf_pointer.c \
			./sprintf/ft_sprintf_strdup.c \
			./sprintf/ft_sprintf_uitoa.c \
			./sprintf/ft_sprintf.c \

OBJECTS = $(patsubst %.c, %.o, $(SRC_FILES))
INCLUDE = libft.h ./sprintf/sprintf.h
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)


%.o: %.c $(INCLUDE)
		$(CC) $(FLAGS) -I ./ -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
