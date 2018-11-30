
//Decoder program takes in a filename as well, reads its, and decompressed it into a file with the same name and a .plaintext 
//suffix. 
//So, for example, running './decoder bitio.cc.comp' should produce a bitio.cc.comp.plaintext in the current directory. It should be identical to bitio.cc.

//In both instances, try to challenge yourself to take more than a single command-line argument, so that the decoder decompresses all of its inputs.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "huffman.hh"
#include "bitio.hh"

int main(int argc, char* argv[])
{
    Huffman huff;
    Huffman::bits_t vectorofbits;
    std::string fileName  = "";
    
    if(argc == 2){ //if there is ONLY the .cpp file and the input file
        fileName = argv[1]; //input file name
    }
    else{
        std::cout << "please input like this: ./cppfile InputFile \n";
        return 1; //too many or two few files
    }

    


    //unsigned char holdByte  = 0x0;
    std::ifstream encryptedFile;
    encryptedFile.open(fileName, std::ios::out);
    std::ofstream decryptedFile; //make a new file
    decryptedFile.open(fileName +".plaintext");
    BitIO bitReceive(nullptr, &encryptedFile);//has input stream, no output stream
    BitIO bitGive(&decryptedFile, nullptr);//has an output steam, no input stream
    

    //encryptedFile.seekg(0, ios::end); // set the pointer to the end
    //auto size = encryptedFile.tellg() ; // get the length of the file
    //encryptedFile.seekg(0, ios::beg); // set the pointer to the beginning
    std::vector<bool> vectorOf1and0s;
    int symbol =0;
    bool b;
    while(symbol != EOF){//until it decodes symbol EOF, it codes with an infinite loop
        //*encryptedFile >> holdByte;
        //std::cout << holdByte<<"\n";
        for(int i =0; i < 8; i++){//for every byte in a decoded file
            b = bitReceive.input_bit();//decode those 8 bits with input bit, but them in an array of 1s and 0s, 
            vectorOf1and0s.push_back(b);
        }
         
        for(auto r : vectorOf1and0s){
            symbol = huff.decode(r);//use that array to work with huffman decode
        }
         decryptedFile << char(symbol);//put the char() version of the returned int into the new file
        //symbol+=2;
    }
   
        

    decryptedFile.close();
    encryptedFile.close();


    return 0;
}

/*int main(int argc, char* argv[])
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

    std::ifstream encryptedFile;
    encryptedFile.open(filenames[0], std::ios::out); */


