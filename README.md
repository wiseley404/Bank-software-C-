# 🏦 Banking Software (C++)

A minimalist banking system built with C++ and Qt for graphical interface.

**Individual University Project** - Developed for GIF-1003 course (Advanced programmation in C++ for Engineer) at Université Laval (Winter 2025).

## 📹 Demo

![Demo](bank-system-demo.gif)


## 📸 Screenshots

![Screenshot 1]
*Main interface*
<img width="1916" height="903" alt="image" src="https://github.com/user-attachments/assets/90cf0e4d-23d4-4707-a187-94c0e42f1155" />


![Screenshot 2]
*Account operations*
<img width="1912" height="884" alt="image" src="https://github.com/user-attachments/assets/beaf9b5a-86aa-4226-8bb1-6b7dd6799638" />


## ✨ Features

- 💰 **Deposit and withdrawal operations**
- 📊 **Automatic interest calculation** for savings accounts
- 💳 **Chequing and savings account management**
- 📄 **Bank statement generation**
- 🖥️ **Qt-based graphical interface**
- ✅ **Input validation** with exception handling
- 🗑️ **Account deletion**

## 🛠️ Tech Stack

- **C++** (Core business logic)
- **Qt** (GUI framework)
- **NetBeans** (IDE)
- **Google Test** (Unit testing framework)

## 📁 Project Structure
```
├── Programme/                # Qt GUI application
│   ├── main.cpp             # Entry point
│   ├── Accueil.cpp/.h/.ui   # Main window
│   ├── AjoutCheque.cpp/.h/.ui    # Add chequing account
│   ├── AjoutEpargne.cpp/.h/.ui   # Add savings account
│   ├── SupprimerCompte.cpp/.h/.ui # Delete account
│   ├── FonctionsEntree.cpp/.h    # Input validation
│   └── ui_*.h               # Qt generated UI headers
│
└── Sources/                 # Core business logic
    ├── Client.cpp/.h        # Client class
    ├── Compte.cpp/.h        # Base account class
    ├── Cheque.cpp/.h        # Chequing account
    ├── Epargne.cpp/.h       # Savings account
    ├── Date.cpp/.h          # Date utilities
    ├── CompteException.cpp/.h     # Account exceptions
    ├── ContratException.cpp/.h    # Contract exceptions
    ├── validationFormat.cpp/.h    # Input validators
    └── tests/               
    ├── ClientTesteur/        # Unit tests
    ├── CompteTesteur/
    ├── ChequeTesteur/
    └── EpargneTesteur/
```


## 🏗️ Architecture

### Core Classes

| Class | Description |
|-------|-------------|
| **Client** | Manages client information and account portfolio |
| **Compte** | Abstract base class for all account types |
| **Cheque** | Chequing account with overdraft support |
| **Epargne** | Savings account with interest calculation |
| **Date** | Date handling and validation |
| **Exceptions** | Custom exception classes for error handling |

### Design Patterns Used

- **Inheritance** (Compte -> Cheque, Epargne)
- **Exception Handling** (CompteException, ContratException)
- **MVC** (Separation of GUI and business logic)
- **Encapsulation** (Data validation in setters)

## 📚 Key Concepts Demonstrated

- Object-oriented programming in C++
- GUI development with Qt
- Exception handling
- Unit testing
- Input validation
- Date manipulation
- Financial calculations (interest, statements)

## 👨‍💻 Developer

Developed by **Petiton Wiseley Paul-Enzer**

🌐 [Portfolio] [https://wiseley404.github.io/portfoilo]
📧 [e-mail] [mailto:enzerpaul@gmail.com]  
💼 [LinkedIn] [https://linkedin.com/in/petitonwiseley]
🐙 [GitHub] [https://github.com/wiseley404]

## 📝 License

© 2025 Petiton Wiseley Paul-Enzer. All rights reserved.

This project was developed as part of GIF-1003 coursework at Université Laval.

---

**Note**: This application was designed for educational purposes to demonstrate C++ and Qt development skills.
