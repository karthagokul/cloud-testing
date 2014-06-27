TEMPLATE = lib
TARGET =../lib/gtest-cloud-plugin
CONFIG += console
CONFIG -= qt

_GTEST_HOME = $$(GTEST_HOME)
isEmpty(_GTEST_HOME) {
    message(Searching for GTest Libraries in /usr)
    LIBS+= -lgtest -lcurl
}
else {
   message(Using GTest from $$_GTEST_HOME)
   LIBS+= -L$$_GTEST_HOME/lib -lgtest -lcurl
   INCLUDEPATH += $$_GTEST_HOME/include/
}

SOURCES += \
    gtestcloudexporter.cpp \
    sysutils.cpp \
    cloudclientengine.cpp \
    gtestresults.cpp \
    iniReader/C++/iniReader.c++

HEADERS += \
    gtestcloudexporter.h \
    sysutils.h \
    cloudclientengine.h \
    gtestresults.h \
    iniReader/C++/iniReader.h
