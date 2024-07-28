#include "tradingdailyexcel.h"

TradingDailyExcel::TradingDailyExcel(const std::string &excel_name)
    : TradingExcel(excel_name)
{

}

void TradingDailyExcel::setHeader()
{
    this->addSheet("测试");

    OneTable table;
    TableCell cell;
    cell.col = 1;
    cell.row = 1;
    cell.value = "日期";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "时间";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "合约代码";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "合约名称";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "方向";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "开平";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "档位";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "成交数量";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "汇总数量";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "档位价格";
    table.add_table_header(cell);


    cell.col = 1;
    cell.row = 1;
    cell.value = "成交价格";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "成交均价";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "委托价格";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "成交金额";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "手续费";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "盈利预期";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "委托编号";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "策略ID";
    table.add_table_header(cell);

    cell.col = 1;
    cell.row = 1;
    cell.value = "组合ID";
    table.add_table_header(cell);

    addTableToSheet("测试", table);
}

bool TradingDailyExcel::addSheet(const std::string &sheet_name)
{
    this->_sheets.insert(std::make_pair(sheet_name, std::vector<OneTable>()));
    return true;
}

bool TradingDailyExcel::addTableToSheet(const std::string &sheet_name, OneTable &table)
{
    TradingExcel::ExcelSheets::iterator it = this->_sheets.find(sheet_name);
    if (it == this->_sheets.end()) {
        return false;

    }
    it->second.push_back(table);
    return true;
}
