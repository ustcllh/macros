#ifndef __TRUTHJETTRIGGER_H__
#define __TRUTHJETTRIGGER_H__

// --- need to check all these includes...
#include <fun4all/SubsysReco.h>
#include <vector>

#include "TTree.h"
#include "TFile.h"

class PHCompositeNode;
class PHG4Particle;
namespace HepMC {
class GenParticle;
} /* namespace HepMC */

class MyTreeMaker: public SubsysReco
{

 public:

  MyTreeMaker(const std::string &name, bool fill_g4particle_tree=true, bool fill_track_tree=true, bool fill_tower_tree=true, bool fill_cluster_tree=true, bool fill_truthjet4_tree=true, bool fill_towerjet4_tree=true, bool fill_phflowjet4_tree=true, bool fill_bhhit_tree=true);

  int Init(PHCompositeNode*);
  int process_event(PHCompositeNode*);
  int End(PHCompositeNode*);

 private:

  float PositionCorrectedNxNTowerE( PHCompositeNode *topNode, unsigned int cl_id, float eNN);
  void getClusterByIndex( PHCompositeNode *topNode, std::string detName, unsigned int cl_id, float teta, float tphi);
  void getClusterPCByIndex( PHCompositeNode *topNode, unsigned int cl_id);
  void getSecClosestClusterByIndex( PHCompositeNode *topNode, std::string detName, unsigned int cl_id);
  void getClusterShape( PHCompositeNode *topNode, std::string detName, unsigned int cl_id);
  void getNPCluster(PHCompositeNode *topNode, std::string detName, float eta, float phi);

  void GetJetPrimaryContributors( PHCompositeNode *topNode, PHG4Particle* g4ptl);
  void TraceHepMCParticle( HepMC::GenParticle *ptcle);

  TFile *_f;
  std::string _foutname;

  bool _fill_g4particle_tree;
  bool _fill_track_tree;
  bool _fill_tower_tree;
  bool _fill_cemc_cluster_tree;
  bool _fill_ihcal_cluster_tree;
  bool _fill_ohcal_cluster_tree;
  bool _fill_truthjet4_tree;
  bool _fill_towerjet4_tree;
  bool _fill_phflowjet4_tree;
  bool _fill_bhhit_tree;

  TTree *g4particle_tree;
  TTree *track_tree;
  TTree *tower_tree;
  TTree *cemc_cluster_tree;
  TTree *ihcal_cluster_tree;
  TTree *ohcal_cluster_tree;
  TTree *truthjet4_tree;
  TTree *towerjet4_tree;
  TTree *phflowjet4_tree;
  TTree *bhhit_tree;

  /////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////
  int _b_event;
  float _b_gvtx_x;
  float _b_gvtx_y;
  float _b_gvtx_z;
  float _b_vtx_x;
  float _b_vtx_y;
  float _b_vtx_z;
  //float _b_vtx_t;

  /////////////////////////////////////////////////////////////////////////
  int _b_g4particle_n;
  std::vector<float> _b_g4particle_e;
  std::vector<float> _b_g4particle_p;
  std::vector<float> _b_g4particle_pt;
  std::vector<float> _b_g4particle_eta;
  std::vector<float> _b_g4particle_phi;
  std::vector<int> _b_g4particle_pid;
  std::vector<float> _b_g4particle_cemc_clE;
  std::vector<float> _b_g4particle_ihcal_clE;
  std::vector<float> _b_g4particle_ohcal_clE;
  std::vector<float> _b_g4particle_cemc_dr;
  std::vector<float> _b_g4particle_ihcal_dr;
  std::vector<float> _b_g4particle_ohcal_dr;

