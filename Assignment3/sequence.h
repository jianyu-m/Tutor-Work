
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
};

template <typename T>
ostream& operator<<(ostream& out, const std::vector<Sequence<T>>& seq);

template <typename T>
void sort_list(vector<Sequence<T>>& seq);

/* Other Neccessary Defination Here */
