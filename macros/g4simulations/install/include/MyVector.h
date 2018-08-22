#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

#include <phool/PHObject.h>
#include <vector>

class MyVector : public PHObject {
public:
  MyVector(const unsigned int idval = 0);
  MyVector(const std::vector<float> &vector);
  virtual ~MyVector();

  void set_val(const std::vector<float> &vector);
  const std::vector<float> get_vec() const {return vec;}
  unsigned int get_vec_size() const {return vec_size;}
  int Id() const {return id;}
  void Reset();


protected:
  int id;
  unsigned int vec_size;
  std::vector<float> vec;

};

MyVector::MyVector( const unsigned int idval){
  id = idval;
  vec_size = 0;
  vec = std::vector<float>();
  return;
}

MyVector::MyVector( const std::vector<float> &vector){
  Reset();
  set_val(vector);
  return;
}

MyVector::~MyVector(){
  Reset();
  return;
}

void MyVector::set_val(const std::vector<float> &vector){
  Reset();
  vec_size = vector.size();
  for(auto&& it : vector){
    vec.push_back(it);
  }
  return;
}

void MyVector::Reset(){
  vec_size = 0;
  vec.clear();
  return;
}

#endif
