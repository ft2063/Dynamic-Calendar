#include <iostream>
#include<vector>
#include<map>
using namespace std;
#include<string>
#include "Day.h"
#include "Week.h"
#include "Event.h"
#include <iomanip>

class Month  {
private:
    int Monthz, Year;
    string dateMonth, titleMonth;
    vector <Week> theMonth;      //month can be thought as a vector of weeks
public:
    Month()  {    //default and parameterized constructor
        Monthz = -1; Year = -1;
        Week Empty;
        theMonth.push_back(Empty);
        theMonth.push_back(Empty);
        theMonth.push_back(Empty);
        theMonth.push_back(Empty);
    }

    Month(int length) {     
        Monthz = -1; Year = -1;
        Week Empty;
        for (int i=0; i<length; i++)
        theMonth.push_back(Empty);
    }
    
    Month(vector<Week> vector) {        
        Monthz = -1; Year = -1;
        Week Empty;
        theMonth.push_back(Empty);
        theMonth.push_back(Empty);
        theMonth.push_back(Empty);
        theMonth.push_back(Empty);
        int FillN = vector.size() - 4;    //fills month with non empty weeks if a vector of eventful week is passed to constructor
        if (FillN > 0) {
            for (int i = 0; i < FillN; i++) { theMonth.push_back(Empty); }
        }
        for (int i = 0; i < vector.size(); i++) {
            int weekN = vector[i].getWeekID();
            if (weekN >= 0 && weekN <= 10)
                theMonth[weekN] = vector[i];
        }
    }
//setters
    void SetTitleMonth(string TitleMonth) { titleMonth = TitleMonth; }
    void setMonthDate( int month, int year) {
        Monthz = month; Year = year;
         string theMonth = to_string(month); string theYear = to_string(year);
        dateMonth =  theMonth + "/" + theYear;
    }

//creates event in a week of vector theMonth as per imput
    void CreateEvent(string name, int WeekIdd, int Dayindex,  int theStartingTime, int theDuration=1)
    {
        int position = WeekIdd;
        int theDay = -1;
        theMonth[position].CreateEvent(name, Dayindex,  theStartingTime, theDuration);
    }

//displays schedule of month by printing each week one by one
    void printMonth() {
        for (int i = 0; i < titleMonth.length(); i++) {
           titleMonth[i]= toupper(titleMonth[i]);
        }

        cout << "Calendar "<<titleMonth << ": \n(" << dateMonth<<")\n";
        for (int i = 0; i < theMonth.size(); i++) {
            cout << setw(20);
            cout << "\n***********************************************************************************************************************\n"<<"Week: " << i +1<< "\n***********************************************************************************************************************\n";
            theMonth[i].printWeek(); 
            cout << setw(20);
           
        }
    }
    
    
};