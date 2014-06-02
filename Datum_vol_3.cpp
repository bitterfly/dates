# include <iostream>
# include <iomanip>
# include <windows.h>

using namespace std;

bool is_leap(int year){
    if(year%400==0) return true;
    else {
    if(year%100==0) return false;
       if(year%4==0) return true;
            else
            return false;
    }
 }

bool correct_year(int year){
if(year>=1000 && year<9999)
    return true;
else
    return false;
}

bool correct_date(int day, int month, int year){
if(correct_year(year)){
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day >= 1 && day <= 31)
            return true;
        else
            return false;
        }
    if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day >= 1 && day <= 30)
            return true;
        else
            return false;
                }
    if(month == 2){
         if(is_leap(year)) {
            if (day >= 1 && day <= 29)
                return true;
            else
                return false;
            }
         else{
            if(day >= 1 && day <= 28)
                return true;
            else
                return false;
            }
        }
        else
            return false;
    }
    }


void enter_date (int &day, int &month, int &year){
cout<<"Day: ";
cin>>day;
cout<<endl;
cout<<"Month: ";
cin>>month;
cout<<endl;
cout<<"Year: ";
cin>>year;
cout<<endl;

if(!correct_date(day,month,year)){
    cout<<"Incorrect date"<<endl;
    enter_date(day,month,year);
}
}

