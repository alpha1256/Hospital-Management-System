#ifndef FUNCTION2_H_INCLUDED
#define FUNCTION2_H_INCLUDED
#include "function1.h"
using namespace std;

///Doctor class
class doctor {
int docid,appointcount;
string username, password, name, docname,skill,dphone ;
public:
doctor();
//set functions
void setdocid (int doid){docid=doid;};
void setusename (string usename) {username=usename;};
void setpassword (string pasword) {password=pasword;};
void setname (string fname) {name=fname;};
void setdphone (string ddphone) {dphone=ddphone;};
void setskill (string dskill) {skill=dskill;};
void setAppCount (int a1){appointcount=a1;};
//Get functions
int getdocidt(){return docid;};
string getusename(){return username;};
string getpassword(){return password;};
string getname(){return name;};
string getdphone(){return dphone;};
string getskill(){return skill;};
int getappcount (){return appointcount;};
void printdoc();
};

///This get the doctors
void getDoctors(fstream & infile2, int & docnumb,vector <doctor> & doctor1);

///This print the doctors
void printdoc(vector <doctor>  doctor1);

///Updating the doctor information
void updateDoc(vector <doctor> & doctor1);

///This is to be able to search doctor by name
void searchDoc(vector <doctor> & doctor1);

///This is for deleting doctors
void DeleDoc(vector <doctor> & doctor1);
#endif //
