#include "ConfigUsersGroup.h"

namespace Example {

// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigUsersGroup::ConfigUsersGroup()
    : CppConfig::ConfigGroupBase() {
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
ConfigUsersGroup::~ConfigUsersGroup() {
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
//                                             Methods                                            //
// ────────────────────────────────────────────────────────────────────────────────────────────── //

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigUsersGroup::clear() {
    _users.clear();
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ConfigUsersGroup::fromJson ( const Json::Value &jsonValue ) {
    _users.clear();
    for ( int i = 0; i < static_cast<int> ( jsonValue.size() ); i++ ) {
        auto usr = ConfigUserGroup();
        usr.fromJson ( jsonValue[i] );
        _users.push_back ( usr );
    }
    return true;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
Json::Value ConfigUsersGroup::toJson() const {
    auto json = Json::Value ( Json::ValueType::arrayValue );
    for ( auto &usr : _users ) {
        json.append ( usr.toJson() );
    }
    return json;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
bool ConfigUsersGroup::isEmpty() const {
    return _users.empty();
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void ConfigUsersGroup::append ( const ConfigUserGroup &cug ) {
    _users.push_back ( cug );
}


} // Example
