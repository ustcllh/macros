#!/bin/csh
echo "*** Executing run_Fun4All.sh"
set workdir = /sphenix/user/lihan/PFJet/macros/macros/g4simulations
#if ($?_CONDOR_SCRATCH_DIR) then
#set workdir = ${_CONDOR_SCRATCH_DIR}
#endif
cd $workdir
pwd
##ls -la
source /etc/csh.login
foreach i (/etc/profile.d/*.csh)
     source $i
end
source /opt/sphenix/core/bin/sphenix_setup.csh -n
setenv MYINSTALL /sphenix/user/lihan/PFJet/macros/macros/g4simulations/install
setenv LD_LIBRARY_PATH $MYINSTALL/lib:$LD_LIBRARY_PATH

set foo = "`printf "%04d" $1`"
echo $foo

set event=500
#set event=10
#set event=100
#set event=0
#set event=50
#root -l -b Fun4All_G4_sPHENIX_egun.C
root -l -b Fun4All_G4_sPHENIX_egun.C\($event,\"\",\"/sphenix/user/lihan/PFJet/output/out_SingleParticle/G4Hits_sPHENIX_$3_eta0.60_$2GeV-$foo\",\"\"\,\"$3\",$2\)
#root -l -b Fun4All_G4_sPHENIX_gun.C\($event,\"\",\"/sphenix/user/lihan/PFJet/output/out_SingleParticle/G4Hits_sPHENIX_k0_$2GeV-$foo.root\",\"\",\"\",$2\)
#root -l -b Fun4All_G4_sPHENIX_SingleParticle.C\($event,\"/sphenix/sim/sim01/cd1_review/single_particle/fieldmap/G4Hits_sPHENIX_$3_eta0_$2-$foo.root\",\"/sphenix/user/lihan/PFJet/output/out_SingleParticle/G4Hits_sPHENIX_$3_eta0_$2-$foo.root\",\"\"\)
#root -l -b Fun4All_G4_sPHENIX_SingleParticle.C\($event,\"/sphenix/sim/sim01/cd1_review/single_particle/fieldmap/G4Hits_sPHENIX_e-_eta0.60_$2-$foo.root\",\"/sphenix/user/lihan/PFJet/output/out_SingleParticle/G4Hits_sPHENIX_e-_eta0.60_$2-$foo.root\",\"\"\)
###root -l -b Fun4All_G4_sPHENIX_jet.C
### pythia8_dijet_highz
###root -l -b -q Fun4All_G4_sPHENIX_py8jet_highz.C\($event,0.45,40.0,0.8,\"./pythia_cfg/phpythia8_QCD30.cfg\",\"/sphenix/user/lihan/PFJet/output/out_$2/QCD30GeV_jet40GeVeta0p45_G4sPHENIX_$2_$1.root\",\"\"\)
### pythia8_dijet_allz
#root -l -b -q Fun4All_G4_sPHENIX_py8jet_highz.C\($event,0.45,40.0,0.0,\"phpythia8_QCD30.cfg\",\"./out_$2/QCD30GeV_jet40GeVeta0p45_G4sPHENIX_$2_$1.root\",\"\"\)

### pythia8 gammajet
#root -l -b -q Fun4All_G4_sPHENIX_py8gammajet.C\($event,\"phpythia8_QCD15_prompt.cfg\",\"./out_$2/QCD15GeV_gammajet5GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)
### pythia8 dijet
#root -l -b -q Fun4All_G4_sPHENIX_py8jet.C\($event,\"phpythia8_QCD15.cfg\",\"./out_$2/QCD15GeV_jet15GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)

################################
### QCDjet 20 GeV
###root -l -b -q Fun4All_G4_sPHENIX_jet.C\($event,\"/sphenix/user/lajoie/gen/QCD15/hepmc_QCD15GeV_R04jet20GeVeta0p6_seq$foo.dat\",\"./out_$2/QCD15GeV_R04jet20GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)
### QCDjet 30 GeV
#root -l -b -q Fun4All_G4_sPHENIX_jet.C\($event,\"/sphenix/user/lajoie/gen/QCD25/hepmc_QCD25GeV_R04jet30GeVeta0p6_seq$foo.dat\",\"./out_$2/QCD25GeV_R04jet30GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)
### QCDjet 40 GeV
#root -l -b -q Fun4All_G4_sPHENIX_jet.C\($event,\"/sphenix/user/lajoie/gen/QCD30/hepmc_QCD30GeV_R04jet40GeVeta0p6_seq$foo.dat\",\"./out_$2/QCD30GeV_R04jet40GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)
### QCDjet 50 GeV (From Dennis)
#root -l -b -q Fun4All_G4_sPHENIX_jet.C\($event,\"/sphenix/user/dvp/gen/QCD35/hepmc_QCD35GeV_R04jet50GeVeta0p6_seq$foo.dat\",\"./out_$2/DVP_QCD35_10k_G4sPHENIX_$2_$1.root\",\"\"\)
################################
### gammajet 20 GeV
#root -l -b -q Fun4All_G4_sPHENIX_jet.C\($event,\"/sphenix/user/lajoie/gen/QCD15_gamma+jet/hepmc_QCD15GeV_gamma+jet_R04jet20GeVeta0p6_seq$foo.dat\",\"./out_$2/QCD15GeV_gamma+jet_R04jet20GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)
### gammajet 30 GeV
#root -l -b -q Fun4All_G4_sPHENIX_jet.C\($event,\"/sphenix/user/lajoie/gen/QCD25_gamma+jet/hepmc_QCD25GeV_gamma+jet_R04jet30GeVeta0p6_seq$foo.dat\",\"./out_$2/QCD25GeV_gamma+jet_R04jet30GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)
### gammajet 40 GeV
#root -l -b -q Fun4All_G4_sPHENIX_jet.C\($event,\"/sphenix/user/lajoie/gen/QCD30_gamma+jet/hepmc_QCD30GeV_gamma+jet_R04jet40GeVeta0p6_seq$foo.dat\",\"./out_$2/QCD30GeV_gamma+jet_R04jet40GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)
### gammajet 50 GeV
#root -l -b -q Fun4All_G4_sPHENIX_jet.C\($event,\"/sphenix/user/lajoie/gen/QCD35_gamma+jet/hepmc_QCD35GeV_gamma+jet_R04jet50GeVeta0p6_seq$foo.dat\",\"./out_$2/QCD35GeV_gamma+jet_R04jet50GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)

### ptlgun
#set event=100
#root -l -b -q Fun4All_G4_sPHENIX_ptlgun.C\($event,\"/sphenix/user/lajoie/gen/QCD35_gamma+jet/hepmc_QCD35GeV_gamma+jet_R04jet50GeVeta0p6_seq$foo.dat\",\"./out_$2/QCD35GeV_gamma+jet_R04jet50GeVeta0p6_G4sPHENIX_$2_$1.root\",\"\"\)

echo "The run_Fun4All.sh script has finished executing, exiting".
