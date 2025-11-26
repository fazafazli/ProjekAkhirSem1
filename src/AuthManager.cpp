#include "AuthManager.h"
#include <iostream>

using namespace std;

// Konstruktor
AuthManager::AuthManager() : loggedIn(false), isAdminUser(false) {}

// Login - cek apakah admin atau customer
bool AuthManager::login(const string &username, const string &password)
{
    // Cek apakah admin
    if (username == "admin" && password == "admin123")
    {
        loggedIn = true;
        isAdminUser = true;
        cout << "\nLogin berhasil sebagai ADMIN!\n";
        cout << "Selamat datang, Admin!\n";
        return true;
    }
    // Jika bukan admin, langsung masuk sebagai customer
    else
    {
        loggedIn = true;
        isAdminUser = false;
        cout << "\nLogin berhasil sebagai PELANGGAN!\n";
        cout << "Selamat datang!\n";
        return true;
    }
}

// Logout
void AuthManager::logout()
{
    if (loggedIn)
    {
        cout << "\nLogout berhasil. Terima kasih!\n";
        loggedIn = false;
        isAdminUser = false;
    }
}

// Cek apakah sudah login
bool AuthManager::isLoggedIn() const
{
    return loggedIn;
}

// Cek apakah user adalah admin
bool AuthManager::isAdmin() const
{
    return isAdminUser;
}