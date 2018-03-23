#include <iostream>
#include <fstream>
#include <vector>
//#include "function5.h"
#include "function4.h"
//#include "function3.h"
//#include "function2.h"
#include "function1.h"

using namespace std;
///Appointment file

void appointment::printappoint()
{
    cout <<"\nAppointment ID: " << aid <<"\nDoctors ID: " << adid << "\nPatient ID: " <<apid << "\nSlot ID: " <<asid
    << "\n Reason for visit: "<<reason << "\nDiagnosis ID: "<<adiaid << "\nPrescription Med: "<<pmed <<endl;
    cout << "--------------------------------------------------------------------------" <<endl;
}

///Scheduling an appointment
void addAppoint (int& aid,int & upnumb, vector <appointment> & appointment1, vector <doctor> & doctor1, vector <patient> & patient1,vector <slot> & slot1)
{
    int adid, apid,asid, adiaid;
    string reason, pmed;
    //int idcount;
    cout << "Add appointment: " <<endl;

    //vector<appointment>::iterator index1=appointment1.end();
    //for (int i=0; i < idcount; i++)


        appointment1.push_back(appointment());
        appointment1[upnumb].setaid(aid);

        //Set the doctors id
        check1:
        cout << "\nEnter doctors id: ";
        cin >> adid;
        bool check;
            vector<doctor>::iterator indexb;
            for (indexb =doctor1.begin(); indexb != doctor1.end(); indexb++)
            {
                //this checks and add the appointment for each doctor
                if (adid==indexb->getdocidt())
                {
                    appointment1[upnumb].setadid(adid);
                    int al = 1;
                    int a2 = indexb -> getappcount();
                    int total= al + a2;
                    indexb -> setAppCount(total);
                    check =1;
                    break;
                }

            }
            if (check ==0)
            goto check1;

        //set the patient id
        check2:
        cout <<"\nEnter patient id: ";
        cin >> apid;
        bool check3;
        vector<patient>::iterator indexa;
            for (indexa=patient1.begin(); indexa != patient1.end(); indexa++){

                    if (apid==indexa->getid() && adid==indexa->getdocid() )
                    {
                            appointment1[upnumb].setapid(apid);
                            adiaid = indexa->getDiad();
                            appointment1[upnumb].setadiaid(adiaid);
                            int al = 1;
                            int a2 = indexa->getAppCount();
                            int total =al + a2;
                            indexa-> setAppointcount(total);
                            check3=1;
                            break;
                    }
            }
            if (check3==0)
                goto check2;

        check4:
        cout << "\nEnter Slot ID: " ;
        cin >> asid;
        bool check4;
        vector<slot>::iterator indexc;
        for (indexc=slot1.begin(); indexc != slot1.end(); indexc++)
        {
            if (asid == indexc ->getid() && adid == indexc ->getdocid() && indexc -> getstatus() !=0)
            {
              appointment1[upnumb].setasid(asid);
              check4=1;
              int a=0;
              indexc->setstatus(a);
              break;
            }

        }
        if (check4==0)
            goto check4;

        //This is for reason
        cout << "\nEnter reason for visit:";
        cin >> reason;
        appointment1[upnumb].setreason(reason);
        upnumb++;
        aid++;

}

///To update the appointment
void UpdateAppt(vector <appointment> & appointment1, vector <slot> &slot1)
{
    int temp1;
    int temp;
    string pmed;
    check:
    cout << "Enter the patient id for the appointment that you would like to update: " ;
    cin >> temp1;
    cout << "\nEnter the new slot id: ";
    cin >> temp;
    cout << "Enter prescription medication for the patient: ";
    cin >> pmed;
    bool check4;
    vector<appointment>::iterator indexa;
    for (indexa=appointment1.begin(); indexa != appointment1.end(); indexa++){
        if (temp1== indexa -> getapid())
        {
            vector<slot>::iterator indexc;
            for (indexc=slot1.begin(); indexc != slot1.end(); indexc++)
            {
                if (indexa->getasid()==indexc->getid())
                {
                    int a=1;
                    indexc->setstatus(a);
                }
            }
            for (indexc=slot1.begin(); indexc != slot1.end(); indexc++)
            {
                if (temp == indexc ->getid() && indexc -> getstatus() !=0)
                {
                    indexa->setasid(temp);
                    check4=1;
                    int b=0;
                    indexc->setstatus(b);
                    break;
                }

            }
        indexa-> setpmed(pmed);
        }

    }
    if (check4==0)
        goto check;
}


