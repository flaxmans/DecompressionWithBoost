#!/bin/bash
refFile=$1

echo "Base reference file is: $refFile"
echo  "Testing while loop over string stream:"
time ./TestBoostZip ${refFile}.bz2 1
time ./TestBoostZip ${refFile}.gz 1
time ./TestBoostZip ${refFile} 1

printf "\n\t*******************\n\n"

echo "Testing file writes:"
# test file writes:
time ./TestBoostZip ${refFile}.bz2 0 > footestbz2.vcf
time ./TestBoostZip ${refFile}.gz 0 > footestgz.vcf
time ./TestBoostZip ${refFile} 0 > footest.vcf

printf "\n\t*******************\n\n"

printf "\nDiffing files.  No output means no diffs.\n"
for i in footest.vcf footestbz2.vcf footestgz.vcf
do
	printf "\n\tdiff $i ${refFile}:"
	diff $i ${refFile}
done

rm footest*

echo " "

