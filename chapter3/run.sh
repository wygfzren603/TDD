g++ *.cpp -o retweet -lgmock -pthread

if [ -f retweet ];then
  ./retweet
  rm -rf retweet
fi
