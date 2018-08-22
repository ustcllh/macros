#ifndef PHFLOWJETMAKER_H__
#define PHFLOWJETMAKER_H__

#include <TLorentzVector.h>
#include <fun4all/SubsysReco.h>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"

class Fun4AllHistoManager;
class PHCompositeNode;
class PHG4HitContainer;
class RawTowerContainer;
class RawTowerGeom;
class RawClusterContainer;
class RawCluster;
class GlobalVertex;
class PHMCTowerContainerV1;
class RawClusterContainer;
class PHFastjetContainer;
class PHPyJetContainerV2;
class PHG4TruthInfoContainer;
class JetMap;
class SvtxTrack;
class SvtxTrackMap;
class TVector3;
class TLorentzVector;
class TH1F;
class TF1;
class TH2F;
class TNtuple;
class MyVector;
class MyVectorContainer;

namespace fastjet
{
class PseudoJet;
class JetDefinition;
class SISConePlugin;
class ClusterSequence;
}

class PHFlowJetMaker : public SubsysReco
{
 public:
  PHFlowJetMaker(const std::string& name = "PHFlowJetMaker", const std::string algorithm = "AntiKt", double r_param = 0.3);

  virtual ~PHFlowJetMaker();

  int Init(PHCompositeNode*);

  int process_event(PHCompositeNode*);

  int End(PHCompositeNode*);

// * Jin - disable. Please use the standard cluster jet on the node tree
//  void create_calo_pseudojets(std::vector<fastjet::PseudoJet>& particles, RawClusterContainer* emc_clusters, RawClusterContainer* hci_clusters, RawClusterContainer* hco_clusters, GlobalVertex* vtx, GlobalVertex* vtx);

  void run_particle_flow(std::vector<fastjet::PseudoJet>& flow_particles, RawClusterContainer* emc_clusters, RawClusterContainer* hci_clusters, RawClusterContainer* hco_clusters, SvtxTrackMap* reco_tracks, GlobalVertex* vtx);

  int get_matched(double clus_energy, double track_energy);

  int create_node_tree(PHCompositeNode*);
  double TMVAEvalBDTG(double cemc_clE, double ihcal_clE, double ohcal_clE);

 private:
  //Sampling Fractions
  static const float sfEMCAL;
  static const float sfHCALIN;
  static const float sfHCALOUT;

  char* outfile;
  std::string algorithm;
  double r_param;

  JetMap* flow_jet_map;

  // flow jet constituents and pid
  // ep: e+/e- 2
  // ph: photon 4
  // ch: charged hadron 1
  // nh: neutral hadron 3
  // un: unknown 0
  MyVectorContainer* flow_jet_e_ep;
  MyVectorContainer* flow_jet_e_ph;
  MyVectorContainer* flow_jet_e_ch;
  MyVectorContainer* flow_jet_e_nh;
  MyVectorContainer* flow_jet_e_un;

  //Tolerance for cluster-track matching
  TF1* match_tolerance_low;
  TF1* match_tolerance_high;

  fastjet::JetDefinition* fJetAlgorithm;
  double min_jet_pT;

  // PHPyJetContainerV2 *flow_jet_container;
};

#endif
