CMAKE ?= cmake
GENERATOR ?= Ninja
BUILD_DIR ?= bin
TARGET := corruptor
RELEASE ?= "Release"
ARGS ?= ""

.PHONY: all configure build rebuild run clean

all: build

configure:
	$(CMAKE) -S . -B $(BUILD_DIR) -G "$(GENERATOR)" -DCMAKE_BUILD_TYPE=$(RELEASE)

build: configure
	$(CMAKE) --build $(BUILD_DIR)

rebuild: clean build

run: build
	./$(BUILD_DIR)/$(TARGET) $(ARGS)

clean:
	rm -rf $(BUILD_DIR)