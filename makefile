# Define the compiler and the flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra -pedantic 

# Define the target executable
TARGET = main

# Find all .cpp files and convert them to .o files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run with valgrind
run: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) 2> valgrind_log.txt

# Run with gdb
debug: $(TARGET)
	gdb -ex run --args ./$(TARGET) 2>&1 | tee gdb_log.txt

# Clean up the build files
clean:
	rm -f $(OBJS) $(TARGET) valgrind_log.txt gdb_log.txt

# Phony targets
.PHONY: all run debug clean# Define the compiler and the flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra -pedantic 

# Define the target executables
TESTING_TARGET = testing
DEMO_TARGET = demo

# Find all .cpp files excluding main files
COMMON_SRCS = $(filter-out TestingMain.cpp DemoMain.cpp, $(wildcard *.cpp))
COMMON_OBJS = $(COMMON_SRCS:.cpp=.o)

# Default target
all: $(TESTING_TARGET) $(DEMO_TARGET)

# Build the testing executable
$(TESTING_TARGET): TestingMain.o $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TESTING_TARGET) TestingMain.o $(COMMON_OBJS)

# Build the demo executable
$(DEMO_TARGET): DemoMain.o $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) DemoMain.o $(COMMON_OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the testing executable with valgrind
run: $(TESTING_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TESTING_TARGET) 2> valgrind_log.txt

# Run the demo executable with valgrind
demo_run: $(DEMO_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(DEMO_TARGET) 2> valgrind_log.txt

# Run the testing executable with gdb
debug: $(TESTING_TARGET)
	gdb -ex run --args ./$(TESTING_TARGET) 2>&1 | tee gdb_log.txt

# Run the demo executable with gdb
demo_debug: $(DEMO_TARGET)
	gdb -ex run --args ./$(DEMO_TARGET) 2>&1 | tee gdb_log.txt

# Clean up the build files
clean:
	rm -f $(COMMON_OBJS) TestingMain.o DemoMain.o $(TESTING_TARGET) $(DEMO_TARGET) valgrind_log.txt gdb_log.txt

# Phony targets
.PHONY: all run demo_run debug demo_debug clean
