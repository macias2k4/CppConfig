#ifndef CONFIGROOTGROUP_H
#define CONFIGROOTGROUP_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// CppConfig
#include <source/ConfigGroupBase.h>

namespace Example {

class ConfigRootGroup : public CppConfig::ConfigGroupBase {
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    ConfigRootGroup();
    ~ConfigRootGroup() override;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    void clear() override;

    bool fromJson ( const Json::Value &jsonObject ) override;
    Json::Value toJson() const override;

    // - property

    std::string serverHost() const;
    void setServerHost ( const std::string &serverHost );

    int16_t serverPort() const;
    void setServerPort ( const int16_t &serverPort );

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    std::string _serverHost = "127.0.0.1";
    int16_t _serverPort = 0;

};

} // Example

#endif // CONFIGROOTGROUP_H
