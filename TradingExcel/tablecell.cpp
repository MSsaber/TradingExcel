#include "tablecell.h"

TableCell::TableCell()
{
}

TableCell::~TableCell()
{
}

bool TableCell::write(QXlsx::Document &xlsx)
{
    return xlsx.write(row, col, value, format);
}
