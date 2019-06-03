#include "ConfigExample.h"

namespace Example {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigExample::ConfigExample()
    : CppConfig::ConfigBase () {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                             Methods                                            //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigRootGroup &ConfigExample::root() {
    return _root;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigExample &ConfigExample::instance() {
    if ( !_instance ) {
        _initializeInstance();
    }
    return *dynamic_cast<ConfigExample *> ( _instance );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigExample::_initializeInstance() {
    _instance = new ConfigExample();
    if ( !isFileExist ( _instance->absoluteFilePath() ) ) {
        std::cout << "Config file not exist. Try to create default" << std::endl;
        _instance->saveConfig();
        return;
    }
    std::cout << "Try to load config file.." << std::endl;
    _instance->loadConfig();
    if ( _instance->isConfigChanged() ) {
        std::cout << "Conf changed !";
        _instance->saveConfig();
    }
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
std::string ConfigExample::absoluteFilePath() const {
    return "/media/macias/data/projects/build/C++/CppConfig/Release/config.json";
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
CppConfig::ConfigGroupBase *ConfigExample::_rootGroup() {
    return &_root;
}


} // Example
