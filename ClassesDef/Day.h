#include <iostream>
#include<vector>
#include<map>
using namespace std;
#include<string>
#pragma once
#include "Event.h"

 //namespace Time include constants which are relevant in Day and Week class
namespace Time { const int hoursDay = 24; const int DayWeek = 7;} 

class Day  {
protected:
  int Dayy, Month, Year;      
	int WeekDay;      //index of day in week (Ranges from 0 to 6, 0=Sunday, 6=saturday)
    string DayName;
	vector<Event> EventsDay;      //vector of objects of events stores events
    string EventsBlock[Time::hoursDay];    //Array of strings conserving name of events

public:
//default and parameterized constructors
    Day() { Dayy=-1; Month=-1; Year=-1; WeekDay = -1; DayName = "null"; EventsDay.empty(); }
    Day(int theWeekDay) {
        WeekDay = theWeekDay;
        switch (WeekDay) {
        case 1: DayName = "Monday"; break;
        case 2: DayName = "Tuesday"; break;
        case 3: DayName = "Wednesday"; break;
        case 4: DayName = "Thursday"; break;
        case 5: DayName = "Friday"; break;
        case 6: DayName = "Saturday"; break;
        case 0: DayName = "Sunday"; break;
        }
    }

//getters
    int getWeekDay() { return WeekDay; }
string returnDay() { DayName.resize(10,' '); return DayName; }

//create Event on that day
    void setEvent(string name, int theDay, int theMonth, int theStartingTime, double theDuration, int theYear ) {
      
        Event EventNew(name, theDay, theMonth, theStartingTime, theDuration, theYear);
      
        EventsDay.push_back(EventNew);      //adds event to vector of Events EventsDay
        EventsBlock[theStartingTime] = name;//add name event to vector of string EventsBlock
      
        
    }
    
    string*  getMatrixEvent() {      //returns array to vector of string in heap which stores elements EventsBlock
        
       string* EventsM = new string[Time::hoursDay];
        for (int i = 0; i < Time::hoursDay; i++)
            EventsM[i] = EventsBlock[i];
        return EventsM;
    }

    
    void printTitle() {cout<<DayName<<"\t";}

    void printEvent() {

        Event *EventPtr= SortEvents(EventsDay);    //pointer to array of Events in heap passed by SortEvents
            for (int i = 0; i < EventsDay.size(); i++) {
                EventPtr[i].print();
        }
            delete[] EventPtr; //delete dynamic memory in heap to prevent leackage
            
    }
 
    void printDay(  ) {    //prints All information about dya
        cout << DayName << ", Day Index: "<<WeekDay;
        printEvent();
        }
    
   
};
