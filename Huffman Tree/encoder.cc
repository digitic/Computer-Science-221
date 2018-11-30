
//Encoder is a program that takes another filename as a command-line argument. 
//It then reads and compresses the file into an output file of the same name with a .comp suffix.

//So, for example, after implementing and compiling the encoder, you'd be able to do something like:

//./encoder bitio.cc

//And when the program completes there'll be a new binary file in your directory called bitio.cc.comp. 
//In both instances, try to challenge yourself to take more than a single command-line argument, so that your encoder actually compresses all the filenames given as input.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "huffman.hh"
#include "bitio.hh"

/*int main(int argc, char* argv[])
{
    Huffman huff;
    Huffman::bits_t vectorofbits;
    std::string fileName  = "";
    
    if(argc == 2){ //if there is ONLY the .cpp file and the input file
        fileName = argv[1]; //input file name
    }
    else{
        std::cout << "please input like this: ./cppfile InputFile \n";
        return 1; //too many or too few files
    }

    
    std::ifstream oldFile;
    oldFile.open(fileName, std::ios::out);
    std::ofstream newFile; //make a new file
    newFile.open(fileName +".comp", std::ios::in);
    //BitIO bitReceive(nullptr, &newFile);//has input stream, no output stream
    BitIO bitGive(&newFile, nullptr);//has an output steam, no input stream

    char c;
    while(oldFile>>c){ //c is a character in oldfile //for every character in input file:
        vectorofbits = huff.encode(c);//take that character, encode it by taking the int value of the character
        for (auto v: vectorofbits){
            bitGive.output_bit(v);//get vector of bits, use bitio output bit to output that into a new file?
        }
    }

    for(auto c : oldFile){ //c is a character in oldfile //for every character in input file:
        vectorofbits = huff.encode(c);//take that character, encode it by taking the int value of the character
        for (auto v: vectorofbits){
            bitGive.output_bit(v);//get vector of bits, use bitio output bit to output that into a new file?
        }
    }
   
        
        
        //put those 1s and 0s into a new file, 8 times


    newFile.close();
    oldFile.close();
    return 0;
} */

int main(int argc, char* argv[])
{
    Huffman huff;
    Huffman::bits_t bitSequence;
    std::vector<std::string> fileNames;

    if(argc < 2)
    {
        std::cout << "Too few files!\n";
        assert(false);
    }
    else
    {
        for(int i = 1; i < argc; i++)
        {
            fileNames.push_back(argv[i]);
        }
    }
    for(int j = 0; j < argc - 1; j++)
    {
        std::ifstream oldFile;
        oldFile.open(fileNames[j], std::ios::out);
        std::ofstream newFile;
        newFile.open(fileNames[j] + ".comp", std::ios::in);
        BitIO bitGive(&newFile, nullptr);
        char c;
        while(oldFile >> c)
        {
            bitSequence = huff.encode(c);
            for(bool v: bitSequence)
            {
                bitGive.output_bit(v);
            }
        }
        newFile.close();
        oldFile.close();
    }

    return 0;
}



