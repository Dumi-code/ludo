# Ludo Game in C

This project is a simple implementation of the classic board game **Ludo** in C, simulating gameplay between four players (Red, Green, Yellow, and Blue).

## 📝 Project Description
- Simulates a four-player Ludo game.
- Implements game logic, including dice rolls, piece movement, capturing, and winning conditions.
- Randomized dice rolls to determine moves.
- Each player takes turns rolling the dice and moving pieces according to Ludo rules.

## 📁 Project Structure
```
├── main.c       // Contains the main function to execute the game.
├── logic.c      // Implements the game logic.
├── logic.h      // Function definitions for game logic.
├── types.h      // Data structures for Player and Piece.
```

## 🚀 How to Run
1. Compile the project using GCC:
```sh
gcc main.c logic.c -o ludo
```
2. Run the executable:
```sh
./ludo
```

## 🔍 Game Rules
- Players roll a dice to move pieces across the board.
- A piece can only enter the game when a player rolls a 6.
- Rolling a 6 gives an extra turn.
- Players can capture opponents' pieces by landing on the same cell.
- The goal is to get all four pieces to the "Home".

## 📌 Key Functions
- `roll()` — Simulates a dice roll.
- `Colours()` — Returns player colors.
- `movepiece()` — Handles piece movement across the board.
- `function()` — Initializes players and handles game flow.

## 🎉 Game Output
- Displays each player's turn, dice rolls, and movements.
- Announces the winner when the game ends.

## 🏆 Author
- **Dumindu**

Enjoy the game! 🎲

