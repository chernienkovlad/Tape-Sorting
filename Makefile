CC = g++
INCLUDE_PATH = include
BUILD_PATH = build
CFLAGS = -std=c++20 -I $(INCLUDE_PATH)
SOURCES = main.cpp src/Tape.cpp

all: build

build: $(SOURCES)
	$(CC) $^ $(CFLAGS) -o $(BUILD_PATH)/tape_sort

clean:
	rm $(BUILD_PATH)/*