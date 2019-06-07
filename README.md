# CppConfig
This is a simple project that provides base classes to create configurations files for applications in C++

## How it work
This project has two base classes, placed in **source** directory: 
+ **ConfigBase** -> base for application configuration class. This class provide functionality to:
  + create default config file if not exist
  + load data from config file and automatic extending him if list of configuration parameters has been changed
+ **ConfigGroupBase** -> base for group of configuration parameters

<br>There is also example, how to use it:
+ **main.cpp** -> using classes provided by **example** directory to:
  + save, load configuration file and display data read from file on standard output
+ **ConfigExample** -> is example of class implementing ConfigBase class
+ **ConfigRootGroup, ConfigUsersGroup and ConfigUserGroup** -> are example of class implementing ConfigGroupBase class

## Dependencies
+ jsoncpp -> CppConfig use great project (https://github.com/open-source-parsers/jsoncpp) for handle JSON file format

## How to run it
After download, compile and install of jsoncpp, we can use one of two way to build and run CppConfig project.
+ QMake(QtCreator) - this project can be open, compiled i running using QtCreator and qmake. 
  Just open CppConfig.pro file in this IDE set build path and run: qmake, build and run.

+ CMake - in future i want to add CMakeLists.txt file, to open this project not only in QMake
 (NOT READY YET)

After project run You will see output:
```
Config file not exist. Try to create default

host -> 127.0.0.1:0
No users in config file. Try to create a fee default
users -> [
        {
                "email" : "login1@email.com",
                "login" : "login1"
        },
        {
                "email" : "login2@email.com",
                "login" : "login2"
        }
]
```


