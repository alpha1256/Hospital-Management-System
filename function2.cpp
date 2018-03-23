#include <iostream>
#include <fstream>
#include <vector>
#include "function2.h"

using namespace std;
/* This is the file for the doctors */

doctor::doctor(){
docid=0;
appointcount=0;
username="";
password="";
name="";
docname="";
name ="";
docname ="";
skill ="";
dphone ="";
}

///This get the doctors
void getDoctors(fstream & infile2, int & docnumb, vector <doctor> & doctor1){
int docid;
string username, name, password, docname,skill,dphone ;
//int upnumb= innumb + numb;
infile2.open("Doctors.txt");
infile2 >> docnumb;
for (int i=0; i < docnumb; i++)
    {
        infile2 >> docid >> username >> password >> name >> dphone >> skill;
        doctor1.push_back(doctor());
        doctor1[i].setdocid(docid);
        doctor1[i].setusename(username);
        doctor1[i].setpassword(password);
        doctor1[i].setname(name);
        doctor1[i].setdphone(dphone);
        doctor1[i].setskill(skill);
        docid=0;
        username = "", name="", password="", docname="", skill="",dphone="";
    }
}

///Printing Member function
void doctor::printdoc()
{
cout <<"Doctor Id :" << docid <<"\nUsername :" << username << "\nPassword :" <<password
<< "\nName :" <<name <<"\nPhone :" <<dphone <<"\nAppointment Count :" <<appointcount<< "\nSkill :" <<skill<<endl;
cout << "-----------------------------------------------------"<<endl;
}

///This prints the doc
void printdoc(vector <doctor>  doctor1)
{
    vector<doctor>::iterator indexb;
    for (indexb =doctor1.begin(); indexb != doctor1.end(); indexb++)
    {
        indexb->printdoc();
    }
}

///Updating the doctor information
void updateDoc(vector <doctor> & doctor1)
{
    string name1;
    int counter;
    int docid;
    string username, password, name, docname,skill,dphone;
    cout << "Enter the doctor name you want to update: ";
    cin >> name1;
    //cout << "Enter number for the thing you want to change\n1 Doctor ID\n2 User Name\n3 Password\n4 Name\n5 Phone\n6 Skill " <<endl;
    //cin >> counter;
    vector<doctor>::iterator indexb;
    for (indexb =doctor1.begin(); indexb != doctor1.end(); indexb++)
    {
        if (name1==indexb->getname())
        {
            //For changing doc id
           // if (counter==1)
            //{
                //cout << "Enter new doc id: ";
               // cin >> docid;
               // indexb->setdocid(docid);
           // }
            //For changing username
           // else if (counter==2)
           // {
                cout << "\nEnter new user name: ";
                cin >> username;
                indexb-> setusename(username);
           // }
            //For changing password
           // else if (counter==3)
            //{
                cout << "\nEnter new password: ";
                cin >> password;
                indexb-> setpassword(password);
            //}
            //For changing name
           // else if (counter==4)
            //{
                cout << "\nEnter new name: ";
                cin >> name;
                indexb-> setname(name);
           // }
            //For changing phone
           // else if (counter==5)
            //{
                cout << "\nEnter new phone: ";
                cin >> dphone;
                indexb->setdphone(dphone);
            //}
            //For changing skill
            //else if (counter==6)
           // {
                cout << "\nEnter new skill";
                cin >> skill;
                indexb->setskill(skill);
            //}
        }
    }
}

///This is to be able to search doctor by name
void searchDoc(vector <doctor> & doctor1)
{
    string searchname;
    cout << "Enter doc name you want to search:";
    cin >> searchname;
    vector<doctor>::iterator indexb;
    for (indexb =doctor1.begin(); indexb != doctor1.end(); indexb++)
    {
        if (searchname==indexb->getname())
        {
          indexb->printdoc();
        }
    }
}

///This is for deleting doctors
void DeleDoc(vector <doctor> & doctor1)
{
    int docid;
    bool check1;
    check:
    int docnumb = doctor1.size();
    cout << "Enter doctor id that you want to delete: ";
    cin >> docid;
    for (int i=0;  i < docnumb; i++)
    {
        if (docid ==doctor1[i].getdocidt() && doctor1[i].getappcount()==0)
        {
            doctor1.erase(doctor1.begin()+i);
            cout << "\nThis doctor has been deleted" <<endl;
            check1=1;
        }
    }
    if (check1==0)
    {
        cout << "Enter a valid id or make sure this doctor has no appointments" <<endl;
        goto check;
    }
}

