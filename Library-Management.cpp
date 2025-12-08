#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<windows.h>
using namespace std;
void printHeader();
void userheader();
void adminheader();
void clearScreen();
void setColor(int color);
string userMenu(string option);
string loginmenu(string option);
string adminMenu(string option);
string Updatemember( string members[],string  memberFatherName[] ,int &memberCount , string name,string fatherName,string Name,string FatherName);
string enterfeedBack( string name,int idnumber,string feedback,string fmembers[],int fmemberIdNumber[],string memberFeedback[],string members[],int memberIdNumber[],int &memberCount,int &fmemberCount);
void studentFeedback(string fmembers[],int fmemberIdNumber[],string memberFeedback[],int &fmemberCount);
bool nameValidation(string input);
bool numberValidation( string idStr , int &idnumber);
bool dayValidation(string dayStr , int &days);
bool ageValidation(string agStr , int &age);
bool contactValidation( string contact , long long contactNumber );
bool passwordValidation(string password);
void memberRecord(string members[],int memberIdNumber[],string  memberFatherName[] ,int &memberCount);
void readData(string userData[][3] , int &idx );
void WriteData(string username , string password , string role1 ,int &userCount);
string getField(string record , int field);
string borrowBook(string BorrowedBooks[] ,string BookAuthor[],string Borrower[],int BorrowerIdNumber[],int &borrowCount,string members[],int memberIdNumber[],int &memberCount , string AllBooks[],string Authors[] ,bool isAvailable[],int &bookCount ,string name,string bookName,string author,int idnumber);
string returnBook(string BorrowedBooks[] ,string BookAuthor[],string Borrower[],int BorrowerIdNumber[],int &borrowCount, string AllBooks[],string Authors[] ,bool isAvailable[],int &bookCount ,  string name,string bookName,string author,int idnumber);
string Addmember(  string members[],int memberIdNumber[],string  memberFatherName[] ,int &memberCount ,string name,string bookName,string author,int idnumber , int age,long long contactNumber,string fatherName );
string Removemember(  string members[],int memberIdNumber[],string  memberFatherName[] ,int &memberCount ,int idnumber, string name,string fatherName  );
string Addbooks( string AllBooks[],string Authors[] ,int &bookCount ,string bookName,string author);
string Removebooks( string AllBooks[],string Authors[] ,int &bookCount ,string bookName,string author);
string signin(string userData[][3] ,string username , string password , int &userCount);
string signup(string username , string password , string role1 , int &userCount);
void bookMenu( string AllBooks[],string Authors[] ,int &bookCount );
void bookRecord(string BorrowedBooks[] ,string BookAuthor[],string Borrower[],int BorrowerIdNumber[],int &borrowCount);
const int max_users = 100;
const int BookArrSize = 50;
const int MemberArrSize = 20;
const int BorrowArrSize = 10;
main()
{
     long long contactNumber ;
     int  idnumber, age  ;
     string name,bookName,author,answer,ans,fatherName,username,role1,title,option,Name ,FatherName ;
     int userCount = 0;
     string password;
     string userData[max_users][3];                          // 2D array use
     int bookCount = 10;
     string AllBooks[BookArrSize]  =   {"english","english","computer","computer","biology","math","physics","chemistry","stat","calculus"};
     string Authors[BookArrSize] =   {"john","david","james","petter","george","jack","thomson","nelson","dawn","jony"};
     bool isAvailable[BookArrSize] = {true , false , false , true , true , false , true , true , false , true};
     int memberCount = 6;
     string members[ MemberArrSize ] =   {"atika","ali","adil","noor","meerab","ayesha"};
     int memberIdNumber[ MemberArrSize ] = {111,112,113,114,115,116};
     string  memberFatherName[ MemberArrSize ] = {"fayyaz","arman","hamza","riaz","luqman","talha"};
     int fmemberCount = 4;
     string fmembers[ MemberArrSize ] =   {"atika","ali","adil","noor"};
     int fmemberIdNumber[ MemberArrSize ] = {111,112,113,114};
     string memberFeedback[MemberArrSize] = {"VeryGood","Excellent","Supper","Good"}; 
     int borrowCount = 4;
     string BorrowedBooks[BorrowArrSize] = {"english","computer","math","stat"};
     string BookAuthor[BorrowArrSize]  =   {"david","james","jack","dawn"};
     string Borrower[BorrowArrSize]  =     {"atika","ali","adil","noor"};
     int BorrowerIdNumber[BorrowArrSize] =   {111, 112, 113, 114};   
     system("cls");
     printHeader();
     while(true)
     
{
   string loginOption = loginmenu(option);
   if(loginOption == "1")
   {
          system("cls");
         {
           setColor(5);
           cout<<R"(    ************************************************************************************** )"<<endl;
           cout<<R"(    *                                  SIGN IN MENU                                      * )"<<endl;
           cout<<R"(    ************************************************************************************** )"<<endl;
          setColor(7);
         }
         setColor(9);  
         cout<<"You Have Entered Option 1.  "<<endl<<endl;
         setColor(7);
         readData(userData ,userCount);
         cout<<"Enter UserName:   ";
         cin.ignore();
         getline(cin , username);
         while (!nameValidation (name))
         {
           cout<<"Invalid Name. Please Enter a Valid Name.  ";
           getline(cin , username);
         }
         cout<<"Enter Password:   ";
         getline(cin , password);
         while(!passwordValidation(password))
         {
            setColor(4);
            cout<<"Password Must Contain At Least 8 Character and Should not containing Space. "<<endl<< "     Try Again:   ";
            setColor(7);
            getline(cin , password);
         }
         string role1 = signin(userData, username , password , userCount);
         if (role1 == "Undefined")
         {
               setColor(4);
               cout << "Invalid username or password." << endl;
               setColor(7);
         }

        else if(role1 == "user")
      {
            system("cls");
            userheader();
            while(true)
         {
          
              string userOption = userMenu(option); 
              if(userOption == "1")
            {
                 
                 system("cls");
       
              {
                 setColor(5);
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 cout<<R"(    *                                   BOOKS MENU                                       * )"<<endl;
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 setColor(7);
              }  
                bookMenu(AllBooks,Authors,bookCount);

            } 
              else if(userOption == "2")

           {
                 
                 system("cls");
              {
                 setColor(5);
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 cout<<R"(    *                                   BORROW BOOK                                      * )"<<endl;
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 setColor(7);
              } 
                 setColor(9);
                 cout<< "You have Entered Option 2"<<endl<<endl;
                 setColor(7);
                 cout<<"Enter Your Name:   ";
                 cin.ignore();
                 getline(cin , name);
                 while (!nameValidation (name))
              {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Name.  ";
                 setColor(7);
                 getline(cin , name);
              }

                 cout<< "Enter Your ID Number (like 231,234...): ";
                 string idStr;
                 cin>>idStr;

                 while (!numberValidation (idStr , idnumber))
              {
                 setColor(4);
                 cout<<"Invalid Id. Please Enter a Valid Id.  ";
                 setColor(7);
                 cin>>idStr;
              }
  
                 cout<< "Enter Book Name :  ";
                 cin.ignore();
                 getline(cin ,bookName); 

                 while (!nameValidation (bookName))
              {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Name.  ";
                 setColor(7);
                 getline(cin ,bookName);
              }
                 cout<< "Enter Author Name :  ";
                 getline(cin ,author);
                 while (!nameValidation (author))
              {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Name.  ";
                 setColor(7);
                 getline(cin ,author); 
              }
                 answer = borrowBook(BorrowedBooks,BookAuthor,Borrower,BorrowerIdNumber,borrowCount,members,memberIdNumber,memberCount ,AllBooks,Authors,isAvailable,bookCount ,name,bookName,author,idnumber);
                 cout<<answer<<endl<<endl;
           }

            else if(userOption == "3")
          {
                 
                 system("cls");
              {
                 setColor(5);
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 cout<<R"(    *                                     RETURN BOOK                                    * )"<<endl;
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 setColor(7);
              } 
                 setColor(9);
                 cout<< "You have Entered Option 3"<<endl<<endl;
                 setColor(7);
                 cout<< "Enter Your Name:  ";
                 cin.ignore();
                 getline(cin ,name);
                 while (!nameValidation (name))
              {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Name.  ";
                 setColor(7);
                 getline(cin ,name);
              }
                 cout<< "Enter Your ID Number (like 231,234...):  ";
                 string idStr;
                 cin >> idStr;
                 while (!numberValidation (idStr , idnumber))
              {
                 setColor(4);
                 cout<<"Invalid Id. Please Enter a Valid Id.  ";
                 setColor(7);
                 cin>>idStr;
              }
   
                 cout<< "Enter Book Name :  ";
                 cin.ignore();
                 getline(cin ,bookName);
                 while (!nameValidation (bookName))
              {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Name.  ";
                 setColor(7);
                 getline(cin ,bookName);
              }
                 cout<< "Enter Author Name :  ";
                 getline(cin ,author);
                 while (!nameValidation (author))
              {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Name.  ";
                 setColor(7);
                 getline(cin ,author);
              }
    
                 ans = returnBook(BorrowedBooks,BookAuthor,Borrower,BorrowerIdNumber,borrowCount,AllBooks,Authors,isAvailable,bookCount,name,bookName,author,idnumber);
                 cout<<ans<<endl<<endl;

            }
               else if(userOption == "4")
            {
                system("cls");
              {
                 setColor(5);
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 cout<<R"(    *                                     FEEDBACK                                       * )"<<endl;
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 setColor(7);
              } 
                 setColor(9);
                 cout<< "You have Entered Option 4"<<endl;
                 setColor(7);
               string feedback;
               cout<<"Enter Your Name: ";
               cin.ignore();
               getline(cin , name);
                 while (!nameValidation (name))
              {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Name.  ";
                 setColor(7);
                 getline(cin ,name);
              }
               cout<<"Enter Your Id Number: ";
                string idStr;
                cin >> idStr;
                 while (!numberValidation (idStr , idnumber))
              {
                 setColor(4);
                 cout<<"Invalid Id. Please Enter a Valid Id.  ";
                 setColor(7);
                 cin>>idStr;
              }
               cout<<"Enter Your Feedback About Us:  ";
               cin.ignore();
               getline(cin, feedback);
                while (!nameValidation (name))
              {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Response.  ";
                 setColor(7);
                 getline(cin ,feedback);
              }
               cout<<enterfeedBack(name,idnumber,feedback,fmembers,fmemberIdNumber,memberFeedback,members,memberIdNumber,memberCount,fmemberCount)<<endl;
            }
               else if(userOption == "5")
            {
                system("cls");
              {
                 setColor(5);
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 cout<<R"(    *                                     FEEDBACK                                       * )"<<endl;
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 setColor(7);
              } 
                 setColor(9);
                 cout<< "You have Entered Option 4"<<endl;
                 setColor(7);
                 studentFeedback(fmembers,fmemberIdNumber,memberFeedback,fmemberCount);

            }
               else if(userOption == "6")
           {

                 cout<<"Exiting the Program...."<<endl;
                 break; 
           }
    
            else if(userOption!= "1" && userOption!= "2" && userOption!= "3" && userOption!= "4" && userOption!= "5" && userOption!= "6"  )

           {
                 setColor(4);
                 cout<<"Invalid Option Please Try Again"<<endl<<endl;
                 setColor(7);
           }
                 clearScreen();
                 userheader();
         }
        
      }

       else if(role1 == "admin")
  {
             system("cls");
             adminheader();
             while(true)
     {
             string adminOption = adminMenu( option);

        {
             if(adminOption == "1")
           {
                    
                    system("cls");
              {
                    setColor(5);
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    cout<<R"(    *                                       ADD MEMBER                                   * )"<<endl;
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    setColor(7);
              } 
                    setColor(9);
                    cout<<"You Have Entered Option 1"<<endl<<endl;
                    setColor(7);
                    cout<<"Enter Member Name:  ";
                    cin.ignore();
                    getline(cin ,name);
                    while (!nameValidation (name))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin ,name);
              }
                    cout<<"Enter Member's Father Name:  ";
                    getline(cin ,fatherName);
                    while (!nameValidation (name))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin ,fatherName);
              }
                    cout<<"Enter Member's Age:  ";
                    string agStr;
                    cin>>agStr;
                    while (!ageValidation (agStr , age))
              {
                    setColor(4);
                    cout<<"Invalid Information. Please Enter a Valid Information.  ";
                    setColor(7);
                    cin>>agStr;
              }
                    cout<<"Enter Member's Contact Number:  03";
                    string contact;
                    cin>>contact;
                    while(!contactValidation( contact , contactNumber )) 
              {
                    setColor(4);
                    cout << "Invalid Number! Please Enter Valid Number.  03" ;
                    setColor(7);
                    cin>>contact;
              }
                    string result = Addmember(members,memberIdNumber,memberFatherName,memberCount , name,bookName,author,idnumber,age , contactNumber,fatherName);
                    cout<<result<<endl<<endl; 
             }
               
              else if(adminOption == "2")
           {
                   
                    system("cls");
              {
                   setColor(5);
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    cout<<R"(    *                                      REMOVE MEMBER                                 * )"<<endl;
                    cout<<R"(    ************************************************************************************** )"<<endl;
                   setColor(7);
               }
                    setColor(9); 
                    cout<<"You Have Entered Option 2"<<endl<<endl;
                    setColor(7);
                    cout<<"Enter Member's Name:  ";
                    cin.ignore();
                    getline(cin ,name);
                    while (!nameValidation (name))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin , name);
              }
                    cout<<"Enter Member's Father Name:  ";
                    getline(cin ,fatherName);
                    while (!nameValidation (name))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin ,fatherName);
              }
                    cout<< "Enter Member's ID Number (like 231,234...):  ";
                    string idStr;
                    cin >> idStr;
                    while (!numberValidation (idStr , idnumber))
              {
                    setColor(4);
                    cout<<"Invalid Id. Please Enter a Valid Id.  ";
                    setColor(7);
                    cin>>idStr;
              }
    
                    string result1 = Removemember(members,memberIdNumber,memberFatherName,memberCount , idnumber, name,fatherName );  
                    cout<<result1<<endl;
     
            }

               else if(adminOption == "3")
           {
                    
                    system("cls");
              {
                    setColor(5);
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    cout<<R"(    *                                        ADD BOOKS                                   * )"<<endl;
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    setColor(7);
              } 
                    setColor(9);
                    cout<<"You Have Entered Option 3"<<endl<<endl;
                    setColor(7);
                    cout<<"Enter Book Name:  ";
                    cin.ignore();
                    getline(cin ,bookName);
                    while (!nameValidation (bookName))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin ,bookName);
              }
                    cout<<"Enter Author Name:  ";
                    getline(cin ,author);  
                    while (!nameValidation (author))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin , author);
              }
   
                    string addDone =  Addbooks( AllBooks,Authors,bookCount ,bookName , author);
                    cout<<addDone<<endl;
             }

                else if(adminOption == "4")
           {
                    
                    system("cls");
              {
                    setColor(5);
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    cout<<R"(    *                                      REMOVE BOOKS                                  * )"<<endl;
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    setColor(7);
              } 
                    setColor(9);
                    cout<<"You Have Entered Option 4"<<endl<<endl;
                    setColor(7);
                    cout<<"Enter Book Name:  ";
                    cin.ignore();
                    getline(cin ,bookName);
                    while (!nameValidation (bookName))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin ,bookName); 
              }
                    cout<<"Enter Author Name:  ";
                    getline(cin , author);
                    while (!nameValidation (author))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin , author);
              }
   
                    string removeDone =  Removebooks(AllBooks,Authors,bookCount ,bookName,author);
                    cout<<removeDone<<endl;
             }

                 else if(adminOption == "5")
           {
                 
                 system("cls");
              {
                    setColor(5);
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    cout<<R"(    *                                    BOOKS RECORD                                    * )"<<endl;
                     cout<<R"(    ************************************************************************************** )"<<endl;
                    setColor(7);
              } 
                    bookRecord(BorrowedBooks,BookAuthor,Borrower,BorrowerIdNumber,borrowCount);
           }

                 else if(adminOption == "6")
           {
                 
                 system("cls");
              {
                    setColor(5);
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    cout<<R"(    *                                     MEMBERS RECORD                                 * )"<<endl;
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    setColor(7);
              }  
                    memberRecord(members,memberIdNumber,memberFatherName,memberCount);
            }

                 else if(adminOption == "7")
           {
                 
                 system("cls");
              {
                    setColor(5);
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    cout<<R"(    *                                   BOOKS MENU                                       * )"<<endl;
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    setColor(7);
              }  
                    bookMenu(AllBooks,Authors,bookCount);
           }
               else if(adminOption == "8")
            {

            
                system("cls");
              {
                 setColor(5);
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 cout<<R"(    *                                     FEEDBACK                                       * )"<<endl;
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 setColor(7);
              } 
                 setColor(9);
                 cout<< "You have Entered Option 8"<<endl;
                 setColor(7);
                 studentFeedback(fmembers,fmemberIdNumber,memberFeedback,fmemberCount);

            
            }
                else if(adminOption == "9")
               {
                        
                    system("cls");
              {
                    setColor(5);
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    cout<<R"(    *                                       Update MEMBER Info                           * )"<<endl;
                    cout<<R"(    ************************************************************************************** )"<<endl;
                    setColor(7);
              } 
                    setColor(9);
                    cout<<"You Have Entered Option 9"<<endl<<endl;
                    setColor(7);
                    cout<<"Enter Member Name(Previous):  ";
                    cin.ignore();
                    getline(cin ,name);
                    while (!nameValidation (name))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin ,name);
              }
                    cout<<"Enter Member's Father Name(Previous):  ";
                    getline(cin ,fatherName);
                    while (!nameValidation (name))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin ,fatherName);
              }

                    cout<<"Enter Member Name(Updated):  ";
                    cin.ignore();
                    getline(cin ,Name);
                    while (!nameValidation (name))
              {
                    setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin ,Name);
              }
                    cout<<"Enter Member's Father Name(Updated):  ";
                    getline(cin ,FatherName);
                    while (!nameValidation (name))
                    {
                     setColor(4);
                    cout<<"Invalid Name. Please Enter a Valid Name.  ";
                    setColor(7);
                    getline(cin ,FatherName);
                    }
                    cout<<Updatemember(members,memberFatherName, memberCount , name,fatherName,Name,FatherName)<<endl;
               }

                 else if(adminOption == "10")
           {
                    cout<<"Exiting the Program...."<<endl<<endl;
                    break; 
           }

                 else if(adminOption!= "1" && adminOption!= "2" && adminOption!= "3"  && adminOption!= "4"  && adminOption!= "5"  && adminOption!= "6" && adminOption!="7" && adminOption!= "8"  && adminOption!= "9" && adminOption!= "10" )
           {
                    setColor(4);
                    cout<<"Invalid Option Please Try Again"<<endl<<endl;
                    setColor(7);
           }

                    clearScreen();
                    adminheader();
          }
       }
    }
   }
     
      else if(loginOption == "2")
     {
              
              system("cls");
           {
                 setColor(5);
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 cout<<R"(    *                                  SIGNUP  MENU                                      * )"<<endl;
                 cout<<R"(    ************************************************************************************** )"<<endl;
                 setColor(7);
           } 
                 setColor(9); 
                 cout<<"You Have Entered Option 2.  "<<endl<<endl;
                 setColor(7);
                 cout<<"Enter UserName:   ";
                 cin.ignore();
                 getline(cin , username);
                 while (!nameValidation (name))
           {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Name.  ";
                 setColor(7);
                 getline(cin , username);
           }
                 cout<<"Enter password(spaces are not Allowed):   ";
                 getline(cin , password);
                 while(!passwordValidation(password))
           {
                 setColor(4);
                 cout<<"Password Must Contain At Least 8 Character and Should not containing Space. "<<endl<<"    Try Again:   ";
                 setColor(7);
                 getline(cin , password);
           }
                 cout<<"Enter Your Role(admin / user):  ";
                 cin>>role1;
                 while (!nameValidation (name))
           {
                 setColor(4);
                 cout<<"Invalid Name. Please Enter a Valid Response.  ";
                 setColor(7);
                 cin>>role1;
           }
                 string sign = signup( username ,password , role1 ,userCount);
                 setColor(10);
                 cout<<sign<<endl<<endl;
                 setColor(7);
       }

          else if(loginOption == "3")
       {
                 system("cls");
                 cout<<endl<<endl<<endl<<endl<<"                                Thanks! For Your Experience."<<endl<<endl;
       }

          else if(loginOption != "1" && loginOption != "2" && loginOption != "3")
       {
            setColor(4);
            cout<<"Invalid Option Please Try Again"<<endl<<endl;
            setColor(7);
       }
           
               clearScreen();
               printHeader();
  
   }
}




