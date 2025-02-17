#created executable file
NAME = libft.a

#compiler
CC = cc
#compiler flags
CFLAGS = -Wall -Wextra -Werror -g

#archiver with it's flags and filename.
ARNAME = ar rcs $(NAME)

#delete with flags
RM = rm -f

#all mandatory files
SRCS =	$(addprefix ft_, $(addsuffix .c, atoi bzero calloc isalnum \
		isalpha	isascii isdigit isprint itoa memchr memcmp memcpy \
		memmove memset putchar_fd putendl_fd putnbr_fd putstr_fd \
		split strchr strdup striteri strjoin strlcat strlcpy strlen \
		strmapi strncmp strnstr strrchr strtrim substr tolower toupper))
#turns source files into object files
OBJS := $(SRCS:%.c=%.o)

#finds all BONUS files in sourcefolder endning on _bonus.c
BONUS_SRCS = $(addprefix ft_, $(addsuffix _bonus.c, lstnew lstadd_back \
			 lstadd_front lstclear lstdelone lstiter lstlast lstmap \
			 lstnew lstsize))
#turns BONUS source files into object files
BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)
#name of the created file for check if any function needs recompilation.
BONUS = libft_bonus

ALL_OBJS = $(OBJS) $(BONUS_OBJS)

#runs $(NAME)
all: $(NAME)

#creates the library for the mandatory part
$(NAME): $(OBJS)
	$(ARNAME) $^

#compiles only bonus files and creates a seperate file named libft_bonus.
#That file is only there to check if Library needs to be redone (to not re-link)
$(BONUS) : $(BONUS_OBJS)
	$(ARNAME) $^
	touch $(BONUS)

bonus: $(BONUS)

# Combined rule to build both normal and bonus
allbonus: $(ALL_OBJS)
	$(ARNAME) $^

#deletes all object files
clean:
	$(RM) $(ALL_OBJS)

#runs clean and deletes library
fclean: clean
	$(RM) $(NAME) $(BONUS)

#runs fclean and $(NAME)
re: fclean $(NAME)

.PHONY: all, bonus, clean, fclean, re, allbonus

