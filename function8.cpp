#include <iostream>
#include <cstdlib>
#include <vector>
#include "function8.h"
#include "function1.h"


using namespace std;
void lab::printLab()
{
    cout << "Id: " <<id  << "\nPatient Id: " << pid << "\nDoctor Id: "  << docid << "\nSlot ID:" << sid <<"\nReason: " <<reason <<"\nMedication: " <<lmed <<endl;
    cout << "---------------------------------------------" <<endl;
}

///To add lab appointment
void addlab (int & numb,vector <lab> & lab1, vector <slot> &slot1, vector <patient> patient1, vector <doctor> doctor1,vector <dtime> dtime1)
{
    //Entering patient id
    int pid;
    bool one;
check1:
    cout << "Enter the patient id that you want to schedule a lab for: ";
    cin >> pid;
    vector<patient>::iterator indexa;
    for (indexa=patient1.begin(); indexa != patient1.end(); indexa++)
    {
        if (pid== indexa -> getid())
        {

            one=1;
        }
    }
    if (one ==0)
        goto check1;


    //slot id and checking date time
    int sid;
    bool two;
check2:
    cout << "Enter the slot id : ";
    cin >> sid;
    //int tempa=sid;
    if (sid <= 30 || sid >= 41 )
    {
        cout << "Number should be greater than 30 and less than 41" <<endl;
        goto check2;
    }
    vector<lab>::iterator indexl;
    for (indexl=lab1.begin(); indexl != lab1.end(); indexl++)
    {
        if (sid==indexl->getsid() )
            goto check2;
    }

    vector<slot>::iterator indexb;
    for (indexb=slot1.begin(); indexb != slot1.end(); indexb++)
    {
        if (sid == indexb->getid() && indexb-> getstatus()!=0)
        {
            int temp=indexb->getdateid();
            int temp2;//temp day
            int temp3;//temp month
            vector<dtime>::iterator indexc;
            vector<dtime>::iterator indexwc;

            for (indexc=dtime1.begin(); indexc != dtime1.end(); indexc++)
            {
                if (temp == indexc->getdid())
                {
                    temp2= indexc->getday();
                    temp3= indexc->getmonth();
                   // cerr <<"This the date that is in the slot you entered"  << temp2 << " " << temp3 << " " << temp <<endl;
                }
            }

            vector<lab>::iterator indexd;
            for (indexd=lab1.begin(); indexd != lab1.end(); indexd++)
            {
                if ( indexd-> getstatus()==true)
                {
                    //sid !=indexd->getsid() &&
                    vector<slot>::iterator indexa;
                    for (indexa=slot1.begin(); indexa != slot1.end(); indexa++)
                    {
                        if (indexd->getsid()==indexa->getid())
                        {
                            temp=indexa->getdateid();
                            for (indexwc=dtime1.begin(); indexwc != dtime1.end(); indexwc++)
                            {
                                if (temp ==indexwc->getdid())
                                {
                                    int temp4=indexwc->getday();
                                    int temp5=indexwc->getmonth();
                                    //cerr << "This is checks the date that is in the lab vector"  <<temp4  <<" " << temp5 <<"" <<temp <<endl;
                                    if (temp2==temp4 && temp3==temp5)
                                    {
                                        cout << "This slot has a lab on the same day as another lab" <<endl;
                                        goto check2;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << sid <<endl;
            int k=0;
            indexb->setstatus(k);
            two=1;
        }

    }
    if (two==0)
        goto check2;

    string reason;
    cout << "Enter the reason: ";
    cin >> reason;

    string med;
    cout << "\nEnter the medication: ";
    cin >> med;

    int  docid;
    bool three;
check3:
    cout << "Enter a doctor id: ";
    cin >> docid;
    //int static tempa=docid;
    vector<doctor>::iterator indexe;
    for (indexe=doctor1.begin(); indexe != doctor1.end(); indexe++ )
    {
        if (docid==indexe->getdocidt())
        {
            three=1;
            break;
        }
    }
    if (three==0)
        goto check3;

    bool ab=true;
    lab1.push_back(lab());
    lab1[numb].setpid(pid);
    lab1[numb].setdoc(docid);
    //assigning id;
    int a = rand()% 20 + 1;
    lab1[numb].setid(a);
    lab1[numb].setsid(sid);
    lab1[numb].setreason(reason);
    lab1[numb].setmed(med);
    lab1[numb].setstatus(ab);
    numb++;
}

///For deleting
void deletLab(int & numb,vector <lab> &lab1, vector <slot> &slot1)
{
    int id;
    int bsize = lab1.size();
    bool check1;
check:
    cout << "Enter the id of the lab you want to delete: ";
    cin >> id;
    for (int i=0; i < bsize; i++)
    {
        vector<slot>::iterator indexc;
        for (indexc=slot1.begin(); indexc != slot1.end(); indexc++)
        {
            if ( id==lab1[i].getid()&&lab1[i].getsid()==indexc->getid())
            {
                int a=1;
                indexc->setstatus(a);
                lab1.erase(lab1.begin()+i);
                cout << "This lab appointment has been deleted" <<endl;
                check1=1;
                numb = numb-1;
                break;
            }
        }

    }
    if (check1==0)
        goto check;
}

///Printing lab
void printLab(vector <lab> lab1)
{
    vector<lab>::iterator indexd;
    for (indexd=lab1.begin(); indexd != lab1.end(); indexd++)
    {
        indexd -> printLab();
    }
}
