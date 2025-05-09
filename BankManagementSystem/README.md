
### 📄

# 🏦 Bank Account Management System (C++)

This repository contains two versions of a **Bank Account Management System** implemented in C++ using object-oriented programming. It is a console-based application with menu-driven navigation, supporting basic bank account operations.

---

## 📁 Versions

### 1. **Bank Account System (In-Memory Only)**
- Implements core banking features using classes and a menu system.
- All account data is stored in memory — it resets when the program ends.
- Ideal for understanding object-oriented design in C++.

**Features:**
- Create account
- Display account
- Modify account
- Deposit/withdraw funds
- Display all accounts

---

### 2. **Bank Account System with File Handling**
- Enhances the previous version by adding **binary file handling**.
- All account data is **persisted in a binary file** (`accounts.dat`).
- Automatically loads last account number on startup to avoid duplicates.

**Additional Features:**
- Persistent data storage
- Prevents duplicate account numbers
- Allows delete/modify operations directly on file

**File Used:**
- `accounts.dat` – stores serialized account objects in binary format.

---

## 🛠️ Tech Stack

- **Language:** C++
- **Concepts Used:**  
  - Classes & Objects  
  - File I/O with `fstream`  
  - Binary serialization  
  - Static members  
  - Console-based UI (menu)

---

## 🔧 How to Compile and Run

```bash
# Compile
g++ -o BankSystem main.cpp
c++ -o BankSystem main.cpp

# Run
./BankSystem
````

*Ensure your compiler supports C++11 or later.*

---

## 🧪 Sample Menu Output

```text
===== BANK ACCOUNT MANAGEMENT SYSTEM =====
1. Create new account
2. Display account details
3. Modify account
4. Delete account
5. Display all accounts
6. Deposit money
7. Withdraw money
0. Exit
Enter your choice:
```

---

## 📌 Notes

* Account numbers start from **1000** and auto-increment.
* Input validation is minimal — focus is on file operations and OOP.
* The file version must be run multiple times to fully observe persistence features.

---

## 📚 Educational Use

This project is ideal for students and beginners to:

* Understand how classes and objects work in C++
* Learn binary file I/O
* Practice menu-based application design
* Explore real-world use of `reinterpret_cast` and `seekp`

---

## 👤 Author

**Mohd Moshir Khan**
*[linkedIn profile link](https://www.linkedin.com/in/moshir-khan/).*

---

## 📄 License

This project is open-source and free to use for learning and teaching purposes.

```