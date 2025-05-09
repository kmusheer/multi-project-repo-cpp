
# Terminal-Based Login and Registration System in C++

This is a simple C++ terminal application that simulates a **login and registration system** with masked password input and an optional random password generator.

## 💡 Features

- ✅ **Registration**
  - User can enter a custom password or generate a random one.
  - Password confirmation with limited attempts.
- ✅ **Login**
  - Masked password input using `*` characters.
  - Limited login attempts (3 tries).
- ✅ **Random Password Generator**
  - Includes uppercase, lowercase, digits, and special characters.
- ✅ **Cross-platform (Windows-focused with `<conio.h>`)**

---

## 🛠️ Technologies Used

- C++
- Standard Library (`<iostream>`, `<string>`, `<cstdlib>`, `<ctime>`)
- `<conio.h>` for real-time key input (Windows only)

---

## 🧪 How to Run

1. Compile the program using a C++ compiler (Windows):

   ```bash
   g++ main.cpp -o login_system

2. Run the executable:

   ```bash
   ./login_system
  

---

## 📸 Sample Flow

```plaintext
 r:Registration
 l:Login
 q:Quit
Enter your choice: r
Enter your name : Alice
Enter your choice 1:generatePassword     2:userPassword : 1
Enter range of password : 10
Your password is : aB$4fG!zX2

Enter your choice: l
Enter your login credentials
User name : Alice
Password: **********
Login successfully
```

---

## ⚠️ Notes

* This code uses `_getch()` from `<conio.h>`, which is **specific to Windows**.
* For Unix/Linux support, you would need to replace `_getch()` with an equivalent using `<termios.h>`.
* Passwords are stored in plain text in memory.

---

## 📚 Future Enhancements (Ideas)

* Store multiple users in a file or map
* Encrypt passwords using hashing (e.g., SHA-256)
* Make the system platform-independent (use `<termios.h>` on Linux)
* Add password strength checking

---

## 👤 Author

**Mohd Moshir Khan**
*Created as a simple demonstration of login systems using basic C++ features.*

> You can replace this with your actual name, [LinkedIn Profile Link](https://www.linkedin.com/in/moshir-khan/).
---

## 📝 License

This project is released under the [MIT License](https://opensource.org/licenses/MIT).

```
