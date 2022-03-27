#include "gmock/gmock.h"
#include "soundex.h"
using namespace testing;

class SoundexEncoding : public Test {
public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, RetainSoleLetterOfOneLetterWord) {
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
  ASSERT_THAT(soundex.encode("Ac"), Eq("A200"));
  ASSERT_THAT(soundex.encode("Ad"), Eq("A300"));
  ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
  ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits) {
  ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
  ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
  ASSERT_THAT(soundex.encode("Baeiouhywcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
  ASSERT_THAT(soundex.encode_digit('b'), Eq(soundex.encode_digit('f')));
  ASSERT_THAT(soundex.encode_digit('c'), Eq(soundex.encode_digit('g')));
  ASSERT_THAT(soundex.encode_digit('d'), Eq(soundex.encode_digit('t')));

  ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter) {
  ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}
