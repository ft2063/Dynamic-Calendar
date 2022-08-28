#include"DemoStandard.h"
#include "../ClassesDef/Month.h"
#include <iostream>
#include<string>
#include<thread>
#include "../ClassesDef/Year.h"

//sample function to show how a day and its events can be created
void CreateDay() {
    Day Mon(1);
    Mon.setEvent("Birthday", 10, 8, 20.00, 2, 2022);
  Mon.setEvent("exam",10,8,6,2,2022);
    Mon.printDay();      //events sorted by time
}


void CreateCostumWeek() { //shows how to construct a week
  Week Break;
  Break.setWeekTitle("Spring Break"); Break.setWeekDate(10,5,2022);
  Break.CreateEvent("Party",0,20);
  Break.CreateEvent("Disco",2,21);
  Break.CreateEvent("Brunch",4,11);
  Break.CreateEvent("Park",5,16);
  Break.CreateEvent("GrandMa",3,15);
  Break.printWeek();
  }

void CreateCostumMonth(){Month HoneyMoon(5); //shows how to construct a month
  HoneyMoon.SetTitleMonth("HoneyMoon");
  HoneyMoon.setMonthDate(12,2030);
  HoneyMoon.CreateEvent("dinner",0,0,20);
   HoneyMoon.CreateEvent("Trip",1,2,20);
  HoneyMoon.CreateEvent("Desert",3,4,19);
  HoneyMoon.CreateEvent("Flight",4,6,15);
  HoneyMoon.printMonth();}

//pass by Rvalue as we use the function to print only, so we don't need to keep memory for the year
void CalendarPrint(int &&theYear) { //shows how external code of Techsane Girl can used to increase functionalities of our program. Original code at https://github.com/debasree888/calendar-in-c/blob/master/Calendar-in-C-master/main.c
    Year Freshman(theYear);
    Freshman.print();
   // Freshman.setYear(2021);
    //Freshman.print();
}

void CreateEmptyWeek() { Week EmptyWeek; EmptyWeek.printWeek(); } //shows what happens when we create an object week without using constructor
//the empty week can be later filled by calling CreateEvent