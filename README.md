# 📦 C++ Inventory Management System

A simple console-based **Inventory Management System** built in **C++**. It allows users to manage product entries by adding, viewing, searching, updating, and deleting inventory items.

---

## 🚀 Features

- Add new inventory items  
- View all items  
- Search for items by ID or name  
- Update existing item details  
- Delete items  
- Generate Database text file
---

## 🛠️ Technologies Used

- **Language**: C++  
- **Compiler**: g++, MinGW, or any standard C++ compiler  
- **Editor**: Dev C++

---

## 📐 Data Structure

```cpp
struct Item {
    int id;
    std::string name;
    int quantity;
    double price;
};
```
## 💻 How to Run
1. Clone Repository
```bash
git clone https://github.com/YourUsername/YourRepoName.git
cd YourRepoName
```
2. Compile
```bash
g++ -o inventory main.cpp
```
3. Run
``` bash
./inventory
```
## 📌 Future Improvements
-  Add user authentication
-  Improve input validation
-  Implement inventory sorting
-  Use persistent storage (e.g., file or database)
