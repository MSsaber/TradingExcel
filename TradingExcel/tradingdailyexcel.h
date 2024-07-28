#ifndef TRADINGDAILYEXCEL_H
#define TRADINGDAILYEXCEL_H

#include <tradingexcel.h>

class TRADINGEXCEL_EXPORT TradingDailyExcel : public TradingExcel
{
public:
    TradingDailyExcel(const std::string &excel_name);

public:
    bool addSheet(const std::string &sheet_name);

    bool addTableToSheet(const std::string &sheet_name, OneTable &table);

    void setHeader();
};

#endif // TRADINGDAILYEXCEL_H
