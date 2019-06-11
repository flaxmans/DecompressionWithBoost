# Decompressing with boost in C++

A toy repo for me to learn about boost's functionalities for reading and parsing .bz2 and .gz files.

## Requirements

To compile the program, you will need:

* g++
* boost libraries

## Compiling the program

The program must be compiled from source.  Clone this repo, `cd` to it, and then simply type `make` in your terminal.

## Usage of wrapper script

To try it out:

* The wrapper script requires one argument, which is the 'base name' of the set of files it will test.  Two sets of example files are provided in this repo.  Both are based upon the data from the citation below.  

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

## Example data files provided here
The example data provided here are subsets of a much larger 
VCF (variant call format) file from the data archive of 
Schilling et al. 2018 (_Genes_ 2018, 9(6), 274).  
The original publication is freely available at: 
[https://doi.org/10.3390/genes9060274](https://doi.org/10.3390/genes9060274),
and the data archive is at: [http://bit.ly/2s6jeIf](http://bit.ly/2s6jeIf).

