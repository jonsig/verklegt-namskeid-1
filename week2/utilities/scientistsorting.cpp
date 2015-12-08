#include "utilities/scientistsorting.h"
using namespace std;

ScientistSorting::ScientistSorting()
{

}

string ScientistSorting::whichSort(string column, bool sortInAscendingOrder)
{
 string howToSort;
 this->sortColumn = column;
 this->sortInAscendingOrder = sortInAscendingOrder;

    if (sortColumn == "name")
    {
        if (sortInAscendingOrder)
        {
            howToSort = "Select * FROM scientists ORDER BY name ASC";
        }
        else
        {
            howToSort = "Select * FROM scientists ORDER BY name DESC";
        }
    }
    else if (sortColumn == "sex")
    {
        if (sortInAscendingOrder)
        {
            howToSort = "Select * FROM scientists ORDER BY sex ASC";
        }
        else
        {
            howToSort = "Select * FROM scientists ORDER BY sex DESC";
        }
    }
    else if (sortColumn == "yearBorn")
    {
        if (sortInAscendingOrder)
        {
            howToSort = "Select * FROM scientists ORDER BY yearBorn ASC";
        }
        else
        {
            howToSort = "Select * FROM scientists ORDER BY yearBorn DESC";
        }
    }
    else if (sortColumn == "yearDied")
    {
        if (sortInAscendingOrder)
        {
            howToSort = "Select * FROM scientists ORDER BY yearDied IS NULL, yearDied ASC";
        }
        else
        {
            howToSort = "Select * FROM scientists ORDER BY CASE WHEN yearDied IS NULL THEN 0 ELSE 1 END, yearDied DESC";
        }
    }

    return howToSort;
}



