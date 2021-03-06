#ifndef HumanPyramids_Included
#define HumanPyramids_Included

/**
 * Given a human pyramid in which each person weighs exactly 160 pounds,
 * returns the weight on the back of the person at the specified row and
 * column in the human pyramid. Rows and columns are zero-indexed, so,
 * for example, weightOnBackOf(2, 0) would give the weight on the back of
 * the leftmost person in the third row from the top of the pyramid.
 *
 * If the arguments are out of range, this function should call error() to
 * report an error.
 *
 * @param row The zero-indexed row of the person in the pyramid.
 * @param col The zero-indexed column of the person in the pyramid.
 * @return The weight on the back of that person.
 */
class Human{
    int row;
    int col;
public:
    Human(int row_, int col_):row(row_), col(col_)
    {}
    const int& getRow() const{
        return row;
    }
    const int& getCol() const{
        return col;
    }
    bool operator<(const Human& humanCmp)const{
        //return (this->row < humanCmp.row && this->col < humanCmp.col);
        return row < humanCmp.row || (row == humanCmp.row && col < humanCmp.col);;
    }
};

int weightOnBackOf(int row, int col);

bool inBounds(int row, int col);

#endif
