
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Sequence {
public:
  vector<T> arr;
  int len;
  Sequence():len(0){}
};

template <typename T>
istream& operator>>(istream& in, Sequence<T>& seq) {
  int m;
  T t;
  in >> m;
  for (int i = 0;i < m;i++) {
    in >> t;
    seq.arr.push_back(t);
  }
}

template <typename T>
ostream& operator<<(ostream& out, const Sequence<T>& seq) {
  for (int i = 0;i < seq.len;i++) {
    out << seq.arr[i] << " ";
  }
  out << "\n";
}

template <typename T>
ostream& operator<<(ostream& out, const std::vector<Sequence<T>> seq) {
  typename std::vector<Sequence<T>>::const_iterator itr;
  for (itr = seq.begin();itr != seq.end();
        itr++) {
          cout << *itr;
        }
}

template <typename T>
void sort_list(vector<Sequence<T>> &seq) {

}
/* Other Neccessary Defination Here */
