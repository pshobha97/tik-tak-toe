#include <iostream>
#include<string>
#include<stdlib.h>//this will define the system("cls")




using namespace std;

  char turn='X';
  bool draw=false;
  int row,column;

 char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void displayBoard(){
system("cls");//to clear previous thing on screen


    cout<<"                  Tick Cross Game"<<endl<<endl;
    cout<<"Player1 [X]"<<endl<<endl;
    cout<<"Player2 [O]"<<endl;
    cout<<"\t\t    |   |    "<<endl;
    cout<<"\t\t "<<board[0][0]<<"  | " <<board[0][1] <<" | "<< board[0][2]  <<endl;
    cout<<"\t\t____|___|____"<<endl;
    cout<<"\t\t    |   |    "<<endl;
    cout<<"\t\t "<<board[1][0]<<"  | " <<board[1][1] <<" | "<< board[1][2]  <<endl;
    cout<<"\t\t____|___|____"<<endl;
    cout<<"\t\t    |   |    "<<endl;
 cout<<"\t\t "<<board[2][0]<<"  | " <<board[2][1] <<" | "<< board[2][2]  <<endl;
    cout<<"\t\t    |   |    "<<endl<<endl;

}
void playerTurn(){
    int choice;
    if(turn=='X'){
    cout<<"\tPlayer1[X] turn:";}
    else
       {cout<<"\tPlayer2[O] turn:";}

 cin>>choice;
 switch(choice){


    case 1:row=0;column=0;break;
    case 2:row=0;column=1;break;
    case 3:row=0;column=2;break;
    case 4:row=1;column=0;break;
    case 5:row=1;column=1;break;
    case 6:row=1;column=2;break;
    case 7:row=2;column=0;break;
    case 8:row=2;column=1;break;
    case 9:row=2;column=2;break;

    default:
        cout<<"invalid choice\n";
        break;}

        if(turn=='X'&& board[row][column]!='X'&&board[row][column]!='O'){
            board[row][column]='X';
            turn='O';
            }
            else if(turn=='O'&& board[row][column]!='X'&&board[row][column]!='O'){
                board[row][column]='O';
                turn='X';
            }
            else{

                cout<<"BOX IS FILLED! PLEASE TRY AGAIN."<<endl;
                playerTurn();
            }
            displayBoard();
}
bool gameover(){
             //check win

             for(int i=0;i<3;i++){


             if(board[i][0]==board[i][1]&&board[i][0]==board[i][2])
             return false;
             if(board[0][i]==board[1][i]&&board[0][i]==board[2][i])
                return false;
             if((board[0][0]==board[1][1]&&board[0][0]==board[2][2]) ||(board[0][2]==board[1][1]&&board[0][2]==board[2][0]))
                return false;

             }
                //check box

              for(int i=0;i<3;i++)
              for(int j=0;j<3;j++)
              if(board[i][j]!='X'&&board[i][j]!='O')
              return true;
                //check draw

              draw=true;
              return false;



}
int main()
{



  while(gameover()){
    displayBoard();

    playerTurn();


    }
    if(turn=='X'&&draw==false){
        cout<<"Player2[O] Wins! CONGRATULATIONS!!"<<endl;

    }
    else if(turn=='O'&&draw==false){
          cout<<"Player1[X] Wins! CONGRATULATIONS!!"<<endl;
    }
    else
        cout<<"GAME DRAW!!\n";
    return 0;
}
