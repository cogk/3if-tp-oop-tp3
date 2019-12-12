CC        = g++
CFLAGS    = -ansi -pedantic -Wall -Werror -Wextra -std=c++11
# ajout du flag -Wextra
EXEC_NAME = application
INCLUDES  =
LIBS      =
SRCS      = $(wildcard src/*.cpp)
OBJS      = $(addprefix tmp/,$(notdir $(SRCS:.cpp=.o)))

ifdef DEBUG
	CFLAGS += -DMAP -g
endif

all: directories $(EXEC_NAME)

.PHONY: clean all

clean:
	rm $(EXEC_NAME) $(OBJS) || true
	rmdir tmp || true

$(EXEC_NAME): $(OBJS)
	$(CC) -o $(EXEC_NAME) $(OBJS) $(LIBS)

directories:
	mkdir -p tmp

tmp/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
