CXX        := g++
BUILD      := ./build
OBJECTS_DIR:= $(BUILD)/objects
APP_DIR    := $(BUILD)/bin
PLY_READER := ./src/ply_reader.cc
OBJ_READER := ./src/obj_reader.cc
PLY_TARGET := plyr
OBJ_TARGET := objr
INCLUDE    := -Iinclude/
SRC        :=                      \
         $(wildcard src/core/*.cc) \

OBJECTS := $(SRC:%.cc=$(OBJECTS_DIR)/%.o)

all: build $(APP_DIR)/$(PLY_TARGET) $(APP_DIR)/$(OBJ_TARGET)

$(OBJECTS_DIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CXX) -std=c++17 $(INCLUDE) -o $@ -c $<
	
$(APP_DIR)/$(PLY_TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	# Install armadillo via CMAKE
	$(CXX) -std=c++17 $(INCLUDE) $(PLY_READER)  -o $(APP_DIR)/$(PLY_TARGET) $(OBJECTS) -larmadillo
	# install armadillo via manually ,link with OpenBLAS and LAPACK instead of the Armadillo runtime library
	# $(CXX) -std=c++17 $(INCLUDE) $(PLY_READER)  -o $(APP_DIR)/$(PLY_TARGET) $(OBJECTS)  -I /home/blah/include/ -DARMA_DONT_USE_WRAPPER -lopenblas -llapack

$(APP_DIR)/$(OBJ_TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) -std=c++17 $(INCLUDE) $(OBJ_READER)  -o $(APP_DIR)/$(OBJ_TARGET) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJECTS_DIR)

debug: all

release: all

clean:
	-@rm -rvf $(OBJECTS_DIR)/*
	-@rm -rvf $(APP_DIR)/app
