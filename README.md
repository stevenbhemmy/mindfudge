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

Create a CMakeUserPresets.json with the following. The Makefile targets expect these for the "default" build preset. Make sure you've sourced the .bashrc/.zshrc additions above.
```json
{
  "version": 3,
  "configurePresets": [
    {
      "name": "default",
      "inherits": "vcpkg",
      "environment": {
        "VCPKG_ROOT": "$env{VCPKG_ROOT}"
      }
    }
  ]
}
```

## Project commands

Build (into <project_dir>/build)
```bash
make build
```

Build with debug targets
```bash
make build-debug
```

Run the interpreter 
```bash
./build/src/mindfudge test_input.bf
```

Clean up build files
```bash
make clean
```
