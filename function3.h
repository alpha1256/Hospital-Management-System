#ifndef FUNCTION3_H_INCLUDED
#define FUNCTION3_H_INCLUDED

#include <fstream>
using namespace std;
///Diagnoses class
class diagnoses {
int did;
string dianame;
public:
//set functions
void setdid (int sdid){did=sdid;};
void setdianame (fstream & inFile) {getline(inFile,dianame);};

//get functions
int getdid (){return did;};
string getdianame(){return dianame;};

void printdiagnoses();
};

///Reading all the diagnosis into a file
void getDiag(int & dianumb, vector <diagnoses> & diagnoses1);

///To print diagnosis
void printDiag(vector <diagnoses> diagnoses1);
#endif //
