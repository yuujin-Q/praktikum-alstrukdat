/**
 * NIM : 13521074
 * Nama : Eugene Yap Jin Quan
 * Tanggal : 2022/11/22
 * Topik praktikum : ADT Binary Tree
 * Deskripsi : bintree.c
 */

#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

/* Selektor 
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

typedef int ElType;
typedef struct treeNode* Address;
typedef struct treeNode { 
     ElType info;
     Address left;
     Address right;
} TreeNode;

Definisi PohonBiner 
pohon Biner kosong p = NULL

typedef Address BinTree; */

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree) {
    BinTree root_node = newTreeNode(root);
    if (root_node != NULL) {
        LEFT(root_node) = left_tree;
        RIGHT(root_node) = right_tree;
    }
    return root_node;
}
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
    *p = NewTree(root, left_tree, right_tree);
}
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val) {
    Address node = (Address) malloc(sizeof(TreeNode));
    if (node != NULL) {
        ROOT(node) = val;
        LEFT(node) = NULL;
        RIGHT(node) = NULL;
    }
    return node;
}
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p) {
    free(p);
}
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (BinTree p) {
    return (p == NULL);
}
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (BinTree p) {
    if (isTreeEmpty(p)) {
        return false;
    } else {
        return isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p));
    }
}
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p) {
    if (isTreeEmpty(p) || isOneElmt(p)) {
        return false;
    } else {
        return isTreeEmpty(RIGHT(p)) && !isTreeEmpty(LEFT(p));
    }
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (BinTree p) {
    if (isTreeEmpty(p) || isOneElmt(p)) {
        return false;
    } else {
        return isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
    }
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (BinTree p) {
    if (isTreeEmpty(p)) {
        return false;
    } else {
        return !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
    }
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */
void printPreorder(BinTree p) {
    putchar('(');
    if (!isTreeEmpty(p)) {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    putchar(')');
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

void printInorder(BinTree p) {
    putchar('(');
    if (!isTreeEmpty(p)) {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    putchar(')');
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

void printPostorder(BinTree p) {
    putchar('(');
    if (!isTreeEmpty(p)) {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    putchar(')');
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

void printIndent(BinTree p, int h, int l) {
    if (!isTreeEmpty(p)) {
        int maxIndent = h * l;
        int i;
        for (i = 0; i < maxIndent; i++) {
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        printIndent(LEFT(p), h, l + 1);
        printIndent(RIGHT(p), h, l + 1);
    }
}

void printTree(BinTree p, int h) {
    printIndent(p, h, 0);
}
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/



/*
 * NIM : 13521074
 * Nama : Eugene Yap Jin Quan
 * Tanggal : 2022/11/24
 * Topik praktikum : ADT Binary Tree
 * Deskripsi : bintree.c
 */
int rob1(BinTree root) {
	if (isOneElmt(root)) {
		return ROOT(root);
	} else if (isTreeEmpty(root)) {
		return 0;
	} else {
		int leftPath = ROOT(root) + rob1(LEFT(root));
		int rightPath = ROOT(root) + rob1(RIGHT(root));
		if (leftPath > rightPath) {
			return leftPath;
		} else {
			return rightPath;
		}
	}
}

// Menerima sebuah ruangan rumah yang akan dirampok.

// Mengembalikan hasil rampokan yang terbesar.


int rob2(BinTree root) {
	if (isTreeEmpty(root)) {
        return 0;
    } else {
		int robRoot, robLeft, robRight;
        robRoot = ROOT(root);
        robLeft = rob2(LEFT(root));
        robRight = rob2(RIGHT(root));

        if (robLeft > 0) {
            robRoot += rob2(LEFT(LEFT(root))) + rob2(RIGHT(LEFT(root)));
        }
        if (robRight > 0) {
            robRoot += rob2(LEFT(RIGHT(root))) + rob2(RIGHT(RIGHT(root)));
        }

        if (robRoot > robLeft + robRight) {
            return robRoot;
        } else {
            return robLeft + robRight;
        }
	}
}

// Menerima sebuah ruangan rumah yang akan dirampok.

// Mengembalikan hasil rampokan yang terbesar.
