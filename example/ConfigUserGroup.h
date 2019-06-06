#ifndef CONFIGUSERGROUP_H
#define CONFIGUSERGROUP_H

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// CppConfig
#include <source/ConfigGroupBase.h>

using namespace std;

namespace Example {

class ConfigUserGroup : public CppConfig::ConfigGroupBase {
public:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // constructors
    ConfigUserGroup();
    ConfigUserGroup ( string login, string email );
    ~ConfigUserGroup() override;

    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // methods
    void clear() override;

    bool fromJson ( const Json::Value &jsonValue ) override;
    Json::Value toJson() const override;

    // - property

    string login() const;
    void setLogin ( const string &login );

    string email() const;
    void setEmail ( const string &email );

private:
    // ────────────────────────────────────────────────────────────────────────────────────────── //
    // property
    string _login;
    string _email;

};

} // Example

#endif // CONFIGUSERGROUP_H
