#ifndef BOARD_H
#define BOARD_H
#include "pieces.h"

class Board
{
public:
    static int x_convert_column(int x);
    static int y_convert_row(int y);
    static int column_convert_x(int column);
    static int row_convert_y(int row);
};
#endif // BOARD_H
