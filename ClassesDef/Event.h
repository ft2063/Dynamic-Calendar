#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;
#pragma once

class Event {
    private:
    string EventName; int Day; int Month; double Duration; int year; double StartingTime;

public:
//parameterized and default constructors
    Event() {  EventName = "Null"; Day = -1; Month = -1; Duration = -1; year = -1; StartingTime = -1; }


    Event(string name, int theDay, int theMonth, double theStartingTime, double theDuration, int theYear ) { //creates an event with parameterized constructor
        EventName = name;
        Day = theDay;
        Month = theMonth;
        Duration = theDuration;
        year = theYear;
        StartingTime = theStartingTime;
        
    }
    
    string getTitle() { return EventName; }

    void print() { //prints the event and its information
        
        cout << "\nName Event: " << EventName << "\t\nEvent Date: " << to_string(Day) << "/" <<to_string(Month) << "/" << to_string(year);
        cout << "\t\nStarting Time: " << to_string(StartingTime) << "\t\nDuration: " << to_string(Duration);
       
    }

//GLOBAL FRIEND FUNCTION can be used by all classes safely to organize events
  friend Event* SortEvents(vector<Event> events) {  // Orders events in ascending order given vector of events
        Event* EventPointer = new Event[10]; //create an empty array of events in heap
        
        sort(events.begin(), events.end(), [](const Event& lhs, const Event& rhs) {return lhs.StartingTime < rhs.StartingTime; }); //sorts by object property StartingTime
        for (int i = 0; i < events.size(); i++) {
            EventPointer[i] =  events[i]; } 
        return EventPointer; //returns pointer pointing to array of events in order by starting time
    }


}; 
