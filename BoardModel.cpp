#include "Headers/Model/BoardModel.h"

Board::Board()
{

}

/* Constructor */
Board::Board(int width, int height)
{
    this->width = width;
    this->height = height;

    board.resize(height);

    for (int i=0;i<height;i++)
    {
        board[i].resize(width);
        for (int j=0;j<width;j++)
        {
            board[i][j] = 0;
        }
    }
}



/*
 * @brief set width of board game
 * @param width: width of board game
 */
void Board::setWidth(int width)
{
    this->width = width;
}

/*
 * @brief set height of board game
 * @param height: height of board game
 */
void Board::setHeight(int height)
{
    this->height = height;
}


/*
 * @brief set data board
 * @param board: data board vector<vector<bool>>
 */
void Board::setBoard(vector<vector<bool>> board)
{
    this->board = board;
}



/*
 * @brief get width of board game
 * @return width of this board game
 */
int Board::getWidth()
{
    return width;
}

/*
 * @brief set height of board game
 * @return height of this board game
 */
int Board::getHeight()
{
    return height;
}


/*
 * @brief get board game
 * @return this board game
 */
vector<vector<bool>>& Board::getBoard()
{
    return board;
}





