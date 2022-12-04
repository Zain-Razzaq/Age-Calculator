#include <iostream>
#include <time.h>
using namespace std;

//This Function is Simply Checking Dates.
bool isValid(int day, int month, int year);

int daysInAMonth(int month, int year);

//This Function is Comparing Both Dates And Validating them.
bool validateCurrentDate(int bDay, int bMonth, int bYear, int cDay, int cMonth, int cYear);

//This Function is Calculating Age.
void ageCalculator(int bDay, int bMonth, int bYear, int cDay, int cMonth, int cYear);

const std::string currentDate(int &d,int & m,int & y);

int main()
{
   int dob, mob, yob;    //date of birth, month of birth, year of birth
   int cd, cm, cy;       //current date, current month, current year
   currentDate(cd,cm,cy);
   do
   {
      cout << "Date of birth (day month year): ";
      cin >> dob >> mob >> yob;
   }while (isValid(dob,mob,yob) == false || validateCurrentDate(dob,mob,yob,cd,cm,cy)==false); // parameters are not given

   ageCalculator(dob, mob, yob, cd, cm, cy);

   return 0;
}

const std::string currentDate(int &d,int & m,int & y) {
   time_t theTime = time(NULL);
   struct tm *aTime = localtime(&theTime);

   d= aTime->tm_mday;
   m = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
   y = aTime->tm_year + 1900;
}

bool isValid(int day, int month, int year)
{
   if (day <= 0 || day > daysInAMonth(month, year)){  // "=" is error. as equal days are valid.
      return false;
   }
   else if(month<=0 || month>12){
      return false;
   }
   else if(year<0){
      return false;
   }
   else
      return true;
}

//Birth_day, Birth_Month, Birth_Year, Current_Day, Current_Month, Current_Year
bool validateCurrentDate(int bDay, int bMonth, int bYear, int cDay, int cMonth, int cYear)
{
   if (cYear > bYear)
      return true;
   if (cYear < bYear)
      return false;
   // month and days must also be checked.
   if(cMonth>bMonth)
      return true;
   if(cMonth<bMonth)
      return false;
   if(cDay>bDay)
      return true;
   if(cDay<bDay)
      return false;
    
   return true;// if date is same then answer will will 0.
}

int daysInAMonth(int month, int year)
{
    int days = 0;
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
       days = 30;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
       days = 31;
    }
    else if (month == 2 && year % 4 == 0)  // AND gate will bw used
    {
      if(year%100==0)               // for leap years
      {
         if(year%400==0)
         {
            days=29;
         }
         else{
            days=28;
         }
      }
      else{
         days = 29;
      }
    }
    
    else{
    days = 28;}

   return days;
}

//Birth_day, Birth_Month, Birth_Year, Current_Day, Current_Month, Current_Year
void ageCalculator(int bDay, int bMonth, int bYear, int cDay, int cMonth, int cYear)
{
   int days = cDay - bDay;
    while(days<0)  // loop will run until days are not positive
    {
        cMonth--; // we must decrease month before getting days.
        if(cMonth==0)
        {
            cMonth=12;
        }
        days += daysInAMonth(cYear, cMonth);      
    }
    int month = cMonth - bMonth;
    if (month < 0)
    {
       cYear--; // year must be decreased.
       month += 12;
    }
   int year = cYear - bYear;
   cout << "Age is: " << year << " years " << month << " months " << days << " days " << endl;
}
