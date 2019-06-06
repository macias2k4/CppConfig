#include "ConfigUserGroup.h"

namespace Example {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigUserGroup::ConfigUserGroup()
    : CppConfig::ConfigGroupBase() {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigUserGroup::ConfigUserGroup ( string login, string email )
    : CppConfig::ConfigGroupBase(),
      _login ( login ),
      _email ( email ) {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigUserGroup::~ConfigUserGroup() {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                             Methods                                            //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigUserGroup::clear() {
    _login.clear();
    _email.clear();
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ConfigUserGroup::fromJson ( const Json::Value &jsonValue ) {
    _login = jsonValue["login"].asString();
    _email = jsonValue["email"].asString();
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
Json::Value ConfigUserGroup::toJson() const {
    auto json = Json::Value();
    json["login"] = _login;
    json["email"] = _email;
    return json;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
std::string ConfigUserGroup::login() const {
    return _login;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigUserGroup::setLogin ( const string &serverHost ) {
    _login = serverHost;
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
std::string ConfigUserGroup::email() const {
    return _email;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigUserGroup::setEmail ( const string &email ) {
    _email = email;
}

} // Example
