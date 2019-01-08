#include "board.h"

//mouse's x convert into array's column.
Board::x_convert_column(int x)
{
    int a=x-70;
    int b=a/65;
    int c=a%65;
    return (0<=b&&b<9&&0<=c&&c<=60) ? b : -1;
}

//mouse's y convert into array's row.
Board::y_convert_row(int y)
{
    int a=y-80;
    int b=a/65;
    int c=a%65;
    return (0<=b&&b<10&&0<=c&&c<=60) ? b : -1;
}

//chessboard column convert into x-coordinate.
Board::column_convert_x(int column)
{
    return 65*column+70;
}

//chessboard row convert into y-coordinate.
Board::row_convert_y(int row)
{
    return 65*row+80;
}
