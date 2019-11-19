CC        = g++
CFLAGS    = -g -Wall -Werror
EXEC_NAME = application
INCLUDES  =
LIBS      =
SRCS      = $(wildcard src/*.cpp)
OBJS      = $(addprefix tmp/,$(notdir $(SRCS:.cpp=.o)))

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
