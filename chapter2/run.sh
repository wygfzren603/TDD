g++ *.cpp -o soundex -lgmock -pthread

if [ -f soundex ];then
  ./soundex
  rm -rf soundex
fi
