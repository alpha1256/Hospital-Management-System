#ifndef FUNCTION6_H_INCLUDED
#define FUNCTION6_H_INCLUDED

using namespace std;
///Dates and time class
class dtime {
int dtid,day, month,year,hours,minutes;
string ap;
public:
void setdtid (int sdtid){dtid=sdtid;};
void setday (int sday) {day=sday;};
void setmonth(int smonth) {month=smonth;};
void setyear (int syear) {year=syear;};
void setdhours (int shours) {hours=shours;};
void setminutes (int min) {minutes=min;};
void setaop (string sap) {ap=sap;};

int getdid (){return dtid;};
int getday(){return day;};
int getmonth(){return month;};
int getyear(){return year;};
int gethour(){return hours;};
int getmin(){return minutes;};
void printdtime();
};

///Get date from it file
void getDate(vector <dtime> & dtime1);

///Output the date
void printDate(vector <dtime> dtime1);
#endif //
