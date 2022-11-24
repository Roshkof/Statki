#include<iostream>
#include<string>
#include"Statki.hpp"
#include"Units.cpp"
#include"Units.hpp"
#include<vector>

using namespace std;
//KOD DLA PLANSZYY--------------------------------------------------------
Board::Board(int width, int height)
{
 this->width=width;
 this->height=height;
 board.resize(width*height);

 for(int i=0;i<(width*height);i++)
 {
    board[i].isShip=false;
    board[i].isHit=false;
 }
}

void Board::displayBoard()
{
    for(int row=0;row<height;row++)
    {
        for(int col=0;col<width;col++)
        {
            if(place(row,col).isHit && place(row,col).isShip){cout<<"[X]";}
            if(place(row,col).isHit && place(row,col).isShip==false){cout<<"[O]";}
            if((place(row,col).isHit==false) && (place(row,col).isShip==false)){cout<<"[.]";}
            if((place(row,col).isHit==false) && (place(row,col).isShip)){cout<<"[S]";}
        }
     cout<<endl;
    }
}

int Board::getBoardWidth() const
{
    return width;
}

int Board::getBoardHeight() const
{
    return height;
}

char Board::getEnemyFieldInfo(int row, int col)
{
 if(place(row,col).isHit && (place(row,col).isShip)){return 'X';}
 if(place(row,col).isHit && (place(row,col).isShip==false)){return 'O';}
 if((place(row,col).isHit==false) && (place(row,col).isShip==false)){return '.';}
 if((place(row,col).isHit==false) && (place(row,col).isShip)){return '.';} 
 return 'z';  
}

char Board::getAllyFieldInfo(int row, int col)
{
 if(place(row,col).isHit && (place(row,col).isShip)){return 'X';}
 if(place(row,col).isHit && (place(row,col).isShip==false)){return 'O';}
 if((place(row,col).isHit==false) && (place(row,col).isShip==false)){return '.';}
 if((place(row,col).isHit==false) && (place(row,col).isShip)){return 'S';} 
 return 'z';  
}

int Board::countNeighbours(int row, int col)
{
    int neighbourCounter=0;
    for(int i=row-1;i<=row+1;i++)
    {
        for(int j=col-1;j<=col+1;j++)
        {
            if((i != row || j != col) && ((i >= 0 && i <= height - 1 ) && (j >= 0 && j <= width - 1)))
            {
                if(place(i,j).isShip) {neighbourCounter++;}
            }
        }
    }

    return neighbourCounter;  
}

Field& Board::place(int row,int col)
{
    return board[((row*width)+col)];
}

int Board::valueAt(int row,int col)
{
    return ((row*width)+col);
}

GameState Board::getGameState()
{
    int shipsInPlay=20;
    for(int i=0;i<(width*height);i++)
    {
        if(board[i].isHit&&board[i].isShip){shipsInPlay--;}
    }
    if(shipsInPlay==0){return GameState::FINISHED_LOSS;}
    return GameState::RUNNING;
}

