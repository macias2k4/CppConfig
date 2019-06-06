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
        _instance = new ConfigExample();
        _setUpInstance();
    }
    return *dynamic_cast<ConfigExample *> ( _instance );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
std::string ConfigExample::absoluteFilePath() const {
#ifdef __linux__
    return "/media/config.json";
#else
    return "C:/data/config.json";
#endif
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
CppConfig::ConfigGroupBase *ConfigExample::_rootGroup() {
    return &_root;
}


} // Example
