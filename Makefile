CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
BUILDDIR = build
OBJDIR = build/$(SRCDIR)
SOURCE = get_next_line.c
OBJECTS = $(SOURCE:%.c=$(OBJDIR)/%.o)

SRCDIR_SHARED = src_shared
OBJDIR_SHARED = build/$(SRCDIR_SHARED)
SOURCE_SHARED = get_next_line_utils_1.c get_next_line_utils_2.c
OBJECTS_SHARED = $(SOURCE_SHARED:%.c=$(OBJDIR_SHARED)/%.o)

SRCDIR_BONUS = src_bonus
OBJDIR_BONUS = build/$(SRCDIR_BONUS)
SOURCE_BONUS = get_next_line_bonus.c
OBJECTS_BONUS = $(SOURCE_BONUS:%.c=$(OBJDIR_BONUS)/%.o)

.PHONY: all clean fclean re

all: $(OBJECTS_SHARED) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR): | $(BUILDDIR)
	mkdir $(OBJDIR)

$(OBJECTS_SHARED): $(OBJDIR_SHARED)/%.o: $(SRCDIR_SHARED)/%.c | $(OBJDIR_SHARED)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR_SHARED): | $(BUILDDIR)
	mkdir $(OBJDIR_SHARED)

$(OBJECTS_BONUS): $(OBJDIR_BONUS)/%.o: $(SRCDIR_BONUS)/%.c | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR_BONUS): | $(BUILDDIR)
	mkdir $(OBJDIR_BONUS)

$(BUILDDIR):
	mkdir $(BUILDDIR)

bonus: $(OBJDIR_SHARED) $(OBJECTS_BONUS)

clean:
	rm -r -f $(OBJECTS) $(OBJECTS_SHARED) $(OBJECTS_BONUS)

fclean: clean

re: fclean all