CMAKE ?= cmake
GENERATOR ?= Ninja
BUILD_DIR ?= bin
TARGET := corruptor

.PHONY: all configure build rebuild run clean

all: build

configure:
	$(CMAKE) -S . -B $(BUILD_DIR) -G "$(GENERATOR)"

build: configure
	$(CMAKE) --build $(BUILD_DIR)

rebuild: clean build

run: build
	echo "This is a test to see if the program runs correctly." > test.txt
	./$(BUILD_DIR)/$(TARGET) test.txt

clean:
	rm -rf $(BUILD_DIR)