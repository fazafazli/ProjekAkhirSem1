#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <string>
using namespace std;

// ===== AUTH MANAGER CLASS (Simplified) =====
// Mengelola autentikasi sederhana
class AuthManager
{
private:
    bool loggedIn;
    bool isAdminUser;

public:
    AuthManager();

    // Login - cek apakah admin atau customer
    bool login(const string &username, const string &password);

    // Logout
    void logout();

    // Cek apakah sudah login
    bool isLoggedIn() const;

    // Cek apakah user adalah admin
    bool isAdmin() const;
};

#endif