#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "function7.h"
using namespace std;

void record::printrecord()
{
    cout << "\nRecord ID: " << rid << "\nPatient ID: " << rpid << "\nNotes: " << notes <<endl;
    cout << "--------------------------------------------------------------------" <<endl;
}
///For adding a record and diagnoses for each patient
void assDiag(vector <diagnoses>  diagnoses1,int & numb, vector <appointment> appointment1, vector <record> &record1, vector <patient> patient1)
{
    string dianame;
    int one;
    bool check1;
    check:
    cout << "Enter the patient id for the patient record that you want to add: ";
    cin >> one;
    check2:
    bool check4;
    cout << "Enter the diagnosis of the patient: ";
    getline(cin,dianame);
    vector <diagnoses>::iterator index;
    for (index=diagnoses1.begin(); index !=diagnoses1.end(); index++)
    {
        if (dianame == index->getdianame())
        {
            check4=1;
        }
    }
    if (check4==0)
    {
        cerr << dianame <<endl;
        goto check2;
    }


            vector<patient>::iterator indexa;
            for (indexa=patient1.begin(); indexa != patient1.end(); indexa++){
                if (one == indexa -> getid())
                {
                    srand(time(0));
                    int rid=indexa->getrid();
                    //int a= rand()% 17 + 0;
                    //dianame=diagnoses1[a].getdianame();
                    record1.push_back(record());
                    record1[numb].setrid(rid);
                    record1[numb].setrpid(one);
                    record1[numb].setnotes(dianame);
                    numb++;
                    check1=1;
                }
            }

    if (check1==0)
    {
        cout << "Enter a valid patient id" <<endl;
        goto check;
    }
}
///Updating patient record
void updateRec(vector <record> & record1, vector <diagnoses> diagnoses1, vector <patient> patient1)
{
    int id;
    bool check1;
    check:
    cout << "Enter the patient id for the record that you want to update:";
    cin >> id;
    vector<record>::iterator indexb;
    for (indexb=record1.begin(); indexb != record1.end(); indexb++)
    {
        if (id==indexb->getrpid())
        {
            check2:
            bool check4;
            string dianame;
            cout << "Enter the new diagnosis of the patient: ";
            getline(cin,dianame);
            vector <diagnoses>::iterator index;
            for (index=diagnoses1.begin(); index !=diagnoses1.end(); index++)
            {
                if (dianame == index->getdianame())
                {
                    check4=1;
                }
            }
            if (check4==0)
            {
                cerr << dianame <<endl;
                goto check2;
            }

            vector<patient>::iterator indexa;
            for (indexa=patient1.begin(); indexa != patient1.end(); indexa++){
                if (id == indexa -> getid())
                {
                    //srand(time(0));
                    int rid=indexa->getrid();
                    //int a= rand()% 17 + 0;
                    //dianame=diagnoses1[a].getdianame();
                    indexb->setrid(rid);
                    indexb->setrpid(id);
                    indexb-> setnotes(dianame);
                    check1=1;
                }
            }
        }
    }
    if (check1==0)
    {
        cout << "Enter a valid patient id" <<endl;
        goto check;
    }
}

///Print records
void printRec(vector <record> record1)
{
    vector<record>::iterator indexb;
    for (indexb=record1.begin(); indexb != record1.end(); indexb++)
    {
        indexb->printrecord();
    }
}
/*
            did=diagnoses1[a].getdid();
            indexa->setDiad(did);
            indexa->setDianame(dianame);
            a=0,did=0, dianame="";*/
