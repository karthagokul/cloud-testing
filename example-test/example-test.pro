TEMPLATE = app
CONFIG += console
CONFIG -= qt
_GTEST_HOME = $$(GTEST_HOME)
isEmpty(_GTEST_HOME) {
    message(Searching for GTest Libraries in /usr)
    LIBS+= -lgtest
}
else {
   message(Using GTest from $$_GTEST_HOME)
   LIBS+= -L$$_GTEST_HOME/lib -lgtest
   INCLUDEPATH += $$_GTEST_HOME/include/
}

INCLUDEPATH+=../gtest-cloud-plugin/

LIBS+= -lgtest-cloud-plugin -lpthread

SOURCES += main.cpp \
    ut_calculator.cpp

HEADERS += \
    calculator.h
