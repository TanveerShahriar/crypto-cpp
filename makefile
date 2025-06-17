# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I./include 

# OpenSSL libraries
LIBS = -lssl -lcrypto

# Target directory and files
OUTDIR = output
TARGET = $(OUTDIR)/blockchain
SRC = src/Block.cpp src/Blockchain.cpp src/main.cpp

# Default target
all: $(TARGET) run

# Create output directory and compile
$(TARGET): $(SRC)
	mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Run the executable
run:
	$(TARGET)

# Clean up output folder
clean:
	rm -rf $(OUTDIR)

# Rebuild the project
rebuild: clean all