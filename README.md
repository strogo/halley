![Halley Logo](http://higherorderfun.com/stuff/halley/halley_scarlet.png)

[![License](https://img.shields.io/badge/license-Apache%202.0-brightgreen.svg)](https://en.wikipedia.org/wiki/C%2B%2B14)
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/c%2B%2B-14-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B14)

# Halley Game Engine
A lightweight game engine written in C++14. It's considered to be highly experimental, and alpha quality at best.

The Halley Game Engine is licensed under the Apache 2.0 license.

## Design guidelines & objectives
* Modern graphics pipelines, with first-class shader support
* Written in modern C++
* "True" entity system based, with components that store data and systems that operate on families of components
* Tuned for high performance
* Code-first: no reliance on editor to generate anything
* Easy to use: games should be easy to implement
* Easy to maintain: games should be easy to keep working on long-term, after it has grown to a large project size
* Cross-platform: support as many platforms as possible
* No legacy: don't bother supporting legacy systems, such as Windows XP or older Android/iOS devices
* Rich tools: where possible, provide tools to assist in development and debugging
* Fast iteration time: hot-reloading wherever possible
* Support scripting in other languages, such as Lua

## Modules
Halley is divided in a several sub-projects:
* **engine**
  * **core**: Core features of the engine, including looper, API management, resouces, and graphics engine
  * **opengl**: Video/OpenGL implementation
  * **sdl**: System/SDL, Input/SDL and AudioOut/SDL implementations
  * **audio**: Audio engine
  * **entity**: Framework for dealing with entities, components, and systems
  * **utils**: Utilities library
  * **net**: Networking library
* **tools**
  * **editor**: Editor UI
  * **cmd**: Command-line interface to tools
  * **runner**: Provides an entry point for execution and dynamic reloading. Highly experimental.
  * **tools**: Editor tools to generate files and assets
* **tests**
  * **entity**: Stress test of entity system
  * **network**: Stress test of network system
* **samples**
  * see [this project](https://github.com/amzeratul/halley-samples)

## Platforms
The following platforms are supported:
* **Windows**: Tested on Windows 10 Professional x64
* **Mac OS X**: Tested on Mac OS X 10.9
* **Linux**: Tested on Ubuntu 16.04

## Installation

### Tools required
* CMake 3.x
* C++14 capable compiler:
  * Visual C++ 14 Update 2 (Visual Studio 2015)
  * Clang 3.5
  * GCC 5.0

### Library dependencies
* Engine:
  * OpenGL
  * Boost 1.59.0 (header only)
  * SDL 2.0.4
* Tools only:
  * Boost 1.59.0 libraries: filesystem, system
  * Freetype 2.6.3
  * yaml-cpp 0.5.3

### Set up
* Ensure that all dependencies above are set up correctly
* Build with CMake (recommended: "mkdir build && cmake ..")
* Run "halley-editor tests/entity" (or whichever other project you want to test)
* Launch that project
