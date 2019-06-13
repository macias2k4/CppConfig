#ifndef CONFIGBASE_H
#define CONFIGBASE_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// std
#include <iostream>
#include <fstream>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// ConfigBase
#include "ConfigGroupBase.h"

namespace CppConfig {

/// \brief Base class for application configuration class
class ConfigBase {
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    ConfigBase();
    virtual ~ConfigBase();

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief Absolute path to configuration file (including file name)
    virtual std::string absoluteFilePath() const = 0;

    /// \brief Return information is file exist
    static bool isFileExist ( const std::string &path );

    /// \brief Read configuration from file in 'path' and set 'root' object properties
    bool loadConfig();
    /// \brief Check is config loaded to memory is different from this in file
    bool isConfigChanged();
    /// \brief Write configuration to file in 'path' by 'root' object properties
    bool saveConfig();


protected:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    //    ConfigBase();

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    /// \brief Configuration class singleton instance
    static std::unique_ptr<ConfigBase> _instance;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    /// \brief Setting up konfigurations in _instance object
    /// <br>_instance need to be initialized, if not it will be crash
    static void _setUpInstance();

    /// \brief Return pointer for root group of parameters
    virtual ConfigGroupBase *_rootGroup() = 0;
    /// \brief Load configuration file, and return as string
    std::string _loadFileToStr();
    /// \brief Build and return Json::Value object from string
    Json::Value _buildJsonValueFromStr ( const std::string &str );
    /// \brief Calculate checksum of data
    uint32_t _calculateCrc ( const std::string &data );


};

} // CppConfig

#endif // CONFIGBASE_H
