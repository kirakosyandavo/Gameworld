CXX = g++

# Compiler flags
CXXFLAGS = -Wall -I./include

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Source files
SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Object files (replace .cpp with .o and put them in the obj directory)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Output executable
TARGET = GameWorld

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)