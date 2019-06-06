TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/../jsoncpp/include
DEPENDPATH += $$PWD/../jsoncpp/include

CONFIG(debug, debug|release): LIBS += -L$$PWD/../jsoncpp/build/debug_lib -ljsoncpp
CONFIG(release, debug|release): LIBS += -L$$PWD/../jsoncpp/build-shared -ljsoncpp

include(source/source.pri)
include(example/example.pri)

SOURCES += \
        main.cpp

# utworzenie podfolderów dla generowanych podczas kompilacji różnych typów plików ( moc/ui/obj)
UI_DIR = uics
MOC_DIR = mocs
OBJECTS_DIR = objs
