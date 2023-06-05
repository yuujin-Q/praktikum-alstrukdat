/* 
NIM : 13521074
Nama : Eugene Yap Jin Quan
Tanggal : 15/09/2022
Topik praktikum : ADT Matrix
Deskripsi : body ADT matriks (matrix.c)
*/

#include <stdio.h>
#include <math.h>
#include "matrix.h"


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
};
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    return (i>=0 && i<ROW_CAP) && (j>=0 && j<COL_CAP);
};
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
    return ROW_EFF(m) - 1;
};
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m){
    return COL_EFF(m) - 1;
};
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (i>=0 && i<=getLastIdxRow(m))&&(j>=0 && j<=getLastIdxCol(m));
};
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i){
    return ELMT(m, i, i);
};
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    int i,j;
    for (i=0;i<=getLastIdxRow(mIn);i++){
        for (j=0;j<=getLastIdxCol(mIn);j++){
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
};
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    ElType val;
    createMatrix(nRow, nCol, m);
    int i, j;
    for (i=0;i<nRow;i++){
        for (j=0;j<nCol;j++){
            scanf("%d", &val);
            ELMT(*m, i, j) = val;
        }
    }
};
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    int i, j;
    for (i=0;i<=getLastIdxRow(m);i++){
        for (j=0;j<=getLastIdxCol(m);j++){
            printf("%d", ELMT(m, i, j));
            if (j<getLastIdxCol(m)){
                putchar(' ');
            }
        }
        putchar('\n');
    }
};
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    int i, j;
    for (i=0; i<=getLastIdxRow(m1); i++){
        for (j=0; j<=getLastIdxCol(m1); j++){
            ELMT(m1, i, j) += ELMT(m2, i, j);
        }
    }
    return m1;
};
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
    int i, j;
    for (i=0; i<=getLastIdxRow(m1); i++){
        for (j=0; j<=getLastIdxCol(m1); j++){
            ELMT(m1, i, j) -= ELMT(m2, i, j);
        }
    }
    return m1;
};
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    int i, j, k;
    ElType sum;
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    for (i=0; i<=getLastIdxRow(m3); i++){
        for (j=0; j<=getLastIdxCol(m3); j++){
            sum = 0;
            for (k=0; k<COL_EFF(m1); k++){
                sum += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            ELMT(m3, i, j) = sum;
        }
    }
    return m3;
};
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyByConst(Matrix m, ElType x){
    int i, j;
    for (i=0; i<=getLastIdxRow(m); i++){
        for (j=0; j<=getLastIdxCol(m); j++){
            ELMT(m, i, j) *= x;
        }
    }
    return m;
};
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k){
    *m = multiplyByConst(*m, k);
};
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
    boolean equal = (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1)==COL_EFF(m2)) && (getLastIdxCol(m1)==getLastIdxCol(m2));
    if (equal==true){
        int i=0;
        int j;
        while (i<=getLastIdxRow(m1) && equal){
            j=0;
            while (j<=getLastIdxCol(m1) && equal){
                if(ELMT(m1, i, j) != ELMT(m2, i, j)){
                    equal = false;
                }
                else{
                    j++;
                }
            }
            i++;
        }
        return equal;
    }
    else{
        return false;
    }
};
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return (!isMatrixEqual(m1, m2));
};
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1)==COL_EFF(m2));
};
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
    return ROW_EFF(m) * COL_EFF(m);
};
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
    return (ROW_EFF(m) == COL_EFF(m));
};
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m){
    if (isSquare(m)){
        int i, j;
        int width = ROW_EFF(m);
        boolean equal = true;
        
        i=0;
        while (i<width && equal) {
            j=1;
            while (i+j<width && equal) {
               equal = (ELMT(m, i+j, i)==ELMT(m, i, i+j));
               j++; 
            }
            i++;
        }
        return equal;
    }
    else{
        return false;
    }
};
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m){
    if (isSquare(m)){
        int i, j;
        int width = ROW_EFF(m);
        boolean identity = true;

        i=0;
        while(identity && i<width){
            j=0;
            while (identity && j<width){
                identity = (i==j && ELMT(m,i,j)==1) || (i!=j && ELMT(m,i,j)==0);
                j++;
            }
            i++;
        }
        return identity;
    }
    else{
        return false;
    }
};
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m){
    float oneElmt = 100.0 / (countElmt(m));
    float percentage = 0;
    int i, j;
    i=0;
    while(percentage<=5 && i<=getLastIdxRow(m)){
        j=0;
        while(percentage<=5 && j<=getLastIdxCol(m)){
            if (ELMT(m, i, j)!=0){
                percentage += oneElmt;
            }
            j++;
        }
        i++;
    }
    return (percentage<=5);
};
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m){
    return multiplyByConst(m, -1);
};
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m){
    *m = negation(*m);
};

Matrix getMinor(Matrix m, int entryRow, int entryCol){
    Matrix minor;
    createMatrix(ROW_EFF(m)-1, ROW_EFF(m)-1, &minor);
    int i,j;
    int k=0;    // indeks baris minor
    int l;      // indeks kolom minor
    for (i = 0; i < ROW_EFF(m); i++) {
        if (i==entryRow) {
            continue;
        } else {
            l=0;
            for (j = 0; j < COL_EFF(m); j++) {
                if (j!=entryCol) {
                    ELMT(minor,k,l) = ELMT(m,i,j);
                    l++;
                }
            }
            k++;    
        }
    }
    return minor;
}

/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant(Matrix m){
    if (ROW_EFF(m)==1 || COL_EFF(m)==1){
        return (float) getElmtDiagonal(m,0);
    }
    else if (ROW_EFF(m)==2 || COL_EFF(m)==2){
        return (float) (ELMT(m,0,0)*ELMT(m,1,1) - ELMT(m,0,1)*ELMT(m,1,0));
    }
    else{    
        float det = 0;
        int sign = 1;
        int j;
        for (j = 0; j <= getLastIdxCol(m); j++){
            det += sign * ELMT(m,0,j) * determinant(getMinor(m, 0, j));
            sign = -sign;
        }
        return det;
    }
};

/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m){
    Matrix mt;
    int i, j;
    createMatrix(COL_EFF(m), ROW_EFF(m), &mt);
    for (i=0; i<=getLastIdxRow(m); i++){
        for (j=0; j<=getLastIdxCol(m); j++){
            ELMT(mt, j, i) = ELMT(m, i, j);
        }
    }
    return mt;
};
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m){
    *m = transpose(*m);
};
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
