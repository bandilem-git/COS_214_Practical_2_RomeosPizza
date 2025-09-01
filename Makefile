# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -fprofile-arcs -ftest-coverage
LDFLAGS  = -fprofile-arcs -ftest-coverage

# Target executable
TARGET = TestingMain

# Source and object files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Compile and link executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Run the executable under Valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Generate coverage report
coverage: $(TARGET)
	@echo "Running tests to generate coverage data..."
	./$(TARGET)
	@echo "Generating coverage report..."
	gcov -o . *.cpp
	@echo "Coverage report generated (.gcov files)."

# Clean object files, executable, and coverage files
clean:
	rm -f $(OBJS) $(TARGET) *.gcda *.gcno *.gcov
