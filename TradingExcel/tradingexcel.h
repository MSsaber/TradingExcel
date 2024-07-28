#ifndef TRADINGEXCEL_H
#define TRADINGEXCEL_H

#include "TradingExcel_global.h"
#include <map>
#include <vector>
#include <onetable.h>

class TRADINGEXCEL_EXPORT TradingExcel
{
protected:
    using SheetName = std::string;
    using TableHeader = std::vector<TableCell>;
    using SheetTables = std::vector<OneTable>;
    using ExcelSheets = std::map<SheetName, SheetTables>;
public:
    TradingExcel();
    TradingExcel(const std::string &excel_name);
    ~TradingExcel();

    void test();
    bool load(const std::string &path);
    bool save(const std::string &path);
public:
    //excel operation function
    void set_excel_name(const std::string &excel_name);
    std::string get_excel_name();

    //add row to sheet
    void add_table_to_sheet(const SheetName &sheet, const OneTable &table);
    void add_tables_to_sheet(const SheetName &sheet, const SheetTables &tables);
protected:
    bool parse_xlsx();
    bool build_xlsx();

    bool build_sheet(const SheetName &sheet_name);
protected:
    QXlsx::Document xlsx;
    std::string _excel_name;
    ExcelSheets _sheets;
};

#endif // TRADINGEXCEL_H
