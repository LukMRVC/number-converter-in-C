/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 12. září 2017, 12:42
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*
 * 
 */

int potrebneMista(int cislo, int soustava){
    int i = 0;
    
    while(cislo != 0){
        ++i;
        cislo /= soustava;
    }
    
    return i;
}

int* doBinarni(int x){
    int j;
    int i = potrebneMista(x, 2);
    int *pole = (int*) malloc( (i * sizeof(int)) );
    for(j = 0; j < i; ++j){
        pole[j] = x % 2;
        x /= 2;
    }
    
    for(; i > 0; --i){
        printf("%d", pole[i-1]);
    }
    printf("\n");
    return pole;   
}

int* doOct(int cislo){
    int i = potrebneMista(cislo, 8);
    int j;
    int *pole = (int*) malloc( (i * sizeof(int)) );
    for(j = 0; j < i; ++j){
        pole[j] = cislo % 8;
        cislo /= 8;
    }
    
    for(; i > 0; --i){
        printf("%d", pole[i-1]);
    }
    printf("\n");
    return pole;
}

int indexOf(char znak){
    int i;
    char cisla[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for( i = 0; i < 16; i++){
        if(toupper(znak) == cisla[i])
            return i;
    }
}

int toDec(char cislo[], int soustava){
    int i = 0;
    int j = 0;
    int vysledek = 0;
    while( cislo[i] != '\0'){
        ++i;
    }
    if(soustava != 16){
        for( ; i > 0; --i ){
            vysledek += ( cislo[i-1]-'0' ) * pow(soustava, j);
            ++j;
        }
    }
    else {
        for( ; i > 0; --i ){
            vysledek +=  indexOf(cislo[i-1]) * pow(soustava, j);
            ++j;;
        }
    }
    return vysledek;
}

int doDec(char cislo[], int volba){
    switch(volba){
        case 0: return toDec(cislo, 2);
            break;
        case 1: return toDec(cislo, 8);
        break;
        case 2: return toDec(cislo, 10);
        break;
        case 3: return toDec(cislo, 16);
        break;
    }
}

char* doHex(int cislo){
    char cisla[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int i = potrebneMista(cislo, 16);
    int j;
    char* pole = (char*)malloc( i*sizeof(char));
    for(j = 0; j < i; ++j){
        pole[j] = cisla[cislo % 16];
        cislo /= 16;
    }
    
    for(; i > 0; --i){
        printf("%c", pole[i-1]);
    }
    printf("\n");
    return pole;
}


int main(int argc, char** argv) {
    int cislo;
    int volba;
    char znaky[100];
    printf("Vyber vstupni soustavu:\n ");
    printf("[0] - Bin [1] - Oct [2] - Dec [3] - Hex\n");
    scanf("%d", &volba);
    printf("Zadej cislo: ");
    scanf("%s", &znaky);
    cislo = doDec(znaky, volba);
    printf("Do ktere soustavy chcete prevest?\n");
    printf("[0] - Bin [1] - Oct [2] - Dec [3] - Hex\n");
    scanf("%d", &volba);
    switch(volba){
        case 0: doBinarni(cislo);
        break;
        case 1: doOct(cislo); 
        break;
        case 2: printf("%d\n", cislo);
        break;
        case 3: doHex(cislo);
        break;
    }
    return (EXIT_SUCCESS);
}

