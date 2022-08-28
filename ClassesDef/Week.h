#include <iostream>
#include<vector>
#include<map>
using namespace std;
#include<string>
#include "Day.h"
#include "Event.h"
#include<iomanip>

class Week {

protected:
    int Monthz, Year;
    string MatrixEvents[Time::hoursDay][Time::DayWeek]; //table for events: rows are hours, columns are days, 
    vector <Day> week; //week can be thought of as a vector of days
    int WeekId;//position of week in month
    string date, title;
    int startHour; //for printing, the first row to print for that week (its useless to pring 4am so starting hour set to 6 in default constructor)
public:
//default constructor
    Week(){
        Monthz = 0; Year = 0;
        startHour = 6;
        WeekId = -1; //no position assigned
        for (int i = 0; i < Time::hoursDay; i++) {
            for (int k = 0; k < Time::DayWeek; k++) {
                MatrixEvents[i][k] = "";
            }

        }
        date = "empty";
        title = "empty";
        Day Sunday(0); week.emplace_back(Sunday);
        Day Monday(1); week.emplace_back(Monday);
        Day Tuesday(2); week.emplace_back(Tuesday);
        Day Wednesday(3); week.emplace_back(Wednesday);
        Day Thursday(4); week.emplace_back(Thursday);
        Day Friday(5); week.emplace_back(Friday);
        Day Saturday(6); week.emplace_back(Saturday);
    }

//parameterized constructor fills the week with days if a vector of non empty day is passed to constructor
    Week(vector<Day> vector) {
        Monthz = 0; Year = 0;
        startHour = 6;
        WeekId = -1;
        Day Sunday(0); week.emplace_back(Sunday);
        Day Monday(1); week.emplace_back(Monday);
        Day Tuesday(2); week.emplace_back(Tuesday);
        Day Wednesday(3); week.emplace_back(Wednesday);
        Day Thursday(4); week.emplace_back(Thursday);
        Day Friday(5); week.emplace_back(Friday);
        Day Saturday(6); week.emplace_back(Saturday);
        for (int i = 0; i < vector.size(); i++) {
            int day = vector[i].getWeekDay();
            if (day >= 0 && day < Time::DayWeek) {
                week[day] = vector[i];
                
                string*eventsCopy = vector[i].getMatrixEvent();    //take the address to string array in heap with name of events
                for (int k = 0; k < Time::hoursDay; k++) {
                    MatrixEvents[k][day] = eventsCopy[k];
                }
                delete[]eventsCopy;  //deallocate dynamic memory
            }
            }
        
        }

//creates evenet for a given day in vector of days, by calling CreateEvent
    void CreateEvent( string name, int index, int theStartingTime, double theDuration=1) {
        int theDay = -1;
        Event EventNew(name, theDay, Monthz, theStartingTime, theDuration, Year);
        MatrixEvents[theStartingTime][index] = EventNew.getTitle();
    }



//setters
    void setWeekDate(int day, int month, int year) {
        string theDay = to_string(day); string theMonth = to_string(month); string theYear = to_string(year);
        date = theDay + "/" + theMonth + "/" + theYear;
        Monthz = month; Year = year;
    }
    void setWeekTitle(string theTitle) { title= theTitle; }
    void setWeekID(int ID) { WeekId = ID; }
    int getWeekID() { return WeekId; }
    void setStartHour(int wakeUp) { startHour = wakeUp; }

//prints the table containing events
    void printEvents() {
        for (int i = 0; i < Time::hoursDay; i++) {
            for (int j = 0; j < Time::DayWeek; j++) {
                cout << MatrixEvents[i][j] << i << "." << j << "; ";
            }
            cout << "\n";
        }
    }

//prints the week and its information
    void printWeek() {
        cout << "Week: " << title << ", Date: " << date;
        cout << "\n\n";
        cout << setw(10)<<left<<"|Time /h|";
        for (int i = 0; i < week.size(); i++)
        {
            cout << setw(16) << right<<week[i].returnDay();
    }
      cout<<endl;
        cout << "\n_____________________________________________________________________________________________________________________________________________________________________\n\n";
        for (int i = startHour; i < Time::hoursDay; i++) {
            double j = i;
            cout << left << setprecision(2) << fixed << j << "\t|";
            for (int j = 0; j < Time::DayWeek; j++) {
                if (!MatrixEvents[i][j].empty())
                    cout << right << setw(15) << MatrixEvents[i][j];
                else
                    cout << setw(13) << right << i << "." << right << j;
            }

            cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
        }
        cout << "\n";
    }
   



};


  



   