string signin(string userData[][3],string username , string password , int &userCount)
{
    for(int x = 0 ; x < userCount ; x = x + 1 )
       {
          if(username ==userData[x][0] && password == userData[x][1])
          {
             return userData[x][2];
          }
       }
        return "Undefined";  
}
string signup(string username , string password , string role1 ,int &userCount)
{  
     fstream fread ;
     string record;
     fread.open("app.txt" , ios :: in);

     while(getline(fread , record))
     {
       string exitUser = getField(record , 1);
       if(exitUser == username)
       {
         fread.close();
         return" Username Already exist";
       }
     }
     fread.close();
     WriteData(username , password , role1 ,userCount);
     return "SignUp Successfully! ";
}

string loginmenu(string option)
{ 
     setColor(5);
     cout<< "                                            WELCOME TO THE LIBRARY                    "<<endl<<endl;
     setColor(7);
     cout<< "              Select one of the Following Options...."<<endl<<endl;
     cout<< "                 1.Sign IN "<<endl;
     cout<< "                 2.Sign Up "<<endl;
     cout<< "                 3.Exit    "<<endl<<endl;
     setColor(9);
     cout<< "                 Your option.. ";
     setColor(7);
     cin>>option;
     return option;
}
string userMenu(string option)
{
     cout<< "Select one of the Following Options...."<<endl<<endl;
     cout<< "1. Books menu  "<<endl;
     cout<< "2. Borrow Book "<<endl;
     cout<< "3. Return Book "<<endl;
     cout<< "4. Enter Your Feedback "<<endl;
     cout<< "5. Student's Feedback "<<endl;
     cout<< "6. Exit        "<<endl<<endl;
     setColor(9);
     cout<< "  Your option.. ";
     setColor(7);
     cin>>option;
     return option;
}
string adminMenu(string option)
{
     cout<< "Select one of the Following Options...."<<endl<<endl;
     cout<< "1. Add Member  "<<endl;
     cout<< "2. Remove Member"<<endl;
     cout<< "3. Add Books   "<<endl;
     cout<< "4. Remove Books"<<endl;
     cout<< "5. Library Record"<<endl;
     cout<< "6. Members Record"<<endl;
     cout<< "7. Books menu  "<<endl;
     cout<< "8. Student's Feedback "<<endl;
     cout<< "9. Update Member's Info"<<endl;
     cout<< "10. Exit          "<<endl<<endl;
     setColor(9);
     cout<< "  Your option.. ";
     setColor(7);
     cin>>option;
     return option;
}
void clearScreen()
{
    setColor(5);
    cout << "Press any Key to continue.";
    setColor(7);
    getch(); 
    system("cls");
}
string Updatemember( string members[],string  memberFatherName[] ,int &memberCount , string name,string fatherName,string Name,string FatherName)
{
   int index ;
   bool found = false;
   for (int idx = 0 ; idx < memberCount ; idx = idx + 1)
   {
        if (members[idx] == name && memberFatherName[idx] == fatherName)
      {
         found = true;
         idx = index;
      }
   }
   if(found)
   {
      members[index] = Name;
      memberFatherName[index] = FatherName;
      return "Member Info Have been Successfully Updated";
   } 
   else
   {
      return "Wrong Information.";
   }

     
}

