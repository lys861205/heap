#include "heap.h"

#include <stdio.h>

class Value {
public:
  Value(int a):v_(a) {}

  friend bool operator<(const Value& lh, const Value& rh) {
    return lh.v_ < rh.v_;
  }

  int get() const {
    return v_;
  }
private:
  int v_;
};

template <typename T>
struct CMP {
  bool operator()(const T& a, const T& b) 
  {
    return a < b;
  }
};

template <> 
struct CMP<int> {
  bool operator()(const int& a, const int& b) 
  {
    return a > b;
  }
};

template <> 
struct CMP<Value> {
  bool operator()(const Value& a, const Value& b) 
  {
    return a < b;
  }
};


int main()
{
  {
    Heap<int, CMP<int> > h;
    for (int i=0; i < 10000; ++i) {
      h.insert(i);
    }
    printf("%d\n", h.best());
    h.pop();
    printf("%d\n", h.best());
  }
  {
    Heap<Value, CMP<Value> > h;
    for (int i=0; i < 10000; ++i) {
      Value v(i);
      h.insert(v);
    }
    Value value = h.best();
    printf("%d\n", value.get());
    h.pop();
    value = h.best();
    printf("%d\n", value.get());
  }
  return 0;
}

