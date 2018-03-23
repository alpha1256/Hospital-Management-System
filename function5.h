#ifndef FUNCTION5_H_INCLUDED
#define FUNCTION5_H_INCLUDED
class doctor;
class dtime;
#include "function2.h"
//#include "function6.h"
using namespace std;
///slot class
class slot {
int sid,dateid,doctid;
int status;
public:
//set
void setsid (int ssid){sid=ssid;};
void setdateid (int ddateid) {dateid=ddateid;};
void setdocid (int docid) {doctid= docid;};
void setstatus (int sstatus) {status=sstatus;};

int getid(){return sid;};
int getdateid (){return dateid;};
int getdocid(){return doctid;};
int getstatus(){return status;};
void printslot();
};
///This reads in slots from file
void getSlot(vector <slot> &slot1,int numb);

///This prints out the slots
void PrintSlot(vector <slot> slot1);

///Show available slots
void availSlot (vector <slot> slot1);

///Show unavailable slots
void unavailSlot (vector <slot> slot1);

///This searches for an available slot doctor’s name.
void searchSlotDoc (vector <slot> slot1,vector <doctor> doctor1);

///This modifies slot
void modSlot (vector <slot> & slot1, vector <doctor> doctor1, vector <dtime> dtime1);

///To show available slots within date and time range.
void ShowSlotTimeRange(vector <slot> slot1, vector <dtime> dtime1);

///To remove a slot
void removeSlt(vector <slot> & slot1);
#endif //
