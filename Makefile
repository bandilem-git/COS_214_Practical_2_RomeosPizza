# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Target executable
TARGET = TestingMain

# Automatically find all .cpp files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

# # Source files
# SOURCES = TestingMain.cpp \
#           PizzaStateContext.cpp \
#           InOven.cpp \
#           Plated.cpp \
#           Boxed.cpp

# # Object files (automatically generated from source files)
# OBJECTS = $(SOURCES:.cpp=.o)

# # Header files (for dependency tracking)
# HEADERS = PizzaStateContext.h \
#           PizzaState.h \
#           InOven.h \
#           Plated.h \
#           Boxed.h \
#           Pizza.h

# # Link object files to create executable
# $(TARGET): $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# # Compile source files to object files
# %.o: %.cpp $(HEADERS)
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

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

# Run the test
test: $(TARGET)
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