string enterfeedBack(string name,int idnumber,string feedback,string fmembers[],int fmemberIdNumber[],string memberFeedback[],string members[],int memberIdNumber[],int &memberCount,int &fmemberCount)
{
   bool ispresent = false;
      for(int idx = 0 ; idx < memberCount ; idx = idx + 1)
   {
      if(members[idx] == name  && memberIdNumber[idx] == idnumber )
      {
         ispresent = true;
         break;
      }
   }
   if(ispresent)
   {
      memberFeedback[fmemberCount] = feedback;
      fmembers[fmemberCount] = name;
      fmemberIdNumber[fmemberCount] = idnumber;
      fmemberCount++;
      return "Your Feedback Successfully Added.";
   }
   else
   {
      return "You are not Library Member. You cannot give Feedback.";
   }
}
void studentFeedback(string fmembers[],int fmemberIdNumber[],string memberFeedback[],int &fmemberCount)
{

   cout<< "Members Feedback..."<<endl<<endl;
   cout<<setw(22)<<left<<"Member's Name"<<setw(22)<<left<< "Member's ID"<<setw(22)<<left<< "Member's Feedback"<<endl<<endl;
    for(int idx = 0 ; idx < fmemberCount ; idx = idx + 1)
  {
     cout<<setw(22)<<left<<fmembers[idx]<<setw(22)<<left<<fmemberIdNumber[idx]<<setw(22)<<left<<memberFeedback[idx]<<endl<<endl;
    
  }  
}


