#include "gmock/gmock.h"
#include "retweet_collection.h"
using namespace ::testing;

class ARetweetCollection : public Test {
  public:
    RetweetCollection retweets;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated) {
  ASSERT_THAT(retweets.size(), Eq(0u));
}
