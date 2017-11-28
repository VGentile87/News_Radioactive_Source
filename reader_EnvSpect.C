//*******************************
// Revision 1: 25/10/2015 (Antonia)
// - revison of recoil classification:
//   S included both in heavy and light nuclei
//
//*******************************

//#include "TMath.h"
#include <cmath>
#include <iomanip>      // std::setprecision
#include <iostream>
#include <fstream>

void reader_EnvSpect(){

  TFile *f = new TFile("NeutronsOutOfConcrete.root"); 
  TH1F * h1;
  TCanvas *c1 = (TCanvas*) f->Get("c1");
  h1 = (TH1F*) c1->GetPrimitive("hout");
  c1->Clear();
  c1->Draw();
  h1->Draw("");

  double energy = 0;
  double rate = 0;
  int nbins = h1->GetNbinsX();
  double step =  h1->GetXaxis()->GetBinCenter(nbins) - h1->GetXaxis()->GetBinCenter(nbins-1);
  cout << nbins << " " << step << endl;

  ofstream log;
  log.open("Neutron_Env_Spect.txt", std::ofstream::out);
  if (log.is_open()){
  for(int i=0;i<nbins;i++){
    energy = step*(i+1);
    rate = h1->GetBinContent(i+1);
    log << "/gps/hist/point " << energy << " " << rate << endl;    
  }
  }
  log.close();

}
