# Project Name
EJ Heinz C++ training

## Description
C++ practice projects

## Database
This repository contains the headers .sln and .cpp files for my projects.

## Getting Started
### Prerequisites

- Visual Studio 
- Visual Studio Code

To run and debug C++ code in Visual Studio Code, follow these steps:

Install the necessary extensions:

Open Visual Studio Code.
Go to the Extensions view by clicking on the Extensions icon in the Activity Bar on the side of the window or by pressing Ctrl+Shift+X.
Install the following extensions:
C/C++ (by Microsoft)
CMake Tools (by Microsoft)
Set up your environment:

Ensure you have a C++ compiler installed, such as GCC for Linux or MinGW for Windows. For Windows, you can also use the MSVC compiler provided by Visual Studio.
Make sure the compiler is added to your system's PATH.
Create a tasks.json file:

Open your project folder in Visual Studio Code.
Go to Terminal > Configure Default Build Task > Create tasks.json file from template > Others.
Replace the content of tasks.json with the following: {
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build",
      "type": "shell",
      "command": "g++",
      "args": [
        "-g",
        "Miles Kilometers.cpp",
        "-o",
        "MilesKilometers"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"],
      "detail": "Generated task by VS Code."
    }
  ]
}

Create a launch.json file:

Go to Run > Add Configuration....
Select C++ (GDB/LLDB).
Replace the content of launch.json with the following: {
  "version": "0.2.0",
  "configurations": [
    {
      "name": "(gdb) Launch",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/MilesKilometers",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "build",
      "miDebuggerPath": "/usr/bin/gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "logging": {
        "engineLogging": true
      }
    }
  ]
}

Build and run your code:

Press Ctrl+Shift+B to build your project.
Press F5 to start debugging.
This setup will allow you to build and debug your C++ code in Visual Studio Code. Make sure to adjust the paths and filenames as necessary for your specific environment and project structure.

- Git

### Installation
1. Clone the repository:
   ```sh 
   git clone https://github.com/1ejheinz/SQL