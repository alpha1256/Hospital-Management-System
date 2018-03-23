#ifndef FUNCTION7_H_INCLUDED
#define FUNCTION7_H_INCLUDED
//#include "function3.h"
//#include "function4.h"
#include "function1.h"
#include <string>
#include <vector>
using namespace std;
///Record class
class record {
int rid, rpid;
string notes;
public:
void setrid (int sid){rid=sid;};
void setrpid (int srpid) {rpid=srpid;};
void setnotes(string snote) {notes=snote;};

int getrpid (){return rpid;};
void printrecord();
};
void printRec(vector <record> record1);
#endif //
