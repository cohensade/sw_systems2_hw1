# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Wextra
# TARGET = main
# SRCS = Graph.cpp Algorithms.cpp main.cpp
# OBJS = $(SRCS:.cpp=.o)

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJS) $(TARGET)


# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = Graph.cpp Algorithms.cpp main.cpp Test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = main

# Targets
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test.o: Test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)