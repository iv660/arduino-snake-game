#if !defined(GRID_LOCATION_H)
#define GRID_LOCATION_H

struct GridLocation
{
    int column = 0;
    int row = 0;

    inline int operator==(GridLocation other)
    {
        return (this->column == other.column) && (this->row == other.row);
    }
};

#endif // GRID_LOCATION_H
