#include <iostream>
using namespace std;

int PinCheck(int x) {
    for (int i = 0; i < 3; i++)
    {
        cout << "\nMasukkan Sandi : ";
        cin >> x;
        if (x == 1326)
        {
            x = 1;
            return x;
        } else {
            cout << "\nSandi Salah";
        }
    }

    x = 0;
    cout << "\nKartu Anda di BLOKIR";
    return x;
}

int TarikTunai (long &x) {
    int y, z = 0, w;
    
    if (x == 0)
    {
        cout << "Saldo anda habis,\ntidak dapat melakukan\npenarikan uang\n";
        return 0;
    }
    while (z != 1) {
    cout << "Nominal yang diambil : ";
    cin >> y;
    w = y;
    
    if(y % 50000 == 0 && y <= x) 
    {
        z = 1;
    } else 
    {
        cout << "Kelipatan Harus 100 Ribu atau 50 Ribu!!\natau Nominal yang di input melebihi saldo anda\n\n\n";
    }
    }
    
    if(y % 100000 == 0) 
    {
        y = y / 100000;
        cout << "Uang 100 Ribu " << y << " Lembar\nUang 50 Ribu 0 Lembar";
    } else 
    {
        y = (y - 50000) / 100000;
        cout << "Uang 100 Ribu " << y << " Lembar\nUang 50 Ribu 1 Lembar";
    }
    
    cout << endl;
    x = x - w;
    return x;
}

void SetorTunai (long &x) {
    int z = 0;
    long long y;
    
    while (z != 1) {
        cout << "Input uang yang mau di setorkan\n  Input : ";
        cin >> y;
        
        if (y % 50000 != 0) 
        {
            cout << "Nominal yang anda masukkan\nbukan kelipatan 50 ribu\natau 100 ribu\n\n";
        } 
        else 
        {
            z = 1;
            x += y;
            cout << endl;
        }
    }
}

void ExitProgramm (int &x) {
    cout << "\nLanjutkan Transaksi?\n 1. Iya\n 2. Tidak\n  Input : ";
    cin >> x;
    if (x == 2){ x = 4; }
    cout << endl << endl;
}

int main () {
    int Pin, Menu = 0;
    long Saldo = 50000;

    // INPUT PIN
    cout << "Halo, Maliq";
    Pin = PinCheck(Pin);
    if (Pin == 0)
    {
        return 0;
    }
    cout << endl;
    
    // MENU
    while (Menu < 4)
    {
        cout << "MENU\n1. Cek Saldo\n2. Tarik Tunai\n3. Setor Tunai\n4. Keluar\n  Input : ";
        cin >> Menu;
        cout << endl << endl;
        switch (Menu)
        {
        
        //Cek Saldo
        case 1:
            cout << "Saldo Anda : " << Saldo << endl;
            
            ExitProgramm(Menu);
            break;

        //Tarik Tunai
        case 2:
            TarikTunai(Saldo);
            cout << "Saldo Anda : " << Saldo << endl;
            
            ExitProgramm(Menu);
            break;

        //Setor Tunai
        case 3:
            SetorTunai(Saldo);
            cout << "Saldo Anda : " << Saldo << endl;
            
            ExitProgramm(Menu);
            break;

        //Keluar Program
        default:
            break;
        }
    }
    
   cout << "Terima Kasih Telah\nMenggunakan jasa kami.";
   return 0;
   }