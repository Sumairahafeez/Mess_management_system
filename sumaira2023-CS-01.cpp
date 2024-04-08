#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<string>
#include<fstream>
using namespace std;
                                                                //Headers//
void header();
void logInPageHeader();
void happyFace();
void sadFace();
void signUpHeader();
void signInHeader();
void managerPage();
void studentHeader();
                                                             //logInPage//
int loginPage();
                                                            //signUp//
bool signUpCredentials(string &name, string &password, string &role, string userName[], string userPasword[], string userRole[], int &userCount, string roomNumber[], string &room, int &studentIndex);
 
bool signUp(string &name, string &password, string &role, string userName[], string userPassword[],string userRole[], int &userCount);
                                                            //signIn//
bool signInValidity(string &InputName, string &InputPassword, string userName[], string userPassword[], int &userCount, int &currentStudent);
string signIn(string &InputName, string &InputPassword, string userName[], string userPassword[], string userRole[], int &userCount);

                                                            //validations//
bool nameValidity(string &name);
bool checkValidity(string &name, string userName[], int &userCount);
bool passwordValidity(string &password);
bool checkRoomNumberValidity(string &room, string roomNumber[], int &studentIndex);
void studentRegistration(string name, string password, string role, int &studentIndex, string roomNumber[],string &room);
void whatIfRoomIsValid(bool check, int &studentIndex);
bool checkManager();
bool checkStudentIndex(int &studentIndex);
bool checkNewUserName(string &newUserName, string userName[], int &currentStudent);
bool intValidations(string code);


                                                            //setColor//
string setcolor(unsigned short color);
                                                             //press Me To Move On//
void breakTime();
                                                            //managerEnd//
int ManagerfirstPage();
int callingManagerMenu(int days, int budget, int things, int studentIndex, int bill, int profit, string complaintBox[], int &currentStudent, string date[], string votedMenu[]);
int Managermenu();
void functionalityOfManager(int &days, int &budget, int &things, int &studentIndex, int &bill, int &profit, string complaintBox[], int &currentStudent, string date[], string votedMenu[]);
void create(string menulunch[], string menuDinner[], int budgetlunch[], int budgetDinner[], int days, int &budget, int things, int studentIndex, int &bill, int &profit, string complaintBox[], int &currentStudent, string date[], string VotedMenu[]);
void viewMenu(string menulunch[], string menuDinner[], int days, int budget, int things, int studentIndex, int bill, int profit, string complaintBox[], int &currentStudent, string date[], string votedMenu[]);
void callAddStock(int &things);
void addStock(string stock[], int quantity[], int &things, int bill, int profit);
void viewStock(string stock[],int quantity[], int things);
int makeBill(int &budget, int studentIndex, int &bill, int profit);
void viewStudentVotedMenu(string date[], string votedMenu[], int currentStudent);
void viewComplaints(string complaintBox[], int studentIndex);
int calculateProfit(int bill, int profit);
                                                    //student End//
int functionalityOfStudent(string offDate[], string offMonth[],int &days, int currentStudent,int &bill, string date[], string votedMenu[], string complaintBox[], string userName[], string userPassword[]);
int studentFirstPage();
void addAttendence(string offDate[], string offMonth[],int days, int currentStudent, int bill);
void updateAttendence(string offDates[], string offMonths[], int &days, int currentStudent, int bill);
void viewAttendence(string offDates[], string offMonths[], int days, int currentStudent, int bill);
int checkBill(int &bill, string offDate[], string offMonth[], int days, int currentStudent);
void studentVotedMenu(string date[], string votedMenu[], int curentStudent);
void editStudentAccount(int currentStudent, string userName[], string userPassword[]);
void studentsComplaint(string complaintBox[], int currentStudent);
void editUserPassword(string &newUserName, string userName[], int currentStudent, string userPassword[], string choice, string &confirmPassword, string &password);
void editUserName(string &newUserName, string userName[], int currentStudent, string userPassword[], string choice);
                                                            //File Handlings//
                                                            //STORE FUNCTIONS//
void storeSignIn(string userName[], string userPassword[], string userRole[], string fileName, int &userCount);
string getField(string record, int order);
                                                            //LOAD FUNCTIONS//
