//
// Created by stu on 27/10/2019.
//
#include "runCaeserCipher.h"

std::string runCaeserCipher(const std::string& input_text, const size_t key, const bool decrypt)
{
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string output_string;
  if (decrypt)
  {
    for (const char in_char : input_text)
    {
      output_string += alphabet[(alphabet.find(in_char) - key)%26];
    }
  } else {
    for (const char in_char : input_text)
    {
      output_string += alphabet[(alphabet.find(in_char) + key)%26];
    }
  }
  return output_string;
}