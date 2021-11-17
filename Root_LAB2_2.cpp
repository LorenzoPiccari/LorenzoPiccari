//
//  LAB_2
//
//  Working on the results of the 10 000 events
//
#include <iostream>
#include "TLorentzVector.h"
#include "TRandom.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TString.h"
#include "TStyle.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    //creating the 4 momentum of the B meson in the LAB frame
    TLorentzVector p4_B;
    double m_B = 5279; //MeV
    double m_B2 = m_B*m_B; //square of the B meson mass
    double E_B = m_B2 + 90000;
    
    // Flat metric, (- - - +) signature: m^2 = E^2 - p^2
    p4_B.SetPxPyPzE(300, 0, 0, E_B);
    
    // Boost parameters of the B frame in the LAB frame can be accessed
    // with the BoostVector method
    cout << "--> boost vector of the B meson" << endl;
    p4_B.BoostVector().Print();
    
    //Creating the histograms we will need afterwards:
    
    //histograms interval
    double x1 = 50, x2 = 800;
    
    // Create new histograms to look at masses distributions
    int nbins = 75;
    double binwidth = (x2-x1) / nbins;
    TH1F m_p("m_p", "distribution of pion mass", nbins, x1, x2);
    TH1F m_b("m_b", "distribution of kaon mass", nbins, x1, x2);

    std::cout << "# bins: " << nbins << "\t bin width: " << binwidth << std::endl;
    
    // ==== Read data from file
    // In order to access the data in a tree one needs
    // 1) name of the ROOT file where the tree is stored ("./data.root")
    // 2) name of the tree object ("datatree")
    // 3) name of the branches ("value", "error" and "neams")
    TString rootfname("./Lab_2.root"); // [1]
    TFile* infile = new TFile(rootfname);
    if( !infile->IsOpen() ) {
      std::cout << "problems opening root file. existing... " << std::endl;
      exit(-1);
    }
    std::cout << "Reading data from root file " << rootfname << std::endl;

    // Get pointer to tree object stored in the file
    TTree* tree = (TTree*) infile->Get("datatree"); // [2]
    if(!tree) {
      std::cout << "null pointer for TTree! exiting..." << std::endl;
      exit(-1);
    }
    
    // Pointer to a TLorentzVector objects to be read from Branches
    TLorentzVector* p;
    TLorentzVector* k;
    
    // Set the info for each branch of the tree to correspond to data
    // Note: setting the address of a pointer to a Datum object in the branch
    tree->SetBranchAddress("pione", &p);
    tree->SetBranchAddress("Kaone", &k);
    
    // Print tree information
    tree->Print();
    
    /*
     Secondo me non ci servono
    // Vector of TLorentzVector for data being read
    std::vector<TLorentzVector> pione;
    std::vector<TLorentzVector> kaone;
    */
    
    // Loop over all the entries in the tree
    long nentries = tree->GetEntries();
    for (int i=0; i<nentries; i++) {
      // Access (i.e., read from file) Datum object which the leaf of the tree
      tree->GetEntry(i);
      // Fill in histos with value and error data
      m_p.Fill(p->M());
      m_b.Fill(k->M());
    }
    
    
    // ==== Make plots

    // Useful plot setting: show over and underflow
    gStyle->SetOptStat(111111);

    // Histogram titles
    m_p.GetXaxis()->SetTitle("Pion mass");
    m_b.GetXaxis()->SetTitle("Kaon mass");

    // Create canvas
    TCanvas canv("canv", "canvas for plotting", 1280, 1024);

    // One pdf with two panels
    canv.Divide(1,2);
    canv.cd(1);
    m_p.SetFillColor(kRed);
    m_p.Draw();
    canv.cd(2);
    m_b.SetFillColor(kRed);
    m_b.Draw();
    canv.SaveAs("./mass.pdf");

    // Critical to close the file!
    infile->Close();
    delete infile;
    
    /*
    // Let's boost the pion to the LAB frame
    cout << "--> now boost the pion to LAB" << endl;
    p4_pi.Boost(p4_B.BoostVector());
    cout << "--> LAB p4 pi: " << endl;
    p4_pi.Print();
    */
    
     return 0;
 }

    
    
