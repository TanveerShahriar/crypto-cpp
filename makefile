# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# OpenSSL libraries
LIBS = -lssl -lcrypto

# Target executable
TARGET = blockchain

# Source files
SRC = blockchain.cpp

# Default target
all: $(TARGET)

# Link the source file directly to create the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Clean up the executable
clean:
	rm -f $(TARGET)

# Rebuild the project
rebuild: clean all