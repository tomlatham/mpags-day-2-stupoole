//
// Created by stu on 27/10/2019.
//
#include "runCaeserCipher.h"

std::string runCaeserCipher(const std::string& input_text, const size_t key, const bool encrypt)
{
  std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  std::string output_string;
  if (encrypt)
  {
    for (const char in_char : input_text)
    {
      output_string += alphabet[alphabet.find(in_char)+key];
    }
  } else {
    for (const char in_char : input_text)
    {
      output_string += alphabet[alphabet.find(in_char) - key];
    }
  }
    return output_string;
}