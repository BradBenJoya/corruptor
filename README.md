# Corruptor

Corruptor is a small C++23 command-line utility that creates a damaged copy of one or more input files. Each output file receives a `.corrupted` suffix, so the original files remain unchanged.

## How to use

Run the program with one or more file paths. File paths can be listed in any order, and options can be placed anywhere in the command:

```bash
corruptor <file> [<file> ...] [-p] [-o]
```

Example:

```bash
corruptor homework.pdf notes.txt image.png
```

This creates one output for each input:

```text
homework.pdf.corrupted
notes.txt.corrupted
image.png.corrupted
```

### Preserve mode

By default, every byte in each file is replaced with a random byte. Preserve mode keeps non-alphanumeric bytes, such as whitespace and punctuation, and randomizes only alphanumeric bytes:

```bash
corruptor homework.pdf notes.txt -p
```

The long and short option names are equivalent:

```text
-preserve
-p
```

### Overwrite mode

By default, Corruptor writes each result to a new file with a `.corrupted` suffix. Use `-o` or `-overwrite` to modify the original file instead:

```bash
corruptor homework.pdf -o
```

Overwrite mode prints a warning and requires a `Y` confirmation before changing the file. The long and short option names are equivalent:

```text
-overwrite
-o
```

## Build

### Requirements

- CMake
- Ninja
- A C++23-compatible compiler
- Static versions of the compiler and system libraries

### Using Make

```bash
make build
```

Run the built program through Make by passing the input files with `ARGS`:

```bash
make run ARGS="homework.pdf notes.txt -p"
```

### Using CMake directly

```bash
cmake -S . -B bin -G Ninja
cmake --build bin
```

### Clean

```bash
make clean
```

