#include <iostream>
#include"Statki.hpp"
#include"Units.hpp"

 using namespace std;
int main()
{
    system("clear");
    cout<<"Zug Zug"<<endl;
    cout<<"Testowa wersja Statkow"<<endl;
    cout<<"Aby rozpoczac wcisnij ENTER"<<endl;
    getchar();
    cout<<"Nastapi teraz proces rozlozenia statkow na planszy"<<endl;
    getchar();
    SingleShip ship1;
    DoubleShip ship2;
    TripleShip ship3;
    QuadraShip ship4;
    Board b1(10,10);
    Board b2(10,10);
    cout<<"Dla gracza nr 1"<<endl;
    b2.setShip(ship1);
    b2.setShip(ship2);
    b2.setShip(ship3);
    b2.setShip(ship4);
    system("clear");
    cout<<"Nastapi teraz zamiana stron"<<endl;
    getchar();getchar();
    system("clear");
    cout<<"Dla gracza nr 2"<<endl;
    b1.setShip(ship1);
    b1.setShip(ship2);
    b1.setShip(ship3);
    b1.setShip(ship4);
    BoardView viewPlayerOne{b1,b2};
    BoardView viewPlayerTwo{b2,b1};
    BoardControl ctrl{b1,b2,viewPlayerOne,viewPlayerTwo};
    system("clear");
    cout<<"Nacisnij ENTER aby rozpoczac ture gracza pierwszego"<<endl;
    getchar();getchar();
    ctrl.play();
//    viewPlayerOne.displayEnemyBoard();
 //   viewPlayerOne.displayAllyBoard();
    
}
