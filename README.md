# 📚 C Data Structures and Algorithms

A comprehensive repository dedicated to studying and implementing **Data Structures and Algorithms in C**, based on classical computer science literature and practical exercises.

This project is inspired by the books:
- *Data Structures Using C* by Aaron M. Tenenbaum
- *C: The Complete Reference* by Herbert Schildt

---

## 🎯 Objectives

This repository was created to:

- Reinforce **core programming concepts in C**
- Implement **classic data structures from scratch**
- Study and compare **algorithmic techniques**
- Apply concepts in **real-world data processing applications**
- Build a **solid foundation for advanced computer science topics**

---

## 🧠 Topics Covered

### 🔹 Fundamentals
Basic building blocks of C programming:

- Variables and data types  
- Conditionals and loops  
- Functions  
- Pointers  
- Arrays and strings  
- Structs and unions  

---

### 🔹 Data Structures

Implementations built from scratch with modular design:

- Stack (static and dynamic)
- Queue
- Deque
- Singly Linked List

Each structure includes:
- Header file (`.h`)
- Source implementation (`.c`)
- Example usage (`main.c`)
- Time and space complexity notes

---

### 🔹 Algorithms

#### Sorting Algorithms
- Bubble Sort
- Insertion Sort
- Selection Sort
- Merge Sort
- Quick Sort

#### Searching Algorithms
- Linear Search
- Binary Search

---

### 🔹 Applications (Real Data)

Practical programs applying data structures and algorithms:

- 📊 **Brazilian Championship Data Analyzer**  
  CSV processing of Brasileirão Série A statistics

- 🧱 **Minecraft Items Loader**  
  Parsing and organizing structured game item data

- 🗳️ **Voting System Simulation**  
  File-based vote processing and counting

---

### 🔹 Advanced Topics

- Dynamic Memory Allocation
- File I/O
- Multithreading in C

---

## 📁 Project Structure

```
c-library/
│
├── fundamentals/
├── data_structures/
├── algorithms/
├── applications/
└── advanced/
```

## ⚙️ How to Compile and Run

All programs are written in standard C (C99 or later).

### Compile (GCC)

```bash
gcc file.c -o program

```
### Run
```bash
./program
```

## 🧪 Example
``` c
#include "stack.h"

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);

    printf("Top: %d\n", top(&s));

    pop(&s);

    return 0;
}
```
## 📈 Learning Outcomes

By studying and maintaining this repository, the following skills are developed:

- Low-level memory management

- Pointer manipulation

- Algorithm complexity analysis

- Modular programming in C

- Problem solving with real datasets


## 🧑‍💻 Author
```
Lorenzo Calabrese Circelli
Computer Engineering Student

Focus areas: Algorithms, Systems Programming, and Applied Computing

Passionate about mathematics, physics, and software engineering
```

## 📜 License

This project is licensed under the MIT License.

## 🤝 Contributions

This repository is primarily for educational purposes, but suggestions and improvements are always welcome.