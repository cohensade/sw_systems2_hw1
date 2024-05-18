CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES = Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default target to build the main executable
all: main test

# Build the main executable
main: main.o $(filter-out main.o TestCounter.o Test.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build the test executable
test: TestCounter.o Test.o $(filter-out main.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run clang-tidy on the source files
tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# Run valgrind on the executables
valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test

# Compile the object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS) main test