string borrowBook(string BorrowedBooks[] ,string BookAuthor[],string Borrower[],int BorrowerIdNumber[],int &borrowCount,  string members[],int memberIdNumber[],int &memberCount , string AllBooks[],string Authors[] ,bool isAvailable[],int &bookCount ,  string name,string bookName,string author,int idnumber)
{
  string answer,choise;
  bool ismember = false;
    for(int idx = 0 ; idx < memberCount ; idx = idx + 1)
   {
      if(members[idx] == name  && memberIdNumber[idx] == idnumber )
      {
         ismember = true;
         break;
      }
   }
      if (!ismember)
     {
       answer = "Sorry! You Cannot Borrow a Book Because You Are Not a Library Member.";
      return answer;
     }
   bool found = false;
   int index = -1;
    for (int i = 0 ; i < bookCount ; i = i + 1)
  {
    if ( bookName == AllBooks[i] && author == Authors[i] && isAvailable[i])
    {
      found = true;
      index = i;
      break;
    }
  }
    if ( found == true )
  {
      answer = "Book is Available!  You Can Borrow it.  ";
      cout<< answer <<endl<<endl;
     
      cout<< "Do You Want to Borrow the Book? (yes/no):  ";
      cin>> choise;
      while (choise!= "yes" && choise != "no")
    {
      cout<<"Invalid Respose.Please Enter a Valid Respose:  ";
      cin>>choise;
    }
      
     if (choise == "yes")
    { 
   
      isAvailable[borrowCount] = false;
      BorrowedBooks[borrowCount] = bookName;
      BookAuthor[borrowCount] = author;
      Borrower[borrowCount] = name;
      BorrowerIdNumber[borrowCount] = idnumber;
      borrowCount++;
      answer = "You Have Successfully Borrowed the Book.";
     }  
       
     else if ( choise == "no")
     {
        
       answer = "You Choose Not to Borrow the Book.  Thanks! For Your Experience.";
     }
     else
     {
       answer = "Please Enter Yes Or No:  ";
       
     }
  }
     else 
   {
     answer = "Sorry! Book is not Available.";
   }
     return answer;
 
}
string returnBook(string BorrowedBooks[] ,string BookAuthor[],string Borrower[],int BorrowerIdNumber[],int &borrowCount,  string AllBooks[],string Authors[] ,bool isAvailable[],int &bookCount ,  string name,string bookName,string author,int idnumber)
{
   string ans;
   int days;
   bool found = false;
   int index = 0;
   for (int i = 0 ; i < borrowCount ; i = i + 1)
   {
    if (  bookName == BorrowedBooks[i] && author ==  BookAuthor[i] && name ==Borrower[i] && idnumber == BorrowerIdNumber[i])
    {
      found = true;
      index = i;
      break;
    }
   }
   if ( found == true )
   { 
      isAvailable[index] = true;
      BorrowedBooks[index] = "";
      BookAuthor[index] = "";
      Borrower[index] = "";
      BorrowerIdNumber[index] = 0;
     
      cout<< "Enter the Number of Days You Kept the Book:  ";
      string dayStr;
      cin>>dayStr;
       while (!dayValidation (dayStr , days))
    {
      cout<<"Invalid . Please Enter a Valid Number of Days.  ";
      cin>>dayStr;
    } 
      if ( days > 14 )
     {
      int exceedDays = days - 14;
      int fine = 100 * exceedDays;
      ans = "Your borrowing period has exceeded by  " + to_string(exceedDays) + "  Days a fine of  "  + to_string(fine) + "  has been applied.";
     }
     else
     {
       ans = "ThankYou! For Returning The Book.";
     }
  }

   else 
   {
     ans = " Details You Entered Are Incorrect. Please Check Again.  ";
   }
   return ans;
  
}
string Addmember(  string members[],int memberIdNumber[],string  memberFatherName[] ,int &memberCount , string name,string bookName,string author,int idnumber,int age ,long long contactNumber,string fatherName)
{
   string result;
    if (age < 15)
     {
        return "Sorry! He/She Is Under Age. He/She Cannot Be a Library Member.";
     }
   int maxId = 0;
   bool found = false;
   for (int idx = 0 ; idx < memberCount ; idx = idx + 1)
   {
        if (members[idx] == name && memberFatherName[idx] == fatherName)
      {
        return "Member Is Already Present";
      }
   }
   for(int idx = 0 ; idx < memberCount  ; idx = idx + 1)
   {
      if (memberIdNumber[idx] > maxId )
      {
         maxId = memberIdNumber[idx];
          found = true;
      }
        
   }
   if (found)
   {
      if(memberCount < MemberArrSize)
   {
      members[ memberCount] = name;
      memberIdNumber[ memberCount] = maxId + 1;
      memberFatherName[ memberCount] = fatherName;
      result = "Congratulations! "+ members[ memberCount] + " Become a Library Member."+ members[ memberCount] +"'s ID is "+ to_string( memberIdNumber[ memberCount]) +" .";
      memberCount++;
   }
      else
   {
      result = "Sorry! No Space Available For New Members.";
   }
   }
 
   return result;
}

