#ifndef SOUNDEX_H
#define SOUNDEX_H 
#include <string>

class Soundex{
public:
  std::string encode(const std::string& word) const {
    return zero_pad(word);
  }
  std::string zero_pad(const std::string& word) const {
    return word + "000";
  }
};

#endif