void loadSignIn(string userName[], string userPassword[], string userRole[], string fileName, int &userCount);
main()
{
    int studentIndex = 0;
    int userCount = 0;
    int userNum=500;
    int currentStudent;
    string userName[userNum];
    string userPassword[userNum];
    string userRole[userNum];
    string roomNumber[userNum];
    string offDate[300];
    string offMonth[300];
    string updateDays[100];
    string updateMonths[100];
    string toUpdateDays[100];
    string toUpdateMonths[100];
    int bill, profit;
    string fileName = "signIn.txt";
    string date[100], 
    votedMenu[100];
    string complaintBox[100];
    string room;
    string name, password, role;
    int days;
    string offDates;
    int option;
    string inputName, inputPassword;
    int  budget, things;
     loadSignIn( userName,  userPassword,  userRole,  fileName, userCount);
        
    
    
    while(option!=3)
    {    header();
        option = loginPage();
       
        if(option == 1)
        {   
            
            signUpCredentials(name,password,role,userName,userPassword,userRole,userCount,roomNumber,room,studentIndex);
            // bool check = 
            bool check = signUp(name, password, role, userName, userPassword, userRole, userCount);
            {if(check==true)

            {   if(role == "Student")
               { setcolor(12);
                   
                    cout<<setw(70)<<"Enter your room number: ";
                    cin>>room;
                    // if(room != "1" && room != "2" && room != "3" && room != "4" && room != "5" && room != "6" && room != "7" && room != "8" && room != "9" && room != "0")
                    // {
                    //     cout<<setw(70)<<"Please Enter a Valid room Number!";
                    //     breakTime();
                        
                    //     continue;
                    // }
                studentRegistration(name, password, role, studentIndex,roomNumber,room);
              
                }
                setcolor(15);
                cout<<setw(100)<<"You Have Signed Up SuccesFully!:)"<<endl;
                cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
                happyFace();
                breakTime();
            }}
             if(check == false)
            {
                cout<<setw(70)<<"User Name Already Exists:]"<<endl;
               sadFace();
               breakTime();
            }  
            
         
        }
        if(option == 2)
        {   signInHeader();
            setcolor(7);
            
            cout<<setw(70)<<"Enter your user Name: ";
            cin>>inputName;
            cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
            cout<<setw(70)<<"Enter your  Password: ";
            cin>>inputPassword;
            cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
            bool isValid = signInValidity(inputName, inputPassword, userName, userPassword, userCount, currentStudent);
            string role;
            
            if(isValid == true)
            {   role = signIn(inputName, inputPassword, userName, userPassword, userRole, userCount);
                
            }
            else if(isValid == false)
            {
                cout<<setw(70)<<"Invalid Credentials :>"<<endl;
                cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
                breakTime();
            }
            if(role == "Manager")
            {   
                bool find = checkManager();
                if(find == true)
                {   cout<<setw(100)<<"You Have Succesfully logged in as a Manager ";
                happyFace();
                breakTime();
                    functionalityOfManager(days, budget, things, studentIndex, bill, profit, complaintBox,currentStudent, date, votedMenu);
                }
                if(find == false)
                {
                    cout<<setw(70)<<"Manager not Found:o"<<endl;
                    sadFace();
                    breakTime();
                }
                
                
            }
            else if(role == "Student")
            {  
                
                cout<<setw(70)<<"You Have Succesfully logged in as a Student "<<endl;
                breakTime();
                functionalityOfStudent(offDate, offMonth,days, currentStudent, bill, date, votedMenu, complaintBox,userName, userPassword);
            }
            
        }
        if(option <1 || option>3)
        {
            cout<<setw(70)<<"Please Enter a Valid Option!";
            sadFace();
            breakTime();
        }
        if(option == 3)
        {
            storeSignIn(userName,userPassword,  userRole, fileName,userCount);
            break;
        }
    }
}            
void header()
{
   setcolor(3); 
cout<<R"(
 __  __                   __  __                                                            _      _____              _                    
|  \/  |                 |  \/  |                                                          | |    / ____|            | |                   
| \  / |  ___  ___  ___  | \  / |  __ _  _ __    __ _   __ _   ___  _ __ ___    ___  _ __  | |_  | (___   _   _  ___ | |_   ___  _ __ ___  
| |\/| | / _ \/ __|/ __| | |\/| | / _` || '_ \  / _` | / _` | / _ \| '_ ` _ \  / _ \| '_ \ | __|  \___ \ | | | |/ __|| __| / _ \| '_ ` _ \ 
| |  | ||  __/\__ \\__ \ | |  | || (_| || | | || (_| || (_| ||  __/| | | | | ||  __/| | | || |_   ____) || |_| |\__ \| |_ |  __/| | | | | |
|_|  |_| \___||___/|___/ |_|  |_| \__,_||_| |_| \__,_| \__, | \___||_| |_| |_| \___||_| |_| \__| |_____/  \__, ||___/ \__| \___||_| |_| |_|
                                                        __/ |                                              __/ |                           
                                                       |___/                                              |___/                            

)";
cout<<endl;


}
void logInPageHeader()
{
    setcolor(1);
cout<<setw(100)<<R"(    
                        #                     ###                 ####                       
                        #                      #                  #   #                      
                        #       ###    ## #    #    # ##          #   #   ###    ## #   ###  
                        #      #   #  #  #     #    ##  #         ####       #  #  #   #   # 
                        #      #   #   ##      #    #   #         #       ####   ##    ##### 
                        #      #   #  #        #    #   #         #      #   #  #      #     
                        #####   ###    ###    ###   #   #         #       ####   ###    ###  
                                      #   #                                     #   #        
                                        ###                                       ###         
)";
cout<<endl;

}
void sadFace()
{cout<<setw(100)<<R"( 
                            .-=+****+=-.         
                          :*@%*=-::::-=*%@*-      
                        -%%=.            .=%%=    
                      .#@-                  -@%.  
                     .@%.     .        .     .%@. 
                     #@.    .@@@:    .@@@.    .@% 
                    :@+      =*=      =*=      +@:
                    -@=                        -@=
                    :@+       -*%@%%@%*-       +@:
                    %@.    =@#-.     -#@=     @% 
                    .@%.   *=          -*    %@. 
                      .%@-                  -@%.  
                        =%%=.             =%@=    
                          -*@%*=-:..:-=+%@*-      
                            .-=+*##**=-.         
)";
cout<<endl;
}
void happyFace()
{   cout<<setw(100)<<R"(
                                                         ..              
                                                    .:::....:::.         
                                                   -.          .-        
                                                  =   .%:  :%.   =       
                                                 =     :    .     =      
                                                 =   :        :   =      
                                                 .:  .-      ::  ::      
                                                  ::   ::::::   ::       
                                                   ::.      .::         
                                                     .::::::.           
)";
cout<<endl;
}
void signUpHeader()
{
    setcolor(7);
 cout<<setw(100)<<R"(   
                                        #                            
                                     
                                 ###   ##     ###  ###   #  #  ###   
                                ##      #    #  #  #  #  #  #  #  #  
                                  ##    #     ##   #  #  #  #  #  #  
                                ###    ###   #     #  #   ###  ###   
                                              ###              #     
)";
cout<<endl;
}
void signInHeader()
{   system("cls");
    header();
    setcolor(7);
    cout<<setw(100)<<R"(
                                                #                 #          
                                     
                                         ###   ##     ###  ###   ##    ###   
                                        ##      #    #  #  #  #   #    #  #  
                                          ##    #     ##   #  #   #    #  #  
                                        ###    ###   #     #  #  ###   #  #  
                                                      ###                    

    )";
    cout<<endl;
}
void managerPage()
{system("cls");
    header();
    setcolor(3);
    cout<<R"(
                                                #  #                                      
                                                ####                                      
                                                ####   ###  ###    ###   ###   ##   ###   
                                                #  #  #  #  #  #  #  #  #  #  # ##  #  #  
                                                #  #  # ##  #  #  # ##   ##   ##    #     
                                                #  #   # #  #  #   # #  #      ##   #     
                                                                         ###              

    )";
    cout<<endl;
}
void studentHeader()
{
    system("cls");
    header();
    setcolor(10);
    cout<<R"(
                                                ##    #             #               #    
                                               #  #   #             #               #    
                                                #    ###   #  #   ###   ##   ###   ###   
                                                 #    #    #  #  #  #  # ##  #  #   #    
                                               #  #   #    #  #  #  #  ##    #  #   #    
                                                ##     ##   ###   ###   ##   #  #    ##  
                                          

    )";
    cout<<endl;
}
string setcolor(unsigned short color)
{
        HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hcon, color);
        return"";
}
int loginPage()
{
    system("cls");
    header();
    logInPageHeader();
    int op;
    setcolor(12);
    cout<<setw(70)<<"1. Sign Up         "<<endl;
     cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"2. Sign In         "<<endl;
     cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"3. Exit            "<<endl;
     cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(80)<<"Enter your Option: ";
    cin>>op;
     cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    return op;
}
bool signUpCredentials(string &name, string &password, string &role, string userName[], string userPasword[], string userRole[], int &userCount, string roomNumber[], string &room, int &studentIndex)
{           setcolor(12);
            system("cls");
            header();
            signUpHeader();
            cout<<setw(70)<<"Enter your Name(alphabets only): ";
            cin>>name;
             cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
           bool check = nameValidity(name);
           bool isValid;
           
           
                if(check == true)
            {
                cout<<setw(70)<<"Invalid UserName! :o"<<endl;
                sadFace();
                breakTime();
                signUpCredentials(name,password,role,userName,userPasword,userRole,userCount,roomNumber,room,studentIndex);
            }
            if(check == false)
            {
                cout<<setw(85)<<"Enter your Password(must have 8 characters): ";
            cin>>password;
             cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
            }
             isValid = passwordValidity(password);
            
             if(isValid == false)
            {
                cout<<setw(70)<<"InValid Password! :o"<<endl;
                sadFace();
                breakTime();
                signUpCredentials(name,password,role,userName,userPasword,userRole,userCount,roomNumber,room,studentIndex );
            }
            if(isValid == true)
            {
                cout<<setw(85)<<"Enter your role(Manager or Student): ";
                cin>>role;
                 cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
                 if(role!="Manager" && role!="Student")
                 {
                    cout<<setw(70)<<"Please Enter a valid role!";
                    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
                    breakTime();
                signUpCredentials(name,password,role,userName,userPasword,userRole,userCount,roomNumber,room,studentIndex );
                 }
            }
            
            
           
            return true;
           
           
               

            
            
}
bool nameValidity(string &name)
{   bool flag = false;
    for(int i = 0; name[i]!='\0'; i++)
    {
        if(name[i]=='1'|| name[i]=='2'|| name[i]=='3' ||  name[i]=='4' ||  name[i]=='5' ||  name[i]=='6' ||  name[i]=='7' ||  name[i]=='8' ||  name[i]=='9'||  name[i]=='0')
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool passwordValidity(string &password)
{   int count=0;
    bool flag = true;
    for(int i = 0; password[i]!='\0'; i++)
    {
        count++;
    }
    
    if(count<8)
    {
        flag = false;
    }
    return flag;
}
bool signUp(string &name, string &password, string &role, string userName[], string userPassword[],string userRole[], int &userCount)
{
    //check if user name not entered and then add them in the array
    if(!checkValidity(name, userName, userCount))
    {
        userName[userCount]=name;           //add name and password in the array
        userPassword[userCount]=password;
        userRole[userCount]=role;
        userCount++;
        return true;
    }
    return false;
}
bool checkValidity(string &name, string userName[], int &userCount)
{bool isValid = false;
    for(int i = 0; i<userCount; i++)
    {
        if(name == userName[i])
        {
            isValid = true;
        }
    }
    return isValid;
}
void studentRegistration(string name, string password, string role, int &studentIndex, string roomNumber[], string &room)
{   
    bool check = checkRoomNumberValidity(room, roomNumber, studentIndex);
   cout<<check;
    whatIfRoomIsValid(check, studentIndex);
    
   

}
bool intValidations(string code)
{
     {
         bool flag = false;
         int i = 0;
         while (i < code.length())
         {
            
             if (code[i] > 47 && code[i] < 58)
             {
                 i++;
                 flag = true;
             }
             else
             {
                 flag = false;
                 cout<<"Please Enter an Integer!";
                 breakTime();
                 break;
             }
         }
         return flag;
}
}
bool checkRoomNumberValidity(string &room, string roomNumber[], int &studentIndex)
{   int count = 0;
    bool flag = true;
    for(int i=0; i<studentIndex; i++)
    {
        if(room == roomNumber[i])
        {
            count++;
        }  
    }
    if(count>3)
    {
        flag = false;
    }
    return flag;
}
void breakTime()
{       setcolor(7); 
        cout<<setw(70)<<"Press any key to continue....";
        getch();
}
void whatIfRoomIsValid(bool check, int &studentIndex)
{
    if(check == true)
    {
        studentIndex++;
        cout<<setw(70)<<"You have signed up as "<<studentIndex<<" student."<<endl;
        
    }
    else if(check == false)
    {
        cout<<setw(70)<<"Enter a valid room Number: "<<endl;
        sadFace();
        breakTime();
    }
}
                                                //SIGNIN//
bool signInValidity(string &InputName, string &InputPassword, string userName[], string userPassword[], int &userCount, int &currentStudent)
{
    bool flag = false;
    for(int i = 0; i<userCount; i++)
    {
        if(InputName==userName[i] && InputPassword == userPassword[i])
        {
            flag = true;
            currentStudent = i;
            break;
        }
    }
    return flag;
}
string signIn(string &InputName, string &InputPassword, string userName[], string userPassword[], string userRole[], int &userCount)
{
    for(int i = 0; i<userCount; i++)
        {
            if(InputName == userName[i] && InputPassword == userPassword[i])
            {
                return userRole[i];
            }
        }
}
bool checkManager()
{   string superPassword;
    cout<<setw(70)<<"What is the Super Password: ";
    cin>>superPassword;
    if(superPassword == "12345678")
    {
        return true;
    }
}
                                            //ManagerEnd//
void functionalityOfManager(int &days, int &budget, int &things, int &studentIndex, int &bill, int &profit, string complaintBox[], int &currentStudent, string date[], string votedMenu[])

{
    int op;
    while(op != 8)
    {           managerPage();
                op = ManagerfirstPage();
                if(op == 1)
                {
                    callingManagerMenu(days, budget, things, studentIndex, bill, profit, complaintBox, currentStudent, date, votedMenu);
                   
                }
    
                else if(op == 2){
                    system("cls");

                    header();
                    managerPage();
                    setcolor(7);
                    callAddStock(things);
                    string stock[things];
                    int quantity[things];
                    addStock(stock, quantity, things, bill, profit);
                   
                }
                else if(op == 3)
                {
                    cout<<setw(70)<<"Please Enter Stock First!";
                    breakTime();
                }
    
                else if( op == 8)
                {
                    break;
                }
    

                else if(op == 5)
                {   
                    system("cls");
                    header();
                    managerPage();
                    setcolor(7);
                     bill = makeBill(budget, studentIndex, bill, profit);
                    
                    cout<<setw(70)<<"Your Bill per each student is: "<<bill<<endl;
                     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
                    breakTime();
                   
                }
    
                else if(op == 6)
                {   system("cls");
                    header();
                    managerPage();
                    setcolor(7);
                    cout<<setw(70)<<"Enter your Profit Margin: ";
                    cin>>profit;
                     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
                    cout<<setw(70)<<"Your Profit is "<<calculateProfit(bill, profit)<<" per each student"<<endl;
                    breakTime();
                   cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
                   
                }
    
                else if(op == 7)
                {   system("cls");
                    header();
                    managerPage();
                    setcolor(7);
                    viewComplaints(complaintBox, currentStudent);
                    breakTime();
                }
                else if(op == 4)
                {   system("cls");
                    header();
                    managerPage();
                    setcolor(7);
                    bool anotherCheck = checkStudentIndex(studentIndex);
                    {
                        if(anotherCheck == true)
                        {
                            viewStudentVotedMenu(date,votedMenu, currentStudent);
                            breakTime();
                        }
                        else
                        {
                                cout<<setw(70)<<"No Votes!";
                            cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
                            breakTime();
                        }
                    }
                    
                }
                if(op<1 || op>8)
                {
                    system("cls");
                    header();
                    managerPage();
                    setcolor(7);
                    cout<<setw(70)<<"Please Enter a Valid Option!"<<endl;
                    sadFace();
                    breakTime();
                    functionalityOfManager(days, budget, things, studentIndex, bill, profit, complaintBox,currentStudent, date, votedMenu);
                }
    }
    
}
int ManagerfirstPage()
{   system("cls");
    header();
    managerPage();
    setcolor(7);
    int option;
    
    cout<<setw(70)<<"1. MENU                      "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"2. ADD STOCK                 "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"3. VIEW STOCK                "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"4. VIEW VOTES                "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"5. BILLING                   "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"6. PROFIT                    "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"7. COMPLAINTS                "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"8. LOG OUT                   "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    
    cout<<setw(70)<<"#Your Options:               ";
    cin>>option;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    return option;
}
int callingManagerMenu(int days, int budget, int things, int studentIndex, int bill, int profit, string complaintBox[], int &currentStudent, string date[], string votedMenu[])

{
             string day;  
                 int choice =  Managermenu();  
                 if(choice==1){
                    system("cls");
                    managerPage();
                    
                    setcolor(7);
                    cout<<setw(70)<<"Enter the number of days for which you want to enter the menu: ";
                    cin>>day;
                    bool check = intValidations(day);
                    if(check == true)
                    {   days = 0;
                        days += stoi(day);
                    }
                     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
                    }
                    string menulunch[days];
                     string menuDinner[days];
                     int budgetlunch[days];
                      int budgetDinner[days];
                     if(choice == 1){

                    create(menulunch, menuDinner, budgetlunch, budgetDinner, days, budget, things, studentIndex, bill, profit, complaintBox,currentStudent, date, votedMenu);
        
                       }
                else if(choice == 2)
                   {
                        
                        return choice;
                   }
                
                
                if(choice == 3)
                         {
                            functionalityOfManager(days, budget, things, studentIndex, bill, profit, complaintBox, currentStudent, date, votedMenu);
                         }
                if(choice<1 ||choice>3)
                {   system("cls");
                    header();
                    managerPage();
                    setcolor(7);
                    cout<<setw(70)<<"Please Enter a Valid Option!"<<endl;
                    sadFace();
                    breakTime();

                    callingManagerMenu(days, budget, things, studentIndex, bill, profit, complaintBox, currentStudent, date, votedMenu);
                }         
                        
}
int Managermenu()
{   system("cls");
    header();
    managerPage();
    setcolor(7);
    int option;
  
    cout<<setw(70)<<"1.CREATE MENU                                     "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"2.VIEW MENU                                       "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"3.EXIT                                            "<<endl;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"Your Option:                                      ";
    cin>>option;
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    return option;
}
void create(string menulunch[], string menuDinner[], int budgetlunch[], int budgetDinner[], int days, int &budget, int things, int studentIndex, int &bill, int &profit, string complaintBox[], int &currentStudent, string date[], string votedMenu[])
{    
    string lunchbudget, dinnerbudget;   
    for(int i = 0; i<days; i++)
    {
        cout<<setw(70)<<"Menu for Day "<<i+1 <<" Lunch: ";
    cin.clear();
    cin.sync();    
    // cin.ignore();
    getline(cin, menulunch[i]);
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"Menu for Day "<<i+1<<" dinner: ";
    cin.clear();
    cin.sync(); 
    // cin.ignore();
    getline(cin, menuDinner[i]);
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"Enter budget for Day "<<i+1<<" Lunch: ";
    cin>>lunchbudget;
    bool check = intValidations(lunchbudget);
    if(check == true)
    {
        budgetlunch[i] = stoi(lunchbudget);
    }
    if(check == false)
    {       days = 0;
    //    create(menulunch, menuDinner, budgetlunch, budgetDinner, days, budget, things, studentIndex, bill, profit, complaintBox,currentStudent, date, votedMenu);
         callingManagerMenu(days, budget, things, studentIndex, bill, profit, complaintBox, currentStudent, date, votedMenu);
    }
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"Enter budget for Day "<<i+1<<" Dinner: ";
    cin>>dinnerbudget;
    bool valid = intValidations(dinnerbudget);
    if(valid == true)
    {
        budgetDinner[i] = stoi(dinnerbudget);
    }
    if(valid == false)
    {   days = 0;
        // create(menulunch, menuDinner, budgetlunch, budgetDinner, days, budget, things, studentIndex, bill, profit, complaintBox,currentStudent, date, votedMenu);
        callingManagerMenu(days, budget, things, studentIndex, bill, profit, complaintBox, currentStudent, date, votedMenu);
    }
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    budget = budgetlunch[i]+budgetDinner[i];
    
    
    }
    breakTime();
    // storeMenucreatedByManager(menulunch,menuDinner,budgetlunch, budgetDinner, days, fileName);
    int op = callingManagerMenu(days, budget, things, studentIndex, bill, profit, complaintBox,currentStudent, date, votedMenu);
    if(op == 2)
    {
         viewMenu(menulunch, menuDinner, days, budget, things, studentIndex, bill , profit, complaintBox, currentStudent, date, votedMenu);
        
    }
}
void viewMenu(string menulunch[], string menuDinner[], int days, int budget, int things, int studentIndex, int bill, int profit, string complaintBox[], int &currentStudent, string date[], string votedMenu[])
{   system("cls");
    header();
    managerPage();
    setcolor(7);
    int choice;
      cout<<setw(70)<<"Day \t"<<"\t"<<"LUNCH \t"<<"\t"<<" DINNER"<<endl;
      cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    for(int i = 0 ; i<days; i++)
    {
      
        cout<<setw(70)<<"Day "<<i+1<<"\t \t"<<menulunch[i]<<" \t \t"<<menuDinner[i]<<endl;
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;

    } 
    breakTime();
    callingManagerMenu(days, budget, things, studentIndex, bill, profit,complaintBox, currentStudent, date, votedMenu);
    
    
}
void callAddStock(int &things)
{   things = 0;
    string thing; 
    cout<<setw(70)<<"Enter the Number of things you want to add to the stock: ";
    cin>>thing;
    bool check = intValidations(thing);
    if(check == true)
    {
        things+=stoi(thing);
    }
    if(check == false)
    {
        things = 0;
        callAddStock(things);
    }
     cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
}
void addStock(string stock[], int quantity[], int &things, int bill, int profit)
{   string quant;
    for(int i = 0; i<things; i++)
    {
        cout<<setw(70)<<"Enter the things you want to order: ";
        cin>>stock[i];
         cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        cout<<setw(70)<<"Enter the quantity of these things(in kgs): ";
        cin>>quant;
        bool check = intValidations(quant);
        if(check == true)
        {
            quantity[i]=stoi(quant);        
         cout<<setw(70)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        
        }
        
    }
     breakTime();
    int op = ManagerfirstPage();
    {
        if(op == 3)
        {
            viewStock(stock, quantity, things );
        }
    }
}
void viewStock(string stock[],int quantity[], int things)
{   managerPage();
    setcolor(7);
    cout<<setw(80)<< "no. stock"<<"\t \t"<<"quantity(kg)"<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    for(int i = 0 ; i<things; i++)
    {
        cout<<setw(70)<< i+1 <<". "<<stock[i]<<"\t \t"<<quantity[i]<<"kg"<<endl;
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    }
    breakTime();

}
int makeBill(int &budget, int studentIndex, int &bill, int profit)
{    
    if(checkStudentIndex(studentIndex))
{
    bill = budget/studentIndex;
}
    else{
        bill=0;
    }
    
    return bill;
}
int calculateProfit(int bill, int profit)
{
    int prof ;
    prof = (bill*profit)/100;
    return prof;
}
                            //Both Student and Manager Related//
void viewComplaints(string complaintBox[], int studentIndex)
{   bool flag = checkStudentIndex(studentIndex);
if(flag == true)
    {
        cout<<setw(70)<<"studentIndex"<<"\t \t"<<"complaints"<<endl;
      cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    for(int i = 0; i<studentIndex; i++)
    {
        cout<<setw(70)<<studentIndex<<"\t \t"<<complaintBox[i]<<endl;
          cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    }
    }
    if(flag == false)
    {
        cout<<setw(70)<<"No Complaints!";
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    }
}
void viewStudentVotedMenu(string date[], string votedMenu[], int currentStudent)
{   cout<<setw(70)<<"\t \t "<<"current Student"<<"\t \t "<<"date"<<"\t \t "<<"voted Menu"<<endl;
  cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    for(int i = 0; i<currentStudent; i++)
    {
        cout<<setw(70)<<"\t \t "<<currentStudent<<"\t \t "<<date[i]<<"\t \t "<<votedMenu[i]<<endl;
          cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    }
}
bool checkStudentIndex(int &studentIndex)
{
    if(studentIndex == 0)
    {
        cout<<setw(70)<<"No Student Is Present! ";
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        return false;
    }
    return true;
}
                                        //Student End//
int functionalityOfStudent(string offDate[], string offMonth[],int &days, int currentStudent,int &bill, string date[], string votedMenu[], string complaintBox[], string userName[], string userPassword[])
{   string day;
    int option;
    days = 0;
    while(option != 9)
    {   studentHeader();
        option = studentFirstPage();
    if(option == 1)
    {
        system("cls");
        header();
        studentHeader();
        setcolor(15);
        cout<<setw(70)<<"How many days you want to off: ";
        cin>>day;
        bool check=intValidations(day);
        
         cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
         if(check == true)
         {
            days += stoi(day);
            addAttendence(offDate, offMonth,days, currentStudent, bill);
         }
         
        
     
    }
    if(option == 2)
    {
        system("cls");
        header();
        studentHeader();
        setcolor(15);
        updateAttendence(offDate, offMonth ,  days,  currentStudent, bill);
    }
    if(option == 3)
    {    system("cls");
        header();
        studentHeader();
        setcolor(15);
        viewAttendence(offDate, offMonth, days, currentStudent, bill);
        
    }
    if(option == 4)
    {    system("cls");
        header();
        studentHeader();
        setcolor(15);
        cout<<setw(70)<<" Your bill is "<<checkBill(bill, offDate, offMonth, days, currentStudent);
        
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        breakTime();
    }
    else if(option == 5)
    {
        system("cls");
        header();
        studentHeader();
        setcolor(15);
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        cout<<setw(70)<<"Coming Soon"<<endl;
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        cout<<setw(70)<<"Development work under process! :)";
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        breakTime();
    }
    if(option == 6)
    {    system("cls");
        header();
        studentHeader();
        setcolor(15);
        studentVotedMenu(date, votedMenu, currentStudent);
        breakTime();
    }
    else if(option == 7)
    {   system("cls");
        header();
        studentHeader();
        setcolor(15);
        studentsComplaint(complaintBox, currentStudent);
        breakTime();
    }
    else if(option == 8)
    {   system("cls");
        header();
        studentHeader();
        setcolor(15);
        editStudentAccount(currentStudent, userName, userPassword);
    }
    else if( option<1 || option>9)
    {
        system("cls");
        header();
        studentHeader();
        setcolor(15);
        cout<<setw(70)<<"Please Enter a Valid Option!";
        breakTime();
    
    }
    
    
}
}
int studentFirstPage()
{
    system("cls");
    header();
    studentHeader();
    setcolor(14);
    
    int op;
    cout<<setw(70)<<"1. ADD MESS ATTENDENCE        "<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"2. UPDATE MESS ATTENDENCE     "<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"3. VIEW MESS ATTENDENCE       "<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"4. CHECK BILL                 "<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"5. PAY BILL                   "<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"6. VOTE FOR MENU              "<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"7. COMPLAINT                  "<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"8. EDIT ACCOUNT               "<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"9. LOG OUT                    "<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"CHOOSE YOUR OPTION:           ";
    cin>>op;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    return op;
}
void addAttendence(string offDate[], string offMonth[],int days, int currentStudent, int bill)
{   string startDate;
    string endDate;
    cout<<setw(70)<<"From which date you want to off: ";
    cin.clear();
    cin.sync(); 
    // cin.ignore();
    getline(cin, offDate[currentStudent]);
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"To Which date you want to off: ";
    cin.clear();
    cin.sync(); 
    // cin.ignore();
    getline(cin,offMonth[currentStudent] );
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    breakTime();
 


}
void updateAttendence(string offDates[], string offMonths[], int &days, int currentStudent, int bill)
{
    
    string day;
    cout<<setw(70)<<"Now how many days you want to update: ";
    cin>>day;
    bool check=intValidations(day);
    if(check == true)
         {  days = 0;
            days += stoi(day);
          cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"Enter the starting date: ";
    cin.clear();
    cin.sync(); 
    // cin.ignore();
    getline(cin, offDates[currentStudent]);
     cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<"Enter the ending date: ";
    cin.clear();
    cin.sync(); 
    // cin.ignore();
    getline(cin, offMonths[currentStudent]);
     cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    breakTime();  
         }
     if (check == false)    
     {
        days = 0;
        system("cls");
        header();
        studentHeader();
        setcolor(15);
        updateAttendence(offDates, offMonths, days, currentStudent, bill);
     }
     
    
    

    
}
void viewAttendence(string offDates[], string offMonths[], int days, int currentStudent, int bill)
{   
    cout<<setw(70)<<"Days Off"<<"\t \t"<<"Starting Date"<<"\t \t"<<"Starting Month"<<endl;
    cout<<setw(120)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<setw(70)<<days<<"\t \t"<<offDates[currentStudent]<<"\t \t"<<offMonths[currentStudent]<<"\t \t"<<endl;
    cout<<setw(120)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    breakTime();

}

int checkBill(int &bill, string offDate[], string offMonth[], int days, int currentStudent)
{   
    int mybill = bill;
    if(mybill<0)
    {
        mybill = 0;
    }
    return mybill;
}
void studentVotedMenu(string date[], string votedMenu[], int curentStudent)
{
        cout<<setw(70)<<"Enter the Date for which you want to vote: ";
        cin.clear();
        cin.sync(); 
        // cin.ignore();
        getline(cin, date[curentStudent]);
         cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        cout<<setw(70)<<"Enter the Menu you want for this date: ";
        cin.clear();
        cin.sync(); 
        // cin.ignore();
        getline(cin, votedMenu[curentStudent]);
         cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
}
void studentsComplaint(string complaintBox[], int currentStudent)
{   string complaint;
    cout<<setw(70)<<"How Can I Help You: ";
    cin.clear();
    cin.sync(); 
    // cin.ignore();
    getline(cin, complaint);
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    complaintBox[currentStudent]=complaint;
    cout<<setw(80)<<"Thank you for cooperating we will try our best to solve your problem!"<<endl;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
}
void editStudentAccount(int currentStudent, string userName[], string userPassword[])
{   system("cls");
        header();
        studentHeader();
        setcolor(15);
    string choice;
    string password;
    string confirmPassword;
    string newUserName;
    
        editUserName(newUserName, userName, currentStudent, userPassword, choice);
        editUserPassword(newUserName, userName, currentStudent, userPassword, choice, confirmPassword, password);
}

bool checkNewUserName(string &newUserName, string userName[], int &currentStudent)
{
    if(!checkValidity(newUserName, userName, currentStudent))
    if(newUserName == userName[currentStudent])
    {
        return true;
    }
    return false;
}
void editUserName(string &newUserName, string userName[], int currentStudent, string userPassword[], string choice)
{   cout<<setw(70)<<"Do you want to change userName(yes or no): ";
     cin>>choice;
      if(choice == "yes")
     {
    cout<<setw(70)<<"Enter your new userName: ";
        cin>>newUserName;
        
            bool flag = checkNewUserName(newUserName, userName, currentStudent);
            if(flag == true)
            {
                cout<<setw(70)<<"Please Enter a New User Name "<<endl;
                breakTime();
                editStudentAccount(currentStudent, userName, userPassword);
            }
            else if(flag == false)
            {
             userName[currentStudent]=newUserName;   
            }
        

        
        
         cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    
     }
    else if(choice == "no")
    {
        cout<<setw(70)<<"User Name is Same!"<<endl;
         cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    }
    else if(choice != "yes" && choice !="no")
     {
        cout<<setw(70)<<"Please yes or no only!";
        breakTime();
        editStudentAccount(currentStudent, userName, userPassword);
    }
}
void editUserPassword(string &newUserName, string userName[], int currentStudent, string userPassword[], string choice, string &confirmPassword, string &password)
{
    cout<<setw(70)<<"Do you want to change user Password(yes, no): ";
    cin>>choice;
    cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
    if(choice == "yes")
    {
        cout<<setw(70)<<"Enter your new password: ";
        cin>>password;
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        cout<<setw(70)<<"Confirm your password: ";
        cin>>confirmPassword;
        cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        cout<<setw(70)<<"Account Updated SuccesFully!"<<endl;
         breakTime();
        if(password == confirmPassword)
        {
            userPassword[currentStudent]=password;
        }
        else
        {
            cout<<setw(70)<<"Password MissMatch :o"<<endl;
            cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
        }
    }
    if(choice == "no")
    {
        cout<<setw(70)<<"PASSWORD IS SAME!"<<endl;
         cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
         breakTime();
    }
    else if(choice != "yes" && choice !="no")
     {
        cout<<setw(70)<<"Please yes or no only!";
        breakTime();
        // editStudentAccount(currentStudent, userName, userPassword);
    }
    

}
// void payBill()
// {   int choice;
// string userAccountNumber;
// int amount;
//     cout<<setw(70)<<"How would you like to pay Bill"<<endl;
//     cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
//     cout<<setw(70)<<"1. EasyPaisa ";
//     cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
//     cout<<setw(70)<<"2. JazzCash ";
//     cout<<setw(100)<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
//     cin>>choice;
//     if(choice == 1)
//     {
//         cout<<setw(70)<<"Enter your account number (11 numbers): ";
//         cin>>userAccountNumber;
//         bool valid = isUserAccountNumberValid(userAccountNumber);
//         if(valid == false)
//         {
//             cout<<setw(70)<<"Enter a Valid Account Number";
//         }
//         cout<<setw(70)<<"The Amount you want to pay: ";
//         cin>>amount;
//         bill = 0;
//         cout<<setw(70)<<"Your Bill Has Been Payed:";
//     }
// }
// bool isUserAccountNumberValid(string userAccountNumber)
// {   int count = 0;
//     for(int i = 0; userAccountNumber[i]!='\0'; i++)
//     {
//         count++;
//     }
//     if(count<11)
//     {
//         return false;
//     }
//     return true;
// }
                                                        //File Handlings//
void storeSignIn(string userName[], string userPassword[], string userRole[], string fileName, int &userCount)
{
    fstream signIn;
    signIn.open(fileName, ios:: out);
    for(int i = 0; i<userCount; i++)
    {
        if (i == userCount - 1) // last iteration so no new line
            signIn<<userName[i]<<","<<userPassword[i]<<","<<userRole[i];
        else
            signIn<<userName[i]<<","<<userPassword[i]<<","<<userRole[i]<<'\n';
    }
    signIn.close();
}
void loadSignIn(string userName[], string userPassword[], string userRole[], string fileName, int &userCount)
{
    string line = "";
    fstream file;
    file.open(fileName, ios::in);
    while(!file.eof())
    { 
        getline(file, line);
        userName[userCount] = getField(line, 1);
        userPassword[userCount] = getField(line, 2);
        userRole[userCount] = getField(line, 3);
        userCount++;
    }
    file.close();
}
string getField(string record, int order)
{
    int count = 1;
    string line= "";
    for(int x =0; x<record.length(); x++)
    {
        if(record[x] == ',')
        {
            count++;
        }
        else if(count == order)
        {
            line = line + record[x];
        }
    }
    return line;
}
// void storeMenucreatedByManager(string menulunch[], string menuDinner[], int budgetlunch[], int budgetDinner[], int &days, string fileName)
// {
//     string line;
//     fstream managerMenu;
//     managerMenu.open(fileName, ios:: out);
//     for(int i = 0; i<days; i++)
//     {
//         managerMenu<<menulunch[i]<<","<<menuDinner[i]<<","<<budgetlunch[i]<<","<<budgetDinner[i]<<endl;
//     }
//     managerMenu.close();
// }
// void loadMenuCreatedByManager(string menulunch[], string menuDinner[], int budgetlunch[], int budgetDinner[], int &days, string fileName)
// {       int x = 0;
//      string line;
//     fstream file;
//     file.open(fileName, ios::in);
//     while(!file.eof())
//     {   if(line !="")
//     {
//          getline(file, line);
//         menulunch[x] = getMenu(line, 1);
//         menuDinner[x] = getMenu(line, 2);
//         budgetlunch[x] = getMenu(line, 3);
//         budgetDinner[x] = getMenu(line, 4);
//     }
       
//     }
// }
