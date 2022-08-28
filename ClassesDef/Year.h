//this code was created by Techsane Girl
//original code at https://github.com/debasree888/calendar-in-c/blob/master/Calendar-in-C-master/main.c
//some changes were included for the sake of this calendar application



#include <iostream>
#include<vector>
#include<map>
using namespace std;
#include<string>

class Year {
private:
    int year, month, day, MonthLength, theDayStart = 0, Start;
    vector <pair<string, double>> Monthss;

public:
    Year(int time) {
        year = time;

        Monthss.emplace_back("january", 31);
        Monthss.emplace_back("february", 28);
        Monthss.emplace_back("march", 31);
        Monthss.emplace_back("april", 30);
        Monthss.emplace_back("may", 31);
        Monthss.emplace_back("june", 30);
        Monthss.emplace_back("july", 31);
        Monthss.emplace_back("august", 31);
        Monthss.emplace_back("september", 30);
        Monthss.emplace_back("october", 31);
        Monthss.emplace_back("november", 30);
        Monthss.emplace_back("december", 31);

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            Monthss[1].second = 29;
        }

        Start =  (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    }
    void setYear(int time) { year = time; }

    //print calendar
    void print() {
        cout << "\n\n**************************************\nCALENDAR YEAR: " << year << "\n**************************************";
        for (int i = 0; i < Monthss.size(); i++) {

            MonthLength = Monthss[i].second;
            cout << "\n\n--------------------------------------------------\n",
                cout << "\t\t" << Monthss[i].first;
            cout << "\n--------------------------------------------------\n",
                cout << ("\nSun\tMon\tTue\tWed\tThurs\tFri\tSat\n");

            for (theDayStart = 0; theDayStart < Start; theDayStart++)
                cout << ("\t");

            for (day = 1; day <= MonthLength; day++) {
                cout << (day);
                cout << "\t";

                if (++theDayStart > 6) {
                    cout << ("\n");
                    theDayStart = 0;
                }
                Start = theDayStart;
            }
        }
    }

   
};