  /////////////////////////////////////////////////////////////////////////
  int _b_track_n;
  std::vector<float> _b_track_p;
  std::vector<float> _b_track_pt;
  std::vector<float> _b_track_eta;
  std::vector<float> _b_track_phi;
  std::vector<int> _b_track_charge;
  std::vector<float> _b_track_chisq;
  std::vector<int> _b_track_ndf;
  std::vector<float> _b_track_dca2d;
  std::vector<float> _b_cemc_E3x3;
  std::vector<float> _b_cemc_E3x3_PC;
  std::vector<float> _b_ihcal_E3x3;
  std::vector<float> _b_ohcal_E3x3;
  std::vector<float> _b_cemc_E5x5;
  std::vector<float> _b_cemc_E5x5_PC;
  std::vector<float> _b_ihcal_E5x5;
  std::vector<float> _b_ohcal_E5x5;
  std::vector<int> _b_cemc_clNtwr;
  std::vector<float> _b_cemc_cldeta;
  std::vector<float> _b_cemc_cldphi;
  std::vector<float> _b_cemc_clE;
  std::vector<float> _b_cemc_clE_PC;
  std::vector<int> _b_ihcal_clNtwr;
  std::vector<float> _b_ihcal_cldeta;
  std::vector<float> _b_ihcal_cldphi;
  std::vector<float> _b_ihcal_clE;
  std::vector<int> _b_ohcal_clNtwr;
  std::vector<float> _b_ohcal_cldeta;
  std::vector<float> _b_ohcal_cldphi;
  std::vector<float> _b_ohcal_clE;
  std::vector<int> _b_track_truthid;

  // get second closest cluster energy and position
  std::vector<float> _b_cemc_2nd_clE;
  std::vector<float> _b_cemc_2nd_cldr;
  std::vector<float> _b_cemc_2nd_cldeta;
  std::vector<float> _b_cemc_2nd_cldphi;
  std::vector<int> _b_cemc_2nd_clNtwr;
  std::vector<float> _b_ihcal_2nd_clE;
  std::vector<float> _b_ihcal_2nd_cldr;
  std::vector<float> _b_ihcal_2nd_cldeta;
  std::vector<float> _b_ihcal_2nd_cldphi;
  std::vector<int> _b_ihcal_2nd_clNtwr;
  std::vector<float> _b_ohcal_2nd_clE;
  std::vector<float> _b_ohcal_2nd_cldr;
  std::vector<float> _b_ohcal_2nd_cldeta;
  std::vector<float> _b_ohcal_2nd_cldphi;
  std::vector<int> _b_ohcal_2nd_clNtwr;
  // get cluster shape
  /*
  std::vector<float> _b_cl_shape_cemc_e;
  std::vector<float> _b_cl_shape_cemc_dr;
  std::vector<float> _b_cl_shape_ihcal_e;
  std::vector<float> _b_cl_shape_ihcal_dr;
  std::vector<float> _b_cl_shape_ohcal_e;
  std::vector<float> _b_cl_shape_ohcal_dr;
  */
  std::vector<float> _b_cl_shape_cemc_width;
  std::vector<float> _b_cl_shape_cemc_eta_width;
  std::vector<float> _b_cl_shape_cemc_phi_width;
  std::vector<float> _b_cl_shape_ihcal_width;
  std::vector<float> _b_cl_shape_ihcal_eta_width;
  std::vector<float> _b_cl_shape_ihcal_phi_width;
  std::vector<float> _b_cl_shape_ohcal_width;
  std::vector<float> _b_cl_shape_ohcal_eta_width;
  std::vector<float> _b_cl_shape_ohcal_phi_width;


  /////////////////////////////////////////////////////////////////////////
  int _b_cemc_n;
  std::vector<float> _b_cemc_e;
  std::vector<float> _b_cemc_p;
  std::vector<float> _b_cemc_pt;
  std::vector<float> _b_cemc_eta;
  std::vector<float> _b_cemc_phi;
  std::vector<int> _b_cemc_id;
  int _b_ihcal_n;
  std::vector<float> _b_ihcal_e;
  std::vector<float> _b_ihcal_p;
  std::vector<float> _b_ihcal_pt;
  std::vector<float> _b_ihcal_eta;
  std::vector<float> _b_ihcal_phi;
  int _b_ohcal_n;
  std::vector<float> _b_ohcal_e;
  std::vector<float> _b_ohcal_p;
  std::vector<float> _b_ohcal_pt;
  std::vector<float> _b_ohcal_eta;
  std::vector<float> _b_ohcal_phi;

