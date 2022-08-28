#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#include "ClassesDef/Year.h"
#include "ClassesDef/Event.h"
#include "ClassesDef/Month.h"
#include "ClassesDef/Day.h"
#include "Functions/DemoStandard.h"
#include "Functions/DemoAdvanced.h"


int main()
{
  //Basic Features:
  
  CreateDay();
  CreateCostumWeek();
  CreateCostumMonth();
  CalendarPrint(2020+1);
  
  //Advanced Features:  
  //DISCOVER ADVANCED FEATURES by UNCOMMENTING functions CALLS below
  
    //CreateMonth();
    // SummerTerm();
     

    return 0;
}














