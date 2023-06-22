CXX      := g++
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/bin
MAIN     := ./src/main.cc 
TARGET   := 3dmr
INCLUDE  := -Iinclude/
SRC      :=                      \
         $(wildcard src/core/*.cc) \

OBJECTS := $(SRC:%.cc=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CXX) -std=c++17 $(INCLUDE) -o $@ -c $<
	
$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	# Install armadillo via CMAKE
	$(CXX) -std=c++17 $(INCLUDE) $(MAIN)  -o $(APP_DIR)/$(TARGET) $(OBJECTS) -larmadillo
	# install armadillo via manually ,link with OpenBLAS and LAPACK instead of the Armadillo runtime library
	# $(CXX) -std=c++17 $(INCLUDE) $(MAIN)  -o $(APP_DIR)/$(TARGET) $(OBJECTS)  -I /home/blah/include/ -DARMA_DONT_USE_WRAPPER -lopenblas -llapack

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: all

release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/app
