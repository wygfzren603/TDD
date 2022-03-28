#ifndef SOUNDEX_H
#define SOUNDEX_H 
#include <string>
#include <unordered_map>

const size_t MAX_CODE_LENGTH{4};
const std::string NotADigit{"*"};

class Soundex{
public:
  std::string encode(const std::string& word) const {
    return zero_pad(upper_front(head(word)) + tail(encode_digits(word)));
  }
  std::string encode_digit(char letter) const {
    const std::unordered_map<char, std::string> encodings{
      {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
      {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"},
      {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
      {'d', "3"}, {'t', "3"},
      {'l', "4"},
      {'m', "5"}, {'n', "5"},
      {'r', "6"}
    };
    auto it  = encodings.find(lower(letter));
    return it == encodings.end() ? NotADigit : it->second;
  }
private:
  std::string head(const std::string& word) const {
    return word.substr(0, 1);
  }

  std::string tail(const std::string& word) const {
    return word.substr(1);
  }

  bool is_complete(const std::string& encoding) const {
    return encoding.length() == MAX_CODE_LENGTH;
  }

  std::string last_digit(const std::string& encoding) const {
    if (encoding.empty()) return NotADigit;
    return std::string(1, encoding.back());
  }

  std::string encode_digits(const std::string& word) const {
    std::string encoding;
    encode_head(word, encoding);
    encode_tail(word, encoding);
    return encoding;
  }

  void encode_head(const std::string& word, std::string& encoding) const {
    encoding += encode_digit(word.front());
  }

  void encode_tail(const std::string& word, std::string& encoding) const {
    for (auto letter : tail(word)) {
      if (is_complete(encoding)) break;
      encode_letter(letter, encoding);
    }
  }

  void encode_letter(char letter, std::string& encoding) const {
      auto digit = encode_digit(letter);
      if (digit != NotADigit && digit != last_digit(encoding))
        encoding += digit;
  }

  std::string zero_pad(const std::string& word) const {
    int zerosNeeded = MAX_CODE_LENGTH - word.length();
    return word + std::string(zerosNeeded, '0');
  }

  std::string upper_front(const std::string& word) const {
    return std::string(1, 
        std::toupper(static_cast<unsigned char>(word.front())));
  }

  char lower(char c) const {
    return std::tolower(static_cast<unsigned char>(c));
  }
};

#endif
