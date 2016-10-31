
#include "sequence.h"
#include <algorithm>
template <typename T>
istream& operator>>(istream& in, Sequence<T>& seq) {
  int m;
  T t;
  in >> m;
  seq.len = m;
  for (int i = 0;i < m;i++) {
   in >> t; 
   seq.push_back(t);
  }
  return in;
}

template <typename T>
ostream& operator<<(ostream& out, const Sequence<T>& seq) {
  for (int i= 0;i < seq.len;i++) {
   out << seq[i] << " "; 
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
bool seq_comp(Sequence<T>& a, Sequence<T>& b){
 return true;
}

template <typename T>
void sort_list(vector<Sequence<T>> &seq) {
  sort(seq.begin(), seq.end(), seq_comp);
}
