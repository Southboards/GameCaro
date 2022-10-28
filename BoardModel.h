#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <iostream>
#include "vector"


using namespace std;



/**********
 * API
**********/

class Board
{
private:
    int width;
    int height;
    vector<vector<bool>> board;
public:
    Board();
    Board(int width, int height);


    /*
     * @brief set width of board game
     * @param width: width of board game
     */
    void setWidth(int width);

    /*
     * @brief set height of board game
     * @param height: height of board game
     */
    void setHeight(int height);

    /*
     * @brief set data board
     * @param board: data board vector<vector<bool>>
     */
    void setBoard(vector<vector<bool>> board);


    /*
     * @brief get width of board game
     * @return width of this board game
     */
    int getWidth();

    /*
     * @brief set height of board game
     * @return height of this board game
     */
    int getHeight();

    /*
     * @brief get board game
     * @return this board game (ref)
     */
    vector<vector<bool>>& getBoard();




};

#endif // BOARDMODEL_H
