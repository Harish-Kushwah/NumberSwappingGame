#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//Standard function to user colors in text
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

//contains various colors
class color
{                                          
    public:                              
    void green(){
        SetConsoleTextAttribute(h,2);
    }
    void blue(){
        SetConsoleTextAttribute(h,1);
    }
    void aqua(){
        SetConsoleTextAttribute(h,3);
    }
    void red(){
        SetConsoleTextAttribute(h,4);
    }
    void gray(){
        SetConsoleTextAttribute(h,8);
    }
    void yellow(){
        SetConsoleTextAttribute(h,6);
    }
    void white(){
        SetConsoleTextAttribute(h,7);
    }
    void lightBlue(){
        SetConsoleTextAttribute(h,9);
    }
    void lightGreen(){
        SetConsoleTextAttribute(h,10);
    }
    void lightYellow(){
        SetConsoleTextAttribute(h,14);
    }
    void lightPurple(){
        SetConsoleTextAttribute(h,13);
    }
    void lightAqua(){
        SetConsoleTextAttribute(h,11);
    }
    void brightWhite(){
        SetConsoleTextAttribute(h,14);
    }
};
//user class used all methods of color
class User:public color
{
    private:
    string username;
    public:
    void setDataOfUser(){         //sets the name of user
         lightAqua();
         cout<<"Enter Name :";
         lightGreen();
         getline(cin,username);
         white();

    }
    void showUser()
    {
        cout<<username;
    }
   
};
//class Interface is used for userinterface work 
class Interface:public User
{
    public:
    void frontPage();   //shows the contain on front page
    void rules();       //shows all rules of the game
    void line();        //print long line
    void help();        //shows many other command of game
    int intro();        //gives the into of the game
};
//Class NumberSwap is derived class of interface
class NumberSwap:public Interface
{
    private:
    int arr[5][5];       //generated matrix;
    int n,m;             //dimension of matrix
    int win[5][5],move;  //wining matrix 
    public:
    void setDim(int row,int col){ n=row; m=col;} //sets the dimension of matrix
    void generateMatrix();                       //generates the matrix
    void showMatrix(int arr[][5]);               //print the matrix in boxes
    int count(int);                              //counts the number of digits in number
    void line1(int );                            //print line between num in matrix
    void winMatrix();                            //generate the wining matrix
    void checkMatrix();                          //check whether the matrix is equal to wining matrix
    void play();                                 //contains all actions required for play the game
    void right();                                //moves empty space to right
    void upp();                                  //moves empty space to upp
    void down();                                 //moves empty space to down
    void left();                                 //moves empty space to left
    int indexRow();                              //returns the row index of empty space
    int indexCol();                              //returns thr column index of empty space
    void statusBar();                            //prints status bar 
    void show();                                 //shows the interface while playing
    void start();                                //starts the game
    int unqNum(int);                             //generate unique number
    void setMove(int);                           //sets the total moves
};
//shows the inerface while playing
void NumberSwap:: show(){
        statusBar();
        winMatrix();
        SetConsoleTextAttribute(h,9);
        cout<<endl<<"Current Matrix :";
        SetConsoleTextAttribute(h,7);
        showMatrix(arr);
    }
