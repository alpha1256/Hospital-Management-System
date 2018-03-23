#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "function1.h"
#include "function2.h"
#include "function3.h"
#include "function4.h"
#include "function5.h"
#include "function6.h"
#include "function7.h"
#include "function8.h"

using namespace std;
///Scheduling an appointment
void addAppoint (int& aid,int & upnumb, vector <appointment> & appointment1, vector <doctor> & doctor1, vector <patient> & patient1,vector <slot> & slot1);

///For searching and showing patient appointment by time range
void searchPatApp(vector <patient> patient1,vector <slot> slot1,vector <dtime> dtime1,vector <appointment> appointment1);

///To delete an appointment
void delApp (int & upnumb, vector <appointment> & appointment1, vector <slot> &slot1, vector <doctor> & doctor1, vector <patient> & patient1);

///Show all appointments for a patient by patient’s name and email
void showPatApp(vector <appointment> appointment1, vector <patient> patient1);

///For updating record and diagnoses for each patient
void assDiag(vector <diagnoses>  diagnoses1,int & numb, vector <appointment> appointment1, vector <record> &record1, vector <patient> patient1);

///Updating patient record
void updateRec(vector <record> & record1, vector <diagnoses> diagnoses1, vector <patient> patient1);

///To add lab appointment
//void addlab (int & numb,vector <lab> & lab1, vector <slot> &slot1, vector <patient> patient1, vector <doctor> doctor1,vector <dtime> dtime1);
int main()
{
    ///Variable declarations
    int struc; //This is for the first number for the first input
    int numb2=0;//This is number from patients text file
    int numb1=0;//This is input for the second input
    int newpat=0;//Number of patient to add
    int docnumb=0;//This is number from doctor text file
    int diagnumb=0;//This is number from diagnosis file
    int slotnumb=40;
    int rnumb=0;
    int aid=1;
    int apNumb=0; //This is the number of appointment
    int labnumb=0; //increment lab number
    int labid=1; //lab id
    fstream infile,infile2;

    ///Vectors
    vector <patient> patient1;//of patient
    vector <doctor> doctor1;
    vector <diagnoses> diagnoses1;
    vector <appointment> appointment1;
    vector <slot> slot1;
    vector <dtime> dtime1;
    vector <record> record1;
    vector <lab> lab1;

    ///All getting info from file
    getPatients(infile,numb2,patient1);
    getDoctors(infile2,docnumb,doctor1);
    getDiag(diagnumb,diagnoses1);
    getSlot(slot1,slotnumb);
    getDate(dtime1);

    //assDiag(diagnoses1,patient1);//this assigns each patient diagnosis and id
    regenerate:
    cout << "****************************************************"<<endl;
    cout << "Welcome to HMS. Please choose an action:" <<endl;
    cout << "1. Manage Appointments" << endl;
    cout << "2. Manage Slots" << endl;
    cout << "3. Manage Doctors" << endl;
    cout << "4. Manage Patients" << endl;
    cout << "5. Manage Patients' records" << endl;
    cout << "6. Manage labs" << endl;
    cout << "7. Print Diagnosis" <<endl;
    cout << "8. Exit" <<endl;
    cout << "****************************************************" <<endl;
   //getPatDoc(newpat,numb2,patient1,docnumb,doctor1);


    getinstruct(struc);///This get the input of the user



    ///For Managing Appointments option 1
    if (struc ==1)
    {
        option1:
        cout << "1. Schedule a new appointment\n2. Show all appointments\n3. Modify/Reschedule an existing appointment\n4. Remove an appointment\n5. Show all appointments for a doctor by doctor's name\n6. Show all appointments for a patient by patient's name, email \n7. Main menu " <<endl;
        cout << "\nEnter menu action you want: ";
        cin >> numb1;
        //For adding new appointment option 1
        if (numb1==1)
        {
            addAppoint(aid,apNumb,appointment1, doctor1,patient1,slot1);
            goto option1;
        }
        //For printing appointment option 2
        else if (numb1==2)
        {
            outAppoint(appointment1);
            goto option1;
        }
        //To update appointment option 3
        else if (numb1==3)
        {
            UpdateAppt(appointment1,slot1);
            goto option1;
        }
        //To delete an appointment
        else if (numb1==4)
        {
            delApp(apNumb,appointment1,slot1,doctor1,patient1);
            goto option1;
        }
        //To Show all appointments for a doctor by doctor’s name
        else if (numb1==5)
        {
            showDocApp(appointment1, doctor1);
            goto option1;
        }
        //To show all appointment for a patient by patient name and email
        else if (numb1==6)
        {
            showPatApp(appointment1,patient1);
            goto option1;
        }
        //To go back to main menu
        else if (numb1==7){
            goto regenerate;
        }
    }

    ///For managing slots option 2
    if (struc==2)
    {
        option2:
        cout << "\n1. Show available slots\n2. Show unavailable slots\n3. Show all slots\n4. Modify slot information\n5. Remove a slot\n6. Search for available slot doctor name\n7. Show all available slots within date and time range\n8. Go back to main menu " <<endl;
        cout << "\nEnter menu action you want: ";
        cin >> numb1;
        //Show available slot
        if (numb1==1)
        {
            availSlot(slot1);
            goto option2;
        }
        //show unavailable slot
        if (numb1==2)
        {
            unavailSlot(slot1);
            goto option2;
        }
        //For showing all slots
        if (numb1==3)
        {
            PrintSlot(slot1);
            goto option2;
        }
        //For modifying slot
        if (numb1==4)
        {
            //cout << "This feature is under maintenance thank you for your patience" <<endl;
            modSlot(slot1,doctor1,dtime1);
            goto option2;
        }
        //For deleting slot
        if (numb1==5)
        {
            removeSlt(slot1);
            goto option2;
        }
        //For searching available slot doctor name
        if (numb1==6)
        {
            searchSlotDoc(slot1,doctor1);
            goto option2;
        }
        //For searching and showing available slots within date and time range.
        if (numb1==7)
        {
            ShowSlotTimeRange(slot1,dtime1);
            goto option2;
        }
        //For returning to main menu
        if (numb1==8){
            goto regenerate;
        }
    }

    ///For Managing Doctors Option 3
    if (struc==3)
        {
            option3:
            cout << "\n1 Show all doctors\n2 Update doctors\n3 Delete doctors\n4 Search Doctor by name\n5 Go back to main menu" <<endl;
            cout << "\nEnter menu action you want: ";
            cin >> numb1;
            //For outputting doctors
            if (numb1==1){
                printdoc( doctor1);
                goto option3;
            }
            //For updating doc info
            if (numb1==2)
            {
                updateDoc(doctor1);
                goto option3;
            }
            //For deleting doctors
            if (numb1==3)
            {
                DeleDoc(doctor1);
                goto option3;
            }
            //For Searching doctors
            if (numb1==4)
            {
                searchDoc(doctor1);
                goto option3;
            }

            //For going back to main menu
            else if (numb1==5)
                goto regenerate;
        }

    ///For Managing patient option 4
    else if (struc==4)
    {
        option4:

        cout << "1. Add patient\n2. Update patient info\n3. Delete patient\n4. View all patient\n5. Search for patient\n6. Search for patient by doctor name\n7. Show patient's appointment by time range\n8. Go back" <<endl;
        cout << "\nEnter menu action you want: ";
        cin >> numb1;
        //For adding patient Option 1
        if (numb1==1)
        {
            newpatient(newpat,numb2,patient1,diagnoses1,doctor1);
            goto option4;
        }
        //For updating patient Option 2
        if (numb1==2)
        {
            updatePat(newpat,numb2,patient1);
            goto option4;
        }
        //For deleting patient Option 3
        else if (numb1==3)
        {
            deletepatient(newpat,numb2,patient1);
            goto option4;
        }
        //For viewing patient Option 4
        else if (numb1==4)
        {
            printpatient(numb2,newpat, patient1, docnumb,doctor1);
            goto option4;
        }

        //For searching patient by name or email Option 5
        else if (numb1==5)
        {
            searchPatient(newpat,numb2,patient1);
            goto option4;
        }

        //For searching patient by doctor name Option 6
        else if (numb1==6)
        {
            searchpatDoc(patient1,doctor1);
            goto option4;
        }
        //Option 7
        else if (numb1==7)
        {
            searchPatApp(patient1,slot1,dtime1,appointment1);
            goto option4;
        }

        //To go back
        else if (numb1==8)
            goto regenerate;
    }



    ///For managing patient files option 5
    else if (struc==5)
    {
        option5:
        cout << "1. Adding to Patient record\n2. For updating patient record\n3. Print patient record\n4. Go back" << endl;
        cout << "\nEnter menu action you want: ";
        cin >> numb1;
        //for adding to patient record
        if (numb1==1)
        {
            printDiag(diagnoses1);
            assDiag(diagnoses1,rnumb,appointment1,record1, patient1);
            goto option5;
        }
        //for updating patient record
        if (numb1==2)
        {
            updateRec(record1,diagnoses1,patient1);
            goto option5;
        }
        //for printing patient record
        if (numb1==3)
        {
            printRec(record1);
            goto option5;
        }

        if (numb1==4)
            goto regenerate;
    }

    ///For managing labs option 6
    else if (struc==6)
    {
        option6:
        cout << "1. Add lab appointment\n2. Delete lab appointment\n3. Show all lab appointment\n4. Go back  " << endl;
        cin >> numb1;

        if (numb1==1)
        {
            addlab(labnumb,lab1,slot1,patient1,doctor1,dtime1);
            goto option6;
        }
        if (numb1==2)
        {
            deletLab(labnumb, lab1,slot1);
            goto option6;
        }
        //to print lab
        if (numb1==3)
        {
            printLab(lab1);
            goto option6;
        }
        if (numb1==4)
            goto regenerate;
    }

    else if (struc==7)
    {
        printDiag(diagnoses1);
        goto regenerate;
    }

    ///For option 7 exit program
    if (struc==8){
    cout << "\nHave a good day thank you \1" <<endl;
    return 0;
    }
}
