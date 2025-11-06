# 42 Exam 05 📚

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42 School](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)

A collection of advanced C/C++ programming exercises from the 42 School Exam 05. This repository contains implementations of complex data structures, algorithms, and problem-solving challenges.

## 📋 Table of Contents

- [Overview](#overview)
- [Structure](#structure)
- [Exercises](#exercises)
  - [Level 1](#level-1)
  - [Level 2](#level-2)
- [Compilation](#compilation)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

## 🎯 Overview

This repository contains solutions to various exam problems, organized by difficulty level. Each exercise focuses on different aspects of programming, from object-oriented design to algorithmic challenges.

## 📁 Structure

```
42-Exam05/
├── level1/
│   ├── bigint/          # Arbitrary precision integer implementation
│   ├── polyset/         # Set and bag data structures
│   └── vect2/           # 2D vector mathematical operations
└── level2/
    ├── BSQ/             # Biggest square finder algorithm
    └── LIFE/            # Conway's Game of Life simulator
```

## 🚀 Exercises

### Level 1

#### 🔢 BigInt
**Files:** `bigint.cpp`, `bigint.hpp`

A class implementing arbitrary precision integers with the following operations:
- Addition (`+`, `+=`)
- Increment (`++`, pre and post)
- Bit shift operations (`<<`, `<<=`, `>>=`)
- Comparison operators (`<`, `>`, `==`, `!=`, `<=`, `>=`)
- String output (`<<`)

**Features:**
- Handles integers larger than standard integer types
- Validates number strings
- Prevents leading zeros

---

#### 📐 Vect2
**Files:** `vect2.cpp`, `vect2.hpp`

A mathematical 2D vector class with integer components.

**Operations:**
- Addition and subtraction
- Scalar multiplication
- Array-style access via `operator[]` (indices 0 and 1)
- Stream output in format `{x, y}`

**Example:**
```cpp
vect2 v1(2, 3);
vect2 v2(1, 1);
vect2 result = v1 + v2 * 2;  // result: {4, 5}
std::cout << result;          // Output: {4, 5}
```

---

#### 📦 PolySet
**Files:** `searchable_array_bag.cpp/hpp`, `searchable_tree_bag.cpp/hpp`, `set.cpp/hpp`

Implementation of sets and bags using different underlying data structures.

**Components:**
- **Bag:** Abstract class representing a collection allowing duplicates
- **Searchable Bag:** Abstract class with search capabilities
- **Array Bag:** Bag implemented with array
- **Tree Bag:** Bag implemented with binary search tree
- **Searchable Array Bag:** Searchable variant of array bag
- **Searchable Tree Bag:** Searchable variant of tree bag
- **Set:** Wrapper class that converts a searchable bag into a mathematical set (no duplicates)

**Features:**
- Orthodox Canonical Form compliance
- Multiple data structure backends
- Const-correctness

---

### Level 2

#### 🟦 BSQ (Biggest Square)
**Files:** `bsq.c`, `bsq.h`

Finds the largest square of empty cells on a map avoiding obstacles.

**Input Format:**
```
[number_of_lines][empty_char][obstacle_char][full_char]
[map_line_1]
[map_line_2]
...
```

**Features:**
- Reads from file or stdin
- Validates map format
- Handles edge cases (multiple solutions, invalid maps)
- Displays the square closest to top-left when multiple solutions exist

**Example:**
```bash
$ cat map.txt
9.ox
...........................
....o......................
............o..............

$ ./bsq map.txt
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
```

**Allowed Functions:** `malloc`, `calloc`, `realloc`, `free`, `fopen`, `fclose`, `getline`, `fscanf`, `fputs`, `fprintf`, `printf`

---

#### 🎮 LIFE (Conway's Game of Life)
**Files:** `life.c`

Simulates Conway's Game of Life with custom board initialization.

**Usage:**
```bash
./life width height iterations
```

**Drawing Commands (stdin):**
- `w`, `a`, `s`, `d` - Move pen up, left, down, right
- `x` - Toggle pen drawing mode

**Rules:**
- Each cell outside the board is considered dead
- Alive cells represented by `O`
- Dead cells represented by space

**Example:**
```bash
$ echo 'dxss' | ./life 3 3 0
 O 
 O 
 O 

$ echo 'dxss' | ./life 3 3 1
   
OOO
   
```

**Allowed Functions:** `atoi`, `read`, `putchar`, `malloc`, `calloc`, `realloc`, `free`

---

## 🔨 Compilation

### C++ Exercises (Level 1)

```bash
# BigInt
cd level1/bigint
c++ -Wall -Wextra -Werror -std=c++98 bigint.cpp main.cpp -o bigint

# Vect2
cd level1/vect2
c++ -Wall -Wextra -Werror -std=c++98 vect2.cpp subject/main.cpp -o vect2

# PolySet
cd level1/polyset
c++ -Wall -Wextra -Werror -std=c++98 *.cpp subject/*.cpp -o polyset
```

### C Exercises (Level 2)

```bash
# BSQ
cd level2/BSQ
gcc -Wall -Wextra -Werror bsq.c -o bsq

# Game of Life
cd level2/LIFE
gcc -Wall -Wextra -Werror life.c -o life
```

## 📝 Notes

- All C++ exercises follow the **Orthodox Canonical Form**
- Code adheres to **42 Norminette** standards
- Exercises test understanding of:
  - Object-oriented programming
  - Data structures (arrays, trees, bags, sets)
  - Algorithm optimization
  - Memory management
  - File I/O
  - Standard input/output handling

## � Examples

Example input files are provided in the `examples/` directory:

- `bsq_example.txt` - Sample map for BSQ exercise
- `life_glider.txt` - Glider pattern for Game of Life

### Running Examples:

```bash
# BSQ
./bsq examples/bsq_example.txt

# Game of Life (glider pattern)
./life 10 10 4 < examples/life_glider.txt
```

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

Feel free to check the [issues page](https://github.com/aychikhi/42-Exam05/issues) if you want to contribute.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## �👤 Author

**aychikhi**

- GitHub: [@aychikhi](https://github.com/aychikhi)

---

<div align="center">

### 🌟 If you find this helpful, please star this repository! ⭐

**Made with ❤️ at 42 School**

</div>
