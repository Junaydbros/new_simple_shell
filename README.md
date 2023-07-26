
## This project is an implementation of the `simple_shell` which acts an interface between a user and the kernel.

## Description
The Shell according to `Wikipedia` definition is a computer program that exposes an operating system's services to a human user or other programs. This generally involves the operating system shells using either a command-line interface or graphical user interface, depending on the computer's role and particular operation.

Just like the standard `shell` that is a command line interpreter, this `simple_shell` implementation is able to simulate the command line interface whilst serving the purpose of the regular shell, which is the interface between a user and the kernel, that executes programs called commands.
The work of the `simple_shell` program here is to take in an input from the user, confirm if it is an executable or a file, and act on the user input accordingly. If the input is an executable, the command is effected appropriately, and if a file, the program checks for it from it's list of file in its specific $PATH, and acts accordingly as well. Otherwise, if the command is not either, file or executable, the program returns an error message to the user. This program is able to accept similar command arguments, and with the help of the appropriate specifier, is able to execute the input appropiately giving a value to the standard output.

The `simple_shell` program modelled here provides similar functionality to the standard `linux shell` used by programmers to interact with the computer, and give commands.

## Installation
To install this project, simply clone the repository and compile using gcc or your prferred c compiler.

**Clone Repository**
```
HTTPS =>
git clone https://github.com/Isaackaayyy/simple_shell.git

SSH =>
git clone git@github.com:Isaackaayyy/simple_shell.git
```

**Compile Project**
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *c
```

## Usage
To use the `simple_shell` program to run commnads, execute the program with the shell name format and type in any command you would like to execute, whether an executable or a file. For example:

```
./shell_name

shell_name$ _

shell_name$ ls
//lists all files in the current directory

shell_name$ alabama
alabama: error not found
//prints an error message if command input does not exist
```

## Supported CHaracters and Commands
The following special characters are supported.
|**Character Name**|**Notation**|
|--|--|
|**Quotation Mark**|**"**|
|**Apostrophe**|**'**|
|**Back-tick**|**`**|
|**\**|**Backslash**|
|*****|**Asterisk**|
|**&**|**Ampersand**|
|**#**|**Number Sign**|

## Future Improvements

## License

## Implemented and Submitted by

```Kamma OKOH``` and ```Abdulhamid SANUSI```
