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
    _users.clear();
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ConfigRootGroup::fromJson ( const Json::Value &jsonValue ) {
    _serverHost = jsonValue["serverHost"].asString();
    _serverPort = static_cast<int16_t> ( jsonValue["serverPort"].asInt() );
    _users.fromJson ( jsonValue["users"] );
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
Json::Value ConfigRootGroup::toJson() const {
    auto json = Json::Value();
    json["serverHost"] = _serverHost;
    json["serverPort"] = _serverPort;
    json["users"] = _users.toJson();
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

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigUsersGroup &ConfigRootGroup::users() {
    return _users;
}

} // Example
