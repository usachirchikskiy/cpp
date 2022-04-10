CC = g++
CFLAGS = -Wall -g

<<<<<<< HEAD
#Folders
SRC = src
OBJ = obj

BINDIR = bin
BIN = $(BINDIR)/main

SRC_TEST = test
BIN_TEST = $(BINDIR)/helloTest
=======
SRC = src
OBJ = obj

BINDIR = output
BIN = $(BINDIR)/main

SRC_TEST = test
BIN_TEST = $(BINDIR)/test
>>>>>>> lab3

INCLUDE = -I include
INCLUDE_TEST:= -I cppunit

<<<<<<< HEAD
LD_LIBRARY_PATH=/usr/local/lib
#Getting files in folders
=======
>>>>>>> lab3
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

SRCS_TEST = $(wildcard $(SRC_TEST)/*.cpp)
OBJS_TEST= $(filter-out $(OBJ)/main.o, $(OBJS)) $(SRCS_TEST:$(SRC_TEST)/%.cpp=$(OBJ)/%.o)

<<<<<<< HEAD
#DEPENDENCIES = $(OBJS:.o=.d)

#SUBMITNAME = project.zip

#echo $LD_LIBRARY_PATH

lab2:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ && ./$(BIN)
=======

lab3:$(BIN)
	cd $(BINDIR) && ./main

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 
>>>>>>> lab3

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -MMD -o $@

test:$(BIN_TEST)

<<<<<<< HEAD

$(BIN_TEST):$(OBJS_TEST)
	$(CC) $(CFLAGS) $^ -lcppunit -o $@ && ./$(BIN_TEST)
=======
$(BIN_TEST):$(OBJS_TEST)
	$(CC) $(CFLAGS) $^ -lcppunit -o $@ && cd $(BINDIR) && ./test
>>>>>>> lab3

$(OBJ)/%.o: $(SRC_TEST)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -MMD -o $@

clean:
<<<<<<< HEAD
	$(RM) -r $(BINDIR)/* $(OBJ)/*

#--------------------------------------------------------------
# CXX      := g++
# CXXFLAGS := -Wall -g
# LDFLAGS  := -L/usr/lib -lstdc++ -lm
# BUILD    := ./bin
# OBJ_DIR  := $(BUILD)/objects
# APP_DIR  := $(BUILD)/apps
# TARGET   := lab2
# INCLUDE  := -Iinclude/
# SRC      := $(wildcard src/*.cpp)         \

# OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
# DEPENDENCIES := $(OBJECTS:.o=.d)

# lab2: build $(APP_DIR)/$(TARGET)

# $(OBJ_DIR)/%.o: %.cpp
# 	@mkdir -p $(@D)
# 	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

# $(APP_DIR)/$(TARGET): $(OBJECTS)
# 	@mkdir -p $(@D)
# 	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

# -include $(DEPENDENCIES)

# build:
# 	@mkdir -p $(APP_DIR)
# 	@mkdir -p $(OBJ_DIR)

# clean:
# 	-@rm -rvf $(OBJ_DIR)/*
# 	-@rm -rvf $(APP_DIR)/*

# submit:
# 	$(RM) $(SUBMITNAME)
# 	zip $(SUBMITNAME) $(BIN)

#g++ -std=c++17 test/helloTest.cpp -lcppunit obj/testHeader.o -o bin/mainTest
#--------------------------------------------------------------
=======
	$(RM) -r $(BINDIR)/* $(OBJ)/*
>>>>>>> lab3
