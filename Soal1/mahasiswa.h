#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

#include <string>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

void inputMahasiswa(mahasiswa &m);
float hitungNilaiAkhir(mahasiswa m);
void tampilMahasiswa(mahasiswa m);

#endif // MAHASISWA_H_INCLUDED