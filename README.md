# Welcome to My Mastermind
---

## Task
The challenge is to implement the classic game Mastermind in C, allowing players to guess a secret code within a limited number of attempts.

## Description
The program allows players to guess a secret code either provided via command-line arguments or generated randomly. Players input their guesses and receive feedback on how many digits are correctly placed and how many are misplaced. The game ends when the player guesses the code correctly or runs out of attempts.

## Installation
To install and compile the program, follow these steps:

1. Clone the repository:
   ```
   git clone <repository-url>
   cd my_mastermind
   ```
2. Compile the program using the provided Makefile:
   ```
   make
   ```
3. Run the executable:
   ```
   ./my_mastermind [-c <CODE>] [-t <ATTEMPTS>]
   ```

## Usage

The program can be executed with optional parameters:

- `-c <CODE>`: Specify the secret code as a 4-digit number (e.g., `-c 1234`).
- `-t <ATTEMPTS>`: Specify the maximum number of attempts (default is 10).

Example usage:

```
./my_mastermind -c 2345 -t 8
```

The game will prompt the player to enter their guess after displaying initial instructions. Input can be provided interactively. Each round of guessing will provide feedback on the number of well-placed and misplaced digits until the code is correctly guessed or the maximum attempts are reached.

### The Core Team
Yelyzaveta Samodid
<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
