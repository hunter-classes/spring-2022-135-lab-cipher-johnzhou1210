#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include "funcs.h"

// capital alphabet ascii range is [65,90] and lower alphabet ascii range is [97,122]
bool isAlpha(char c)
{
  return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

char shiftChar(char c, int rShift)
{
  if (!isAlpha) // if not alphabetical character
  {
    return c;
  }
  // take care of bounds
  int newAscii = c + rShift;
  if (newAscii > 90 && (c >= 65 && c <= 90)) // capital overflow
  {
    int overflow = newAscii - 90 - 1;
    return (char)(65 + overflow);
  }
  if (newAscii > 122 && (c >= 97 && c <= 122)) // lowercase overflow
  {
    // std::cout << "lowercase overflow!\n";
    int overflow = newAscii - 122 - 1;
    return (char)(97 + overflow);
  }
  return (char)(newAscii);
}

std::string encryptCaesar(std::string plainTxt, int rShift)
{
  std::string result = plainTxt;
  for (int i = 0; i < plainTxt.length(); i++)
  {
    char currChar = plainTxt[i];
    if (isAlpha(currChar))
    {
      char shiftedChar = shiftChar(currChar, rShift);
      result[i] = shiftedChar;
    }
  }
  return result;
}


int countChar(std::string str, char c)
{
  int count = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == c)
    {
      count++;
    }
  }
  return count;
}

int countAlpha(std::string str)
{
  int count = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (isAlpha(str[i]))
    {
      count++;
    }
  }
  return count;
}

char charToLower(char c)
{
  char result = c;
  if (c >= 65 && c <= 90) // if upper case
  {
    result = c + 32;
  }
  return result;
}

double dist(std::vector<double> v1, std::vector<double> v2)
{
  if (v1.size() != v2.size())
  {
    std::cerr << "Could not perform distance operation! v1.size() != v2.size()\n";
    return 0.0;
  }
  double result = 0.0;
  for (int i = 0; i < v1.size(); i++)
  {
    double pair = pow(v1[i] - v2[i], 2);
    result = result + pair;
  }
  return sqrt(result);
}

std::vector<double> scaleAlphaLFreqs(std::vector<double> v, double factor)
{
  std::vector<double> result;
  // clone v into result
  for (int i = 0; i < v.size(); i++)
  {
    result.push_back(v[i]);
  }
  // scale result
  for (int i = 0 ; i < v.size(); i++)
  {
    result[i] = result[i] * factor;
  }
  return result;
}

std::string solve(std::string encryptedString)
{
  int bestRot = 0;
  double closestDist = std::numeric_limits<double>::max(); // max double val
  std::vector<char> alphaChars = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
  };
  // frequencies are in decimal form, NOT percent.
  std::vector<double> alphaLFreqs = {
    .085, .021, .045, .034, .112, .018, .025, .030, .075, .002, .011, .055, .03, .067, .072, .032,
    .002, .076, .057, .07, .036, .01, .013, .003, .018, .003
  };
  std::vector<double> scaledAlphaLFreqs = scaleAlphaLFreqs(alphaLFreqs, (double)countAlpha(encryptedString));

  // for (int k = 0; k < scaledAlphaLFreqs.size(); k++)
  // {
  //   std::cout << std::to_string(alphaChars[k]) << ": " << scaledAlphaLFreqs[k] << "\n";
  // }
  // std::cout << "==========================\n";

  // get alpha character frequencies for each rotation
  for (int i = 0; i < 26; i++)
  {
    std::string currRotStr = encryptCaesar(encryptedString, i);
    std::vector<double> rotAlphaFreqs(26,0);
    for (int j = 0; j < currRotStr.length(); j++)
    {
      char currChar = currRotStr[j];
      if (isAlpha(currChar))
      {
        int alphaIndex = charToLower(currChar) - 96; // 96 makes chars start at 1
        rotAlphaFreqs[alphaIndex] = rotAlphaFreqs[alphaIndex] + 1.0;
      }
    }
    double currDist = dist(scaledAlphaLFreqs, rotAlphaFreqs);
    if (currDist < closestDist)
    {
        closestDist = currDist;
        bestRot = i;
    }
  }
  // std::cout << bestRot << "\n";
  return encryptCaesar(encryptedString, bestRot + 1);
}
