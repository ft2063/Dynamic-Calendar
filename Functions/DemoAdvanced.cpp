#include<iostream>
using  namespace std;
#include "../ClassesDef/Month.h"
#include"DemoAdvanced.h"

//generates a month by first creating a vector of weeks. 
//This is useful to show that if you already created weeks and you want to unite them in a Month entity this can //be done through parameterized constructor of month
void CreateMonth() {
    Day Mon(1);  Mon.setEvent("Birthday", 10, 8, 20.00, 2, 2022);
    Day Wed(3); Wed.setEvent("Nutella", 3, 4, 15, 1, 2022);
    vector<Day> WeekX; WeekX.push_back(Mon); WeekX.push_back(Wed);
    Week Ciao(WeekX); Ciao.setWeekTitle("Exams Week"); Ciao.setWeekDate(10, 5, 2022); Ciao.setStartHour(7); Ciao.setWeekID(0);  //Ciao.printWeek();
    Day Tue(2); Tue.setEvent("end year", 12, 12, 22, 2, 2022);
    vector<Day>WeekY; WeekY.push_back(Tue);
    Week B(WeekY); B.setWeekID(3); B.setWeekTitle("Week Carneval"); B.setWeekDate(3, 2, 2022); B.setStartHour(10);
    vector<Week>February; February.push_back(Ciao); February.push_back(B);
    Month Feb(February); Feb.SetTitleMonth("February"); Feb.setMonthDate(2, 2022);  Feb.printMonth();

}
//same as create month, however, the vector of weeks passed to constructor of month object is greater than 4 
//so class month can be used to create period of times of non conventional length (number weeks>4) as independent entities

void SummerTerm() {
    vector<Week>SummerTerm;
    Day Fri1(5);     Fri1.setEvent("Departure", 23, 5, 8, 3, 2022);     vector <Day>Week1; Week1.push_back(Fri1);   Week Summer1(Week1);  Summer1.setWeekID(0); Summer1.setWeekTitle("Summer Week 1");  SummerTerm.push_back(Summer1);
    Day Tue2(2);     Tue2.setEvent("Quiz 1", 29, 5, 10, 1, 2022);       vector <Day>Week2; Week2.push_back(Tue2);   Week Summer2(Week2);  Summer2.setWeekID(1); Summer2.setWeekTitle("Summer Week 2");  SummerTerm.push_back(Summer2);
    Day Thurs3(4);   Thurs3.setEvent("Quiz 2", 5, 6, 17, 1, 2022);      vector <Day>Week3; Week3.push_back(Thurs3);   Week Summer3(Week3); Summer3.setWeekID(2); Summer3.setWeekTitle("Summer Week 3");  SummerTerm.push_back(Summer3);
    Day Mon4(1);     Mon4.setEvent("Quiz 3", 12, 6, 18, 1, 2022);       vector <Day>Week4; Week4.push_back(Mon4);    Week Summer4(Week4);  Summer4.setWeekID(3); Summer4.setWeekTitle("Summer Week 4");  SummerTerm.push_back(Summer4);
    Day Thurs5(4);   Thurs5.setEvent("Exam", 18, 6, 19, 3, 2022);        vector <Day>Week5; Week5.push_back(Thurs5);   Week Summer5(Week5); Summer5.setWeekID(4); Summer5.setWeekTitle("Summer Week 5");  SummerTerm.push_back(Summer5);
    Day Friday6(5);   Friday6.setEvent("Summer2", 25, 6, 10, 5, 2022);    vector <Day>Week6; Week6.push_back(Friday6);  Week Summer6(Week6); Summer6.setWeekID(5); Summer6.setWeekTitle("Summer Week 6");  SummerTerm.push_back(Summer6);
    Day Sunday7(0);   Sunday7.setEvent("Competition", 5, 6, 10, 9, 2022); vector <Day>Week7; Week7.push_back(Sunday7); Week Summer7(Week7); Summer7.setWeekID(6); Summer7.setWeekTitle("Summer Week 7");  SummerTerm.push_back(Summer7);
    Day Saturday8(6); Saturday8.setEvent("flight", 10, 6, 8, 10, 2022); vector <Day>Week8; Week8.push_back(Saturday8); Week Summer8(Week8); Summer8.setWeekID(7); Summer8.setWeekTitle("Summer Week 8");  SummerTerm.push_back(Summer8);
    Month Summer(SummerTerm);
    Summer.SetTitleMonth("Summer Term"); Summer.setMonthDate(5, 2022);
    Summer.printMonth();
}