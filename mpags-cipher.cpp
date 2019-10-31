// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MPAGSCipher/processCommandLine.h"
#include "MPAGSCipher/transformChar.h"
#include "MPAGSCipher/print.h"
#include "MPAGSCipher/runCaeserCipher.h"
#include <cctype>




// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  bool decryptRequested {false};
  bool appendRequested {false};
  std::size_t key {5};
  std::string inputFile;
  std::string outputFile;


  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  const bool processedOK { processCommandLine(cmdLineArgs, helpRequested, versionRequested,
      decryptRequested, appendRequested, key, inputFile,
      outputFile) };
  if ( ! processedOK ) {
    std::cerr << "Problem processing command line arguments" << std::endl;
    return 1;
  }

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n"
      << "  -d               Specify decryption\n "
      << "                   Defaults to encryption\n\n"
      << "  -k KEY           Integer key for Encryption/Decryption\n"
      << "                   Default Key is 5 \n\n"
      << "  -a               Append to output file if specified"
      << std::endl;
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.2.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar;
  std::string inputText;

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) {
    std::ifstream in_file {inputFile};
    if (in_file.good()){
      while (in_file  >> inputChar) {
        inputText += transformChar(inputChar);
      }
      in_file.close();
    }else{
      in_file.close();
      print("Could not open file " + inputFile);
    }
  } else {


//   Loop over each character from user input
//   (until Return then CTRL-D (EOF) pressed)
    print("\n Input your text and press ctrl+d to finish");
    while(std::cin >> inputChar)
    {
      inputText += transformChar(inputChar);
    }
  }

  std::string outputText { runCaeserCipher(inputText, key, decryptRequested) };

  // Output the transliterated text
  if (!outputFile.empty()) {
    std::ofstream out_file;
    if (appendRequested) {
      out_file.open(outputFile, std::ios::app);
    } else {
      out_file.open(outputFile);
    }
    if (out_file.good()){
      out_file << outputText;
    } else {
      out_file.close();
      print("Failed to write to file " + outputFile);
    }
  } else {
    //print(inputText);
    std::cout << outputText << std::endl;
  }



  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
