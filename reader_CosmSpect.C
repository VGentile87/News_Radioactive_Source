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

void reader_CosmSpect(){

  TFile *f = new TFile("MuonInducedNeutron-4NEWS.root"); 
  TH1F * h1;
  TH1F * h2;
  /*TCanvas *c1 = (TCanvas*) f->Get("c1");
  h1 = (TH1F*) c1->GetPrimitive("hout");
  c1->Clear();
  c1->Draw();
  h1->Draw("");*/

  
  h1 = (TH1F*)f->Get("hNeutronZenithAngle");
  h1->RebinX(10);
  h1->Draw();

  h2 = (TH1F*)f->Get("hNeuNrg");
  h2->RebinX(10);
  // h2->Draw(); 

  double energy = 0;
  double theta = 0;
  double rate_ene = 0;
  double rate_theta = 0;

  int nbins_theta = h1->GetNbinsX();
  double step_theta =  h1->GetXaxis()->GetBinCenter(nbins_theta) - h1->GetXaxis()->GetBinCenter(nbins_theta-1);
  cout << nbins_theta << " " << step_theta << endl;

  int nbins_ene = h2->GetNbinsX();
  double step_ene =  h2->GetXaxis()->GetBinCenter(nbins_ene) - h2->GetXaxis()->GetBinCenter(nbins_ene-1);
  cout << nbins_ene << " " << step_ene << endl;

  double pi = TMath::Pi();

  TH1F *htheta = new TH1F("theta_alto","theta_alto",100,0,pi);
  TH1F *htheta_mod1 = new TH1F("theta_lato1","theta_lato1",100,0,pi);
  TH1F *htheta_mod2 = new TH1F("theta_lato2","theta_lato2",100,0,pi);
  
  ofstream log_ene;
  log_ene.open("Neutron_Cosm_Spect_Ene.txt", std::ofstream::out);
  if (log_ene.is_open()){
  for(int i=0;i<nbins_ene;i++){
    energy = step_ene*(i+1);
    rate_ene = h2->GetBinContent(i+1);
    log_ene << "/gps/hist/point " << energy << " " << rate_ene << endl;    
  }
  }
  log_ene.close();

  ofstream log_theta;
  log_theta.open("Neutron_Cosm_Spect_Theta.txt", std::ofstream::out);
  if (log_theta.is_open()){
  for(int i=0;i<nbins_theta;i++){
    //cout << (-1+step_theta*(i+1)) << endl;
    theta = TMath::ACos(-(-1+step_theta*(i+1)));//-1+step_theta*(i+1);
    rate_theta = h1->GetBinContent(i+1);
    log_theta << "/gps/hist/point " << theta << " " << rate_theta << endl;
    htheta->SetBinContent(i+1,rate_theta);
  }
  for(int i=0;i<nbins_theta;i++){
    //cout << (-1+step_theta*(i+1)) << endl;
    theta = TMath::ACos(-(-1+step_theta*(i+1)))+TMath::Pi();//-1+step_theta*(i+1);
    rate_theta = h1->GetBinContent(i+1);
    log_theta << "/gps/hist/point " << theta << " " << rate_theta << endl;
    htheta->SetBinContent(i+1,rate_theta);
  }
  }
  log_theta.close();
  
  ofstream log_theta1;
  double theta_new_ref=0;
  log_theta1.open("Neutron_Cosm_Spect_Theta_par1.txt", std::ofstream::out);
  if (log_theta1.is_open()){
    for(int i=0;i<nbins_theta;i++){
      //cout << (-1+step_theta*(i+1)) << endl;
      theta = TMath::ACos(-1+step_theta*(i+1));//-1+step_theta*(i+1);
      theta_new_ref = TMath::Pi()/2. - theta ;
      cout << theta << " " << theta_new_ref << endl;
      if(theta_new_ref<0)theta_new_ref = pi + theta_new_ref;
      cout << theta_new_ref << " " << rate_theta << endl;
      rate_theta = h1->GetBinContent(i+1);
      log_theta1 << "/gps/hist/point " << theta_new_ref << " " << rate_theta << endl;
      htheta_mod1->SetBinContent(i+1,rate_theta);
    }
    log_theta1 << "\n" <<"\n"<< endl;
    for(int i=0;i<nbins_theta;i++){
      //cout << (-1+step_theta*(i+1)) << endl;
      theta = TMath::ACos(-1+step_theta*(i+1));//-1+step_theta*(i+1);
      theta_new_ref = TMath::Pi()/2. + theta;
      if(theta_new_ref>pi)theta_new_ref = theta_new_ref-pi;
      cout << theta_new_ref << " " << rate_theta << endl;
      rate_theta = h1->GetBinContent(i+1);
      log_theta1 << "/gps/hist/point " << theta_new_ref << " " << rate_theta << endl;
      htheta_mod2->SetBinContent(i+1,rate_theta);
    }
  }
  log_theta1.close();

  TCanvas *c1 = new TCanvas("c1","c1",600,600);
  htheta->Draw();

  /*
  TCanvas *c2 = new TCanvas("c2","c2",600,600);
  htheta_mod1->Draw();

  TCanvas *c3 = new TCanvas("c3","c3",600,600);
  htheta_mod2->Draw();*/
  
}
