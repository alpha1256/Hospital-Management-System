#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "function3.h"

using namespace std;

/* File for diagnosis */
///To print diagnosis
void diagnoses::printdiagnoses()
{
    cout << "\nID :" <<did <<"\nDiagnosis :" <<dianame <<endl;
    cout << "-----------------------------------------" <<endl;
}

///Reading all the diagnosis into a file
void getDiag(int & dianumb, vector <diagnoses> & diagnoses1)
{
    fstream infile;
    infile.open("Diagnosis.txt");
    infile >> dianumb;
    for (int i=0; i < dianumb; i++)
    {
    int did;
    string dianame;
        diagnoses1.push_back(diagnoses());
        getline(infile,dianame);
        diagnoses1[i].setdianame(infile);
        did = (rand()%1000+1000);
        diagnoses1[i].setdid(did);
    }
}

///To print diagnosis
void printDiag(vector <diagnoses> diagnoses1)
{
        vector<diagnoses>::iterator indexb;
    for (indexb =diagnoses1.begin(); indexb != diagnoses1.end(); indexb++)
    {
        indexb->printdiagnoses();
    }
}
