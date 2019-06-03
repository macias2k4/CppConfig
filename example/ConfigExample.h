#ifndef CONFIGEXAMPLE_H
#define CONFIGEXAMPLE_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// CppConfig
#include <source/ConfigBase.h>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Example
#include "ConfigRootGroup.h"

namespace Example {

class ConfigExample : public CppConfig::ConfigBase {
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief Return instance of configuration file
    static ConfigExample &instance();
    std::string absoluteFilePath() const override;

    // - property

    ConfigRootGroup &root();

protected:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    CppConfig::ConfigGroupBase *_rootGroup() override;

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    ConfigExample();

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    ConfigRootGroup _root;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    static void _initializeInstance();

};

} // Example

#endif // CONFIGEXAMPLE_H