void Board::setShip(Ship& setting_ship)
{
    int row=0,col=0,quantity=0,rowLast=0,colLast=0,end=0;
    if(setting_ship.getShipSize()==1)
    {
        while(true)
        {
            if(quantity==4){break;}
            displayBoard();
            cout<<"Rozstawiasz SingleShip"<<endl;
            cout<<"Podaj wiersz:";
            cin>>row;
            cout<<endl<<"Podaj kolumne:";
            cin>>col;
            if(countNeighbours(row,col)==0)
            {
                place(row,col).isShip=true;
                quantity++;
            }
            else{cout<<"Niepoprawne pole! Podaj inne"<<endl;}
        }
    }
    quantity=0;
    if(setting_ship.getShipSize()==2)
    {
        while(true)
        {
            if(quantity==3){break;}
            displayBoard();
            cout<<"Rozstawiasz DoubleShip"<<endl;
            cout<<"Podaj wiersz:";
            cin>>row;
            cout<<endl<<"Podaj kolumne:";
            cin>>col;
            if(countNeighbours(row,col)==0)
            {
                place(row,col).isShip=true;
                rowLast=row;
                colLast=col;
                while(true)
                {
                    system("clear");
                    displayBoard();
                    cout<<"Rozstawiasz DoubleShip"<<endl;
                    cout<<"Podaj wiersz:";
                    cin>>row;
                    cout<<endl<<"Podaj kolumne:";
                    cin>>col;
                    if(valueAt(row,col)==valueAt(rowLast,colLast)-1||valueAt(row,col)==valueAt(rowLast,colLast)+1||valueAt(row,col)==valueAt(rowLast,colLast)-10||valueAt(row,col)==valueAt(rowLast,colLast)+10)
                    {
                        place(row,col).isShip=true;
                        quantity++;
                        break;
                    }
                    else{cout<<"Niepoprawne pole! Podaj inne"<<endl;}
                 
                }
            }
            else{cout<<"Niepoprawne pole! Podaj inne"<<endl;}
        }

    }
    quantity=0;
    if(setting_ship.getShipSize()==3)
    {
        while(true)
        {
            end=0;
            if(quantity==2){break;}
            displayBoard();
            cout<<"Rozstawiasz TripleShip"<<endl;
            cout<<"Podaj wiersz:";
            cin>>row;
            cout<<endl<<"Podaj kolumne:";
            cin>>col;
            if(countNeighbours(row,col)==0)
            {
                place(row,col).isShip=true;
                rowLast=row;
                colLast=col;
                while(end<2)
                {
                    system("clear");
                    displayBoard();
                    cout<<"Rozstawiasz TripleShip"<<endl;
                    cout<<"Podaj wiersz:";
                    cin>>row;
                    cout<<endl<<"Podaj kolumne:";
                    cin>>col;
                    if(valueAt(row,col)==valueAt(rowLast,colLast)-1||valueAt(row,col)==valueAt(rowLast,colLast)+1||valueAt(row,col)==valueAt(rowLast,colLast)-10||valueAt(row,col)==valueAt(rowLast,colLast)+10)
                    {
                        place(row,col).isShip=true;
                        rowLast=row;
                        colLast=col;
                        end++;
                    }
                    else{cout<<"Niepoprawne pole! Podaj inne"<<endl;}  
                }
                quantity++;
            }
            else{cout<<"Niepoprawne pole! Podaj inne"<<endl;}
        }   
    }
    quantity=0;
    if(setting_ship.getShipSize()==4)
    {
        while(true)
        {
            end=0;
            if(quantity==1){break;}
            displayBoard();
            cout<<"Rozstawiasz QuadraShip"<<endl;
            cout<<"Podaj wiersz:";
            cin>>row;
            cout<<endl<<"Podaj kolumne:";
            cin>>col;
            if(countNeighbours(row,col)==0)
            {
                place(row,col).isShip=true;
                rowLast=row;
                colLast=col;
                while(end<3)
                {
                    system("clear");
                    displayBoard();
                    cout<<"Rozstawiasz QuadraShip"<<endl;
                    cout<<"Podaj wiersz:";
                    cin>>row;
                    cout<<endl<<"Podaj kolumne:";
                    cin>>col;
                    if(valueAt(row,col)==valueAt(rowLast,colLast)-1||valueAt(row,col)==valueAt(rowLast,colLast)+1||valueAt(row,col)==valueAt(rowLast,colLast)-10||valueAt(row,col)==valueAt(rowLast,colLast)+10)
                    {
                        place(row,col).isShip=true;
                        rowLast=row;
                        colLast=col;
                        end++;
                    }
                    else{cout<<"Niepoprawne pole! Podaj inne"<<endl;}  
                }
                quantity++;
            }
            else{cout<<"Niepoprawne pole! Podaj inne"<<endl;}
        }

    }
}

