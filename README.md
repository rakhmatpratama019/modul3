# Praktikum Struktur Data --- Minggu 3: Abstract Data Type (ADT)

## Identitas

-   **Mata kuliah:** Struktur Data
-   **Materi:** Abstract Data Type (ADT)
-   **Minggu/Modul:** Modul 3
-   **Nama:** `[Rakhmat Pratama]`
-   **NIM:** `[109082530037]`
-   **Kelas:** `[S1IF-13-01]`
-   **Institusi:** Telkom University

------------------------------------------------------------------------

## Daftar Isi

-   [Pendahuluan](#pendahuluan)
-   [Tujuan Praktikum](#tujuan-praktikum)
-   [Konsep Dasar ADT](#konsep-dasar-adt)
-   [Struktur Direktori](#struktur-direktori)
-   [Bagian A --- Guided](#bagian-a--guided)
    -   [Deskripsi Soal Guided](#deskripsi-soal-guided)
    -   [Implementasi Guided](#implementasi-guided)
    -   [Cara Menjalankan Guided](#cara-menjalankan-guided)
    -   [Contoh Output Guided](#contoh-output-guided)
-   [Bagian B --- Unguided/Laprak](#bagian-b--unguidedlaprak)
    -   [Soal 1 --- Data Mahasiswa](#soal-1--data-mahasiswa)
    -   [Soal 2 --- ADT Pelajaran](#soal-2--adt-pelajaran)
    -   [Soal 3 --- Array 2D dan Pointer](#soal-3--array-2d-dan-pointer)
-   [Dokumentasi Screenshot](#dokumentasi-screenshot)
-   [Kesimpulan](#kesimpulan)
-   [Daftar Pustaka](#daftar-pustaka)

------------------------------------------------------------------------

## Pendahuluan

Abstract Data Type (ADT) merupakan konsep dalam pemrograman yang
mendefinisikan suatu tipe data beserta operasi-operasi yang dapat
dilakukan terhadap tipe data tersebut. ADT memisahkan spesifikasi tipe
dan operasi dari detail implementasinya. Dalam C++, pemisahan sederhana
ini dapat dilakukan menggunakan file header (`.h`), file implementasi
(`.cpp`), dan program utama (`main.cpp`).

Pada praktikum ini, konsep ADT diterapkan melalui latihan input data
mahasiswa, pembuatan ADT mata pelajaran, serta manipulasi array dua
dimensi dan pointer. Bagian Guided mengikuti contoh dasar pada modul,
sedangkan bagian Unguided mengerjakan tiga latihan yang diberikan pada
akhir modul.

## Tujuan Praktikum

1.  Memahami konsep dan fungsi Abstract Data Type (ADT).
2.  Memisahkan deklarasi tipe data dan prototype fungsi ke dalam file
    header.
3.  Memisahkan implementasi fungsi/prosedur ke dalam file `.cpp`.
4.  Menggunakan `main.cpp` sebagai program utama untuk menguji ADT.
5.  Mengolah data menggunakan `struct`, array, fungsi, dan pointer.
6.  Memahami pertukaran elemen array dua dimensi dan nilai yang ditunjuk
    oleh pointer.

## Konsep Dasar ADT

Pemisahan file yang digunakan pada praktikum ini adalah:

  -----------------------------------------------------------------------
  File                                Peran
  ----------------------------------- -----------------------------------
  `.h`                                Mendefinisikan tipe data dan
                                      mendeklarasikan prototype
                                      fungsi/prosedur.

  `.cpp` (implementasi)               Berisi realisasi atau badan
                                      fungsi/prosedur yang dideklarasikan
                                      di header.

  `main.cpp`                          Berisi fungsi `main()` untuk
                                      menjalankan dan menguji
                                      implementasi ADT.
  -----------------------------------------------------------------------

`#include` digunakan agar file sumber dapat menggunakan deklarasi yang
ada pada header. Include guard seperti `#ifndef`, `#define`, dan
`#endif` mencegah header diproses berulang kali dalam satu unit
kompilasi.

------------------------------------------------------------------------

# Bagian A --- Guided

## Deskripsi Soal Guided

Latihan Guided mengacu pada contoh ADT mahasiswa dalam modul. Data
mahasiswa terdiri dari NIM serta dua nilai. Program meminta pengguna
memasukkan NIM, nilai pertama, dan nilai kedua, kemudian menghitung
rata-rata kedua nilai tersebut.

Rumus yang digunakan:

\[ `\text{rata-rata}`{=tex} =
`\frac{\text{nilai1}+\text{nilai2}}{2}`{=tex} \]

Implementasi dipisahkan menjadi `mahasiswa.h`, `mahasiswa.cpp`, dan
`main.cpp`.

## Implementasi Guided

### 1. `mahasiswa.h`

``` cpp
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif // MAHASISWA_H_INCLUDED
```

**Penjelasan:** - `struct mahasiswa` mendefinisikan tipe data dengan
atribut `nim`, `nilai1`, dan `nilai2`. - `inputMhs(mahasiswa &m)`
mendeklarasikan prosedur input. Parameter referensi (`&`) memungkinkan
data pada objek mahasiswa diisi langsung. - `rata2(mahasiswa m)`
mendeklarasikan fungsi yang mengembalikan nilai rata-rata bertipe
`float`.

### 2. `mahasiswa.cpp`

``` cpp
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim ";
    cin >> m.nim;

    cout << "input nilai1 = ";
    cin >> m.nilai1;

    cout << "input nilai2 = ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}
```

**Penjelasan:** - `inputMhs()` meminta NIM dan dua nilai dari
pengguna. - `rata2()` menjumlahkan kedua nilai, mengubah hasil
penjumlahan menjadi `float`, lalu membaginya dengan `2`. Dengan
demikian, hasil rata-rata dapat memiliki angka desimal.

### 3. `main.cpp`

``` cpp
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);

    return 0;
}
```

**Penjelasan alur program:** 1. Membuat objek `mhs` dengan tipe
`mahasiswa`. 2. Memanggil `inputMhs(mhs)` untuk mengisi NIM dan dua
nilai. 3. Memanggil `rata2(mhs)` dan menampilkan hasilnya. 4. Mengakhiri
program dengan `return 0`.

## Cara Menjalankan Guided

Buka terminal pada folder `LatihanWeek3`, yaitu folder yang berisi
ketiga file Guided. Jalankan:

``` powershell
g++ .\main.cpp .\mahasiswa.cpp -o guided
.\guided.exe
```

Jika terminal dibuka dari folder proyek utama, masuk ke folder Guided
terlebih dahulu:

``` powershell
cd .\LatihanWeek3
g++ .\main.cpp .\mahasiswa.cpp -o guided
.\guided.exe
```

**Contoh input dan output** (angka input hanya contoh):

``` text
input nim 123456789
input nilai1 = 80
input nilai2 = 90
rata-rata = 85
```

Nilai rata-rata dihitung sebagai `(80 + 90) / 2 = 85`.

------------------------------------------------------------------------

# Bagian B --- Unguided/Laprak

Bagian Unguided terdiri dari tiga latihan sesuai soal pada Modul 3.
Setiap soal disimpan di folder tersendiri dan dikompilasi secara
terpisah karena masing-masing memiliki `main.cpp`.

## Soal 1 --- Data Mahasiswa

### Deskripsi soal

Buat program yang dapat menyimpan maksimal 10 data mahasiswa dalam
array. Setiap mahasiswa memiliki field nama, NIM, UTS, UAS, tugas, dan
nilai akhir. Nilai akhir dihitung dengan rumus:

\[ `\text{Nilai Akhir}`{=tex} = 0.3(UTS) + 0.4(UAS) + 0.3(Tugas) \]

### 1. `Soal1/mahasiswa.h`

``` cpp
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

#include <string>
using namespace std;

const int MAX_MHS = 10;

struct mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

void inputMhs(mahasiswa &m);
float hitungNilaiAkhir(mahasiswa m);
void tampilMhs(mahasiswa m);

#endif // MAHASISWA_H_INCLUDED
```

### 2. `Soal1/mahasiswa.cpp`

``` cpp
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Nama       : ";
    getline(cin, m.nama);

    cout << "NIM        : ";
    getline(cin, m.nim);

    cout << "Nilai UTS  : ";
    cin >> m.uts;

    cout << "Nilai UAS  : ";
    cin >> m.uas;

    cout << "Nilai Tugas: ";
    cin >> m.tugas;
    cin.ignore(1000, '\n');

    m.nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3f * m.uts + 0.4f * m.uas + 0.3f * m.tugas;
}

void tampilMhs(mahasiswa m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "Nilai UTS   : " << m.uts << endl;
    cout << "Nilai UAS   : " << m.uas << endl;
    cout << "Nilai Tugas : " << m.tugas << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
}
```

### 3. `Soal1/main.cpp`

``` cpp
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa dataMhs[MAX_MHS];
    int n;

    do {
        cout << "Jumlah mahasiswa (1-" << MAX_MHS << "): ";
        cin >> n;
        cin.ignore(1000, '\n');
    } while (n < 1 || n > MAX_MHS);

    cout << "\n=== INPUT DATA MAHASISWA ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n=== Data Mahasiswa ke-" << i + 1 << " ===" << endl;
        inputMhs(dataMhs[i]);
    }

    cout << "\n========== DAFTAR MAHASISWA ==========" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        tampilMhs(dataMhs[i]);
    }

    return 0;
}
```

### Penjelasan Soal 1

-   `mahasiswa dataMhs[MAX_MHS]` membuat array yang dapat menampung
    maksimal 10 mahasiswa.
-   Validasi `do-while` memastikan jumlah mahasiswa berada pada rentang
    1--10.
-   `inputMhs()` menerima data setiap mahasiswa.
-   `hitungNilaiAkhir()` menghitung nilai akhir berdasarkan bobot UTS
    30%, UAS 40%, dan tugas 30%.
-   `tampilMhs()` menampilkan kembali semua data mahasiswa.

Penggunaan `getline()` untuk nama dan NIM memungkinkan input teks yang
memiliki spasi, terutama nama lengkap. Setelah input angka,
`cin.ignore()` membersihkan karakter newline sebelum input teks
berikutnya.

### Cara menjalankan Soal 1

Dari folder proyek utama:

``` powershell
cd .\LaprakModul3\Soal1
g++ .\main.cpp .\mahasiswa.cpp -o soal1
.\soal1.exe
```

**Contoh output** (input hanya ilustrasi):

``` text
Jumlah mahasiswa (1-10): 2

=== INPUT DATA MAHASISWA ===

=== Data Mahasiswa ke-1 ===
Nama       : Andi Saputra
NIM        : 12345
Nilai UTS  : 80
Nilai UAS  : 90
Nilai Tugas: 85

=== Data Mahasiswa ke-2 ===
Nama       : Budi Santoso
NIM        : 12346
Nilai UTS  : 75
Nilai UAS  : 80
Nilai Tugas: 90

========== DAFTAR MAHASISWA ==========

Mahasiswa ke-1
Nama        : Andi Saputra
NIM         : 12345
Nilai UTS   : 80
Nilai UAS   : 90
Nilai Tugas : 85
Nilai Akhir : 85.5

Mahasiswa ke-2
Nama        : Budi Santoso
NIM         : 12346
Nilai UTS   : 75
Nilai UAS   : 80
Nilai Tugas : 90
Nilai Akhir : 81.5
```

Perhitungan: - Andi: `0.3(80) + 0.4(90) + 0.3(85) = 85.5`. - Budi:
`0.3(75) + 0.4(80) + 0.3(90) = 81.5`.

------------------------------------------------------------------------

## Soal 2 --- ADT Pelajaran

### Deskripsi soal

Buat ADT `pelajaran` yang memiliki atribut `namaMapel` dan `kodeMapel`.
Implementasi menyediakan: - `create_pelajaran()` untuk membuat dan
mengembalikan objek `pelajaran`. - `tampil_pelajaran()` untuk
menampilkan informasi mata pelajaran.

Contoh yang digunakan dalam soal adalah nama mata pelajaran
`Struktur Data` dan kode `STD`.

### 1. `Soal2/pelajaran.h`

``` cpp
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
```

### 2. `Soal2/pelajaran.cpp`

``` cpp
#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;

    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama Mata Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran : " << pel.kodeMapel << endl;
}
```

### 3. `Soal2/main.cpp`

``` cpp
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Penjelasan Soal 2

-   `struct pelajaran` mendefinisikan tipe data dengan dua atribut
    berbasis `string`.
-   `create_pelajaran()` mengisi atribut objek dari parameter dan
    mengembalikan objek tersebut.
-   `tampil_pelajaran()` menampilkan nama dan kode mata pelajaran.
-   `main()` membuat data contoh, memanggil fungsi pembentuk objek,
    kemudian menampilkan hasilnya.

### Cara menjalankan Soal 2

``` powershell
cd ..\Soal2
g++ .\main.cpp .\pelajaran.cpp -o soal2
.\soal2.exe
```

Perintah `cd ..\Soal2` berlaku jika terminal sedang berada di folder
`LaprakModul3\Soal1`. Jika terminal berada di folder proyek utama,
gunakan `cd .\LaprakModul3\Soal2`.

**Contoh output:**

``` text
Nama Mata Pelajaran : Struktur Data
Kode Mata Pelajaran : STD
```

------------------------------------------------------------------------

## Soal 3 --- Array 2D dan Pointer

### Deskripsi soal

Buat program yang menggunakan: 1. Dua array integer dua dimensi
berukuran 3 × 3. 2. Dua pointer integer. 3. Prosedur untuk menampilkan
isi array dua dimensi. 4. Prosedur untuk menukar elemen dari dua array
pada posisi yang sama. 5. Prosedur untuk menukar nilai dua variabel yang
ditunjuk oleh pointer.

### 1. `Soal3/arraypointer.h`

``` cpp
#ifndef ARRAYPOINTER_H_INCLUDED
#define ARRAYPOINTER_H_INCLUDED

const int BARIS = 3;
const int KOLOM = 3;

void tampilArray(int arr[BARIS][KOLOM]);

void tukarArray(int arr1[BARIS][KOLOM],
                int arr2[BARIS][KOLOM],
                int baris,
                int kolom);

void tukarPointer(int *p1, int *p2);

#endif // ARRAYPOINTER_H_INCLUDED
```

### 2. `Soal3/arraypointer.cpp`

``` cpp
#include <iostream>
#include "arraypointer.h"

using namespace std;

void tampilArray(int arr[BARIS][KOLOM]) {
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[BARIS][KOLOM],
                int arr2[BARIS][KOLOM],
                int baris,
                int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```

### 3. `Soal3/main.cpp`

``` cpp
#include <iostream>
#include "arraypointer.h"

using namespace std;

int main() {
    int array1[BARIS][KOLOM] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[BARIS][KOLOM] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int a = 100;
    int b = 200;

    int *p1 = &a;
    int *p2 = &b;

    cout << "=== ARRAY SEBELUM DITUKAR ===" << endl;
    cout << "\nArray 1:" << endl;
    tampilArray(array1);
    cout << "\nArray 2:" << endl;
    tampilArray(array2);

    // Menukar elemen pada baris indeks 1, kolom indeks 1.
    tukarArray(array1, array2, 1, 1);

    cout << "\n=== ARRAY SETELAH DITUKAR ===" << endl;
    cout << "\nArray 1:" << endl;
    tampilArray(array1);
    cout << "\nArray 2:" << endl;
    tampilArray(array2);

    cout << "\n=== POINTER SEBELUM DITUKAR ===" << endl;
    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;

    tukarPointer(p1, p2);

    cout << "\n=== POINTER SETELAH DITUKAR ===" << endl;
    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;

    return 0;
}
```

### Penjelasan Soal 3

-   `tampilArray()` menggunakan perulangan bersarang untuk menampilkan
    seluruh elemen array 3 × 3.
-   `tukarArray()` menggunakan variabel sementara `temp` untuk menukar
    elemen pada indeks yang diberikan.
-   Indeks C++ dimulai dari `0`. Karena itu, pemanggilan
    `tukarArray(array1, array2, 1, 1)` menukar elemen tengah dari kedua
    array, yaitu `5` dan `14`.
-   `p1` menunjuk ke variabel `a`, sedangkan `p2` menunjuk ke variabel
    `b`.
-   `tukarPointer()` menukar nilai yang ditunjuk melalui operator
    dereferensi `*`, bukan menukar alamat pointer.

### Cara menjalankan Soal 3

Jika terminal sedang berada di `LaprakModul3\Soal2`:

``` powershell
cd ..\Soal3
g++ .\main.cpp .\arraypointer.cpp -o soal3
.\soal3.exe
```

Jika terminal berada di folder proyek utama:

``` powershell
cd .\LaprakModul3\Soal3
g++ .\main.cpp .\arraypointer.cpp -o soal3
.\soal3.exe
```

**Contoh output:**

``` text
=== ARRAY SEBELUM DITUKAR ===

Array 1:
1   2   3
4   5   6
7   8   9

Array 2:
10  11  12
13  14  15
16  17  18

=== ARRAY SETELAH DITUKAR ===

Array 1:
1   2   3
4   14  6
7   8   9

Array 2:
10  11  12
13  5   15
16  17  18

=== POINTER SEBELUM DITUKAR ===
Nilai a = 100
Nilai b = 200

=== POINTER SETELAH DITUKAR ===
Nilai a = 200
Nilai b = 100
```

Output tersebut memperlihatkan bahwa hanya elemen pada posisi yang
dipilih yang bertukar, sedangkan elemen array lainnya tetap. Pada bagian
pointer, nilai `a` dan `b` bertukar melalui dereferensi pointer.

------------------------------------------------------------------------

## Dokumentasi Screenshot

Tambahkan screenshot **hasil terminal yang benar-benar dijalankan** ke
folder `LaprakModul3/screenshots/`. Pastikan screenshot memperlihatkan
command atau hasil program dan output yang terbaca.

Setelah file gambar disimpan sesuai nama berikut, bagian ini akan
menampilkan gambarnya di GitHub:

### Guided

Simpan screenshot output Guided dengan nama `guided-output.png`.

![Screenshot output Guided](screenshots/guided-output.png)

### Unguided --- Soal 1: Data Mahasiswa

Simpan screenshot yang menampilkan input data mahasiswa dan hasil
perhitungan nilai akhir dengan nama `soal1-output.png`.

![Screenshot output Soal 1](screenshots/soal1-output.png)

### Unguided --- Soal 2: ADT Pelajaran

Simpan screenshot output nama dan kode mata pelajaran dengan nama
`soal2-output.png`.

![Screenshot output Soal 2](screenshots/soal2-output.png)

### Unguided --- Soal 3: Array 2D dan Pointer

Simpan screenshot yang menampilkan array sebelum/sesudah pertukaran dan
nilai pointer dengan nama `soal3-output.png`.

![Screenshot output Soal 3](screenshots/soal3-output.png)

> Gambar di atas merupakan tautan relatif ke file screenshot yang perlu
> ditambahkan ke repositori. Gambar tidak akan tampil sampai file dengan
> nama dan lokasi tersebut benar-benar diunggah ke GitHub.

------------------------------------------------------------------------

## Kesimpulan

Berdasarkan praktikum Modul 3, ADT membantu memisahkan definisi tipe
data, deklarasi operasi, dan implementasi program. File header (`.h`)
berfungsi sebagai antarmuka, file implementasi (`.cpp`) berisi logika
fungsi/prosedur, dan `main.cpp` menjadi driver untuk menguji program.

Pada bagian Guided, ADT mahasiswa digunakan untuk menerima NIM dan dua
nilai, lalu menghitung rata-ratanya. Pada Unguided Soal 1, struktur data
mahasiswa dan array digunakan untuk menyimpan beberapa data serta
menghitung nilai akhir berdasarkan bobot. Pada Soal 2, fungsi pembentuk
objek dan fungsi tampilan diterapkan pada ADT pelajaran. Pada Soal 3,
perulangan digunakan untuk menampilkan array dua dimensi, variabel
sementara digunakan untuk menukar elemen, dan dereferensi pointer
digunakan untuk menukar nilai dua variabel.

Dengan latihan ini, konsep `struct`, prototype fungsi, implementasi
fungsi, array, dan pointer dapat dipraktikkan dalam struktur program C++
yang terpisah dan lebih terorganisasi.

## Daftar Pustaka

1.  **Modul Praktikum Struktur Data.** *Modul 3: Abstract Data Type
    (ADT)*, bagian 3.1 "Abstract Data Type (ADT)" dan 3.2 "Latihan".
    Materi praktikum yang diberikan pada perkuliahan.
2.  Microsoft Learn. *Header Files (C++)*.
    https://learn.microsoft.com/en-us/cpp/cpp/header-files-cpp
3.  cppreference.com. *Function declaration*.
    https://en.cppreference.com/w/cpp/language/function
4.  Microsoft Learn. *Struct (C++)*.
    https://learn.microsoft.com/en-us/cpp/cpp/struct-cpp

------------------------------------------------------------------------

## Catatan Kompilasi

Setiap latihan memiliki `main.cpp` masing-masing, sehingga kompilasikan
satu soal dalam satu waktu. Jangan menggabungkan seluruh `main.cpp` ke
dalam satu perintah kompilasi.

  -----------------------------------------------------------------------------------------------
  Folder                   Perintah compile                               Perintah menjalankan
  ------------------------ ---------------------------------------------- -----------------------
  Guided (`LatihanWeek3`)  `g++ .\main.cpp .\mahasiswa.cpp -o guided`     `.\guided.exe`

  Soal 1                   `g++ .\main.cpp .\mahasiswa.cpp -o soal1`      `.\soal1.exe`
  (`LaprakModul3/Soal1`)                                                  

  Soal 2                   `g++ .\main.cpp .\pelajaran.cpp -o soal2`      `.\soal2.exe`
  (`LaprakModul3/Soal2`)                                                  

  Soal 3                   `g++ .\main.cpp .\arraypointer.cpp -o soal3`   `.\soal3.exe`
  (`LaprakModul3/Soal3`)                                                  
  -----------------------------------------------------------------------------------------------

Jika Windows menampilkan pesan bahwa kebijakan *Application Control*
memblokir executable, itu bukan dengan sendirinya bukti bahwa kode gagal
dikompilasi. Ikuti kebijakan keamanan perangkat atau minta bantuan
administrator/dosen; jangan mencoba melewati pembatasan keamanan.
