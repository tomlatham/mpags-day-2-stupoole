//
// Created by stu on 27/10/2019.
//
#include "runCaeserCipher.h"

std::string runCaeserCipher(const std::string& input_text, const size_t key, const bool decrypt)
{
  const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const std::string::size_type alphabetSize {alphabet.size()};
  std::string output_string;
  if (decrypt)
  {
    for (const char in_char : input_text)
    {
      output_string += alphabet[(alphabetSize + alphabet.find(in_char) - key)%alphabetSize];
    }
  } else {
    for (const char in_char : input_text)
    {
      output_string += alphabet[(alphabet.find(in_char) + key)%alphabetSize];
    }
  }
  return output_string;
}
