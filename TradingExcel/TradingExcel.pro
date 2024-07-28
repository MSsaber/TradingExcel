QT += gui

TEMPLATE = lib
DEFINES += TRADINGEXCEL_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    onetable.cpp \
    tablecell.cpp \
    tradingdailyexcel.cpp \
    tradingexcel.cpp

HEADERS += \
    TradingExcel_global.h \
    onetable.h \
    tablecell.h \
    tradingdailyexcel.h \
    tradingexcel.h

TRANSLATIONS += \
    TradingExcel_zh_CN.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../QXlsx/lib/release/ -lQXlsx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../QXlsx/lib/debug/ -lQXlsx

INCLUDEPATH += $$PWD/../QXlsx/incldue
DEPENDPATH += $$PWD/../QXlsx/incldue
