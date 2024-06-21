#all:g++ -Isrc/Include -Lsrc/lib -o main main.c -lmingw32 -lSDL2main -lSDL2
# Define variables
CC = g++
#-Isrc/CustomInclude 如果有寫其他的headerfile ，在src底下多創一個資料夾塞進去
CFLAGS = -Isrc/Include
LDFLAGS = -Lsrc/lib
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf


# Source files
# Add your additional .c files here. EX: SRCS = main.c otherfile1.c otherfile2.c
SRCS = main.c SDL_music.c SDL_basic.c SDL_breeding_farm_menu.c SDL_advisory_office_menu.c SDL_ticket_office_menu.c SDL_home_menu.c SDL_racingmenu.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
OUTPUT = main

# Default target
all: $(OUTPUT)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link .o files to generate executable
$(OUTPUT): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(OUTPUT) $(LIBS)

# Run target
run: $(OUTPUT)
	./$(OUTPUT)

# Clean target
clean:
	rm -f $(OBJS) $(OUTPUT)