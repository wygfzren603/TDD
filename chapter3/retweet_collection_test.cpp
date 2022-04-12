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

TEST_F(ARetweetCollection, HasSizeOfOneAfterTweetAdded) {
  collection.add(Tweet());
  ASSERT_THAT(collection.size(), Eq(1u));
}

class BRetweetCollection : public Test {
  public:
    RetweetCollection collection;
};

TEST_F(BRetweetCollection, HasSizeOfTwoAfterTwoTweetsAdded) {
  collection.add(Tweet());
  collection.add(Tweet());
  ASSERT_THAT(collection.size(), Eq(2u));
}

class CRetweetCollection : public Test {
  public:
    RetweetCollection collection;
};
TEST_F(CRetweetCollection, DecreasesSizeAfterRemovingTweet) {
  collection.add(Tweet());
  collection.remove(Tweet());
  ASSERT_THAT(collection.size(), Eq(0u));
}
TEST_F(CRetweetCollection, IsEmptyAfterRemovingTweet) {
  collection.add(Tweet());
  collection.remove(Tweet());
  ASSERT_TRUE(collection.is_empty());
}

TEST_F(CRetweetCollection, HasSizeOfZeroAfterRemovingMoreTweets) {
  collection.add(Tweet());
  collection.remove(Tweet());
  collection.remove(Tweet());
  ASSERT_THAT(collection.size(), Eq(0u));
}
