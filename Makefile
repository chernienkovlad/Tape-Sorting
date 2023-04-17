CC = g++
INCLUDE_DIR = include
BUILD_DIR = build
CFLAGS = -std=c++20 -I $(INCLUDE_DIR) -Wall -Wextra
SOURCES = main.cpp src/Tape.cpp src/Init.cpp

all: build

build: $(SOURCES)
	$(CC) $^ $(CFLAGS) -o $(BUILD_DIR)/tape_sorting

clean:
	rm $(BUILD_DIR)/*