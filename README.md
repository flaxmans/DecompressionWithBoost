# Decompressing with boost in C++

A toy repo for me to learn about boost's functionalities for reading and parsing .bz2 and .gz files.

## Requirements

To compile the program, you will need:

* g++
* boost libraries

## Compiling the program

The program must be compiled from source 

## Usage of wrapper script

To try it out:

* Use the wrapper script, which requires one argument, which is the base name.  

* It also requires the presence of the file of that name, a gzipped version of that file, and a bzip2 compressed version of that file. (see list of files in repo for examples)

* File extensions are mandatory!  Gzipped files must have names that end in .gz , and bzip2 compressed files must have names that end in .bz2 .

Here is an example using the wrapper script and files here:

```
./TryProgram.sh Medium_hmel2.5.30f4.vcf
```

## Usage of program without wrapper script:

For output of decompressed file to stdout:
```
./TestBoostZip filename.ext 0
# note argument "0"
# replace filename.ext with actual name, such as TinyTest.vcf.gz
```

For a test of clock time to parse stream into strings:
```
./TestBoostZip TinyTest.vcf.gz 1
# note argument "1"
```

```

