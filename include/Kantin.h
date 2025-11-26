#ifndef KANTIN_H
#define KANTIN_H

#include "MenuManager.h"
#include "CartManager.h"
#include "TransactionManager.h"
#include "AuthManager.h"
#include <string>

// ===== KANTIN CLASS (Main Orchestrator) =====
// Mengatur semua manager dan flow aplikasi
class Kantin
{
private:
    MenuManager menuManager;
    CartManager cartManager;
    TransactionManager transactionManager;
    AuthManager authManager;

    // Menu untuk admin
    void menuAdmin();

    // Menu untuk customer
    void menuCustomer();

    // Menu login
    void menuLogin();

public:
    Kantin();

    // Load menu saat startup
    void initialize();

    // Menu transaksi
    void transaksi();

    // Menu utama
    void run();
};

#endif