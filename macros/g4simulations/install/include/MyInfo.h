#ifndef __MYINFO_H__
#define __MYINFO_H__
#include <fastjet/PseudoJet.hh>

class MyInfo: public fastjet::PseudoJet::UserInfoBase {
public:
  MyInfo(int id) {
    _pdg_id = id;
  }
  int pdg_id() const {return _pdg_id;}
private:
  int _pdg_id;
};

/* particle types
 * 0 unknown or dummy
 * 1 charged hadron
 * 2 electron or position
 * 3 neutral hadron
 * 4 gamma
*/
#endif

