//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#elif __APPLE__
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif

#include "./Tetris.h"
#include "./InfoJoc.h"

OpcioMenu menu()
{
    int opcio = 0;
    cout << "MENU PRINCIPAL" << endl;
    cout << "==============" << endl;
    cout << "1. Joc en mode normal" << endl;
    cout << "2. Joc en mode test" << endl;
    cout << "3. Mostrar puntuacions" << endl;
    cout << "4. Sortir" << endl;
    cin >> opcio;

    while (1 > opcio > 4)
    {
        cout << "Error: introdueix un altre caracter" << endl;
        cin >> opcio;
    }

    return OpcioMenu(opcio);
}

int main(int argc, const char* argv[])
{
    //Instruccions necesaries per poder incloure la llibreria i que trobi el main
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    Tetris tetris;
    OpcioMenu opcio;
    do
    {
        opcio = menu();
        switch (opcio)
        {
        case NORMAL:    tetris.juga(NORMAL);
            break;
        case TEST: tetris.juga(TEST);
            break;
        case PUNTUACIONS:   tetris.mostraPuntuacions();
            break;
        default:    cout << "E R R O R" << endl;
            break;
        }
    } while (opcio != SORTIR);

    //Instruccio necesaria per alliberar els recursos de la llibreria 
    SDL_Quit();
    return 0;
}

