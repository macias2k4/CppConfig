#ifndef CONFIGGROUPBASE_H
#define CONFIGGROUPBASE_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// std
#include <iostream>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// jsoncpp
#include <json/json.h>

namespace CppConfig {

/// \brief Base class for group of configuration parameters
class ConfigGroupBase {
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    ConfigGroupBase();
    virtual ~ConfigGroupBase();

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief Reset all group parameters value
    virtual void clear() = 0;

    /// \brief Fill current group of parameters from Json (to implement in child class)
    virtual bool fromJson ( const Json::Value &jsonValue ) = 0;
    /// \brief Return current group of parameters as Json (to implement in child class)
    virtual Json::Value toJson() const = 0;

    // - property

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property

};

} // CppConfig

#endif // CONFIGGROUPBASE_H
