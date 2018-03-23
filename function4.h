#ifndef FUNCTION4_H_INCLUDED
#define FUNCTION4_H_INCLUDED
class slot;
class doctor;
class patient;
//#include "function1.h"
//#include "function5.h"

using namespace std;

///Appointment class
class appointment{
int aid, adid, apid,asid, adiaid;
string reason, pmed;
public:
//Set functions
void setaid (int said){aid=said;};
void setadid (int sadid) {adid=sadid;};
void setapid (int sapid) {apid=sapid;};
void setasid (int sasid) {asid=sasid;};
void setreason (string sreason) {reason=sreason;};
void setadiaid (int sadiaid) {adiaid=sadiaid;};         //To set diagnosis id
void setpmed (string spmed) {pmed=spmed;};

int getasid(){return asid;};
int getapid (){return apid;};
int getadid(){return adid;};
int getadiad(){return adid;};
void printappoint();
};

//this is in main
///Scheduling an appointment
//void addAppoint (int& aid,int & upnumb, vector <appointment> & appointment1, vector <doctor> & doctor1, vector <patient> & patient1,vector <slot> & slot1);

///Output appoint
void outAppoint(vector <appointment> appointment1);

///To update the appointment
void UpdateAppt(vector <appointment> & appointment1, vector <slot> &slot1);

///Show all appointments for a doctor by doctor’s name
void showDocApp(vector <appointment> appointment1, vector <doctor> doctor1);

///Show all appointments for a patient by patient’s name and email
//void showPatApp(vector <appointment> appointment1, vector <patient> patient1);

//this is in main
///To delete an appointment
//void delApp (vector <appointment> & appointment1, vector <slot> &slot1, vector <doctor> & doctor1, vector <patient> & patient1);
#endif //
