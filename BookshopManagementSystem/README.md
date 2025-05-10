### 📄

# 📚 Bookshop Management System (C++)

This repository contains three versions of a simple Bookshop Management System project built using **C++**, showcasing a gradual improvement of features and functionality in each version.

---

## 🧩 Version 1: Basic Bookshop Management

> 📁 Folder: `main.cpp/`    ||  `v1_basic`

### ✅ Features:
- Add book
- Show all books
- Search for a book by name
- Update book details
- Delete a book
- Save and load books from a file

### 💡 Description:
This version is a basic terminal-based bookshop manager. The book records are stored and retrieved using a simple `.txt` file. Each operation is done via standard input/output.

---

## 🧩 Version 2: Purchase and Inventory Management

> 📁 Folder: `mainWithFileManagment/`   ||  `v2_purchase_inventory`

### ✅ Features:
- All Version 1 features
- Buy a book
- Quantity management (decrement on purchase)
- Inventory check (insufficient stock warning)
- User prompts to confirm purchase

### 💡 Description:
This version introduces an inventory system. Users can buy books, and the system keeps track of quantity. After each transaction, the file is updated with the new quantity.

---

## 🧩 Version 3: User/Admin Authentication + Role-based Access

> 📁 Folder: `mainFileWithUser/`    ||  `v3_authentication_roles`

### ✅ Features:
- All Version 2 features
- Admin and User registration
- Role-based login system (admin/user)
- Masked password input using `getch()`
- Random password generator for registration
- Append multiple users to `user.txt`
- Admin access to all features
- User access limited to:
  - View books
  - Search books
  - Buy books

### 💡 Description:
The final version adds user authentication. Admins can manage books, while users can only view, search, or buy. Credentials are saved in `user.txt`. Passwords can be manually entered or randomly generated.

---

## 🔐 Planned/Optional Enhancements:
- Encrypt stored passwords (e.g., hashing)
- Validate duplicate usernames on registration
- Role-based session timeout or logout
- Book categorization (genre, author filter)
- UI enhancement using a GUI framework (e.g., Qt)

---
Sure! Here's the workflow snippet you can add under **v3\_authentication\_roles** in your `README.md`:

```markdown
### 🧭 User Login Workflow Example

```

1. Registration
2. Login
3. Exit
   Enter your choice: 2
   Enter your login credentials
   User name : jack
   Password: ***

Login successful as user.

User Menu:

1. Show Books
2. Search Book
3. Buy Book
4. Exit
   Enter your choice:

---

## 👨‍💻 Author

**Name:** Mohd Moshir Khan 
**LinkedIn:** [linkedin.com/in/moshir-khan](https://www.linkedin.com/in/moshir-khan/)

---

## 📁 Folder Structure

```bash
multi-project-repo-cpp/
│
├── BookshopManagementSystem/
│   └── main.cpp
│   └── mainWithFileManagment.cpp
│   └── mainFileWithUser.cpp
    └── README.md
````

---

## 🧪 How to Run

Make sure you have a C++ compiler installed (e.g., g++ on Linux/Windows).

```bash
g++ main.cpp -o bookshop
./bookshop
```

*Note: `getch()` is a Windows-specific function from `<conio.h>`. On Linux, it needs alternatives like `getchar()` or using `ncurses`.*

---

## 📜 License

MIT License – feel free to use, modify, and contribute.

