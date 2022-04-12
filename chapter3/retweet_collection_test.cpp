#include "gmock/gmock.h"
#include "retweet_collection.h"
using namespace ::testing;

class ARetweetCollection : public Test {
  RetweetCollection retweets;
};

TEST(ARetweetCollection, IsEmptyWhenCreated) {
}