int days_in_month(int month, int year){
if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    return 31;
if(month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
if(month == 2){
    if(is_leap(year))
        return 29;
    else
        return 28;
    }
}

void bigger_date(int &d1, int &m1, int &y1, int &d2, int &m2, int &y2){
 if(y1>y2){
    swap(y1, y2);
    swap(m1, m2);
    swap(d1, d2);
    }
 if(y1==y2){
   if(m1>m2){
    swap(m1, m2);
    swap(d1, d2);
    }
    if(m1==m2){
      if(d1>d2)
            swap(d1,d2);
     }
  }
 }

void calculate_duration(int d1, int m1, int y1, int d2, int m2, int y2){

bigger_date(d1, m1, y1, d2, m2, y2);

int counter = 0, days = 0, months = 0, years = 0;

if(d2 - d1 >= 0)
    days = d2 - d1;
else{
    days = days_in_month(m2,y2) + d2 - d1;
    counter = -1;
}

if(m2 - m1 >= 0){
    months = m2 - m1 + counter;
    counter = 0;
    }
    else{
        months = 12 + m2 - m1 + counter;
    }

    years = y2 - y1 + counter;

cout<<"Difference between: "<<d1<<'/'<<m1<<'/'<<y1<<" and "<<d2<<'/'<<m2<<'/'<<y2<<" is: "<<endl;
cout<< years<<" year/s, "<<months<<" month/s, "<< days<<" day/s."<<endl;

}

int weekday(int d1,int m1,int y1){

    int week = 0;

    for(int i = 1; i < y1; i++){
        week = week + 365 + is_leap(i);
        }
    for(int i = 1; i < m1; i++){

        week = week + days_in_month(i, y1);
        }
    for(int i = 1; i <= d1; i++){
        week = week + 1;
        }
return week%7;
    }

void add(int d1,int m1,int y1, int days, int press){
if(correct_date(d1, m1, y1)){

if(press==3){
while((m1+days)>12){
y1++;
days = days-12;
}

cout<<days_in_month(m1+days,y1)<<'/'<<m1+days<<'/'<<y1<<endl;
}

if(press==4){
    cout<<d1<<'/'<<m1<<'/'<<y1+days<<endl;
}
if(press==1 ||press == 2){
    if(press==2)
        days = days*7;
while (d1+days > days_in_month(m1, y1)){
    days = days - days_in_month(m1,y1) + d1;
    d1 = 0;
    m1++;

    if(m1 > 12){
        y1++;
        m1 = 0;
     }
    }

 cout<<d1+days<<'/'<<m1<<'/'<<y1<<endl;
 }
}
 else
    cout<<"Incorrect date. Please, enter a new one. " <<endl;
    }

void check_date(int m1, int y1, int day, int con){
int br = 0;

for(int i = 1; i <= days_in_month(m1,y1); i++){
    if(weekday(i,m1,y1)==day)
        br++;
    }
   if(con == 5)
        con = br;

br = 0;
bool flag = true;

for(int i = 1; i <= days_in_month(m1,y1), flag; i++){
    if(weekday(i,m1,y1)==day)
        br++;
        if(br==con)
            {
        cout<<i<<'/'<<m1<<'/'<<y1<<endl;
        flag = false;}
    }
}

void calendar(int m1, int y1){

HANDLE hConsole;

int cal[100][100]={};

bool flag = false, flag2 = true;

int br = 0;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int first_day = weekday(1,m1,y1);
    if(first_day==0){
    first_day = 7;
    }
first_day = first_day - 1;
cout<<"Mon  Tue  Wed  Th  Fr  Sat  Sun"<<endl;

for(int i = 0; i < 6; i++){
    for(int j = 0; j < 7; j++){
    	if (j==5 || j==6)
    	SetConsoleTextAttribute(hConsole, 12);
    	else
    	SetConsoleTextAttribute(hConsole, 7);



            if(i==0 && j == first_day){
                flag = true;
                br++;
                }

                if(br>days_in_month(m1,y1)){
                flag2= false;
                br=0;
                //break;
                }
            if(!flag){
                cout<<" -   ";
            }
            if(flag2==true && flag==true){

                cal[i][j]=br;
                br++;
            if(br<=10){

                  cout<<" "<<cal[i][j]<<"   ";

                }
                else
                    cout<<cal[i][j]<<"   ";
        }

     }
    cout<<endl;
    }
    SetConsoleTextAttribute(hConsole, 7);
    }

void format(int d1, int m1, int y1, int ch){
if (ch==1){
        if(d1>=10)
    cout<<y1<<'/'<<m1<<'/'<<d1<<endl;
        else
    cout<<y1<<'/'<<m1<<'/'<<0<<d1<<endl;

}

if(ch==2){
  std::cout << std::setfill ('0') << std::setw (2);
  std::cout<<y1%100<<'/';
  std::cout << std::setfill ('0') << std::setw (2);
  std::cout<<m1<<'/';
  std::cout << std::setfill ('0') << std::setw (2);
  std::cout<<d1<<std::endl;

        }

if(ch==3){
  std::cout << std::setfill ('0') << std::setw (2);
  std::cout<<d1<<'/';
  std::cout << std::setfill ('0') << std::setw (2);
  std::cout<<m1<<'/';
  std::cout << std::setfill ('0') << std::setw (2);
  std::cout<<y1%100<<std::endl;

}
        }

void easter (int y1){
int a, b, c, d, e;
a = y1%19;
b = y1%4;
c = y1%7;
d = (19*a + 15) % 30;
e = (2*b + 4*c + 6*d + 6)%7;

if(d+e>=10)
    add(d+e-9,4,y1,13,1);
else
    add(22+d+e,3,y1,13,1);
}


int main(){


int menu, d1, m1, y1, d2, m2, y2;
cout<<"Menu"<<endl<<"Press: "<<endl;
cout<<"'1' to enter a date."<<endl;
cout<<"'2' to check if it's correct."<<endl;
cout<<"'3' to see the difference between two dates."<<endl;
cout<<"'4' to add/subtract days from a date."<<endl;
cout<<"'5' for weekday calculator"<<endl;
cout<<"'6' to see the calendar."<<endl;
cout<<"'7' for Easter date."<<endl;
cout<<"'8' to see the date in a diferent format."<<endl;
cout<<"'9' to find a day matching you description."<<endl;
cout<<"'10' to Exit."<<endl;

do
    {
        cin>>menu;

        switch(menu){

        case 1:
            enter_date(d1,m1,y1);
            break;
        case 2:
            if(correct_date(d1,m1,y1))
                cout<<"It's correct"<<endl;
            else
                cout<<"It's incorrect"<<endl;
            break;

        case 3:
             cout<<"Enter second date."<<endl;
             do{
             enter_date(d2,m2, y2);
               }while(!correct_date(d2,m2,y2));
             calculate_duration(d1,m1, y1, d2, m2, y2);
             break;

        case 4:
                int days, press;
                cout<<"To add:"<<endl<<"days - Press 1 "<<endl<<"weeks - Press 2"<<endl<<"months - Press 3"<<endl<<"years - Press 4"<<endl;
                cin>>press;
                switch(press){

                    case 1:
                        cout<<"add ___ days"<<endl;
                        cin>>days;
                        add(d1,m1, y1,days,press);
                        break;
                    case 2:
                        cout<<"add___weeks"<<endl;
                        cin>>days;
                        add(d1,m1,y1,days,press);
                        break;
                    case 3:
                        cout<<"add___months"<<endl;
                        cin>>days;
                        add(d1,m1,y1,days,press);
                        break;
                }
                break;

       case 5:
switch(weekday(d1,m1,y1)){
    case 1:
        cout<<"Monday"<<endl;
        break;
    case 2:
        cout<<"Tuesday"<<endl;
        break;
    case 3:
        cout<<"Wednesday"<<endl;
        break;
    case 4:
        cout<<"Thursday"<<endl;
        break;
    case 5:
        cout<<"Friday"<<endl;
        break;
    case 6:
        cout<<"Saturday"<<endl;
        break;
    case 0:
        cout<<"Sunday"<<endl;
        break;
     }
    break;

       case 6:

           cout<<"Enter a month and year"<<endl;
           cin>>m1>>y1;
           calendar(m1,y1);
           break;

       case 7:
           cout<<"Enter year.";
        cin>>y1;
            cout<<"Easter is on: ";
        easter(y1);
        break;

        case 8:
            int ch;
            cout<<"Press '1' for YYYY/MM/DD"<<endl<<"Press '2' for YY/MM/DD"<<endl<<"Press '3' for DD/MM/YY"<<endl;
            cin>>ch;
            format(d1,m1,y1,ch);
            break;
       case 9:
           int day = 0, con = 0;
           cout<<"Enter a month and year"<<endl;
           cin>>m1>>y1;
            cout<<"Search for: "<<endl<<"1 - Monday"<<endl<<"2 - Tuesday"<<endl<<"3 - Wednesday"<<endl<<"4 - Thursday"<<endl<<"5 - Friday"<<endl<<"6 - Saturday"<<endl<<"7 - Sunday"<<endl;
            cin>>day;
            if(day == 7)
                day = 0;
            cout<<"Search for: "<<endl<<"1 - First"<<endl<<" 2 - 4 (from 2nd to 4th)"<<endl<<"5 - last"<<endl;
                cin>>con;
            check_date(m1, y1, day, con);
            break;
       }

    } while(menu!=10);
}


