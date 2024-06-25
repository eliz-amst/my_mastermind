# Welcome to My Mastermind
---

## Task
The challenge is to implement the classic game Mastermind in C, allowing players to guess a secret code within a limited number of attempts.

## Description
Mastermind is a game composed of 9 pieces of different colors.
A secret code is then composed of 4 distinct pieces.
The player has 10 attempts to find the secret code.
After each input, the game indicates to the player the number of well-placed pieces and the number of misplaced pieces.
Pieces will be '0' '1' '2' '3' '4' '5' '6' '7' '8'.
If the player finds the code, he wins, and the game stops.
A misplaced piece is a piece that is present in the secret code but that is not in a good position.
You must read the player's input from the standard input.
Your program will also receive the following parameters:
```
-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.
-t [ATTEMPTS]: specifies the number of attempts; by default, the player has 10 attempts.
```

## Installation
To install and compile the program, follow these steps:
1. Clone the repository:
2. Compile the program using the provided Makefile:
3. Run the executable:
   ```
   ./my_mastermind [-c <CODE>] [-t <ATTEMPTS>]
   ```


## Usage
The program can be executed with optional parameters:
```
- `-c <CODE>`: Specify the secret code as a 4-digit number (e.g., `-c 1234`).
- `-t <ATTEMPTS>`: Specify the maximum number of attempts (default is 10).
```

Example usage:
```
./my_mastermind -c 2345 -t 8
```

The game will prompt the player to enter their guess after displaying initial instructions. Input can be provided interactively. Each round of guessing will provide feedback on the number of well-placed and misplaced digits until the code is correctly guessed or the maximum attempts are reached.

### The Core Team
Yelyzaveta Samodid
<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
