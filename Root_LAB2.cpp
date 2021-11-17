//
//  main.cpp
//  LAB_2
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
    
    // Open TFile for output
    TString rootfname("./lab2.root");
    // Overwite output file if it already exists
    TFile rfile(rootfname, "RECREATE");
    // Open the ROOT file and make sure the file was opened successfully.
    // Typical cause for failure are: 1) wrong path, 2) no write privilege in the directory that is used
      
    if( !rfile.IsOpen() ) {   //So there is a method in TFile that states if the file is open or closed (NOTE THAT: in the statement there is the "!", so I'm                            negating the result of the statement
      std::cout << "problems creating root file. existing... " << std::endl;
      exit(-1);
    }
    std::cout << "storing output in root file " << rootfname << std::endl; //This is what is couted if instead the file is actually open

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
    
    //cout<<"( "<<x<<" , "<<y<<" , "<<z<<" )"<<endl;
    
    
    //generare i vettori 3d con TRandom::Sphere
    
    //Trovare il modo di mettere i vettori 3d dentro i 4vettori del pione e del K

    //Fare cose con TLorentzVector
    
    delete gen;
    
    

    
    
    
    
    return 0;
}
