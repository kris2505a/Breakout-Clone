# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -m64 -I./Vendor/SFML/include -I./src/Headers

# Directories
SRC_DIR = src
BIN_DIR = bin
BUILD_DIR = build
LIB_DIR = Vendor/SFML/lib

# Executable name
TARGET = Game

# Sources and objects
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Default rule
all: $(BIN_DIR)/$(TARGET)

# Create output directories
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Link the executable
$(BIN_DIR)/$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) -o $@ $^ -L$(LIB_DIR) -lsfml-graphics -lsfml-window -lsfml-system

# Compile .cpp files to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up the build artifacts
.PHONY: clean
clean:
	del /Q $(BUILD_DIR)\*.o 2>nul
	del /Q $(BIN_DIR)\$(TARGET).exe 2>nul  # Remove the .exe file

# Run the program
.PHONY: run
run: $(BIN_DIR)/$(TARGET)
	$(BIN_DIR)\$(TARGET).exe