#include "onetable.h"

OneTable::OneTable()
{
}

OneTable::TableHeader &OneTable::get_table_header()
{
    return this->_header;
}

OneTable::TableRows &OneTable::get_table_data()
{
    return this->_rows;
}

void OneTable::add_table_header(const TableCell &header)
{
    this->_header.push_back(header);
}

void OneTable::add_table_row(const TableRow &row)
{
    this->_rows.push_back(row);
}

void OneTable::add_table_rows(const TableRows &row)
{
    this->_rows.insert(this->_rows.end(), row.begin(), row.end());
}

bool OneTable::fill_table(QXlsx::Document *excel, int begin_row, int *end_row)
{
    int row = begin_row, col = 0, max_row = 0;
    for (TableHeader::iterator header = _header.begin();
         header != _header.end(); header++) {
        excel->write(header->row+row ,header->col+col,
                     header->value, header->format);
        col += header->col;
        if (header->row > max_row) {
            max_row = header->row;
        }
    }

    col = 0;
    row += max_row;
    for (TableRows::iterator row_it = _rows.begin();
         row_it != _rows.end(); row_it++) {
        for (TableRow::iterator cell = row_it->begin();
             cell != row_it->end(); cell++) {
            excel->write(cell->second.row+row ,cell->second.col+col,
                        cell->second.value, cell->second.format);
            col += cell->second.col+col;
        }
        col = 0;
        row++;
    }

    *end_row = row;
    return true;
}
