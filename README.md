# Simple Shell

## Overview

**Simple Shell** is a custom implementation of a Unix shell developed in C. The shell serves as a command-line interpreter, accepting user input and executing commands in a manner similar to bash or other Unix shells. This project is designed to deepen understanding of how a shell interacts with the Unix kernel, handling various system calls, file I/O, process management, and signal handling.

## Features

- **Command Execution**: Supports running commands with arguments like `/bin/ls -l`.
- **Interactive and Non-Interactive Modes**: Can run commands interactively (user inputs commands in real-time) or in non-interactive mode (commands are executed from a file).
- **Built-in Commands**: Supports built-in commands such as `exit`.
- **Error Handling**: Implements basic error handling for commands not found or incorrect arguments.
- **Environment Variable Handling**: Manages environment variables and allows their usage within commands.
- **Process Control**: Utilizes Unix system calls like `fork()`, `execve()`, and `wait()` to handle processes.

## Getting Started

### Prerequisites

You need a Unix-based system (Linux, macOS) with a GCC compiler to build the project. If you are using a Linux system, these should already be installed.

### Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/Mos3aB696/simple_shell.git
   ```

2. **Compile the program**:

   Navigate to the project directory and run the following command:

   ```bash
   gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
   ```

3. **Run the shell**:

   You can now run the shell interactively or in non-interactive mode:

   - **Interactive Mode**:
   
     ```bash
     ./hsh
     ```
     Enter commands like in a standard shell.

   - **Non-Interactive Mode**:
   
     Provide a file with commands:
   
     ```bash
     echo "ls -l" | ./hsh
     ```

## Usage

The **Simple Shell** can execute built-in commands and system commands available in `/bin` or `/usr/bin`. Here's a quick overview of supported functionalities:

- **Execute Commands**: Type commands like `ls`, `pwd`, `echo` followed by arguments.
- **Exit Shell**: Type `exit` to exit the shell.
- **Handle Environment Variables**: Access and manipulate environment variables, e.g., `$PATH`.

### Example Usage

```bash
$ ./hsh
($) /bin/ls -l
total 44
-rwxrwxr-x 1 user user 10208 Sep 23 12:00 hsh
-rw-rw-r-- 1 user user  1468 Sep 23 12:00 main.c
-rw-rw-r-- 1 user user   468 Sep 23 12:00 README.md
($) exit
```

## Project Structure

```plaintext
simple_shell/
├── main.c            # Entry point of the shell program
├── shell.h           # Header file with function prototypes and macros
├── builtins.c        # Contains implementations for built-in shell commands
├── execute.c         # Logic for executing commands
├── helpers.c         # Helper functions for parsing and managing input
├── man_1_simple_shell # Man page for the shell
└── README.md         # Project documentation
```

## Built With

- **C Programming Language**: The core of the project.
- **GCC Compiler**: Used to compile the project.
- **Unix System Calls**: `fork()`, `execve()`, `wait()`, `getcwd()`, etc.

## How it Works

1. **Input**: The shell reads user input through `getline()`.
2. **Parsing**: The input is parsed into commands and arguments.
3. **Command Execution**: The shell uses `fork()` to create a new process and `execve()` to replace the process image with the command execution.
4. **Built-in Handling**: Built-in commands such as `exit` are handled directly within the shell without creating a new process.
5. **Loop**: The shell repeats this cycle until the user exits.

## Man Page

The project includes a custom manual page (`man_1_simple_shell`) that provides more detailed documentation on usage, commands, and functionality. You can view it by running:

```bash
man ./man_1_simple_shell
```

## Bugs

There are no known bugs at this time. Please report any issues or feature requests via the [Issues tab](https://github.com/Mos3aB696/simple_shell/issues).

## Future Improvements

- Add support for additional built-in commands (e.g., `cd`, `setenv`, `unsetenv`).
- Implement piping (`|`) and redirection (`>`, `<`).
- Improve error handling and input validation.

## Contribution

Contributions are welcome! Feel free to fork the repository, create a new branch, and submit a pull request with improvements or bug fixes. Please ensure your code adheres to the style of the existing codebase.

## Contact

For any questions or issues, you can reach me at:

**Mosaab Abdelkawy**
- [LinkedIn](https://www.linkedin.com/in/mosaab-abdelkawy/)
- [YouTube](https://youtube.com/@tapseta696?si=7q1LRJdUoOW2Yamk)
