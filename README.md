# 🚀 Electronic Arts Software Engineering Virtual Experience

![EA](https://img.shields.io/badge/Electronic%20Arts-Virtual%20Experience-blue?style=for-the-badge&logo=ea)

---

## 📌 Overview

This repository contains my work and solutions completed as part of the **Electronic Arts Software Engineering Virtual Experience Program**.

Through this program, I gained hands-on experience in real-world **game development workflows**, including debugging, optimization, and writing production-level C++ code.

---

## 🧩 System Design

Below is the class diagram of the **Dynamic Rivalry System** implemented during the project:

![Dynamic Rivalry System](./Dynamic%20rivalry%20system%20class%20diagram.jpg)

---

## 🧠 Key Learnings

- Writing clean and maintainable C++ code  
- Understanding **const correctness** and memory safety  
- Debugging real-world issues in existing codebases  
- Applying **OOP principles** in game systems  
- Code optimization in a collaborative environment  
- Writing meaningful commits and patches  

---

## 🛠️ Tasks Completed

### ✅ Task 1: Codebase Understanding
- Explored the existing system architecture  
- Understood class relationships and data flow  

### ✅ Task 2: Feature Enhancement
- Improved system functionality with better logic  
- Applied OOP concepts for modular design  

### ✅ Task 3: Code Review & Refactoring
- Refactored header files and improved structure  
- Fixed design issues and improved readability  
- Updated `.h` files using best practices  

### ✅ Task 4: Live Bug Fix & Optimization
- Identified and fixed runtime and compile-time errors  
- Resolved const reference issue  
- Optimized performance and improved code efficiency  

---

## 🐞 Problem Faced

- error: binding 'const Item' to reference of type 'Item&' discards qualifiers


### 🔍 Root Cause:
A `const Item` object was passed to a function expecting a non-const reference.

### ✅ Solution:
- Updated function signature to accept `const Item&`  
- Ensured read-only safety  
- Improved code correctness and robustness  

---

## ⚙️ Tech Stack

- **Language:** C++  
- **Concepts:** OOP, Debugging, Optimization  
- **Tools:** Git, GitHub  

---

## 📈 Outcome

- Successfully completed all assigned tasks  
- Improved debugging and problem-solving skills  
- Gained practical exposure to real-world game development scenarios  

---

## 📬 How to Run

```bash
g++ task-4-starter.cpp -o app
./app