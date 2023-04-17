CC = g++
INCLUDE_DIR = include
BUILD_DIR = build
CFLAGS = -std=c++20 -I $(INCLUDE_DIR)
SOURCES = main.cpp src/Tape.cpp src/Init.cpp src/TapeSort.cpp
EXECUTABLE = tape_sorting

all: build

build: $(SOURCES)
	$(CC) $^ $(CFLAGS) -o $(BUILD_DIR)/$(EXECUTABLE)

run:
	./$(BUILD_DIR)/$(EXECUTABLE) data/input1.txt data/output.txt

clean:
	rm $(BUILD_DIR)/* tmp/* data/output.txt