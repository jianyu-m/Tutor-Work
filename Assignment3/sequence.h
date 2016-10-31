
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Sequence {
private:
  vector<T> arr;
  int len;
public:
  Sequence():len(0){}
  
  template <typename U>
  friend istream& operator>>(istream& in, Sequence<U>& seq);
  
  template <typename U>
  friend ostream& operator<<(ostream& out, const Sequence<U>& seq);
  
  template <typename U>
  friend ostream& operator<<(ostream& out, const const std::vector<Sequence<U>>& seq);
  
  template <typename U>
  friend sort_list(vector<Sequence<U>>& seq);
};

/* Other Neccessary Defination Here */
