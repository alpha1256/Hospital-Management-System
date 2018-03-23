#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "function1.h"


using namespace std;

/*This contains functions related to patients
*/

///Patient constructor
patient::patient(){
id =0;
doctor_id=0;
record_id=0;
appointcount=0;
phone="";
name="";
email="";
gender='*';
blood_type='*';
}

///This get the instruction
void getinstruct(int & getstruc){
cout << "Enter the menu action you want:";
cin >> getstruc;

}

///Prints out the patient
void patient::print(){
cout << "ID: " << id <<"\nDoctor ID: " << doctor_id << "\nRecord ID: " << record_id
<< "\nName: " << name << "\nPhone Number: "  << phone << "\nGender: " << gender
<<"\nEmail: " << email << "\nBlood Type: " <<blood_type <<"\nDoctor Name: " <<docname <<"\nThis patient has: " << appointcount << " appointments"<<endl;
cout << "\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4"<<endl;
}

///This get the patient
void getPatients(fstream & infile, int & numb,vector <patient> & patient1){
infile.open("Patients.txt");
infile >> numb;
//numb=numb1 + innumb;


int id, doctor_id, record_id;
string name,email,blood_type, phone;
char gender='*';

for (int i=0; i < numb; i++){
    infile >> id >> doctor_id >> record_id >> name >> phone;
    infile>> gender;
    infile>>email;
    infile>> blood_type;

    patient1.push_back(patient());
    patient1[i].setid(id);
    patient1[i].setdid(doctor_id);
    patient1[i].setrid(record_id);
    patient1[i].setname(name);
    patient1[i].setphone(phone);
    patient1[i].setgender(gender);
   //cout << patient1[i].genderrt();
    patient1[i].setemail(email);
    patient1[i].setblood(blood_type);

    id=0, record_id=0, doctor_id=0,phone="";
    name="", email="";
    gender='*', blood_type='*';
    }
}

///This is the function for adding new patient
void newpatient(int & innumb,int numb, vector <patient> & patient1,vector <diagnoses>  diagnoses1,vector <doctor>  doctor1 ){
cout << "\nAdding new patient:";

int id, doctor_id, record_id;
string name,email,blood_type, phone;
char gender='*';

   patient1.push_back(patient());
    check3:
   // bool onecheck;
    int did;
    string dianame;
    cout << "\nEnter ID:";
    cin >> id;
    vector<patient>::iterator indexl;
    for (indexl =patient1.begin(); indexl != patient1.end(); indexl++)
    {
        if (id == indexl->getid())
        {
            goto check3;
        }

    }
    patient1[numb+innumb].setid(id);

    make1:
    cout << "\nEnter doctor id:";
    cin >> doctor_id;

    bool check;
    vector<doctor>::iterator indexb;
    for (indexb =doctor1.begin(); indexb != doctor1.end(); indexb++)
    {
        if (doctor_id==indexb->getdocidt())
        {
            patient1[numb+innumb].setdid(doctor_id);
            check =1;
            break;
        }

    }
    if (check ==0)
        goto make1;


    check5:
    cout << "\nEnter record id:";
    cin >> record_id;
    for (indexl =patient1.begin(); indexl != patient1.end(); indexl++)
    {
        if (record_id==indexl->getrid())
            goto check5;
    }
    patient1[numb+innumb].setrid(record_id);

    cout << "\nEnter name:";
    cin >> name;
    patient1[numb+innumb].setname(name);

    cout << "\nEnter phone:";
    cin >> phone;
    patient1[numb+innumb].setphone(phone);

    cout << "\nEnter gender:";
    cin >> gender;
    patient1[numb+innumb].setgender(gender);

    cout << "\nEnter email:";
    cin >> email;
    patient1[numb+innumb].setemail(email);

    cout << "\nEnter blood type:";
    cin >> blood_type;
    patient1[numb+innumb].setblood(blood_type);

}


///To update patient patient info
void updatePat(int innumb,int numb, vector <patient> & patient1){
int upnumb=innumb + numb;
string upname;
int counter;
int id, doctor_id, record_id;
string name,email,blood_type, phone;
char gender;

cout << "Enter patient name you want to update";
cin >> upname;
cout << "Enter the number \n1 Update ID\n2 Update Doctor ID\n3 Update record id\n4 Update name\n5 Update phone\n6 Update gender\n7 Update Email\n8 Update blood type" <<endl;
cin >> counter;
for (int i=0; i < upnumb; i++)
{
    if (upname==patient1[i].getname()){
        if (counter==1)//For updating new id
        {
            cout << "Enter new id:";
            cin >> id;
            patient1[i].setid(id);
        }
        else if (counter==2)//For updating new doctor id
        {
            cout << "\nEnter new doctor Id:";
            cin >> doctor_id;
            patient1[i].setdid(doctor_id);
        }
        else if (counter==3)//For updating new  record id
        {
            cout << "\nEnter new record Id:";
            cin >> record_id;
            patient1[i].setrid(record_id);
        }
        else if (counter==4)//For updating new name
        {
            cout << "\nEnter new name:";
            cin >> name;
            patient1[i].setname(name);
        }
        else if (counter==5)//For updating new phone
        {
            cout << "\nEnter new Phone:";
            cin >> phone;
            patient1[i].setphone(phone);
        }
        else if (counter==6)//For updating new gender
        {
            cout << "\nEnter new gender:";
            cin >> gender;
            patient1[i].setgender(gender);
        }
        else if (counter==7)//For updating new email
        {
            cout << "\nEnter new email:";
            cin >> email;
            patient1[i].setemail(email);
        }
        else if (counter==8)//For updating new bloodtype
        {
            cout << "\nEnter new blood type:";
            cin >> blood_type;
            patient1[i].setblood(blood_type);
        }
    }
}
}

