#ifndef RETWEETCOLLECTION_H
#define RETWEETCOLLECTION_H

#include "tweet.h"

class RetweetCollection {
  public:
    RetweetCollection():size_(0) {
    }

    unsigned int size() const {
      return size_;
    }

    bool is_empty() const {
      return 0 == size();
    }

    void add(const Tweet& tweet) {
      size_++;
    }
  private:
    unsigned int size_;
};

#endif