//sets the number of moves
void NumberSwap::setMove(int mv)
{
    move=mv;
}
//status bar of the game
void NumberSwap::statusBar()
{
    lightBlue(); //sets light blue color
    cout<<"___________________[  ";
    lightGreen();//sets light green color
    cout<<"GAMMING MODE ";
    lightBlue();
    cout<<" ]______________________ \n";
    line();
    lightGreen();
    showUser(); //to show username
    lightPurple();
    cout<<"                                            Move :"<<move<<endl;
    white();//wight color
    line();
    //cout<<"\n\n";


}
//prints long line
void Interface::line()
{
    lightAqua(); 
    for(int i=0;i<15;i++)
    {
        cout<<"____";
    }
    cout<<"\n\n";
}
void Interface::rules()
{
    line();
    cout<<"------[ RULES ]----\n\n";
    yellow(); 
    cout<<"____[ How to play game  ]_____\n";
    gray();
    cout<<"  * Their is square matrix is given to you \n ";
    cout<<" * You have to convert int into win matrix \n";
    cout<<"  * You have limited amount of moves\n";
    yellow();
    cout<<"__[  How to transformed matrix  ]__\n";
    gray();
    cout<<"  - press [RIGHT] ARROW to move space to right \n";
    cout<<"  - press [LEFT ] ARROW to move space to left \n";
    cout<<"  - press [UPP  ] ARROW to move space to upp \n";
    cout<<"  - press [DOWN ] ARROW to move space to down \n";
    line();
    brightWhite();

}
void Interface::help()
{
    cout<<endl;
    line();
    gray(); //sets gray color
    cout<<"Enter [h] to HELP\n";
    cout<<"Enter [r] to see RULES of the game\n";
    cout<<"Enter [e] to EXIT form the game\n";
    cout<<"Enter [s] to SUBMIT Matrix\n";
    cout<<"Enter [c] to CLEAR screen\n";
    line();
    white();//sets white color
    

}
//gives the intro to the user
int Interface::intro()
{
    char ch;
    line();
    lightBlue();
    cout<<" ___________[  ";
    lightGreen();
    cout<<"WELCOME IN NUMBER SWAPPING GAME ";
    lightBlue();
    cout<<" ]___________ \n";
    lightAqua();
    line();
    cout<<"BENEFITS OF PLAYING GAME \n";
    yellow();
    cout<<"   1] THINKING POWER INCREASES \n";
    cout<<"   2] IMPROVE DECISION MAKING SKILL\n";
    cout<<"   3] HELPS TO BUILD LOGIC\n";
    white();
    cout<<"\n  LET'S PLAY..!\n";
    cout<<"ENTER [Y/y] to move forward :";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    return 1;
    else
    return 0;

}
//shows the front page to the user
void Interface::frontPage()
{
    if(intro()){
    cin.ignore();
    setDataOfUser();
    rules();
    }
    else{
    cout<<"Thanks for ";
    showUser();
    cout<<" visiting \n";
    exit(0);
    }
}
//return row index where space present 
int NumberSwap::indexRow()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==48){
            return i;
            }
        }
    }
    return -1;
}
//return col index where space present
int NumberSwap::indexCol()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==48){
            return j;
            }
        }
    }
    return -1;
}
//move space to right
void NumberSwap::right()
{
    int i=indexRow();
    int j=indexCol();
    if(j<(n-1)){
    swap(arr[i][j],arr[i][j+1]);
    }
    else
    cout<<"Sorry we can't perform "<<endl;
}
//move space to left
void NumberSwap::left()
{
    int i=indexRow();
    int j=indexCol();
    if(j>0)
    swap(arr[i][j],arr[i][j-1]);
    else
    cout<<"Sorry we can't perform "<<endl;
}
//move space to upp
void NumberSwap::upp()
{
    int i=indexRow();
    int j=indexCol();
    if(i>0)
    swap(arr[i][j],arr[i-1][j]);
    else
    cout<<"Sorry we can't perform "<<endl;
}
//move space to down
void NumberSwap::down()
{
    int i=indexRow();
    int j=indexCol();
    if(i<(m-1))
    swap(arr[i][j],arr[i+1][j]);
    else
    cout<<"Sorry we can't perform "<<endl;
}
void NumberSwap::play()
{
    generateMatrix();
    show();
    int flag=0;
    while(1){
    if(move>0){    
    cout<<endl<<"Enter key :";
    char key;  //accept the ASCI code of keys
    key=getch();
    switch(key)
    {
        case 101: //ascii of e
        lightPurple();
        cout<<"Thanks for playing ";
        white();
        flag=1;
        break;
        case 69: //ascii of E
        lightPurple();
        cout<<"Thanks for playing";
        white();
        flag=1;
        break;
        case KEY_LEFT: //left <-
        left();
        move--;
        system("cls");
        show();
        break;
        case KEY_UP: //upp arrow
        upp();
        move--;
        system("cls");
        show();
        break;
        case KEY_RIGHT: //right ->
        right();
        move--;
        system("cls");
        show();
        break;
        case KEY_DOWN: //down arrow
        down();
        move--;
        system("cls");
        show();
        break;
        case 115:      //ASCII s 
        checkMatrix();
        break;
        case 104:      //ASCII h
        help();
        break;
        case 114:      //ASCII e
        cout<<endl;
        rules();
        break;
        case 99:         //ASCII c
        system("cls");
        show();
        break;
        default:
        cout<<"Enter a valid choice ";

    }
    if(flag==1)
    break;
    }
    else{
        system("cls");
        blue();
        cout<<"Sorry ";
        showUser();
        cout<<" no more moves "<<endl;
        white();
        break;
    }
    }
}
//checks whether the matrix are same or not
void NumberSwap::checkMatrix()
{
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=win[i][j]){
                flag=1;
            }
        }
    }
    if(flag==0){
        system("cls");
        SetConsoleTextAttribute(h,3); //aqua
        cout<<"Congratulation,";
        showUser();
        cout<<" You won the game..!! :"<<endl;
        SetConsoleTextAttribute(h,7);//white
        exit(0);
    }
    else{
        system("cls");
        SetConsoleTextAttribute(h,3); //aqua
        cout<<"Sorry ";
        showUser();
        cout<<" you lose the game..!!"<<endl;
        SetConsoleTextAttribute(h,7);//white
        exit(0);
    }
}
//winning matrix
void NumberSwap::winMatrix()
{
    SetConsoleTextAttribute(h,9); //set light blue
     cout<<"Wining Matrix :";
     SetConsoleTextAttribute(h,7);
    int num=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            win[i][j]=num;
            num++;
            if(i==n-1&&j==m-1)
            win[i][j]='0';
        }
    }
    SetConsoleTextAttribute(h,6);
    showMatrix(win);
    SetConsoleTextAttribute(h,7);
}
//counts the digit
int NumberSwap::count(int n)
{
    int ct=0;
    while(n>0){
        n/=10;
        ct++;
    }
    return ct;
}
//print the line
void NumberSwap::line1(int n )
{
for(int i=0;i<n;i++){
        cout<<" _____";
    }
    cout<<endl;
}
//generates unique number
int NumberSwap::unqNum(int in)
{
    
    srand(0);
    int size=n*m;
    int numarr[size+1];
    int hash[size+1];
    for(int i=0;i<=size;i++){
        hash[i]=0;
    }
    int k=size,num,j=1;
    for(int i=0;i<k;i++){
     num=(rand()%(size))+1;  //generate number upto size-1
        if(hash[num]==0){
         if(num!=size){
         numarr[j]=num;
         j++;
         }
        }
        else
        k++;
        
      hash[num]++;
    }
    return numarr[in];

}
//generate random matrix;
void NumberSwap::generateMatrix()
{
   
   int i,j;
   int size=n*m;                //size of matrix 
   int in=1;                   //initial num
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        arr[i][j]=unqNum(in);
        in++;
        if(i==n-1&&j==m-1)
        arr[i][j]='0';
    }
   }
} 
//show the matrix
void NumberSwap::showMatrix(int arr[][5])
{
   cout<<endl;
     line1(m);
    for(int i=0;i<n;i++){
        cout<<"| ";
      for(int j=0;j<m;j++){
        if(arr[i][j]==48){
            cout<<' '<<' '<<' ';
        }
        else{
        cout<<arr[i][j]<<" ";
        }
        if(count(arr[i][j])==2)
         cout<<"  |";
         else
         cout<<"   |";
    }
    cout<<endl;
   }
   line1(m);
}  
//start the game
void NumberSwap::start()
{
    char choice;
    white();
    cout<<"Enter[Y/N] to start game :";
    cin>>choice;
    if(choice=='Y'||choice=='y'){
    system("cls");
    play();
    }
    else{
        cout<<"Have a nice day ";
        exit(0);
    }

}
int main()
{
   NumberSwap n1;
   Interface i1;
    n1.setDim(4,4); //sets 4X4 matrix
    n1.setMove(100); //total 100 moves
    n1.frontPage();
    n1.start();
    return 0;
}