///This searches for patient by name or email
void searchPatient(int innumb,int numb,vector <patient> & patient1 ){
int upnumb = innumb + numb;
string searchone;
int numbsearch;
cout << "Search for patient:\n1 Name \n2 Email" <<endl;
cin >> numbsearch;
cout << "Enter name or email you want to search" << endl;
cin >> searchone;
//Option to search by name
if (numbsearch==1){
    for (int i=0; i < upnumb; i++){

        if (searchone ==patient1[i].getname()){
            patient1[i].print();
            break;
        }
        //else
           // cout << "No patient by this name" <<endl;

    }
}
//Option to search by email
if (numbsearch==2){
    for (int i=0; i < upnumb; i++)
    {
        if (searchone==patient1[i].getemail()){
            patient1[i].print();
            break;
        }
       // else
           // cout << "No patient by this email" <<endl;
    }
}
}

///This deletes the patient
void deletepatient(int innumb,int & numb,vector <patient> & patient1)
{
    string dele;
    int upnumb= innumb + numb;
    cout << "Enter patient name you want to delete:";
    cin >> dele;
    for (int i=0; i < patient1.size(); i++)
    {
        if (dele==patient1[i].getname())
        {
            patient1.erase(patient1.begin()+i);
            cout << "Patient has been deleted"<<endl;

            break;
        }
    }
numb-=numb-1;
}

///This prints out the patient
void printpatient(int numb,int innumb,vector <patient> & patient1, int docnumb, vector <doctor> & doctor1){
//int numb1=numb + innumb;
vector<patient>::iterator indexa;
for (indexa=patient1.begin(); indexa != patient1.end(); indexa++){

        vector<doctor>::iterator indexb;
        for (indexb =doctor1.begin(); indexb != doctor1.end(); indexb++)
        {
            if (indexa->getdocid() == indexb->getdocidt())
            {
             string docname= indexb->getname();
             indexa->setDocname(docname);
             break;
            }
        }
indexa->print();
}

}

///Search for patient by doctors name
void searchpatDoc(vector <patient> & patient1, vector <doctor> & doctor1)
{
        string searchdoc;
        cout << "Enter doctors name you want to search:";
        cin >> searchdoc;
        vector<doctor>::iterator indexb;
        for (indexb =doctor1.begin(); indexb != doctor1.end(); indexb++)
        {
            if (searchdoc==indexb->getname())
            {
                indexb->printdoc();
                vector<patient>::iterator indexa;
                for (indexa=patient1.begin(); indexa != patient1.end(); indexa++){
                    if (indexa->getdocid() == indexb->getdocidt())
                            indexa->print();
                }
            }
        }
}



///For searching and showing patient appointment by time range
 void searchPatApp(vector <patient> patient1,vector <slot> slot1,vector <dtime> dtime1,vector <appointment> appointment1)
{
    int day, month , year, hours, minutes;
    bool check1;

    check:
    cout << "Enter Day: ";
    cin >> day;
    cout << "\nEnter month: ";
    cin >> month;
    cout << "\nEnter year: ";
    cin >> year;
    cout << "\nEnter hours: ";
    cin >> hours;
    cout << "\nEnter minutes: ";
    cin >> minutes;

    vector<dtime>::iterator indexa;
    for (indexa=dtime1.begin(); indexa != dtime1.end(); indexa++)
    {
        if (day==indexa->getday() && month == indexa->getmonth() && year==indexa->getyear())
        {
            if (hours==indexa->gethour() && minutes== indexa->getmin())
            {
                vector<slot>::iterator indexb;
                for (indexb=slot1.begin(); indexb != slot1.end(); indexb++)
                {
                    if (indexa->getdid()==indexb->getdateid() && indexb->getstatus()==0)
                    {
                        vector<appointment>::iterator indexc;
                        for (indexc=appointment1.begin(); indexc != appointment1.end(); indexc++)
                        {
                            if (indexb->getid()==indexc->getasid())
                            {
                                vector<patient>::iterator indexd;
                                for (indexd=patient1.begin(); indexd != patient1.end(); indexd++)
                                {
                                    if (indexc->getapid()==indexd->getid())
                                    {
                                        cout <<"\n" <<indexd->getname() <<" has an appointment on the day:" <<endl;
                                        check1=1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (check1==0)
        goto check;
}

