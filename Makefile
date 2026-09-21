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
	./$(BUILD_DIR)/$(TARGET) essay.txt

clean:
	rm -rf $(BUILD_DIR)