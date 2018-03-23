#include <iostream>
#include <fstream>
#include <vector>

#include "function5.h"
//#include "function2.h"
//#include "function6.h"
using namespace std;
///Slot file

///Default print function for slot
void slot::printslot(){
cout << "\nSlot Id: " <<sid << "\nDate Id: " << dateid << "\nDoctor ID: " << doctid << "\nStatus: " << status <<endl;
}

///This reads in slots from file
void getSlot(vector <slot> &slot1,int numb)
{
    fstream infile;
    infile.open("Slots.txt");
    int gar;
    infile >>gar ;
    for (int i=0; i < numb; i++)
    {
        int sid,dateid,doctid;
        string status;
        infile >> sid >> dateid >> doctid >> status;
        slot1.push_back(slot());
        slot1[i].setsid(sid);
        slot1[i].setdateid(dateid);
        if ( sid >=31 )
        {
            doctid=0;
            slot1[i].setdocid(doctid);
        }
        else
            slot1[i].setdocid(doctid);


        if (status =="available")
        {
            int a=1;
            slot1[i].setstatus(a);
        }
        else if (status == "unavailable")
        {
            int a=0;
            slot1[i].setstatus(a);
        }

    }

}

///Show available slots
void availSlot (vector <slot> slot1)
{
    int status =1;
    vector<slot>::iterator indexb;
    for (indexb =slot1.begin(); indexb != slot1.end(); indexb++)
    {
        if (status==indexb-> getstatus())
            indexb->printslot();
    }
}

///Show unavailable slots
void unavailSlot (vector <slot> slot1)
{
    int status =0;
    vector<slot>::iterator indexb;
    for (indexb =slot1.begin(); indexb != slot1.end(); indexb++)
    {
        if (status==indexb-> getstatus())
            indexb->printslot();
    }
}

///This prints out the slots to screen
void PrintSlot(vector <slot> slot1)
{
    vector<slot>::iterator indexb;
    for (indexb =slot1.begin(); indexb != slot1.end(); indexb++)
    {
       indexb->printslot();
    }
}

///This searches for an available slot doctor’s name.
void searchSlotDoc (vector <slot> slot1,vector <doctor> doctor1)
{
    int id;
    bool a;
    check1:
    cout << "Enter available slot id" <<endl;
    cin >> id;
    vector<slot>::iterator indexb;
    for (indexb =slot1.begin(); indexb != slot1.end(); indexb++)
    {
        if (id==indexb->getid() && indexb->getstatus()==1)
        {
            vector<doctor>::iterator indexa;
            for (indexa =doctor1.begin(); indexa != doctor1.end(); indexa++)
            {
                if(indexb->getdocid()==indexa->getdocidt())
                {
                    cout << "\nDoctor Name for this slot: " <<indexa->getname() <<endl;
                    break;
                }

            }
            a=1;
            break;
        }

    }
    if (a==0)
    goto check1;
}

///This modifies slot
void modSlot (vector <slot> & slot1, vector <doctor> doctor1, vector <dtime> dtime1)
{
    int sid,dateid,doctid;
    bool check;
    check3:
    cout << "Enter the slot id for the slot that you want to modify: ";
    cin >> sid;
    vector<slot>::iterator indexb;
    for (indexb =slot1.begin(); indexb != slot1.end(); indexb++)
    {
        if (sid == indexb -> getid())
        {
            //cout << "Enter new slot id: ";
            //cin >> sid;
            //indexb -> setsid(sid);

            check1:
            cout << "\nEnter new date id: ";
            cin >> dateid;
            if (dateid <=0 || dateid >10 )
                goto check1;
            else
                indexb->setdateid(dateid);

            check2:
            cout << "\nEnter new doctor id: ";
            cin >> doctid;
            bool one;
            vector<doctor>::iterator indexa;
            for (indexa =doctor1.begin(); indexa != doctor1.end(); indexa++)
            {
                if (doctid==indexa->getdocidt())
                {
                    indexb->setdocid(doctid);
                    one=1;
                }
            }
            if (one==0)
                goto check2;
            check =1;
        }
    }
    if (check==0)
        goto check3;
}

///To show available slots within date and time range.
void ShowSlotTimeRange(vector <slot> slot1, vector <dtime> dtime1)
{
    int day, month , year, hours, minutes;
    bool check1;

    check:
    cout << "Enter Day";
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
                    if (indexa->getdid()==indexb->getdateid() && indexb->getstatus()==1)
                    {
                        indexb->printslot();
                        check1=1;
                    }
                }
            }
        }
    }
    if (check1==0)
    goto check;
}

///To remove a slot
void removeSlt(vector <slot> & slot1)
{
    int id;
    int a= slot1.size();
    bool one;
    check:
    cout << "Enter id for the slot you want to delete";
    cin >> id;
    for (int i=0; i < a; i++)
    {
        if (id==slot1[i].getid() && slot1[i].getstatus()==1)
        {
            slot1.erase(slot1.begin()+i);
            one=1;
            cout << "This slot has been successfully deleted" <<endl;
        }
    }
    if (one==0)
    {
        cout << "\nEnter valid and make sure the status of the id is available" <<endl;
        goto check;
    }
}
