# Minishell

## As beautiful as a shell

### Introduction
Minishell is a project aimed at building a simple shell, similar to a minimalistic bash. This project allows you to delve deep into the workings of processes, file descriptors, and the interaction between the user and the operating system through a command-line interface.

### Features
- **Prompt Display:** Minishell displays a prompt awaiting new commands, similar to traditional shells.
- **Command History:** Implemented a working history feature for easier navigation through previously entered commands.
- **Executable Search:** Minishell searches and executes the correct binaries based on the PATH environment variable or through specified relative or absolute paths.
- **Signal Handling:** Properly handles signals like `ctrl-C`, `ctrl-D`, and `ctrl-\` without using more than one global variable.
- **Redirections and Pipes:** Supports input and output redirections (`<`, `>`, `<<`, `>>`) and pipelines (`|`) to chain commands.
- **Environment Variables:** Manages environment variables and supports expanding them within the shell.
- **Exit Status:** Handles `$?` to expand to the exit status of the most recently executed foreground pipeline.
- **Builtins:** Implements several builtin commands like `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.

### Challenges and Learning Opportunities

The Minishell project presents a unique set of challenges, especially for students who are new to coding. Here's a look at what makes this project particularly demanding and enriching:

#### Understanding UNIX Processes and Signals
One of the fundamental challenges of the Minishell project is gaining a deep understanding of UNIX processes and signal handling. Implementing features like process creation and execution, as well as handling signals like `SIGINT` (`ctrl-C`), `SIGQUIT` (`ctrl-\`), and `EOF` (`ctrl-D`), requires a solid grasp of UNIX process management and inter-process communication.

#### Memory Management
Proper memory management is crucial in the Minishell project. Students must allocate and free memory dynamically while ensuring there are no memory leaks or segmentation faults. This aspect of the project emphasizes the importance of disciplined memory management practices, which are vital in low-level programming.

#### Parsing and Lexical Analysis
Implementing a shell involves complex parsing and lexical analysis to interpret user commands accurately. Handling quotes, spaces, pipes, redirections, and environment variables challenges students to develop robust parsing algorithms, which is a foundational skill in many areas of software development.

#### Implementation of Builtins
The project requires the implementation of several shell builtins like `cd`, `echo`, `exit`, `env`, and more. Each of these builtins has its own set of rules and behaviors, which must be replicated accurately. This requires students to research and understand the intricacies of these commands, deepening their understanding of shell environments.

#### Error Handling
Robust error handling is crucial in creating a stable and user-friendly shell. Students must anticipate and gracefully handle a wide range of possible errors, from invalid commands to file permission issues. This aspect of the project underscores the importance of defensive programming and user-centric design.

### What do we Personnaly Gain from this Project?

Despite its challenges, the Minishell project is an invaluable learning opportunity for students, especially those new to coding, because it:

- **Reinforces Fundamental Concepts:** It solidifies understanding of core concepts such as loops, conditionals, data structures, and more.
- **Introduces System Programming:** We can gain hands-on experience with system-level programming.
- **Improves Problem-Solving Skills:** The project's complexity requires us to develop and apply advanced problem-solving strategies.
- **Enhances Research Skills:** Students must independently research topics such as POSIX standards, shell behavior, and more, improving their ability to learn autonomously.
- **Prepares for Real-World Scenarios:** The project simulates real-world software development challenges, including debugging, version control, and collaborative coding, preparing students for future projects and employment.

In summary, while the Minishell project is challenging, it is these challenges that make it an excellent learning tool, pushing my mate and I to expand our knowledge, improve our coding skills, and become better coders.
