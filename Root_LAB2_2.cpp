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
    
    /*
    // Let's boost the pion to the LAB frame
    cout << "--> now boost the pion to LAB" << endl;
    p4_pi.Boost(p4_B.BoostVector());
    cout << "--> LAB p4 pi: " << endl;
    p4_pi.Print();
    */
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
     return 0;
 }

    
    
