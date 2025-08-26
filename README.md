# cpp-ci-data-structs-alg

This repository contains worked examples from the Data Structures and Algorithms C++ course on Udemy captured in the dsa_cpp_course directory. For further details see this link https://www.udemy.com/course/data-structures-algorithms-using-c-zero-to-mastery/?couponCode=25BBPMXNVD20CTRL

Additionally the original usage guide on setting up the cpp-ci-example pipeline is contained below.

## Usage:

This project contains a cpp project configured with the following:
- devcontainer with tools and vscode extensions
- cmake
- gtest
- and more..

### Getting Started

Open the devcontainer > ctrl + shift + p > Search: Dev Containers: Reopen in container

### Build

Go to the cmake extension, Build

If using cmake default run the output:

```sh
./out/build/default/cpp-template 
```

### Debug

Go to main.cpp add a breakpoint, then go to cmake extension, Debug.

### Run Tests

Go to the cmake extension, Test

### git commits

The Github actions requires git commits to using [conventional commits](https://www.conventionalcommits.org/en/v1.0.0/)