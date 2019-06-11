# Decompressing with boost in C++

A toy repo for me to learn about boost's functionalities for reading and parsing .bz2 and .gz files.

## Requirements

To compile the program, you will need:

* g++
* boost libraries

## Usage

To try it out:

* Use the wrapper script, which requires one argument, which is the base name.  

* It also requires the presence of the file of that name, a gzipped version of that file, and a bzip2 compressed version of that file. (see list of files in repo for examples)

* File extensions are mandatory!  Gzipped files must have names that end in .gz , and bzip2 compressed files must have names that end in .bz2 .

