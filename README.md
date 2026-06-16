# Battleship Game

A C implementation of the classic Battleship game with turn-based gameplay, input validation, and random AI opponent.

## Overview
This project demonstrates game logic, state management, and pointer arithmetic in C. Two players (human and computer) take turns guessing positions on a 1D grid to locate and destroy opponent ships.

## Features
- **Turn-Based Gameplay** — Players alternate guessing positions
- **Ship Placement** — Player places 2 ships on a 10-position grid
- **Random AI** — Computer randomly places ships and makes guesses
- **State Tracking** — Uses encoded values (0=empty, 1=ship, 2=miss, 3=hit)
- **Input Validation** — Rejects invalid guesses and duplicate attempts
- **Win Conditions** — First player to sink both opponent ships wins
- **Board Display** — Visual representation of both boards after each round

## Technical Details
**Data Structures:**
- 1D arrays (10 positions) for player and computer boards
- Pointer arithmetic for array manipulation

**Game States:**
- 0 = Empty cell
- 1 = Ship (undetected)
- 2 = Miss
- 3 = Hit

**Algorithm:**
- Turn-based loop with up to 4 rounds
- Game ends when either player sinks both ships
- Winner determined by total hits

## How to Run

**Compile:**
```bash
gcc battleship.c -o battleship
```

**Run:**
```bash
./battleship
```

## Example Gameplay

Enter position 1: 3

Enter position 2: 7

Round 1:

Computer guesses 5

MISS!

Enter guess: 2

You guessed 2

MISS!

Human Board:

0 1 2 3 4 5 6 7 8 9

S * * * S * *

Computer Board:

0 1 2 3 4 5 6 7 8 9

M * * * * * * * *
