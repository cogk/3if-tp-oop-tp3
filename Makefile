CC        = g++
<<<<<<< HEAD
CFLAGS    = -ansi -pedantic -Wall -Werror -std=c++11
=======
CFLAGS    = -ansi -pedantic –Wall -Werror –std=c++11
>>>>>>> 73d83bff3d68196c7054c701770786ce7aee93ac
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
