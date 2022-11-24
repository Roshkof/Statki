#pragma once
#include<vector>
#include"Units.hpp"

using namespace std;
//GAMESTATE

enum class GameState
{
    RUNNING,
    FINISHED_WIN,
    FINISHED_LOSS
};

//POLE PLANSZY-------------------------------------------------

struct Field
{
    bool isHit;
    bool isShip;
};

//PLANSZA DO GRY------------------------------------------------
class Board
{
 int width;
 int height;
 vector <Field> board;

 public:
    Board(int width, int height);

    void displayBoard();
    int getBoardWidth() const;
    int getBoardHeight() const;
    char getEnemyFieldInfo(int row, int col);
    char getAllyFieldInfo(int row, int col);
    GameState getGameState();

    int countNeighbours(int row, int col);
    int valueAt(int row,int col);
    void setShip(Ship& setting_ship);
    void shootShip(int row, int col);


 private:
    Field& place(int row,int col);
};

//KONTROLA ROZGRYWKI--------------------------------------------
class BoardView
{
 Board &b1;
 Board &b2;
 public:
    BoardView(Board &b1,Board &b2);
    
    void displayEnemyBoard();
    void displayAllyBoard();
    void menu(Board &underFire);
    void playerChange();
};

class BoardControl
{
 Board &b1;
 Board &b2;
 BoardView &viewPlayerOne;
 BoardView &viewPlayerTwo;
 public:
    BoardControl(Board &b1,Board &b2,BoardView &viewPlayerOne,BoardView &viewPlayerTwo);

    void play();
};
