#Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Files
SRCS = Lexer.cpp driver.cpp
TARGET = nell

# Default target - release build
all: release

# Debug build
debug: CXXFLAGS += -g -Og
debug: $(TARGET)

# Release build
release: CXXFLAGS += -O2
release: $(TARGET)

#Link and build target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

#Run compiled program
run: $(TARGET)
	./$(TARGET)

#Clean build files
Clean:
	rm -f $(TARGET)
