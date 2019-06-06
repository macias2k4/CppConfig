#ifndef CONFIGUSERSGROUP_H
#define CONFIGUSERSGROUP_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// CppConfig
#include "ConfigUserGroup.h"

using namespace std;

namespace Example {

class ConfigUsersGroup : public CppConfig::ConfigGroupBase {
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    ConfigUsersGroup();
    ~ConfigUsersGroup() override;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    void clear() override;

    bool fromJson ( const Json::Value &jsonValue ) override;
    Json::Value toJson() const override;

    bool isEmpty() const;
    void append ( const ConfigUserGroup &cug );

    // - property

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    vector<ConfigUserGroup> _users;

};

} // Example

#endif // CONFIGUSERSGROUP_H
