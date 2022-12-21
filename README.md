# Project_DataCompression
To compile the project:-
Compression:-
g++ -o comp encode.cpp huffman.cpp

Decompression:-

g++ -o decomp decode.cpp huffman.cpp

Input-
./comp input.txt compressed.huff

Decompress-
./decomp compressed.huff Output.txt
