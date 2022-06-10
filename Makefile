NAME_PS = pipex

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)
INCLUDES_BONUS = -I$(HEADERS_DIRECTORY_BONUS) -I$(LIBFT_HEADERS)

LIBFT_A = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft_src/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)


HEADERS_LIST = pipex.h
HEADERS_DIRECTORY = ./src/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./src/
SOURCES_LIST = 	main.c		utils.c		errors.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
OBJECTS_DIRECTORY = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

HEADERS_LIST_BONUS = pipex_bonus.h
HEADERS_DIRECTORY_BONUS = ./src_bonus/
HEADERS_BONUS = $(addprefix $(HEADERS_DIRECTORY_BONUS), $(HEADERS_LIST_BONUS))

SOURCES_DIRECTORY_BONUS = ./src_bonus/
SOURCES_LIST_BONUS = 	main_bonus.c		utils_bonus.c		errors_bonus.c

SOURCES_BONUS = $(addprefix $(SOURCES_DIRECTORY_BONUS), $(SOURCES_LIST_BONUS))
OBJECTS_DIRECTORY_B = ./objects_b/
OBJECTS_LIST_BONUS = $(patsubst %.c, %.o, $(SOURCES_LIST_BONUS))
OBJECTS_BONUS	= $(addprefix $(OBJECTS_DIRECTORY_B), $(OBJECTS_LIST_BONUS))

.PHONY: all clean fclean re bonus

all: $(NAME_PS)

$(NAME_PS): $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(MAKE) -sC $(LIBFT_DIRECTORY)
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME_PS)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

bonus: $(OBJECTS_DIRECTORY_B) $(OBJECTS_BONUS)
	$(MAKE) -sC $(LIBFT_DIRECTORY)
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES_BONUS) $(OBJECTS_BONUS) -o $(NAME_PS)

$(OBJECTS_DIRECTORY_B):
	mkdir -p $(OBJECTS_DIRECTORY_B)

$(OBJECTS_DIRECTORY_B)%.o : $(SOURCES_DIRECTORY_BONUS)%.c $(HEADERS_BONUS)
	$(CC) $(FLAGS) -c $(INCLUDES_BONUS) $< -o $@

clean:
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)
	rm -rf $(OBJECTS_DIRECTORY_B)

fclean: clean
	rm -f $(LIBFT_A)
	rm -f $(NAME_PS)

re:
	$(MAKE) fclean
	$(MAKE) all