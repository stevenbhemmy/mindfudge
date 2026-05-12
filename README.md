# mindfudge
A C++ Brainfuck Interpreter

Just a toy to get my brain wrapped around C++ again. 

100% not vibe coded.

## Setup and installation 

Prereqs: gcc, cmake, vcpkg

Install cmake and gcc
```bash
# On Ubuntu
sudo apt install cmake build-essential
```

Installing vcpkg
```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
cd ~/vcpkg
./bootstrap-vcpkg.sh

# put in .bashrc/.zshrc 
export VCPKG_ROOT="$HOME/vcpkg"
export PATH="$VCPKG_ROOT:$PATH"
```

## Project commands

Build
```bash
make build
```

Build with debug targets
```bash
make build-debug
```

Run the interpreter 
```bash
./build/mindfudge test_input.bf
```

Clean up build files
```bash
make clean
```
