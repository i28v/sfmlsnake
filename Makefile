CC = g++
src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -Wall -O2 -I/usr/include/SFML/ -I./include/ -lsfml-graphics -lsfml-window -lsfml-system

snake: $(obj)
	$(CXX) -s $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(LDFLAGS) -c $< -o $@

clean: 
	rm -f $(obj) snake
