# Patatap-cpp

## Summary

This project is a port of the famous web application [patatap](https://patatap.com/) in c++. It is coming with a new feature that allows you to play the simon says game with the generated shapes.

## Getting Started

Patatap-cpp relies on multiple dependencies,

#### Dependencies

+ GNU Make ang g++11
+ SDL 2
+ SDL Mixer

In order to build the project, you need to do :

```bash
git clone https://github.com/sudo-cho/patatap-cpp
make re
```

It will generate the coresponding execution file in the build/ folder.

## How to play

You can perform actions using the keys : S, D, F, G, H, J.

You can start the simon says game using the SPACE key. It is not 100% functional for now and will be updated in the future.

## Configuration

Possible modifications are available in main.cpp such as the number of shapes, the size of the screen and the number of steps for the simon says game.
