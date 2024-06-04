#ifndef INFO_JOC_H
#define INFO_JOC_H

#include "GraphicManager.h"
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/keyboard_sdl.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Cua.h"
using namespace std;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef struct
{
    int vertical;
    int horitzontal;
} Posicio;

typedef struct
{
    string jugador;
    int xifra;
} Puntuacio;

typedef enum
{
    NONE = 0,
    NORMAL,
    TEST,
    PUNTUACIONS,
    SORTIR
} OpcioMenu;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

typedef enum
{
    MOVIMENT_ESQUERRA,
    MOVIMENT_DRETA,
    MOVIMENT_GIR_HORARI,
    MOVIMENT_GIR_ANTI_HORARI,
    MOVIMENT_BAIXA,
    MOVIMENT_BAIXA_FINAL,
} TipusMoviment;

typedef enum
{
    TECLA_ESQUERRA,
    TECLA_DRETA,
    TECLA_AMUNT,
    TECLA_ABAIX,
    TECLA_ESPAI,
    TECLA_ESCAPE,
    NO_TECLA
} TipusTecla;

const int N_TIPUS_FIGURES = 7;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;

typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S
} TipusFigura;

// Tamany de la pantalla gràfica
const int SCREEN_SIZE_X = 600;
const int SCREEN_SIZE_Y = 700;

// Mida dels quadrats que formen el tauler
const int MIDA_QUADRAT = 26;
const int MIDA_QUADRAT_SMALL = 13;

// Temps que apareixen els missatges temporals
const int TEMPS_MISSATGE = 2;

// Maxim de figures a la cua
const int MAX_CUA = 3;

// Tamany del tauler
const int N_FILES_TAULER = 21;
const int N_COL_TAULER = 11;

// Posició del tauler a la pantalla
const int POS_X_TAULER = 120;
const int POS_Y_TAULER = 100;

#endif