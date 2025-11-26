#include "TransactionManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

// Konstruktor
TransactionManager::TransactionManager() : nextTransId(1) {}

// Fungsi helper untuk mendapatkan tanggal dan waktu yang readable
string getReadableDateTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    ostringstream oss;
    oss << setfill('0') << setw(2) << ltm->tm_mday << "/"
        << setfill('0') << setw(2) << (1 + ltm->tm_mon) << "/"
        << (1900 + ltm->tm_year) << " "
        << setfill('0') << setw(2) << ltm->tm_hour << ":"
        << setfill('0') << setw(2) << ltm->tm_min << ":"
        << setfill('0') << setw(2) << ltm->tm_sec;

    return oss.str();
}

// Membuat struk dan simpan ke file
void TransactionManager::buatStruk(CartManager &cartManager)
{
    if (cartManager.getCart().empty())
    {
        cout << "Keranjang belanja kosong. Tidak ada yang dibeli.\n";
        return;
    }

    cartManager.tampilCart();

    // Buat nama file dengan nomor urut
    ostringstream filenameStream;
    filenameStream << "data/receipt" << nextTransId << ".txt";
    string filename = filenameStream.str();

    // Buat file struk pembelian
    ofstream out(filename);

    out << "========================================\n";
    out << "         STRUK PEMBELIAN KANTIN        \n";
    out << "========================================\n";
    out << "ID Transaksi  : " << nextTransId << "\n";
    out << "Tanggal/Waktu : " << getReadableDateTime() << "\n";
    out << "========================================\n\n";

    int totalHarga = 0;
    const auto &cart = cartManager.getCart();

    for (int i = 0; i < cart.size(); i++)
    {
        out << (i + 1) << ". " << cart[i].getName()
            << " x" << cart[i].getQuantity()
            << " @ Rp" << cart[i].getPrice()
            << "\n   Subtotal: Rp" << cart[i].getSubtotal() << "\n\n";
        totalHarga += cart[i].getSubtotal();
    }

    out << "========================================\n";
    out << "TOTAL PEMBAYARAN: Rp" << totalHarga << "\n";
    out << "========================================\n";
    out << "\n   Terima kasih atas kunjungan Anda!  \n";
    out << "========================================\n";
    out.close();

    cout << "\nTransaksi berhasil!\n";
    cout << "Struk disimpan di: " << filename << "\n";

    // Increment ID transaksi untuk receipt berikutnya
    nextTransId++;

    cartManager.clearCart();
}