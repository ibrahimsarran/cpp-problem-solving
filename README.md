# C++ Problem Solving

My C++ practice repository, covering programming fundamentals, arrays, matrices, strings, file handling, and date algorithms. I use these exercises to build problem-solving skills and practice breaking programs into smaller functions.

The repository contains **216 numbered exercises across 4 levels**, plus a **console bank project**.

## Repository contents

| Folder | Numbered exercises | Main topics |
| --- | ---: | --- |
| [Level 1](Level1/) | 50 | Input/output, conditions, loops, functions, enums, and basic calculations |
| [Level 2](Level2/) | 50 | Number algorithms, patterns, random numbers, arrays, searching, and array manipulation |
| [Level 3](Level3/) | 51 | Matrices, Fibonacci and recursion, strings, records, file handling, and client management |
| [Level 4](Level4/) | 65 | Number-to-text conversion, leap years, calendars, date arithmetic, date comparison, and period overlap |

Files are named by problem number and title. Some Level 4 files combine multiple exercises: **20–32**, **33–46**, **47–53**, and **63–64**. There are **185 C++ source files** in total, including the bank project.

## What I am practicing

- Breaking a problem into smaller functions for input, processing, and output.
- Using conditions and loops to implement algorithms.
- Working with arrays, matrices, strings, structs, enums, and vectors.
- Reading and writing text files to store records.
- Combining smaller functions into a menu-driven console application.

## Bank project

[View the source](Level3/Bank%20Project.cpp)

A console application that brings together the client-management exercises from Level 3.

Features:

- List, add, find, update, and delete clients.
- Deposit money and withdraw from an account.
- Display account balances and the total balance.
- Save and load client records using `Clients.txt`.

The program reads and writes `Clients.txt` in its **current working directory**. To start with an empty client list, run the program and choose **2 — Add New Client**; saving a client creates the file.


## Compatibility notes

Some programs use Windows console commands such as `system("cls")` and `system("pause>0")`, and some use MSVC-specific pragmas. These files may need adjustments when used with another operating system or compiler.

These are learning exercises. The focus is on understanding the algorithms and improving the code through practice.
