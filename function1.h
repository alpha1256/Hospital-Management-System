#ifndef FUNCTION1_H_INCLUDED
#define FUNCTION1_H_INCLUDED
class doctor;
//#include "function2.h"
#include "function3.h"
#include "function4.h"
#include "function5.h"
#include "function6.h"
using namespace std;

///Patient Class
class patient{
int id, doctor_id,diad,record_id,appointcount;
string name,email,blood_type, phone,Dianame,docname;
char gender;
public:
    //All set function
    void setid(int geid){id=geid;};                 //For id
    void setdid(int did){doctor_id=did;};           //For doctor id
    void setrid(int rid){record_id=rid;};           //for record id
    void setname(string fname){name=fname;};        //For name
    void setphone(string fphone){phone=fphone;};    //For phone
    void setgender(char g){gender=g;};              //For gender
    void setemail(string eml){email=eml;};          //For email
    void setblood(string b){blood_type=b;};         //For Blood type
    void setDiad (int d){diad=d;};                  //For diagnoses id
    void setDianame(string n){Dianame=n;};          //For diagnoses name
    void setDocname(string b){docname=b;};          //For doctor name
    void setAppointcount (int a){appointcount=a;};  //For getting how many appointment a patient has

    //All get functions
    string getname(){return name;};                 //To return name
    string getemail(){return email;};               //To Return email
    char getgender(){return gender;};               //To return gender
    int getDiad(){return diad;};                      //To return diagnosis id
    int getdocid(){return doctor_id;};
    int getid(){return id;};
    int getrid(){return record_id;};
    int returnDiad(){return diad;};
    int getAppCount(){return appointcount;};
   // vector <doctor> bigDoctor;
    void print();
    patient();
};



///This get the input of the user
void getinstruct(int & getstruc);

///This get the patient
void getPatients(fstream & infile, int & numb,vector <patient> & patient1);

///This get the patients doctors
//void getPatDoc(int innumb,int numb,vector <patient> & patient1, int docnumb,vector <doctor> doctor1 );

///This prints the patient
void printpatient(int numb,int innumb ,vector <patient> & patient1, int docnumb, vector <doctor> & doctor1);

///This adds a new patient
void newpatient(int & innumb,int numb, vector <patient> & patient1, vector <diagnoses>  diagnoses1,vector <doctor>  doctor1 );

///This searches for patient by name or email
void searchPatient(int innumb,int numb,vector <patient> & patient1);

///This updates the patient info
void updatePat(int innumb,int numb, vector <patient> & patient1);

///This deletes the patient
void deletepatient(int innumb,int & numb,vector <patient> & patient1);

///Search for patient by doctors name
void searchpatDoc(vector <patient> & patient1, vector <doctor> & doctor1);

///For assigning diagnoses for each patient
void assDiag(vector <diagnoses>  diagnoses1, vector <patient> & patient1);

//This is in main
///For searching and showing patient appointment by time range
//void searchPatApp(vector <patient> patient1,vector <slot> slot1,vector <dtime> dtime1,vector <appointment> appointment1);

#endif //