  /////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////
  float _b_cl_cemc_e;
  float _b_cl_cemc_p;
  float _b_cl_cemc_pt;
  float _b_cl_cemc_eta;
  float _b_cl_cemc_phi;
  int _b_cl_cemc_id;
  int _b_cl_cemc_ntwr;
  float _b_cl_cemc_twrEsum;
  float _b_cl_cemc_prob;
  float _b_cl_cemc_chi2;
  std::vector<float> _b_cl_twr_cemc_e;
  std::vector<int> _b_cl_twr_cemc_id;
  /////////////////////////////////////////////////////////////////////////
  float _b_cl_ihcal_e;
  float _b_cl_ihcal_p;
  float _b_cl_ihcal_pt;
  float _b_cl_ihcal_eta;
  float _b_cl_ihcal_phi;
  int _b_cl_ihcal_id;
  int _b_cl_ihcal_ntwr;
  std::vector<float> _b_cl_twr_ihcal_e;
  std::vector<int> _b_cl_twr_ihcal_id;
  /////////////////////////////////////////////////////////////////////////
  float _b_cl_ohcal_e;
  float _b_cl_ohcal_p;
  float _b_cl_ohcal_pt;
  float _b_cl_ohcal_eta;
  float _b_cl_ohcal_phi;
  int _b_cl_ohcal_id;
  int _b_cl_ohcal_ntwr;
  std::vector<float> _b_cl_twr_ohcal_e;
  std::vector<int> _b_cl_twr_ohcal_id;
  /////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////
  std::vector<float> _b_truthjet4_e;
  std::vector<float> _b_truthjet4_p;
  std::vector<float> _b_truthjet4_pt;
  std::vector<float> _b_truthjet4_eta;
  std::vector<float> _b_truthjet4_phi;
  std::vector<int> _b_truthjet4_cons_n; //constituents
  std::vector<std::vector<float>> _b_truthjet4_cons_e;
  std::vector<std::vector<float>> _b_truthjet4_cons_p;
  std::vector<std::vector<float>> _b_truthjet4_cons_pt;
  std::vector<std::vector<float>> _b_truthjet4_cons_eta;
  std::vector<std::vector<float>> _b_truthjet4_cons_phi;
  std::vector<std::vector<float>> _b_truthjet4_cons_dR;
  std::vector<std::vector<int>> _b_truthjet4_cons_pid;
  std::vector<std::vector<int>> _b_truthjet4_pg_n; //progenitors
  std::vector<std::vector<int>> _b_truthjet4_pg_id;
  std::vector<std::vector<float>> _b_truthjet4_pg_fract;
  std::vector<std::vector<int>> _b_truthjet4_pg_status;

