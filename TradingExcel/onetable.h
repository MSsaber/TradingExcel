#ifndef ONETABLE_H
#define ONETABLE_H

#include <vector>
#include <xlsxdocument.h>
#include <tablecell.h>

class OneTable
{
public:
    using CellTital = std::string;
    using TableHeader = std::vector<TableCell>;
    using TableRow = std::map<CellTital, TableCell>;
    using TableRows = std::vector<TableRow>;
public:
    OneTable();

    TableHeader &get_table_header();

    TableRows &get_table_data();

    void add_table_header(const TableCell &header);

    void add_table_row(const TableRow &row);

    void add_table_rows(const TableRows &row);

    bool fill_table(QXlsx::Document *excel, int begin_row, int *end_row);
protected:
    TableHeader _header;
    TableRows   _rows;
};

#endif // ONETABLE_H
