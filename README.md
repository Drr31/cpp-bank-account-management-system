# Bank Account Management System

A console-based Bank Account Management System built in C++.  
This application allows users to create accounts, deposit money, withdraw cash, and store account information using file handling.

> This project was originally developed as a C++ learning project and later improved and documented for portfolio presentation.

---

## Features

- Create new bank accounts
- Store account number and password
- Deposit cash into accounts
- Withdraw cash securely using password verification
- Save account data into text files
- File-based account management system
- Simple console-based interface

---

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling (`fstream`)
- String Stream Processing (`stringstream`)
- Console Input/Output

---

## Project Structure

```text
cpp-bank-account-management-system/
├── main.cpp
├── README.md
├── LICENSE
├── .gitignore
└── Account.txt
```

---

## How It Works

1. User creates a bank account
2. Account details are stored in `Account.txt`
3. User can:
   - Deposit cash
   - Withdraw money
4. The system updates balances automatically
5. Temporary files are used for safe account updates

---

## Sample Menu

```text
Welcome to Bank Account Management System
******************************************
1 Open New Account
2 Add Cash
3 Withdraw Cash
4 Exit
```

---

## How to Compile and Run

### Linux / macOS

```bash
g++ main.cpp -o bank-system
./bank-system
```

### Windows

```bash
g++ main.cpp -o bank-system.exe
bank-system.exe
```

---

## Concepts Demonstrated

- Classes and Objects
- Encapsulation
- File Handling
- Data Persistence
- String Parsing
- Conditional Logic
- Loops and User Menus

---

## Possible Future Improvements

- Encrypt passwords
- Add account balance checking
- Add money transfer between accounts
- Add transaction history
- Improve validation and error handling
- Build a graphical interface
- Store data using a database

---

## Notes

This project uses plain text files for storing account information.  
It was designed for educational purposes and does not implement advanced banking security features.

---

## Author

Developed as part of learning and practicing C++ programming concepts.

---

## License

This project is licensed under the MIT License.
