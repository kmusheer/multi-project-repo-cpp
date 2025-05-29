
# 🎓 Student Database Management System

A **console-based Student Database Management System** developed in **C++**, designed to manage student academic records efficiently. It supports features like adding, editing, deleting, searching, and displaying student data. All records are stored in **JSON format** using the [nlohmann/json](https://github.com/nlohmann/json) library.

---

## 🧰 Features

- ✅ Add new student with **unique ID** generation  
- ✅ Edit existing student details  
- ✅ Delete student records  
- ✅ Search student by **ID**  
- ✅ Display all students in a **formatted table**  
- ✅ Save records to a **JSON file**  
- ✅ Load records from file on **startup**  
- ✅ Continues **ID tracking** correctly after reloading  
- ✅ **Regex-based input validation** for:
  - Name  
  - Email  
  - Contact Number  

---

## 📁 Student Record Structure

Each student entry includes:

- `ID` – Auto-generated (e.g., `V24HE2M01`)
- `Name`
- `Email`
- `Contact Number`
- `Date of Birth` (day, month, year)
- `SSC Marks`
- `Pre-Degree Type` – Inter or Diploma
- `Pre-Degree Marks`
- `Degree Marks`

---

## 📦 File Format (JSON)

All student data is stored in `studentLib.json` with the following format:

```json
[
  {
    "id": "V24HE2M01",
    "name": "Mack Smith",
    "email": "mack.smith@example.com",
    "contact": "9876543210",
    "dob": {
      "day": 15,
      "month": 6,
      "year": 1998
    },
    "ssc": 88.5,
    "preDegree": 72.3,
    "degree": 78.5,
    "preDegreeType": "Diploma"
  }
]
```

---

## 🔐 Input Validation (Using Regex)

Input fields are validated using **regular expressions** to ensure data consistency:

```cpp
regex nameRegex("^[A-Za-z ]+$");
regex emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
regex contactRegex(R"(^(\+?\d{1,4}[- ]?)?\d{10}$)");

regex_match();
```

---

## 🛠️ Technologies Used

* **C++17**
* [nlohmann/json](https://github.com/nlohmann/json) for JSON handling
* Standard Template Library (**STL**) – `map`, `vector`, `string`, etc.

---

## 🧾 How to Run (on Windows)

1. **Install Dependencies**

   * Install [MinGW](https://www.mingw-w64.org/) or any C++ compiler with C++17 support
   * Ensure `g++` and `make` are available in your system's PATH

2. **Clone the Repository**:

   ```bash
   git clone https://github.com/kmusheer/student-db-manager.git
   cd student-db-manager
   ```

3. **Build the Project**:

   ```bash
   make
   ```

4. **Run the Executable**:

   ```bash
   studentDB.exe
   ```

---

## 🧾 Makefile Example

```makefile
CXX = g++
CXXFLAGS = -std=c++17
OBJ = main.o studentLib.o lib.o
TARGET = studentDB.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	del *.o *.exe
```

---

## 👤 Author

**Mohd Moshir Khan**
🔗 [LinkedIn: moshir-khan](https://www.linkedin.com/in/moshir-khan/)

---

## 📜 License

Licensed under the **MIT License** – you are free to use, modify, and distribute it.

