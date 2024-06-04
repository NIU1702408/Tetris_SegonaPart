#include "Tetris.h"

void Tetris::inicialitzaNormal() 
{
    string fitxer;
    string nom;

    // Demana el nom per poder guardar la puntuació posteriorment
    cout << "Nom del jugador: ";
    cin >> nom;
    cout << endl;
    m_puntuacioActual.jugador = nom;

    m_joc.inicialitza(fitxer); 
}

void Tetris::inicialitzaTest()
{
    string fitxer;
    string FitxerTauler, FitxerFigures, FitxerMoviments;

    cout << "Nom del fitxer amb l'estat inicial del tauler: ";
    cin >> FitxerTauler;
    cout << endl << "Nom del fitxer amb la sequencia de figures: ";
    cin >> FitxerFigures;
    cout << "Nom del fitxer amb la sequencia de moviments: ";
    cin >> FitxerMoviments;
    cout << endl;

    m_joc.inicialitza(fitxer);
}

void Tetris::actualitzaPuntuacio()
{
    //escriu nova puntuacio al fitxer
    ofstream file("puntuacio.txt", ios::app);
    file << m_puntuacioActual.jugador << ": " << m_puntuacioActual.xifra << endl;
}

void Tetris::juga(const OpcioMenu& mode)
{
    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    if (mode == NORMAL)
        inicialitzaNormal();
    else
        inicialitzaTest();

    //Mostrem la finestra grafica
    pantalla.show();

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

    m_puntuacioActual.xifra = m_joc.getPuntuacio();
    actualitzaPuntuacio();
}

void Tetris::mostraPuntuacions() const
{
    //llegeix les puntuacions del fitxer
    ifstream file("puntuacio.txt");
    cout << endl;
    cout << "Puntuacions:" << endl;
    cout << "============" << endl;
    string line;
    int i = 1;
    while (getline(file, line)) {
        cout << i << ". " << line << endl;
        i++;
    }
    cout << endl;
}
