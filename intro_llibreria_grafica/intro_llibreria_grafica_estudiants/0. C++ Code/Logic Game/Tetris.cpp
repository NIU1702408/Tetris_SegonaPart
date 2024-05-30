#include "Tetris.h"

void Tetris::inicialitzaTest()
{
    string FitxerTauler, FitxerFigures, FitxerMoviments;
    cout << "Nom del fitxer amb l'estat inicial del tauler: ";
    cin >> FitxerTauler;
    cout << endl << "Nom del fitxer amb la sequencia de figures: ";
    cin >> FitxerFigures;
    cout << "Nom del fitxer amb la sequencia de moviments: ";
    cin >> FitxerMoviments;
    cout << endl;
    string fitxer;

    m_joc.inicialitza(fitxer);
}

void Tetris::actualitzaPuntuacio(const string& nomJugador)
{
    //escriu nova puntuacio al fitxer
}

void Tetris::finalitzaNormal()
{
    string nom;
    cout << "Nom del jugador: ";
    cin >> nom;
    cout << endl;

    actualitzaPuntuacio(nom);
}

void Tetris::juga(const OpcioMenu& mode)
{
    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    //Mostrem la finestra grafica
    pantalla.show();

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    if (mode == NORMAL)
        inicialitzaNormal();
    else
        inicialitzaTest();

    do
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

        // Captura tots els events de ratolí i teclat de l'ultim cicle
        pantalla.processEvents();

        m_joc.actualitza(deltaTime);

        // Actualitza la pantalla
        pantalla.update();

    } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
    // Sortim del bucle si pressionem ESC

    if (NORMAL)
        finalitzaNormal();
}

void Tetris::mostraPuntuacions() const
{
    //llegeix les puntuacions del fitxer
}