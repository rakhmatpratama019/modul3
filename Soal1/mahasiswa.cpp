#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMahasiswa(mahasiswa &m) {
    cout << "Nama       : ";
    cin >> m.nama;

    cout << "NIM        : ";
    cin >> m.nim;

    cout << "Nilai UTS   : ";
    cin >> m.uts;

    cout << "Nilai UAS   : ";
    cin >> m.uas;

    cout << "Nilai Tugas : ";
    cin >> m.tugas;

    m.nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(mahasiswa m) {
    return (0.3 * m.uts) +
           (0.4 * m.uas) +
           (0.3 * m.tugas);
}

void tampilMahasiswa(mahasiswa m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "Nilai UTS   : " << m.uts << endl;
    cout << "Nilai UAS   : " << m.uas << endl;
    cout << "Nilai Tugas : " << m.tugas << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
}