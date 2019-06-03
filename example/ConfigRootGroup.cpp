#include "ConfigRootGroup.h"

namespace Example {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigRootGroup::ConfigRootGroup()
    : CppConfig::ConfigGroupBase () {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigRootGroup::~ConfigRootGroup() {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                             Methods                                            //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigRootGroup::clear() {
    _serverHost.clear();
    _serverPort = 0;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ConfigRootGroup::fromJson ( const Json::Value &jsonObject ) {
    _serverHost = jsonObject["serverHost"].asString();
    _serverPort = static_cast<int16_t> ( jsonObject["serverPort"].asInt() );
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
Json::Value ConfigRootGroup::toJson() const {
    Json::Value json;
    json["serverHost"] = _serverHost;
    json["serverPort"] = _serverPort;
    return json;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
std::string ConfigRootGroup::serverHost() const {
    return _serverHost;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigRootGroup::setServerHost ( const std::string &serverHost ) {
    _serverHost = serverHost;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
int16_t ConfigRootGroup::serverPort() const {
    return _serverPort;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigRootGroup::setServerPort ( const int16_t &serverPort ) {
    _serverPort = serverPort;
}

} // Example
