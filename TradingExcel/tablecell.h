#ifndef TABLECELL_H
#define TABLECELL_H

#include <string>
#include <xlsxdocument.h>
#include <xlsxformat.h>
#include <QVariant>

class TableCell
{
public:
    TableCell();
    ~TableCell();
public:
    bool write(QXlsx::Document &xlsx);

    int             col;
    int             row;
    std::string     header;
    QVariant        value;
    QXlsx::Format   format;
};

#endif // TABLECELL_H
