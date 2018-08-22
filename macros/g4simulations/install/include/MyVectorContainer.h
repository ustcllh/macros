#ifndef __MYVECTORCONTAINER_H__
#define __MYVECTORCONTAINER_H__

#include <phool/PHObject.h>
#include <vector>
#include "MyVector.h"

class MyVector;

class MyVectorContainer : public PHObject {
public:
  MyVectorContainer();
  virtual ~MyVectorContainer();

  void AddVector(std::vector<float> &myvec);
  void Reset();

  std::vector<std::vector<float>>* get_val() {return myvecarray;}

protected:
  std::vector<std::vector<float>>* myvecarray;

};

MyVectorContainer::MyVectorContainer(){
  myvecarray = new std::vector<std::vector<float>>();
  return;
}

MyVectorContainer::~MyVectorContainer(){
  myvecarray->clear();
  delete myvecarray;
  return;
}

void MyVectorContainer::AddVector(std::vector<float> &myvec){
  myvecarray->push_back(myvec);
  return;
}

void MyVectorContainer::Reset(){
  myvecarray->clear();
  return;
}

#endif
