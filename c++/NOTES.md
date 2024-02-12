# C++

## About the C++ Programming Language

C++ is a **compiled language**, created by Bjarne Stroustrup. A **compiled language** means to get a C++ program to run, you must first translate the human-readable C++ language into something a language that can be "interpreted" by a computer. This transition is down by what is known as a "compiler".

The code that you read and write is called _source code_ (usually it is in a English-like language like C++), and what the computer executes is called an _executable, object, code, or machine code (a machine language)_.

Typically C++ source code files are given the suffix:

- .cpp (ex. calculate.cpp) or
- .h (ex. std_lib_facilities.h)

![Compilation to Execution Process of C++ Program](https://i.imgur.com/JUDOhEj.png)

### Compiling a C++ Program

`g++ my_program.cpp -o my_program`

A [compiler](https://en.wikipedia.org/wiki/Compiler) translates the C++ program into machine language code which it stores on the disk as a file with the extension **.o** (e.g. my_program.o).

A [linker](https://shorturl.at/clRY8) then links the object code with standard library routines that the program may use and creates an executable image which is also saved on disk, usually as a file with the file name without any extension (e.g. my_program).

### Executing a C++ Program

`./my_program`

The **executable** is loaded from the disk to memory and the computer's [CPU](https://www.codecademy.com/resources/docs/general/computer-hardware/cpu?page_ref=catalog) (Central Processing Unit) executes the program one instruction at a time.

## Variables

![C++ Variables Table](https://content.codecademy.com/courses/learn-cpp/variables/data-types.gif)

| Type   | Usage                  | Examples                        |
| ------ | ---------------------- | ------------------------------- |
| int    | integer numbers        | 0, 256                          |
| double | floating-point numbers | 3.14, -200.0                    |
| char   | characters             | 'a', '@'                        |
| string | sequence of characters | "Hello, World!", "OMG WOW!! 😲" |
| bool   | truth values           | true, false                     |

Every variable has a **type**, which represents the kind of information you can store inside of it. A type tells the compiler how much memory to set aside for the variable, and it defines what you can do with the variable.

### Using Variables in a C++ Program

Before we can use a variable, we must _declare_, or create, it. To declare a variable, we need to provide **TWO** things:

1. A _type_ for the variable.
2. A name for the variable.

So to declare an integer variable called "score", we would write:

```c
int score;
```
