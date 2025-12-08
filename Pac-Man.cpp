#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
void setColor(int color);
void printMaze();
void printHeader(); 
void printEnemy1(int ex1, int ey1);
void printEnemy2(int ex2, int ey2);
void printEnemy3(int ex3, int ey3);
void eraseEnemy1(int ex1, int ey1);
void eraseEnemy2(int ex2, int ey2);
void eraseEnemy3(int ex3, int ey3);
void moveEnemy1(int &ex1, int &ey1 , int px , int py);
void moveEnemy2(int &ex2, int &ey2 , int px , int py);
void moveEnemy3(int &ex3, int &ey3, int px , int py);
void printPlayer(int px, int py);
void erasePlayer(int px, int py);
void movePlayerLeft(int &px, int &py);
void movePlayerRight(int &px, int &py);
void movePlayerUp(int &px, int &py);
void movePlayerDown(int &px, int &py);
void checkCollision(int ex , int ey , int px , int py);
void printBullet(int x , int y);
void eraseBullet(int x , int y);
void makeBulletInactive(int index);
void generateBullet(int px , int py);
bool bulletCollision(int ex ,int ey);
void moveBullet();
char getCharAtxy(short int x, short int y);
void gotoxy(int x,int y);
void addScore(int px,int py);
void addLives(int px , int py);
void decreaseLives();
void WinGame();
int menu();
void Score();
void Lives();
void gameOver();
void winner();
void instructions();
int BulletX[100];
int BulletY[100];
bool isBulletActive[100];
int BulletCount = 0;
int score=0;
int lives = 5;
int pills = 30; 
main()
{

   int px=3  ,  py=35  ;
   int ex1=47  , ey1=13 ,ex2=44   ,ey2=16, ex3=51    , ey3=16 ;
   system("cls");
   gotoxy(0 , 15);
   printHeader();
   gotoxy(55 , 25);
   cout<<"Tap to Play...";
   getch();
   while(true)
{
   system("cls");
   gotoxy(0 , 15);
   printHeader();
   int option = menu();
   if(option == 1)
 {

 
   system("cls");
   printMaze();
   printEnemy1(ex1, ey1);
   printEnemy2(ex2, ey2);
   printEnemy3(ex3, ey3);
   printPlayer(px, py);
   while(true)
 { 
    {
       Score();                                    //Display score on screen
       Lives();                                    //Display Lives on Screen
        if (GetAsyncKeyState(VK_LEFT))
        {
          movePlayerLeft( px, py);
            
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {

         movePlayerRight( px, py);  
        }
        if (GetAsyncKeyState(VK_UP))
        {

          movePlayerUp( px, py);  
        }
        if (GetAsyncKeyState(VK_DOWN))
        {

          movePlayerDown(px, py);
        }
        if(GetAsyncKeyState(VK_SPACE))
        {
        	generateBullet(px ,py);                    //is initialize the bullet
        }
		    moveBullet();                                // move bullet along direction of player     
        moveEnemy1(ex1,ey1,  px ,  py);
        moveEnemy2(ex2,ey2,  px ,  py);
        moveEnemy3(ex3,ey3,  px ,  py);
        
        Sleep(50);
     }
   }
 }
      else if(option == 2)
      {
        system("cls");
        gotoxy(0 , 15);
        printHeader();
        instructions();
      }
      else if(option == 3)
      {
        system("cls");
        break;
      }
      cout<<"           Press Any Key to Continue..."<<endl;
      getch();
  }
}

 
void printPlayer(int px, int py)
{
  setColor(14);
  gotoxy(px, py);
  cout <<  "  ___";
  gotoxy(px, py+1);
  cout <<  " (  *)";
  gotoxy(px, py+2);
  cout <<  "  XXX";
  setColor(7);
}

void erasePlayer(int px, int py)
{
    gotoxy(px, py);
  cout <<  "     ";
  gotoxy(px, py+1);
  cout <<  "       ";
  gotoxy(px, py+2);
  cout <<  "     ";
 
}
void movePlayerLeft(int  &px, int &py)
{
        if (getCharAtxy(px - 1, py) == ' ' && 
        getCharAtxy(px - 1, py + 1) == ' ' &&            // player move if next location is empty
        getCharAtxy(px - 1, py + 2) == ' ' )
    {
        erasePlayer(px,py);
        px = px - 1;
        printPlayer(px,py);
    }
     if (getCharAtxy(px - 1, py + 1) == 'x') 
     {
        addScore(px,py);                               //score add when player eat x
        decreaseLives();                                 //lives decrease
        WinGame();                                    //Win function call if some condition satisfy then it return win
        erasePlayer(px,py);
        px = px - 1;
        printPlayer(px,py);
    }
     if (getCharAtxy(px - 1, py + 1) == 'O') 
     {
        addLives(px ,py);                            //on eating o lives add
        erasePlayer(px,py);
        px = px - 1;
        printPlayer(px,py);
    }
    
}
void movePlayerRight(int  &px, int &py)
{
   if (getCharAtxy(px + 7, py) == ' ' && 
        getCharAtxy(px + 7, py + 1) == ' ' && 
        getCharAtxy(px + 7, py + 2) == ' ' )
    {
        erasePlayer(px,py);
        px = px + 1;
        printPlayer(px,py);
    }
   if (getCharAtxy(px + 7, py+1) == 'x' ) 
       
    {
        addScore(px,py);
        decreaseLives();
        WinGame();
        erasePlayer(px,py);
        px = px + 1;
        printPlayer(px,py);
    }
    if (getCharAtxy(px + 7, py+1) == 'O' ) 
       
    {
        addLives(px ,py);
        erasePlayer(px,py);
        px = px + 1;
        printPlayer(px,py);
    }
   
}
void movePlayerUp(int  &px, int &py)
{
    if (getCharAtxy(px  , py - 1 ) == ' ' &&
        getCharAtxy(px + 1, py - 1 ) == ' ' &&
        getCharAtxy(px + 2, py - 1 ) == ' ' &&
        getCharAtxy(px + 3, py - 1 ) == ' ' &&
        getCharAtxy(px + 4, py - 1 ) == ' ' &&
        getCharAtxy(px + 5, py - 1 ) == ' ' &&
        getCharAtxy(px + 6, py - 1 ) == ' ' )
       
    {
        erasePlayer(px,py);
        py = py - 1;
        printPlayer(px,py);
    }
    if (getCharAtxy(px + 3 , py - 1 ) == 'x' )
     {
        addScore(px,py);
        decreaseLives();
        WinGame();
        erasePlayer(px,py);
        py = py - 1;
        printPlayer(px,py);
    }
    if (getCharAtxy(px + 3 , py - 1 ) == 'O' )
     {
        addLives(px , py);
        erasePlayer(px,py);
        py = py - 1;
        printPlayer(px,py);
    }
 }
void movePlayerDown(int  &px, int &py)
{
        if (getCharAtxy(px , py + 3) == ' ' &&
        getCharAtxy(px + 1, py + 3 ) == ' ' &&
        getCharAtxy(px + 2, py + 3 ) == ' ' &&
        getCharAtxy(px + 3, py + 3 ) == ' ' &&
        getCharAtxy(px + 4, py + 3 ) == ' ' &&
        getCharAtxy(px + 5, py + 3 ) == ' ' &&
        getCharAtxy(px + 6, py + 3 ) == ' ' )
    {
        erasePlayer(px,py);
        py = py + 1;
        printPlayer(px,py);
    }
        if (getCharAtxy(px + 3 , py + 3) == 'x')
     {
        addScore(px,py);
        decreaseLives();
        WinGame();
        erasePlayer(px,py);
        py = py + 1;
        printPlayer(px,py);
    }
     if (getCharAtxy(px + 3 , py + 3) == 'O')
     {
        addLives(px , py);
        erasePlayer(px,py);
        py = py + 1;
        printPlayer(px,py);
    }
}

void printEnemy1(int ex1, int ey1)
{ 
      setColor(12);
      gotoxy (ex1,ey1);
      cout <<  " AAA";
      gotoxy(ex1, ey1+1);
      cout << "(*,*)";
      gotoxy(ex1, ey1+2);
      cout << "/!!!\\";
      setColor(7);
     
  } 
void eraseEnemy1(int ex1, int ey1)
{
      gotoxy (ex1,ey1);
      cout <<  "    ";
      gotoxy(ex1, ey1+1);
      cout << "     ";
      gotoxy(ex1, ey1+2);
      cout << "      ";

}
void moveEnemy1(int &ex1, int &ey1 , int px , int py)
 
  { 
   eraseEnemy1(ex1,ey1);
  
    if (ey1 > 9 && ex1 == 47)                              //enemy move if these condition satisfy
    {
      ey1--;                                              //move up
    }
    else if (ey1 == 9 && ex1 > 33)
    {
        ex1--;                                              //move left
    } 
    else if (ex1 == 33 && ey1 > 1)
    {
        ey1--;  
    } 
    else if (ey1 == 1 && ex1 > 1) 
    {
        ex1--; 
    }
    else if (ex1 == 1 &&  ey1 < 21)
    {
      
        ey1 ++;                                           //move down
    }
    else if (ey1 == 21 && ex1 < 33)
    {
        ex1 ++;                                          //move right
    }
      printEnemy1(ex1, ey1);
     if(bulletCollision(ex1 ,ey1))                      //it check if enemy collide with bullet
    {
    	eraseEnemy2(ex1,ey1);                           //when bullet collide with enemy it remove enemy and enemy 
    	ex1 = 47;                                       // start from initial position
    	ey1 = 13;
	}
   checkCollision(ex1 ,ey1 ,px ,py);                   //it check if enemy collide with player
 }
    
 
void printEnemy2(int ex2, int ey2)
{
      setColor(12);
      gotoxy (ex2,ey2);
      cout <<  " AAA";
      gotoxy(ex2, ey2+1);
      cout << "(*,*)";
      gotoxy(ex2, ey2+2);
      cout << "/XXX\\";
      setColor(7);
      
  } 
void eraseEnemy2(int ex2, int ey2)
{
      gotoxy (ex2,ey2);
      cout <<  "    ";
      gotoxy(ex2, ey2+1);
      cout << "     ";
      gotoxy(ex2, ey2+2);
      cout << "      ";
}
void moveEnemy2(int &ex2, int &ey2 , int px , int py)
{  
    eraseEnemy2(ex2,ey2);
     if (ey2 > 9 && ex2 == 44) 
    {                                                  //for enemy 2 movement
        ey2--; 
    }
    else if (ey2 == 9 && ex2 < 64)
   {
        ex2++;  
    }
     else if (ex2 == 64 && ey2 > 1) 
    {
        ey2--;  
    } 
    else if (ey2 == 1 && ex2 < 99) 
    {
        ex2++;
    } 
    else if (ex2 == 99 && ey2 < 21)
    {
        ey2++;
    } 
    else if ( ey2 == 21 &&  ex2 > 64) 
    {
        ex2--;
    } 
      printEnemy2(ex2,ey2);
     if(bulletCollision(ex2 ,ey2))
    {
    	eraseEnemy2(ex2,ey2);
    	ex2 = 44;
    	ey2 = 16;
	}
    checkCollision(ex2 ,ey2 ,px ,py);
    
 }

void printEnemy3(int ex3, int ey3)
{
      setColor(12);
      gotoxy (ex3,ey3);
      cout <<  " AAA";
      gotoxy(ex3, ey3+1);
      cout <<  "(*,*)";
      gotoxy(ex3, ey3+2);
      cout <<  "/###\\";
      setColor(7);

  } 
void eraseEnemy3(int ex3, int ey3)
{
      gotoxy (ex3,ey3);
      cout <<  "    ";
      gotoxy(ex3, ey3+1);
      cout <<  "     ";
      gotoxy(ex3, ey3+2);
      cout <<  "      ";
}
void moveEnemy3(int &ex3, int &ey3 , int px , int py)

 {  
    eraseEnemy3(ex3,ey3);
     if (ey3 > 9 && ex3 == 51)
   {
        ey3--; 
    }                                                    //for enemy 3 movement
    else if (ey3 == 9 && ex3 < 65 )
    {
        ex3++;  
    }
    else if (ex3 == 65 && ey3 < 25) 
    {
        ey3++;  
    }
    else if (ey3 == 25 && ex3 < 80)
   {
       ex3++;  
    }
    else if (ex3 == 80 && ey3 < 35)
    {
      ey3++;
    }
    else if (ey3 == 35 && ex3 < 118)
    {
      ex3++;
    }
     else if (ex3 == 118 && ey3 > 25)
    {
      ey3--;
    }
     else if (ey3 == 25 && ex3 > 80)
    {
      ex3--;
    }
   
     printEnemy3(ex3,ey3);
     if(bulletCollision(ex3 ,ey3))
    {
    	eraseEnemy3(ex3,ey3);
    	
    	ex3 = 51;
    	ey3 = 16;
	}
    checkCollision(ex3 ,ey3 ,px ,py);
 }
void checkCollision(int ex , int ey , int px , int py)
{
	if(ex + 3 >= px &&  ex <= px + 6 &&  ey + 2>= py && ey <= py + 2)
	{
                                                        
	  gameOver();                                      //it check if player axis match with enemy then game will over
	  exit(0);
		
	}
}
void printBullet(int x , int y)
{                                                        
  gotoxy(x , y);
  setColor(14);
  cout<<"_";
  setColor(7);	
}
void eraseBullet(int x , int y)
{
	gotoxy(x , y);
	cout<<" ";
}
void makeBulletInactive(int index)
{
	isBulletActive[index] = false;                        //initially bulletactive is kept false until space bar press
}
void generateBullet(int px , int py)
{
	BulletX[BulletCount] = px + 6;                    //bullet generate from special axis of player
	BulletY[BulletCount] = py + 1;
	isBulletActive[BulletCount] = true;                //bulletactive become true
	gotoxy(px + 6 , py + 1);
	setColor(9);                                    //setColor is use to color bullet
  cout<<"_";
  setColor(7);	
	BulletCount = BulletCount + 1;                  
	
}
void moveBullet()
{
	for(int x = 0 ; x < BulletCount ; x = x + 1)
	{
		if(isBulletActive[x] == true)
		{
			char nextLocation = getCharAtxy(BulletX[x] + 1 , BulletY[x] );
			if(nextLocation != ' ')
			{
			   eraseBullet(BulletX[x] , BulletY[x]);          //it inactivate the bullet if next location is not empty
			   makeBulletInactive(x);	
			}
			else
			{
			   eraseBullet(BulletX[x] , BulletY[x]);
			   BulletX[x] = BulletX[x] + 1;
			   printBullet(BulletX[x] , BulletY[x]);
			   
			   	
			}
		}
	}
}
bool bulletCollision(int ex,int ey)
{
   for (int i = 0; i < BulletCount; i++)
    {
         if (isBulletActive[i] && BulletX[i] >= ex - 1 && BulletX[i] <= ex + 3 && BulletY[i] >= ey && BulletY[i] <= ey + 2)
        {
        	eraseBullet(BulletX[i] , BulletY[i]);
            makeBulletInactive(i);                               //when bullet axis match with enemy then it remove the enemy
            score = score + 10;
            return true;
        }
    }
   return false;
}
void addScore(int px,int py)
{
  if (getCharAtxy(px - 1, py + 1) == 'x'|| getCharAtxy(px + 7, py+1) == 'x' ||getCharAtxy(px + 3 , py - 1 ) == 'x' ||getCharAtxy(px + 3 , py + 3) == 'x')
 {
   score+= 10 ;                                  //score add when payer eat candy x
   Score();
}

}
void addLives(int px , int py)
{
  if (getCharAtxy(px - 1, py + 1) == 'O'|| getCharAtxy(px + 7, py+1) == 'O' ||getCharAtxy(px + 3 , py - 1 ) == 'O' ||getCharAtxy(px + 3 , py + 3) == 'O')
  {
  	lives = lives + 5;                    
    Lives();                                    //score add when payer eat bonus candy o
  	
  }	
}
void decreaseLives()
{
   lives = lives - 1;
    if(lives <= 0)
    {                                            //lives decrease gradually
        gotoxy(147 , 11);
  	    cout<<"Lives:   "<<lives;
        gameOver();   
	      gotoxy(147 , 25);
	      cout<<"YOU ARE OUT OF LIVES... ";
        exit(0);
   }	
}
void WinGame()
{
	pills = pills - 1;
	if(pills <= 0)                               //if player eat all candies than wingame call
	{
    system("cls");
    gotoxy(0 , 20);
    winner();
		exit(0);
	}
}
int menu()
{
    int option;
    gotoxy(0 , 25);
    cout<<"             Select One Of The Following option... "<<endl;
    cout<<"             1.Enter To Start the Game "<<endl;
    cout<<"             2.Instructon"<<endl;
    cout<<"             3.Exit"<<endl<<endl;
    cout<<"             Your Option...";
    cin>>option;
    return option;
}
void instructions()
{
   gotoxy(0 , 25);
   cout<<"                            INSTRUCTIONS"<<endl<<endl;
   cout<<"              1. Use Up,Down,left,Right button for player movement"<<endl;
   cout<<"              2. Use Space bar for Shoot the Enemy"<<endl;
   cout<<"              3. 'x' a Candy is Player Food "<<endl;
   cout<<"              4. 'O' is a bonus Candy for increment in lives"<<endl;
   cout<<"              5. Score also increase when you Shoot the enemy"<<endl;
   cout<<"              6. Finish All the Candies For Win the game"<<endl;
   cout<<"              7. If lives become 0 you will  loss the game so"<<endl;
   cout<<"                  Finish all the Candies before lives become 0"<<endl<<endl;
}
void Score()
{
       
        setColor(14);
        gotoxy(147,3);
        cout<<"*********************"<<endl;
        gotoxy(147,4);
        cout<<"* Score: "<<score<<"         *"<<endl;
        gotoxy(147,5);
        cout<<"*********************"<<endl;
        setColor(7);
        

}
void Lives()
{
        setColor(14);
        gotoxy(147,10);
        cout<<"*********************"<<endl;
        gotoxy(147,11);
        cout<<"* Lives: "<<lives<<"          *"<<endl;
        gotoxy(147,12);
        cout<<"*********************";
        setColor(7);
       
}
void gameOver()
{
      
      setColor(13);
      gotoxy(150 , 20);
	    cout<<"X X X X X X X X X"<<endl;
	    gotoxy(150 , 21);
	    cout<<"X  GAME OVER!   X" <<endl;
	    gotoxy(150 , 22);
	    cout<<"X X X X X X X X X"<<endl;
      setColor(7);
     

}
void gotoxy(int x ,int y)
{
  COORD coordinates;

  coordinates.X = x;

  coordinates.Y = y;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
char getCharAtxy(short int x, short int y)
{

CHAR_INFO ci;

COORD xy = {0, 0};

SMALL_RECT rect = {x, y, x, y};

COORD coordBufSize;

coordBufSize.X = 1;

coordBufSize.Y = 1;

return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar: ' ';

}
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void printMaze()
{
  setColor(10);
  cout<<"############################################################################################################################################"<<endl;
  cout<<"#                                                                                                                                          #"<<endl;
  cout<<"#                                       x       x          x                                                        x              x       #"<<endl;
  cout<<"#                                                                                                                                          #"<<endl;
  cout<<"#        ################               ######################                 ##################                       #####              #"<<endl;               
  cout<<"#        #                                        ##                           #                #            x              #              #"<<endl;
  cout<<"#        #                                   O    ##   x                       #                #         #######           #              #"<<endl;
  cout<<"#        #                                        ##                           #      x         #               #           #              #"<<endl;
  cout<<"#        #        ##########               ###############                     #                #               #           #      O       #"<<endl;
  cout<<"#        #   x    #                                                       ######             ####               #           #              #"<<endl;
  cout<<"#        #        #    x                                                  #                                     #############              #"<<endl;          
  cout<<"#        #        #                                                       #                                     #                          #"<<endl;
  cout<<"#        ##########                                                       #        x        O                   #                          #"<<endl;
  cout<<"#                 #        #            #                    #            #                                     #                          #"<<endl;   
  cout<<"#                 #    x   #            #                    #            #                                     #    x            ##########"<<endl;
  cout<<"#                 #        #            #                    #            #############                  ########                 #        #"<<endl;
  cout<<"#                 ##########            #                    #                        #                                           #        #"<<endl;
  cout<<"#        #                              #                    #                        #                      O       x            #    x   #"<<endl;
  cout<<"#        #            x                 #                    #                 x      #                                           #        #"<<endl;
  cout<<"#        #                              ######################                        #                   ######             ######        #"<<endl;
  cout<<"#        #        ########                       ##                       #############                                                    #"<<endl;
  cout<<"#                                                ##  x                                                                                     #"<<endl;
  cout<<"#                                                ##                                                                                        #"<<endl;
  cout<<"#                                                ##       O                                                                                #"<<endl;
  cout<<"#############################      x         ##########                ########                ##################              #############"<<endl;
  cout<<"#                                                                                                                              #           #"<<endl;
  cout<<"#         x                                                                                                                    #    x      #"<<endl;
  cout<<"#                                                                                                                              #           #"<<endl;
  cout<<"#    O             ######################             ##################                         ################              #           #"<<endl;
  cout<<"#                                                              #                                                #                          #"<<endl;
  cout<<"#                                                              #                                 x           x  #                          #"<<endl;
  cout<<"#           x              x                         x         #       x                                        #                          #"<<endl;
  cout<<"#                                                              #                                                #                          #"<<endl;
  cout<<"############################                     #############################            #######################             ##############"<<endl;
  cout<<"#                                                                                                                                          #"<<endl;
  cout<<"#                                         x                  x                                                                             #"<<endl;
  cout<<"#                                                                                                                                  x       #"<<endl;
  cout<<"#                                                                                                                                          #"<<endl;
  cout<<"############################################################################################################################################";  
  setColor(7);
 } 
 void printHeader()
{
  setColor(13);
  cout<<R"(                                _     _  _      _  _ _   _   __ ___  _ _ _  _     _        _     _  _ ___   _ _ _    _ __       )"<<endl;
  cout<<R"(                               | \   / || \    / || \ \ / | /  ____|| \   \\ \   / /      | \   / || \___| | \   \  / __ \      )"<<endl;
  cout<<R"(                               | |___| || |    | || |\ \| |/  /     | | |) |\ \ / /       | |___| || |___  | | |) || /  \ |     )"<<endl;
  cout<<R"(                               | |___| || |    | || | \ | || |    _ | |_ _/  \ | /        | |___| || |___| | |_ _/ | |  | |     )"<<endl;
  cout<<R"(                               | |   | || \_ _ / || |  \| || \_ _| || |\ \    | |         | |   | || |___  | |\ \  | \__/ |     )"<<endl;
  cout<<R"(                               |_/   \_| \_ _ __/ |_/   |_| \_ __| ||_/ \_\   |_|         |_/   \_||_/___| |_/ \_\  \_ __/      )"<<endl;
  setColor(7);
}
void winner()
{
    setColor(13);
    cout<<R"(                      **    **    ****     **     **       **    **     **     ****     ***     **       )"<<endl;
    cout<<R"(                       ** **    *      *   **     **       **   ** **   **   *      *   ** **   **       )"<<endl;
    cout<<R"(                        **     *        *  **     **       **  **   **  **  *        *  **  **  **       )"<<endl;
    cout<<R"(                        **      *      *   **     **       ** **     ** **   *      *   **   ** **       )"<<endl;
    cout<<R"(                        **        ****       *****          **         **      ****     **     ***       )"<<endl;
    setColor(7);
}







