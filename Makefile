# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Target executable
TARGET = TestingMain

# Automatically find all .cpp files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

# Default build
all: $(TARGET)

# Shortcut for just 'make'
make: all

# Compile and link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the executable under valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Run the executable under gdb
gdb: $(TARGET)
	gdb $(TARGET)
