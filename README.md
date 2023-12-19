# minishell

# **Getting started: understanding the parts of a shell program**

The shell implementation is divided into three parts: the **parser**, the **executor** and **shell subsystems**.

## **The parser**
The parser is the software component that reda the command line such as "ls -al" and puts it into a data structure called **Command Table** that will store the commands that will be executed.