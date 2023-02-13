# Huffman Code
  Author: Yanyan Zhou
  
  Environment: Visual Studio 2019
  
  Date: 2022/5/17
# Description 
Huffman coding is a data compression algorithm that assigns variable-length codes to characters in a data stream based on their frequency of occurrence. The idea is to give shorter codes to the more frequently occurring characters and more extended codes to the less frequently occurring characters to reduce the overall number of bits needed to represent the data, which leads to more efficient use of storage and a reduction in long-strings data that needs to be transmitted or stored. Huffman coding is widely used in various applications, including image and audio compression, as well as in data transmission and storage.

This code is an implementation of the Huffman coding algorithm for text data compression. The purpose of the code is to reduce the size of a text file by representing each character with a variable-length code, where the characters with a higher frequency are assigned a shorter code. The code is written in C++, and it uses the priority queue and vector data structures from the Standard Template Library (STL).

The code starts by defining a number of variables and structures, including:

  A long long int type called "ll"

  An array called "number" to store the frequency of each character's occurrence in the input text file

  A 2D vector called "schedle" to store the encoding of each character

  A vector of type Node called "t", which represents the Huffman tree

  A priority queue of type "int" called "q" to store the nodes of the Huffman tree during the building process.

The input function reads the data from the "input.txt" file and counts the frequency of each character using a loop.

The BuildTree function builds the Huffman tree by creating leaf nodes for each character with a non-zero frequency and merging them into a parent node. The merging process is done by selecting two nodes with the highest weight from the priority queue "q", generating a parent node for them, and putting the parent node back into "q". The process is repeated until all the nodes are merged into one root node, which is then returned.

The HuffmanCoding function is a recursive function that assigns the binary code to each character by traversing the Huffman tree. The function first checks if the current node is a leaf node (i.e., it contains a character). If it is, the function records the current binary code in the "schedle" array. If it's not, the function appends a 0 to the binary code and calls itself with the index of the left child node, then appends a 1 and calls itself with the index of the right child node.

The output function writes the character-code mapping and the compressed data to the "output.txt" file.

Finally, the main function initializes all the variables, calls the input and BuildTree functions, runs the HuffmanCoding function to encode the characters, and writes the results to the "output.txt" file using the output function.
# Directory Structure

    ├── ReadMe.md               // User Guide
    
    ├── Debug             
    
    │   ├── Huffman_Code.exe   // run the program
    
    ├── Huffman_Code.sln       // solution file 
    
    ├── Huffman_Code.cpp       // source code
        
    ├── Huffman_Code.vcxproj   //Visual Studio project files
            
    ├── Huffman_Code.vcxproj.filters   
            
    ├── Huffman_Code.vcxproj.user 
                
    ├──input.txt               //the data that need to be compressed
                
    ├──output.txt              //the output Huffman code
    
# Input and Output
This program require user to put the code text file in the root
Input:

![image](https://user-images.githubusercontent.com/82789287/218552209-a8cd1303-b50c-45b5-a9ac-640a9d4cfcf5.png)

Output:

![image](https://user-images.githubusercontent.com/82789287/218552264-42ca291c-5e72-42c6-b693-0952f8bfdc13.png)
