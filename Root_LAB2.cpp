//
//  LAB_2
//
//  Generation of the 10 000 events
//
//  Created by Lorenzo Piccari on 12/11/21.
//

#include <iostream>
#include "TLorentzVector.h"
#include "TRandom.h"
#include "TMath.h"
#include "TFile.h"
#include "TTree.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
//---------------------------------------------------------------------------------------------------------------------------------------------------
    
    // ==== Store data in a TTree
    // Open a root file
    TString rootfname("./Lab_2.root");
    TFile* orootfile = new TFile( rootfname, "RECREATE");
    if( !orootfile->IsOpen() ) {
      std::cout << "problems creating root file. existing... " << std::endl;
      exit(-1);
    }
    std::cout << "storing output in root file " << rootfname << std::endl;


//-----------------------------------------------------------------------------------------------------------------------------------------------------
    
    /*
    //creating the 4 momentum of the B meson in the center of mass of the meson frame
    TLorentzVector p4_B;
    double M_B = 5279; //MeV
    // Flat metric, (- - - +) signature: m^2 = E^2 - p^2
    p4_B.SetPxPyPzE(0, 0, 0, M_B);
     */
    
    //Defining the variables that I need to do the simulation:
    
    int nmeas = 10;  //# of measurements
    
    //masses of the particles involved
    double m_B = 5279; //MeV
    double m_p = 140; //MeV
    double m_k = 500; //MeV
    
    //Definition of the momentum of decay products
    double m_B2 = m_B*m_B;
    double m_p2 = m_p*m_p;
    double m_k2 = m_k*m_k;
    
    double num = sqrt(m_B2*m_B2 + m_p2*m_p2 + m_k2*m_k2 -2*m_B2*m_p2 - 2*m_B2*m_k2 - 2*m_k2*m_p2);
    double p = num/2*m_B;
    
    //Energies of the particles involved
    double E_p = m_p2 + p*p;
    double E_k = m_k2 + p*p;
    
    
    // Create a new TTree object with branch suited for TLorentzVector objects
    TTree* tree = new TTree("datatree", "tree containing our data");
    
    //creating the variable to store in the tree
    TLorentzVector p4_p;
    TLorentzVector p4_k;
    
    // Set the info for each branch (one) of the tree to correspond to data
    tree->Branch("pione", &p4_p);
    tree->Branch("Kaone", &p4_k);

    // Start up a new random generator... (we have a new: we will need a delete!)
    TRandom* gen = new TRandom();
    // ...exploiting the machine clock for the seed
    gen->SetSeed(0);
    
    double px,py,pz; //definition of the 3 components of the random vector for the pion
    double kx,ky,kz; //definition of the 3 components of the random vector for the kaon
    
    for(int i = 0; i < nmeas; i++) {
        
        //generating the random vector for p
        gen->Sphere(px,py,pz,p);
        
        //generating the random vector for K
        gen->Sphere(kx,ky,kz,p);
        
        p4_p.SetPxPyPzE(px,py,pz,E_p);
        p4_k.SetPxPyPzE(kx,ky,kz,E_k);
        
        //Add leaves to the 2 branches
        tree->Fill();
        
    }
    
    // Finally, actually store tree in file on disk
    tree->Write();

    // Print some info about the tree
    tree->Print();
    
    //cout<<"( "<<x<<" , "<<y<<" , "<<z<<" )"<<endl;
    
    // Critical to close the file!
    orootfile->Close();
 
    // ==== Done storing data in a TTree

    delete gen;
    delete orootfile;
   
    return 0;
}
