# 🎮 Tic-Tac-Toe Variations – OOP Assignment 2  
**Cairo University – Faculty of Artificial Intelligence**  
**CS213: Object-Oriented Programming – Assignment 2**

This repository contains implementations of **nine different Tic-Tac-Toe game variations**, each designed using Object-Oriented Programming (OOP) principles in C++.  
Every game is implemented in a separate header file and integrated through a unified driver in `main.cpp`.

---

## 👥 Team Members

- **Ahmed Hussein** - [@ahmedElsherif](https://github.com/ahmed2005hussen)  
- **Menna Abdelgawad** - [@MennaAbdelgawad](https://github.com/Menna-AbdElGawad)  
- **Mawada Emad** - [@MawadaEmad](https://github.com/mawadaemad) 
---

## 📁 Repository Structure  
Pyramic_Tic-Tac-Toe.h  
FiveByFive.h  
Four_In_Row.h  
Word_Tic-tac-toe.h  
Num_Tic_Tac_Toe.h  
Misere.h  
game7.h  
game8.h    
SUS.h  
dic.txt  
main.cpp  
README.md  

---

# 🕹️ Game Variations

## 1️⃣ Pyramic Tic-Tac-Toe  
A pyramid-shaped Tic-Tac-Toe board with 3 levels (5–3–1 squares).  
Players take turns placing **X** and **O**.  
**Winning Condition:** Get **three in a row** (horizontal, vertical, diagonal).

---

## 2️⃣ Four-in-a-Row  
A 7×6 grid similar to Connect Four.  
Players mark cells instead of dropping discs, but must always place in the **lowest available cell** of a column.  
**Winning Condition:** Get **four in a row** in any direction.

---

## 3️⃣ 5×5 Tic-Tac-Toe  
Played on a 5×5 grid.  
Each player plays 12 moves (24 total filled squares).  
**Winning Condition:** Count all **3-in-a-row sequences** for each player.  
The player with the **most sequences** wins.  
A mark **may be counted more than once** if part of multiple sequences.

---

## 4️⃣ Word Tic-Tac-Toe  
A linguistic version played on a 3×3 board.  
Players place **letters** instead of X/O.  
**Objective:** Form a **valid 3-letter English word** horizontally, vertically, or diagonally.  
Valid words are checked from the provided **dic.txt** file.  
**Winning Condition:** First valid word wins.

---

## 5️⃣ Numerical Tic-Tac-Toe  
A mathematical variation on a 3×3 grid.  
- Player 1 uses **odd numbers**: 1, 3, 5, 7, 9  
- Player 2 uses **even numbers**: 2, 4, 6, 8  
Each number can be used **once only**.  
**Winning Condition:** Form a line that sums to **15**.

---

## 6️⃣ Misere Tic-Tac-Toe  
Also called "Inverse Tic-Tac-Toe."  
Players try to **avoid** creating three-in-a-row.  
**Losing Condition:** If you form 3-in-a-row → **you lose**.  
If the board fills with no alignments, the game is a **draw**.

---

## 7️⃣ 4×4 Tic-Tac-Toe (Token Movement Game)  
Played on a 4×4 board.  
Each player has **four tokens** placed in fixed starting positions.  
Players move **one token per turn** to an **adjacent empty square** (horizontally/vertically only, no jumps).  
**Winning Condition:** Align **3 tokens** in a row.

---

## 8️⃣ Ultimate Tic-Tac-Toe  
A 3×3 grid of **nine small Tic-Tac-Toe boards**.  
Players play inside smaller boards; winning a small board gives control of the corresponding cell in the main board.  
**Winning Condition:** Win **3 small boards** in a row on the main grid.

---

## 9️⃣ SUS Game  
Played on a 3×3 board.  
Players place only **S** or **U**, using the **same letter every turn**.  
**Objective:** Form the sequence **S-U-S** in any direction.  
Each completed SUS gives **one point**.  
The player with the **most SUS sequences** wins.

---
# 🧱 OOP Concepts Applied
- **Inheritance**
- **Polymorphism**
- **Abstract base classes**
- **Encapsulation**
- **Virtual functions**
- **Dynamic dispatch**
- **Modular design (each game in its own class)**


---

# 📜 License  
This project is created for educational purposes as part of **CS213 OOP Assignment 2**.
