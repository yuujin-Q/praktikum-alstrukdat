#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "point.h"
        

void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P){
    float x, y;
    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
} 

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2){
    return (Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2));
}
boolean IsOrigin (POINT P){
    return (Absis(P) == 0 && Ordinat(P) == 0);
}
boolean IsOnSbX (POINT P){
    return Ordinat(P) == 0;
}
boolean IsOnSbY (POINT P){
    return Absis(P) == 0;
}
int Kuadran (POINT P){
    if (Absis(P)>0 && Ordinat(P)>0){
        return 1;
    }
    else if (Absis(P)<0 && Ordinat(P)>0){
        return 2;
    }
    else if (Absis(P)<0 && Ordinat(P)<0){
        return 3;
    }
    else if (Absis(P)>0 && Ordinat(P)<0){
        return 4;
    }
}

POINT NextX (POINT P){
    Absis(P) += 1;
    return P;
}
POINT NextY (POINT P){
    Ordinat(P) += 1;
    return P;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}
POINT MirrorOf (POINT P, boolean SbX){
    if (SbX){
        Ordinat(P) *= (-1);
    }
    else{
        Absis(P) *= (-1);
    }
    return P;
}

float Jarak0 (POINT P){
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
}
float Panjang (POINT P1, POINT P2){
    return sqrt(pow(Absis(P1) - Absis(P2), 2) + pow(Ordinat(P1) - Ordinat(P2), 2));
}
void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}
void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
    *P = MirrorOf(*P, SbX);
}
void Putar (POINT *P, float Sudut){
    float newX, newY;
    Sudut = Sudut * M_PI / 180.0;
    newX = Absis(*P) * cos(Sudut) - Ordinat(*P) * sin(Sudut);
    newY = Absis(*P) * sin(Sudut) + Ordinat(*P) * cos(Sudut);
    CreatePoint(P, newX, newY);
}