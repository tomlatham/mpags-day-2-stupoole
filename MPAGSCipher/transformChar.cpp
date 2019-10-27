//
// Created by stu on 27/10/2019.
// ! Transliterate char to string
//

#include <string>
#include "transformChar.h"

std::string transformChar (const char in_char) {
  // Uppercase alphabetic characters
  if (std::isalpha(in_char))
  {
    std::string str;
    return str += std::toupper(in_char);
  }

  // Transliterate digitSs to English words
  switch (in_char)
  {
  case '0':
    return "ZERO";
  case '1':
    return "ONE";
  case '2':
    return "TWO";
  case '3':
    return "THREE";
  case '4':
    return "FOUR";
  case '5':
    return "FIVE";
  case '6':
    return "SIX";
  case '7':
    return "SEVEN";
  case '8':
    return "EIGHT";
  case '9':
    return "NINE";
  default:
    return "";
  }

  // If the character isn't alphabetic or numeric, DONT add it.
  // Our ciphers can only operate on alphabetic characters.

}