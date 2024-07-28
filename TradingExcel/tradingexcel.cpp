#include <QDebug>
#include <xlsxdocument.h>
#include "tradingexcel.h"
using namespace QXlsx;

TradingExcel::TradingExcel()
{
}

TradingExcel::TradingExcel(const std::string &excel_name)
{
    this->_excel_name = excel_name;
}

TradingExcel::~TradingExcel()
{
}

//excel operation function
void TradingExcel::set_excel_name(const std::string &excel_name)
{
    this->_excel_name = excel_name;
}

std::string TradingExcel::get_excel_name()
{
    return this->_excel_name;
}

//add row to sheet
void TradingExcel::add_table_to_sheet(const SheetName &sheet, const OneTable &row)
{
    ExcelSheets::iterator iter = this->_sheets.find(sheet);
    if (iter == this->_sheets.end()) {
        this->_sheets.insert(std::make_pair(sheet, SheetTables()));
    }
    this->_sheets.find(sheet)->second.push_back(row);
}

void TradingExcel::add_tables_to_sheet(const SheetName &sheet, const SheetTables &rows)
{
    ExcelSheets::iterator iter = this->_sheets.find(sheet);
    if (iter == this->_sheets.end()) {
        this->_sheets.insert(std::make_pair(sheet, SheetTables()));
    }
    iter = this->_sheets.find(sheet);
    iter->second.insert(iter->second.end(), rows.begin(), rows.end());
}

bool TradingExcel::load(const std::string &path)
{
    return true;
}

bool TradingExcel::save(const std::string &path)
{
    std::string filepath = path + this->_excel_name + ".xlsx";
    this->build_xlsx();
    this->xlsx.saveAs(QString(filepath.c_str()));
    return true;
}

bool TradingExcel::build_xlsx()
{
    for (ExcelSheets::iterator it = this->_sheets.begin();
         it != this->_sheets.end(); it++) {
        if (!build_sheet(it->first)) {
            qInfo() << "sheet[" << it->first << "] " << "创建失败";
            return false;
        }
    }
    return true;
}

bool TradingExcel::parse_xlsx()
{
    return true;
}

bool TradingExcel::build_sheet(const SheetName &sheet_name)
{
    int begin_row = 0, end_row = 0;
    QXlsx::AbstractSheet *sheet = nullptr;
    ExcelSheets::iterator sheet_it = this->_sheets.find(sheet_name);

    xlsx.addSheet(QString(sheet_name.c_str()));

    if (!xlsx.selectSheet(QString(sheet_name.c_str()))) {
        return false;
    }

    for (SheetTables::iterator table_it = sheet_it->second.begin();
         table_it != sheet_it->second.end(); table_it++) {
        table_it->fill_table(&(this->xlsx), begin_row, &end_row);
        begin_row = end_row + 1;
    }
    return true;
}

void TradingExcel::test()
{
    QXlsx::Document xlsx;
    // 添加一个工作表（sheet），默认情况下，如果不指定名称，它会使用"Sheet1"
    // 这里我们显式地添加一个名为"DataSheet"的工作表
    xlsx.addSheet("DataSheet");

    // 写入数据到A1单元格
    xlsx.write("A1", "Hello, QXlsx!");

    // 写入更多数据到不同的单元格
    xlsx.write("A2", 123); // 写入整数
    xlsx.write("A3", 45.67); // 写入浮点数

    // 也可以一次性写入多行数据
    QXlsx::Format format; // 创建一个格式对象（如果需要的话，可以自定义格式）
    xlsx.write(2, 4, "QXlsx can write arrays!", format); // 写入字符串到第3行第5列（注意行和列索引从0开始）

    // 保存文件
    xlsx.saveAs("example.xlsx");
}
