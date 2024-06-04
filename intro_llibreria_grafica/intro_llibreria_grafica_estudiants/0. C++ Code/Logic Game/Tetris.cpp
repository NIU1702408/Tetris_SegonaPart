#include "Tetris.h"

void Tetris::inicialitzaNormal()
{
    string nom;

    // Demana el nom per poder guardar la puntuació posteriorment
    cout << "Nom del jugador: ";
    cin >> nom;
    cout << endl;
    m_puntuacioActual.jugador = nom;

    m_joc.inicialitza(NORMAL, "", "", "");
}

void Tetris::inicialitzaTest()
{
    string fitxerTauler, fitxerFigures, fitxerMoviments;

    cout << "Nom del fitxer amb l'estat inicial del tauler: ";
    cin >> fitxerTauler;
    cout << endl << "Nom del fitxer amb la sequencia de figures: ";
    cin >> fitxerFigures;
    cout << "Nom del fitxer amb la sequencia de moviments: ";
    cin >> fitxerMoviments;
    cout << endl;

    m_joc.inicialitza(TEST, fitxerTauler, fitxerFigures, fitxerMoviments);
}

void Tetris::actualitzaPuntuacio()
{
    //escriu nova puntuacio al fitxer
    ofstream file("puntuacio.txt", ios::app);
    file << m_puntuacioActual.jugador << ": " << m_puntuacioActual.xifra << endl;
}

void showGameOver()
{
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER, 1.0, "G A M E  O V E R");
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER + 50, 1.0, "Prem Esc per sortir");
}

void Tetris::juga(const OpcioMenu& mode)
{
    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;
    bool gameOver = false;

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

        if (!gameOver)
            m_joc.actualitza(deltaTime, gameOver);
        else
            showGameOver();

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
