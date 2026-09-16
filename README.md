# Corruptor

Corruptor is a small C++ utility that takes an input file and creates a damaged copy with a `.corrupted` suffix. It is intended for testing how files degrade under non-destructive corruption patterns, especially for text-based files where the goal is to make them look like accidental damage rather than a full overwrite.

## How to use

Run the program with a file path:

```bash
corruptor <file_to_corrupt>
```

Example:

```bash
corruptor homework.pdf
```

This creates a new file named:

```bash
homework.pdf.corrupted
```

The original file remains unchanged.

## Build steps

### Requirements

- CMake
- Ninja
- A C++23-compatible compiler

### Build with the included Makefile

```bash
make build
```

### Or build manually

```bash
cmake -S . -B bin -G Ninja
cmake --build bin
```

### Clean the build directory

```bash
make clean
```