string Removemember(  string members[],int memberIdNumber[],string  memberFatherName[] ,int &memberCount ,int idnumber, string name,string fatherName)
{
   string result1;   
   bool found = false;
   int index = 0 ;
    for(int idx=0 ; idx < memberCount ; idx = idx + 1)
    {
       if(name == members[idx] && idnumber == memberIdNumber[idx])
       {
         found = true;
         index = idx;
         break;
       }
    }
    if (found == true)
   {
      members[index] = "";
      memberFatherName[index] = "";
      memberIdNumber[index] = 0;
      result1 = "Member Is Successfully Removed.Thanks For Your Experience.";
     
   }
   else
   {
      result1 = "Wrong Information. Please Enter Valid Information.";
   }
   return result1;
}
string Addbooks( string AllBooks[],string Authors[] ,int &bookCount ,string bookName,string author)
{
   string addDone;
   bool found = false;
   int index = -1 ;
   for(int idx = 0; idx < bookCount ; idx = idx + 1)
   {
      if(AllBooks[idx] != bookName  && Authors[idx] != author )
    {
      found = true;
      index = idx;
    }
   }
   if (found == true)
   {
      AllBooks[index] = bookName;
      Authors[index] =  author;
      addDone = "Your Book is Successfully Add.";
      bookCount++;
   }
   return addDone;
}
string Removebooks( string AllBooks[],string Authors[] ,int &bookCount , string bookName,string author)
{
   string removeDone;
   bool found = false;
   int index = -1;
    for(int idx = 0; idx < bookCount ; idx = idx + 1)
   {
      if(AllBooks[idx] == bookName  && Authors[idx] == author )
     {
      found = true;
      index = idx;
     }
   }
   if (found == true)
   {
      AllBooks[index] = " ";
      Authors[index] =  " ";
      removeDone= "Your Book is Successfully Removed.";
     
   }
   else
   {
      removeDone = "Sorry! Book is Not Found.";
   }
   return removeDone;
}
bool nameValidation(string input)
{
 for(int idx = 0 ; idx < input.length() ; idx = idx + 1)
    {
        char c = input[idx];
        if (! (c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z') &&(c != ' ') )
        
         {
            return false;
         }
    }
    return true;
}
bool numberValidation(string input , int &idnumber) 
 {
    if (input.length() != 3)
    {
        return false;
    }
    for (int i = 0 ; i < input.length() ; i = i + 1) 
    {
       char c = input[i];
        if (!isdigit(c))
        {
            return false;
        }
    }

    idnumber = stoi(input); 
    if (idnumber <= 0)
    {
        return false; 
    }

    return true;  
 }
 bool dayValidation(string input , int &days)
 {

    for (int i = 0 ; i < input.length() ; i = i + 1) 
    {
       char c = input[i];
        if (!isdigit(c))
        {
            return false;
        }
    }

    days = stoi(input); 
    if (days <= 0)
    {
        return false; 
    }

    return true;  
 }
 
 bool contactValidation( string contact , long long contactNumber )
 {
    for (int i = 0 ; i < contact.length() ; i = i + 1) 
    {
       char c = contact[i];
        if (!isdigit(c))
        {
            return false;
        }
    }
        if (contact.length() != 9)
    {
        return false;
    }

    contactNumber = stoll(contact); 
    return true;  
 }
 bool passwordValidation(string password)
 {
      if (password.length() < 8)
       {
         return false;
       }
     for(int idx = 0 ; idx < password.length() ; idx = idx + 1)
    {
        if(password[idx] == ' ')
        {
         return false;
        }
    }
      return true;     
 }
 
 
 bool ageValidation(string input , int &age) 
 {
    for (int i = 0 ; i < input.length() ; i = i + 1) 
    {
       char c = input[i];
        if (!isdigit(c))
        {
            return false;
        }
    }
       if (input.length() > 3)
    {
        return false;
    }

    age = stoi(input); 
    if (age <= 0)
    {
        return false; 
    }

    return true;  
 }
void bookMenu( string AllBooks[],string Authors[] ,int &bookCount )
{
   cout<< "All Available Books..."<<endl<<endl;
   cout<<setw(22)<<left<<"Book Titles"<<setw(22)<<left<<"Author's Name"<<endl<<endl;
  
      for(int idx = 0 ; idx < bookCount ; idx = idx + 1)
  {
      cout<<setw(22)<<left<<AllBooks[idx]<<setw(22)<<left<<Authors[idx]<<endl;
    
  }
 

 }
void bookRecord(string BorrowedBooks[] ,string BookAuthor[],string Borrower[],int BorrowerIdNumber[],int &borrowCount)
{
   cout<< "Library Record..."<<endl<<endl;
   cout<<setw(30)<<left<<"Borrowed Books"<<setw(30)<<left<<"Authors Name"<<setw(30)<<left<<"Borrower Name"<<setw(30)<<left<<"Borrower ID"<<endl<<endl;
   
   for(int idx = 0 ; idx < borrowCount ; idx = idx + 1)
   {
      cout<<setw(30)<<left<<BorrowedBooks[idx]<<setw(30)<<left<<BookAuthor[idx]<<setw(30)<<left<<Borrower[idx]<<setw(30)<<left<<BorrowerIdNumber[idx]<<endl<<endl;
   }
  
}
void memberRecord(  string members[],int memberIdNumber[],string  memberFatherName[] ,int &memberCount )
{
   cout<< "Members Record..."<<endl<<endl;
   cout<<setw(22)<<left<<"Member's Name"<<setw(22)<<left<<"Member's Fathername"<<setw(22)<<left<< "Member's ID"<<endl<<endl;
    for(int idx = 0 ; idx < memberCount ; idx = idx + 1)
  {
     cout<<setw(22)<<left<<members[idx]<<setw(22)<<left<< memberFatherName[idx]<<setw(22)<<left<<memberIdNumber[idx]<<endl<<endl;
    
  }
}
void readData(string userData[][3],  int &userCount )
{
    fstream file;
    string record;
    file.open("app.txt" , ios::in);

    while(getline(file , record))
    {
        if(record.empty())
        continue;

        userData[userCount][0] = getField(record , 1);
        userData[userCount][1] = getField(record , 2);
        userData[userCount][2] = getField(record , 3);
        userCount = userCount + 1;
    }
    file.close();

}
string getField(string record , int field)
{
    int countComma = 1;
    string item;
    for(int x = 0 ; x < record.length() ; x = x + 1)
    {
        if(record[x] == ',')
        {
            countComma = countComma + 1;
        }
        else if(countComma == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
void WriteData(string username , string password , string role1 , int &userCount)
{
    fstream fWrite;
    string line;
    fWrite.open("app.txt" , ios::app);
    fWrite << username << "," << password <<"," << role1 <<endl;
   
    fWrite.close();

}
void printHeader()
{
   setColor(9);
   cout<<R"( _    _ _ _  ___   _ ___    __   _ ____  _     _       _    _   __    _     _   __      _ _     _    _ _ _ _ _  _     _  _ _ _ _  )"<<endl;
   cout<<R"(| |  |_| |_|| __ )| | _  \ /  \ | | _  \\ \   / /     | \  / | /  \  | |   | | /  \   /  __ \  | \  / | |_ _ _|| |   | ||_ _|_ _| )"<<endl;
   cout<<R"(| |    | |  |  _ \| | _ _|/ __ \| | _ _| \ \ / /      |  \/  |/ __ \ | |\  | |/ __ \ | |   |_| |  \/  | |_ __  | |\  | |   | |    )"<<endl;
   cout<<R"(| |_ _ | |_ | |_) | | \ \/ /  \ \ | \ \   | | |       | |  | | /  \ \| | \ | | /  \ \| |   __  | |  | | |_ _ _ | | \ | |   | |    )"<<endl;
   cout<<R"(\_ _ _||_|_||____/|_|  \_\/    \_\|  \_\  |_ _|       |_|  |_|/    \_\_|  \ _|/    \_\_|__| __||_|  |_|_|_ _ _||_|  \ _|   |_|    )"<<endl;
   cout<<R"(                                  ____ _      _ ____  _ _ _ _  _ _ _ _  _    _                                                    )"<<endl;
   cout<<R"(                                 / ___|\ \   / / ___||_ _|_ _|| |_ _ _|| \  / |                                                   )"<<endl;
   cout<<R"(                                 \___ \ \ \ / /\___ \   | |   | |_ __  |  \/  |                                                   )"<<endl;
   cout<<R"(                                  ___) | | | |  ___) |  | |   | |_ _ _ | |  | |                                                   )"<<endl;
   cout<<R"(                                 |____/  |_|_| |____/   |_|   |_|_ _ _||_|  |_|                                                   )"<<endl<<endl;
   setColor(7);
}
void userheader()
 {  
           setColor(5);       
           cout<<R"(    ************************************************************************************** )"<<endl;
           cout<<R"(    *                                         USER MENU                                   *)"    <<endl;
           cout<<R"(    ************************************************************************************** )"<<endl;
           setColor(7);
}
void adminheader()
 {
           setColor(5);
           cout<<R"(    ************************************************************************************** )"<<endl;
           cout<<R"(    *                                         ADMIN MENU                                 *)"    <<endl;
           cout<<R"(    ************************************************************************************** )"<<endl;
          setColor(7);
}
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
