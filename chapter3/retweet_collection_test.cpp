#include "gmock/gmock.h"
#include "retweet_collection.h"
#include "tweet.h"
using namespace ::testing;

class ARetweetCollection : public Test {
  public:
    RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
  ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdd) {
  collection.add(Tweet());

  ASSERT_FALSE(collection.is_empty());
}

