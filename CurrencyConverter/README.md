# Currency Converter in C++

A command-line based Currency Converter written in C++ that allows users to:

- Load exchange rates from a file
- Set or update currency rates
- Retrieve individual currency rates
- Convert between any two supported currencies
- View all available exchange rates

---

## 📁 File Structure


- currencyConverter/main.cpp      // Main source code
- currency.txt                    // Input file with currency codes and rates

---

## 📄 Sample currency.txt Format

```

USD 1
INR 83.2
EUR 0.92
JPY 154.3
GBP 0.79
AUD 1.52
CAD 1.36

```

Each line contains a currency code and its exchange rate relative to a base currency (USD here).

---

## 🛠 Features

- Modular class-based structure
- Easy-to-extend currency file format
 
- **STL `map`**: Utilized for storing currency codes as keys and their corresponding exchange rates as values.
- Menu-driven user interface for easy access to conversion and rate management options.
- Option to load exchange rates from a text file and update rates interactively.
- Input validation for currency codes to ensure only valid ones are processed.

---

## 🚀 How to Run

1. Make sure you have a C++ compiler (like g++) installed.
2. Compile the program:
```

g++ -o main.cpp

```
3. Run the executable: a.exe/a.out
```

./currencyConverter

```

---

## 📌 Example Use

- **Set Exchange Rate**: Add or update a currency exchange rate (e.g., EUR to USD).
- **Get Exchange Rate**: Retrieve the exchange rate for a given currency.
- **Convert Currency**: Convert an amount between two currencies.
- **Display All Rates**: View all stored exchange rates.

---

## 👤 Author

**Name:** [Mohd Moshir Khan]  
**LinkedIn:** [https://www.linkedin.com/in/moshir-khan](https://www.linkedin.com/in/moshir-khan/)

---

## 📄 License

This project is free to use and modify.