  /////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////
  std::vector<float> _b_phflowjet4_e;
  std::vector<float> _b_phflowjet4_p;
  std::vector<float> _b_phflowjet4_pt;
  std::vector<float> _b_phflowjet4_eta;
  std::vector<float> _b_phflowjet4_phi;
  std::vector<std::vector<float>> _b_phflowjet4_e_un;
  std::vector<std::vector<float>> _b_phflowjet4_e_ep;
  std::vector<std::vector<float>> _b_phflowjet4_e_ch;
  std::vector<std::vector<float>> _b_phflowjet4_e_nh;
  std::vector<std::vector<float>> _b_phflowjet4_e_ph;
  /////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////
  float _b_towerjet4_e;
  float _b_towerjet4_p;
  float _b_towerjet4_pt;
  float _b_towerjet4_eta;
  float _b_towerjet4_phi;
  int _b_towerjet4_cemc_n; //cemc towers
  std::vector<float> _b_towerjet4_cemc_e;
  std::vector<float> _b_towerjet4_cemc_p;
  std::vector<float> _b_towerjet4_cemc_pt;
  std::vector<float> _b_towerjet4_cemc_eta;
  std::vector<float> _b_towerjet4_cemc_phi;
  std::vector<float> _b_towerjet4_cemc_dR;
  std::vector<int> _b_towerjet4_cemc_id;
  int _b_towerjet4_clcemc_n; //cemc clusters
  std::vector<float> _b_towerjet4_clcemc_e;
  std::vector<float> _b_towerjet4_clcemc_p;
  std::vector<float> _b_towerjet4_clcemc_pt;
  std::vector<float> _b_towerjet4_clcemc_eta;
  std::vector<float> _b_towerjet4_clcemc_phi;
  std::vector<float> _b_towerjet4_clcemc_dR;
  std::vector<int> _b_towerjet4_clcemc_id;
  std::vector<int> _b_towerjet4_clcemc_ntwr;
  std::vector<float> _b_towerjet4_clcemc_prob;
  std::vector<float> _b_towerjet4_clcemc_chi2;
  std::vector<float> _b_towerjet4_clcemc_twrEsum;
  std::vector<float> _b_towerjet4_clcemc_twrNfrac;
  int _b_towerjet4_clcemcMatched_n; //cemc clusters matched to track!
  std::vector<float> _b_towerjet4_clcemcMatched_e;
  std::vector<float> _b_towerjet4_clcemcMatched_p;
  std::vector<float> _b_towerjet4_clcemcMatched_pt;
  std::vector<float> _b_towerjet4_clcemcMatched_eta;
  std::vector<float> _b_towerjet4_clcemcMatched_phi;
  std::vector<float> _b_towerjet4_clcemcMatched_dR;
  std::vector<int> _b_towerjet4_clcemcMatched_id;
  std::vector<int> _b_towerjet4_clcemcMatched_ntwr;
  std::vector<float> _b_towerjet4_clcemcMatched_prob;
  std::vector<float> _b_towerjet4_clcemcMatched_chi2;
  std::vector<float> _b_towerjet4_clcemcMatched_track_p;
  std::vector<float> _b_towerjet4_clcemcMatched_track_deta;
  std::vector<float> _b_towerjet4_clcemcMatched_track_dphi;
  std::vector<float> _b_towerjet4_clcemcMatched_track_dr;
  int _b_towerjet4_ihcal_n; //ihcal towers
  std::vector<float> _b_towerjet4_ihcal_e;
  std::vector<float> _b_towerjet4_ihcal_p;
  std::vector<float> _b_towerjet4_ihcal_pt;
  std::vector<float> _b_towerjet4_ihcal_eta;
  std::vector<float> _b_towerjet4_ihcal_phi;
  std::vector<float> _b_towerjet4_ihcal_dR;
  std::vector<int> _b_towerjet4_ihcal_id;
  int _b_towerjet4_clihcal_n; //ihcal clusters
  std::vector<float> _b_towerjet4_clihcal_e;
  std::vector<float> _b_towerjet4_clihcal_p;
  std::vector<float> _b_towerjet4_clihcal_pt;
  std::vector<float> _b_towerjet4_clihcal_eta;
  std::vector<float> _b_towerjet4_clihcal_phi;
  std::vector<float> _b_towerjet4_clihcal_dR;
  std::vector<int> _b_towerjet4_clihcal_id;
  std::vector<int> _b_towerjet4_clihcal_ntwr;
  std::vector<float> _b_towerjet4_clihcal_twrEsum;
  std::vector<float> _b_towerjet4_clihcal_twrNfrac;
  int _b_towerjet4_ohcal_n; //ohcal towers
  std::vector<float> _b_towerjet4_ohcal_e;
  std::vector<float> _b_towerjet4_ohcal_p;
  std::vector<float> _b_towerjet4_ohcal_pt;
  std::vector<float> _b_towerjet4_ohcal_eta;
  std::vector<float> _b_towerjet4_ohcal_phi;
  std::vector<float> _b_towerjet4_ohcal_dR;
  std::vector<int> _b_towerjet4_ohcal_id;
  int _b_towerjet4_clohcal_n; //ohcal clusters
  std::vector<float> _b_towerjet4_clohcal_e;
  std::vector<float> _b_towerjet4_clohcal_p;
  std::vector<float> _b_towerjet4_clohcal_pt;
  std::vector<float> _b_towerjet4_clohcal_eta;
  std::vector<float> _b_towerjet4_clohcal_phi;
  std::vector<float> _b_towerjet4_clohcal_dR;
  std::vector<int> _b_towerjet4_clohcal_id;
  std::vector<int> _b_towerjet4_clohcal_ntwr;
  std::vector<float> _b_towerjet4_clohcal_twrEsum;
  std::vector<float> _b_towerjet4_clohcal_twrNfrac;
  /////////////////////////////////////////////////////////////////////////
  int _b_bhhit_n;
  float _b_bhhit_edepTot;
  std::vector<float> _b_bhhit_edep;
  std::vector<float> _b_bhhit_p;
  std::vector<float> _b_bhhit_pt;
  std::vector<float> _b_bhhit_eta;
  std::vector<float> _b_bhhit_phi;

};

#endif // __TRUTHJETTRIGGER_H__
