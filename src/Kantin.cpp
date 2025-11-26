#include "Kantin.h"
#include <iostream>

using namespace std;

// Konstruktor
Kantin::Kantin() {}

// Load menu saat startup
void Kantin::initialize()
{
    menuManager.loadMenu("data/input.txt");
}

// Menu transaksi
void Kantin::transaksi()
{
    int pilihan;

    do
    {
        cout << "\n=== Menu Transaksi ===\n";
        cout << "1. Lihat menu\n";
        cout << "2. Tambah item ke keranjang\n";
        cout << "3. Lihat keranjang\n";
        cout << "4. Hapus item dari keranjang\n";
        cout << "5. Checkout (buat struk)\n";
        cout << "0. Batal\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            menuManager.tampilMenu();
            break;
        case 2:
            cartManager.tambahKeCart(menuManager);
            break;
        case 3:
            cartManager.tampilCart();
            break;
        case 4:
            cartManager.hapusDariCart(menuManager);
            break;
        case 5:
            transactionManager.buatStruk(cartManager);
            return;
        case 0:
            cout << "Transaksi dibatalkan. Stok dikembalikan.\n";
            cartManager.returnAllStock(menuManager);
            return;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
}

// Menu untuk admin
void Kantin::menuAdmin()
{
    int pilihan;

    do
    {
        cout << "\n=== Menu Admin ===\n";
        cout << "1. Tambah menu\n";
        cout << "2. Edit menu\n";
        cout << "3. Hapus menu\n";
        cout << "4. Tampilkan menu\n";
        cout << "5. Transaksi\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            menuManager.tambahMenu();
            break;
        case 2:
            menuManager.editMenu();
            break;
        case 3:
            menuManager.hapusMenu();
            break;
        case 4:
            menuManager.tampilMenu();
            break;
        case 5:
            transaksi();
            break;
        case 0:
            authManager.logout();
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
}

// Menu untuk customer
void Kantin::menuCustomer()
{
    int pilihan;

    do
    {
        cout << "\n=== Menu Pelanggan ===\n";
        cout << "1. Lihat menu\n";
        cout << "2. Transaksi\n";
        cout << "0. Logout\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            menuManager.tampilMenu();
            break;
        case 2:
            transaksi();
            break;
        case 0:
            authManager.logout();
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
}

// Menu login
void Kantin::menuLogin()
{
    string username, password;

    cout << "\n=================================\n";
    cout << "   SELAMAT DATANG DI KANTIN\n";
    cout << "=================================\n";
    cout << "\nSilakan login untuk melanjutkan\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (authManager.login(username, password))
    {
        if (authManager.isAdmin())
        {
            menuAdmin();
        }
        else
        {
            menuCustomer();
        }
    }
}

// Menu utama
void Kantin::run()
{
    char pilihan;

    do
    {
        menuLogin();

        cout << "\nKembali ke halaman login? (y/n): ";
        cin >> pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');

    cout << "\nTerima kasih telah menggunakan Sistem Kantin!\n";
}