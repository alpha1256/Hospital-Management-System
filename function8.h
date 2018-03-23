#ifndef FUNCTION8_H_INCLUDED
#define FUNCTION8_H_INCLUDED
class slot;
class patient;
class doctor;
class dtime;
using namespace std;
///lab class and function
class lab{
int id;
int pid;
int docid;
int sid;
string reason,lmed;
bool appointmentstatus= false;
public:
void setid (int i){id=i;};
void setpid(int i){pid=i;};
void setdoc(int i){docid=i;};
void setsid(int i){sid=i;};
void setreason(string i){reason=i;};
void setmed(string i){lmed=i;};
void setstatus(bool a){appointmentstatus=a;};
//get functions
int getid(){return id;};
int getpid(){return pid;};
int getdoc(){return docid;};
int getsid(){return sid;};
bool getstatus(){return appointmentstatus;};
void printLab();
};


///To add lab appointment
void addlab (int & numb,vector <lab> & lab1, vector <slot> &slot1, vector <patient> patient1, vector <doctor> doctor1,vector <dtime> dtime1);

///For deleting
void deletLab(int &numb, vector <lab> &lab1, vector <slot> &slot1);

///Printing lab
void printLab(vector <lab> lab1);
#endif //
