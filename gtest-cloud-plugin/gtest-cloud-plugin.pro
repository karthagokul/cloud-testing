TEMPLATE = lib
TARGET =../libs/gtest-cloud-plugin
CONFIG += console
CONFIG -= qt

_GTEST_HOME = $$(GTEST_HOME)
isEmpty(_GTEST_HOME) {
    message(Searching for GTest Libraries in /usr)
    LIBS+= -lgtest
}
else {
   message(Using GTest from $$_GTEST_HOME)
   LIBS+= -L$$_GTEST_HOME/libs -lgtest
   INCLUDEPATH += $$_GTEST_HOME/include/
}

SOURCES += \
    gtestcloudexporter.cpp \
    sysutils.cpp

HEADERS += \
    gtestcloudexporter.h \
    sysutils.h