void Board::shootShip(int row,int col)
{
 place(row,col).isHit=true;
}

//KONTROLA ROZGRYWKI-----------------------------------------------------

BoardView::BoardView(Board &b1,Board &b2):b1(b1), b2(b2)
{
}
void BoardView::displayEnemyBoard()
{
    cout<<"Plansza przeciwnika:"<<endl;
    for(int row=0;row<b1.getBoardHeight();row++)
    {
        for(int col=0;col<b1.getBoardWidth();col++)
        {
         cout<<"["<< b1.getEnemyFieldInfo(row,col) << "]";
        }
     cout<<endl;
    }    
}

void BoardView::displayAllyBoard()
{
    cout<<"Twoja Plansza:"<<endl;
    for(int row=0;row<b2.getBoardHeight();row++)
    {
        for(int col=0;col<b2.getBoardWidth();col++)
        {
         cout<<"["<< b2.getAllyFieldInfo(row,col) << "]";
        }
     cout<<endl;
    }   
}

void BoardView::menu(Board &underFire)
{
 int row=0,column=0;
    cout<<"Wybierz pole na planszy które chcesz zestrzelic"<<endl;
    cout<<"Jaki wiersz?";
    cin>>row;
    cout<<endl;
    cout<<"Jaka kolumna?";
    cin>>column;
    underFire.shootShip(row,column);
}

void BoardView::playerChange()
{
 system("clear");
 cout<<"Nastapi teraz zamiana graczy "<<endl;
 cout<<"-----------------------------"<<endl;
 cout<<"-----------------------------"<<endl;
 cout<<"wcisnij ENTER aby kontynuowac"<<endl;
 getchar();getchar();
}



//KONSTRUKTOR
BoardControl::BoardControl(Board &b1,Board &b2,BoardView &viewPlayerOne,BoardView &viewPlayerTwo):b1(b1),b2(b2),viewPlayerOne(viewPlayerOne),viewPlayerTwo(viewPlayerTwo)
{ 
}

void BoardControl::play()
{
 while((b1.getGameState()==GameState::RUNNING) && (b2.getGameState()==GameState::RUNNING))
 {
  system("clear");
  for(int i=0;i<3;i++)
  {
    system("clear");
    cout<<"Tura Gracza Pierwszego"<<endl;
    viewPlayerOne.displayEnemyBoard();
    viewPlayerOne.displayAllyBoard();
    viewPlayerOne.menu(b1);
    if(b1.getGameState()==GameState::FINISHED_LOSS){break;}
  }
  if(b1.getGameState()==GameState::FINISHED_LOSS){break;}
  system("clear");
  viewPlayerOne.displayEnemyBoard();
  viewPlayerOne.displayAllyBoard();
  cout<<"Nastapi zaraz zmiana graczy"<<endl;
  getchar();getchar();

  viewPlayerOne.playerChange();

  system("clear");
  for(int j=0;j<3;j++)
  {
    system("clear");
    cout<<"Tura Gracza Drugiego"<<endl;
    viewPlayerTwo.displayEnemyBoard();
    viewPlayerTwo.displayAllyBoard();
    viewPlayerTwo.menu(b2);
    if(b2.getGameState()==GameState::FINISHED_LOSS){break;}
  }
  if(b2.getGameState()==GameState::FINISHED_LOSS){break;}
  system("clear");
  viewPlayerTwo.displayEnemyBoard();
  viewPlayerTwo.displayAllyBoard();
  cout<<"Nastapi zaraz zmiana graczy"<<endl;
  getchar();getchar();

  viewPlayerTwo.playerChange();

 }
 system("clear");
 if(b1.getGameState()==GameState::FINISHED_LOSS){cout<<"Wygrywa gracz nr 2";}
 if(b2.getGameState()==GameState::FINISHED_LOSS){cout<<"wygrywa gracz nr 1";}
}