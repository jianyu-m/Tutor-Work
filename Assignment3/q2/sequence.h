
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Sequence {
private:
  vector<T> arr;
  int len;
public:
  Sequence():len(0){}
  template <typename U>
  friend bool seq_comp(const Sequence<U>& a, const Sequence<U>& b);  
  
  template <typename U>
  friend istream& operator>>(istream& in, Sequence<U>& seq);
  
  template <typename U>
  friend ostream& operator<<(ostream& out, const Sequence<U>& seq);
};

template <typename T>
istream& operator>>(istream& in, Sequence<T>& seq) {
  int m;
  T t;
  in >> m;
  seq.len = m;
  for (int i = 0;i < m;i++) {
   in >> t; 
   seq.arr.push_back(t);
  }
  return in;
}

template <typename T>
ostream& operator<<(ostream& out, const Sequence<T>& seq) {
  for (int i= 0;i < seq.len;i++) {
   out << seq.arr[i] << " "; 
  }
  out << "\n";
  return out;
}

template <typename T>
ostream& operator<<(ostream& out, const std::vector<Sequence<T>>& seq) {
 typename std::vector<Sequence<T>>::const_iterator itr;
 for (itr = seq.begin();itr != seq.end();itr++) {
  out << *itr; 
 }
  return out;
}

template <typename T>
bool seq_comp(const Sequence<T>& a,const Sequence<T>& b){
 if (a.len != b.len) {
    return a.len < b.len;
 }
 T t1, t2;
 t1 = 0;
 t2 = 0;
 for (int i = 0;i < a.len;i++) {
    t1 += a.arr[i] * a.arr[i];
    t2 += b.arr[i] * b.arr[i];
 }
 return t1 < t2;
}

template <typename T>
void sort_list(vector<Sequence<T>>& seq) {
  sort(seq.begin(), seq.end(), seq_comp<T>);
}

/* Other Neccessary Defination Here */
