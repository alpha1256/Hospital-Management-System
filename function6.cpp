#include <iostream>
#include <fstream>
#include <vector>
#include "function6.h"

using namespace std;
///Date and time function

///Print member function
void dtime::printdtime()
{
    cout << "\nID: " << dtid << "\nDate: " << day << "/" << month << "/" << year <<endl;
    cout << "Hours: " <<hours << "\nMinutes: " <<minutes <<"\nAm or Pm: " <<ap <<endl;
}

///Get date from it file
void getDate(vector <dtime> & dtime1)
{
    fstream infile;
    int numb=0;
    infile.open("Date_Time.txt");
    infile >> numb;
    for (int i=0; i < numb; i++)
    {
        int dtid,day, month,year,hours,minutes;
        string ap;
        char temp;
        infile >> dtid >> day >> month >> year >>hours >> minutes >> temp;
        dtime1.push_back(dtime());
        dtime1[i].setdtid(dtid);
        dtime1[i].setday(day);
        dtime1[i].setmonth(month);
        dtime1[i].setyear(year);
        dtime1[i].setdhours(hours);
        dtime1[i].setminutes(minutes);

        if (temp=='a')
        {
            ap ="am";
            dtime1[i].setaop(ap);
        }
        else if (temp=='p')
        {
            ap ="pm";
            dtime1[i].setaop(ap);
        }

    }
}

///Output the date
void printDate(vector <dtime> dtime1)
{
    vector<dtime>::iterator indexb;
    for (indexb =dtime1.begin(); indexb != dtime1.end(); indexb++)
    {
       indexb->printdtime();
    }
}