///To delete an appointment
void delApp (int & upnumb,vector <appointment> & appointment1, vector <slot> &slot1, vector <doctor> & doctor1, vector <patient> & patient1)
{
    int temp1;
    check:
    cout << "Enter the slot id for the appointment you want to delete: ";
    cin >> temp1;
    bool check4;
    int b= appointment1.size();
    for (int i=0; i < b; i++)
    {
        if (temp1==appointment1[i].getasid())
        {

            vector<slot>::iterator indexc;
            for (indexc=slot1.begin(); indexc != slot1.end(); indexc++)
            {
                if (appointment1[i].getasid()==indexc->getid())
                {
                    int a=1;
                    indexc->setstatus(a);
                }
            }
            vector<patient>::iterator indexd;
            for (indexd=patient1.begin(); indexd != patient1.end(); indexd++)
            {
                if (appointment1[i].getapid()==indexd->getid())
                {
                    int a2 = indexd->getAppCount();
                    int total =a2-1;
                    indexd-> setAppointcount(total);
                }
            }
            vector<doctor>::iterator indexb;
            for (indexb =doctor1.begin(); indexb != doctor1.end(); indexb++)
            {
                if (appointment1[i].getadiad()==indexb->getdocidt())
                {
                    int a2 = indexb -> getappcount();
                    int total= a2-1;
                    indexb -> setAppCount(total);
                }
            }
                appointment1.erase(appointment1.begin()+i);
                cout << "This appointment has been canceled" <<endl;
                check4=1;
                upnumb=upnumb-1;
        }
    }
    if (check4==0)
    goto check;
}

///Show all appointments for a doctor by doctor’s name
void showDocApp(vector <appointment> appointment1, vector <doctor> doctor1)
{
    int id;
    bool one;
    check:
    cout << "Enter the doctor id: ";
    cin >> id;
    vector<appointment>::iterator indexa;
    for (indexa=appointment1.begin(); indexa != appointment1.end(); indexa++)
    {
        if (id==indexa->getadid())
        {
            vector<doctor>::iterator indexb;
            for (indexb =doctor1.begin(); indexb != doctor1.end(); indexb++)
            {
                if (indexa->getadid()==indexb->getdocidt())
                {
                    cout << "Doctor Name: " << indexb -> getname();
                    indexa->printappoint();
                    one=1;
                }
            }
        }
    }
    if (one==0)
        goto check;
}

///Show all appointments for a patient by patient’s name and email
void showPatApp(vector <appointment> appointment1, vector <patient> patient1)
{
    int id;
    bool one;
    check:
    cout << "Enter the patient id: ";
    cin >> id;
    vector<appointment>::iterator indexa;
    for (indexa=appointment1.begin(); indexa != appointment1.end(); indexa++)
    {
        if (id==indexa->getapid())
        {
            vector<patient>::iterator indexb;
            for (indexb =patient1.begin(); indexb != patient1.end(); indexb++)
            {
                if (indexa->getapid()==indexb->getid())
                {
                    cout << "--------------------------------------" <<endl;
                    cout << "Patient Name: " << indexb -> getname();
                    cout << "\nEmail: " <<indexb->getemail();
                    indexa->printappoint();
                    one=1;
                }
            }
        }
    }
    if (one==0)
        goto check;
}

///Output appoint
void outAppoint(vector <appointment> appointment1)
{
        vector<appointment>::iterator indexa;
            for (indexa=appointment1.begin(); indexa != appointment1.end(); indexa++){
                indexa->printappoint();
            }
}

