#ifndef CONFIGEXAMPLE_H
#define CONFIGEXAMPLE_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// CppConfig
#include "ConfigBase.h"

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
    /// \brief Absolute path to configuration file (including file name)
    std::string absoluteFilePath() const override;

    // - property

    ConfigRootGroup &root();

protected:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief Return pointer for root group of parameters
    CppConfig::ConfigGroupBase *_rootGroup() override;

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    ConfigExample();

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    ConfigRootGroup _root;

};

} // Example

#endif // CONFIGEXAMPLE_H
