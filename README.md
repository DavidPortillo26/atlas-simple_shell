How the shell works by David Portillo

Introduction

Welcome to our custom shell implementation written in C, leveraging system calls for enhanced functionality and efficiency.

How to Run

To launch the shell:

1. Ensure you have `make` installed (`sudo apt-get install make`).
2. Navigate to the source code directory.
3. Run `make run`.

Features

- **cd Command**: Navigate directories efficiently.
  - Supports options like `cd`, `cd ~`, `cd .`, `cd ..`, and `cd <directory>`.
- **pwd Command**: Print the current working directory.
- **echo Command**: Display text messages with flexibility.
  - Supports both double quotes (`"`) and single quotes (`'`).
  - Example usage: `echo "Hello, World!"`.
- **ls Command**: List directory contents with various options.
  - Options include `ls`, `ls -l`, `ls -a`, `ls -al`, and more.
- **System Commands**: Execute commands in foreground or background.
  - Supports foreground and background processes.
  - Returns Process IDs (PIDs) for background processes.
- **pinfo Command**: Retrieve information about running processes.
  - Example usage: `pinfo`.

This shell offers a user-friendly command-line interface with essential features for system management and process handling.

FLOW CHART
![2C45A891-5B51-4D40-B055-D19DB6BB0C78_1_105_c](https://github.com/DavidPortillo26/atlas-simple_shell/assets/144150513/74fffa31-2ee8-4d76-945d-eda95ec075ed)
