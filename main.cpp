// ────────────────────────────────────────────────────────────────────────────────────────────── //
// std
#include <iostream>

// ────────────────────────────────────────────────────────────────────────────────────────────── //
// Example
#include "example/ConfigExample.h"

using namespace std;

void printHostAndPort ( Example::ConfigRootGroup &rootGroup );
void createDefaultUsersIfNeed ( Example::ConfigRootGroup &rootGroup );
void createDefaultUsers ( Example::ConfigUsersGroup &users );
void printUsers();


// ────────────────────────────────────────────────────────────────────────────────────────────── //
int main() {
    auto &rootGroup = Example::ConfigExample::instance().root();
    printHostAndPort ( rootGroup );
    createDefaultUsersIfNeed ( rootGroup );
    printUsers();
    getchar();
}

// ────────────────────────────────────────────────────────────────────────────────────────────── //
void printHostAndPort ( Example::ConfigRootGroup &rootGroup ) {
    auto host = rootGroup.serverHost();
    auto port = rootGroup.serverPort();
    cout << endl << "host -> " << host << ":" << port << endl;
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void createDefaultUsersIfNeed ( Example::ConfigRootGroup &rootGroup ) {
    if ( !rootGroup.users().isEmpty() ) {
        return;
    }
    createDefaultUsers ( rootGroup.users() );
    Example::ConfigExample::instance().saveConfig();
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void createDefaultUsers ( Example::ConfigUsersGroup &users ) {
    cout << "No users in config file. Try to create a fee default" << endl;
    users.append ( Example::ConfigUserGroup ( "login1", "login1@email.com" ) );
    users.append ( Example::ConfigUserGroup ( "login2", "login2@email.com" ) );
}
// ────────────────────────────────────────────────────────────────────────────────────────────── //
void printUsers() {
    cout << "users -> " << Example::ConfigExample::instance().root().users().toJson() << endl;
}
