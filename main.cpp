#include "Lista.h"
#include "Ruta.h"
#include <vector>

using namespace std;
using namespace sf;

RutaMapa ruta;

int main() {
    setlocale(LC_ALL, "");
   
    ListaDoble<float> lista("points.txt");  
    std::string filename = "points.txt";
    string RUTA = "";
    //string RUTA = lista.guardarNombreRuta(RUTA);
    std::string namePto;
    sf::Color colorSeleccionado = sf::Color::Black; // Color inicial
    sf::Font font;
    font.loadFromFile("Fonts/BlackOpsOne-Regular.ttf");

    sf::RectangleShape botonAgregar(sf::Vector2f(200, 50));
    botonAgregar.setPosition(850, 50);
    sf::Text textoAgregar;
    botonAgregar.setFillColor(sf::Color(40, 116, 166));
    textoAgregar.setString("Agregar Ruta");
    textoAgregar.setFont(font);
    textoAgregar.setCharacterSize(20);
    textoAgregar.setPosition(botonAgregar.getPosition().x + 10, botonAgregar.getPosition().y + 10);

    // paleta de colores
    sf::RectangleShape redColor(sf::Vector2f(45, 45));
    redColor.setPosition(870, 120);
    redColor.setFillColor(sf::Color::Red);

    sf::RectangleShape greenColor(sf::Vector2f(45, 45));
    greenColor.setPosition(925, 120);
    greenColor.setFillColor(sf::Color::Green);

    sf::RectangleShape blueColor(sf::Vector2f(45, 45));
    blueColor.setPosition(980, 120);
    blueColor.setFillColor(sf::Color::Blue);

    sf::RectangleShape yellowColor(sf::Vector2f(45, 45));
    yellowColor.setPosition(870, 170);
    yellowColor.setFillColor(sf::Color::Yellow);

    sf::RectangleShape pinkColor(sf::Vector2f(45, 45));
    pinkColor.setPosition(925, 170);
    pinkColor.setFillColor(sf::Color::Magenta);

    sf::RectangleShape cyanColor(sf::Vector2f(45, 45));
    cyanColor.setPosition(980, 170);
    cyanColor.setFillColor(sf::Color::Cyan);
    //--

    sf::RectangleShape botonEliminar(sf::Vector2f(200, 50));
    botonEliminar.setPosition(850, 300);
    sf::Text textoEliminar;
    botonEliminar.setFillColor(sf::Color(40, 116, 166));
    textoEliminar.setString("Eliminar");
    textoEliminar.setFont(font);
    textoEliminar.setCharacterSize(20);
    textoEliminar.setPosition(botonEliminar.getPosition().x + 10, botonEliminar.getPosition().y + 10);

    sf::RectangleShape botonEditar(sf::Vector2f(200, 50));
    botonEditar.setPosition(850, 360);
    sf::Text textoEditar;
    botonEditar.setFillColor(sf::Color(40, 116, 166));
    textoEditar.setString("Editar");
    textoEditar.setFont(font);
    textoEditar.setCharacterSize(20);
    textoEditar.setPosition(botonEditar.getPosition().x + 10, botonEditar.getPosition().y + 10);

    sf::RectangleShape botonGuardar(sf::Vector2f(200, 50));
    botonGuardar.setPosition(850, 420);
    sf::Text textoGuardar;
    botonGuardar.setFillColor(sf::Color(40, 116, 166));
    textoGuardar.setString("Guardar");
    textoGuardar.setFont(font);
    textoGuardar.setCharacterSize(20);
    textoGuardar.setPosition(botonGuardar.getPosition().x + 10, botonGuardar.getPosition().y + 10);

    sf::RectangleShape botonCargar(sf::Vector2f(200, 50));
    botonCargar.setPosition(850, 480);
    sf::Text textoCargar;
    botonCargar.setFillColor(sf::Color(40, 116, 166));
    textoCargar.setString("Cargar");
    textoCargar.setFont(font);
    textoCargar.setCharacterSize(20);
    textoCargar.setPosition(botonCargar.getPosition().x + 10, botonCargar.getPosition().y + 10);

    sf::RectangleShape botonFin(sf::Vector2f(200, 50));
    botonFin.setPosition(850, 540);
    sf::Text textoFin;
    botonFin.setFillColor(sf::Color(40, 116, 166));
    textoFin.setString("Finalizar Ruta");
    textoFin.setFont(font);
    textoFin.setCharacterSize(20);
    textoFin.setPosition(botonFin.getPosition().x + 10, botonFin.getPosition().y + 10);

refresh:

    std::ifstream archivo("points.txt");
    if (archivo.is_open()) {
        sf::RenderWindow ventana(sf::VideoMode(1100, 700), " CONOZCA COSTA RICA ");
     
        sf::VertexArray segmentos(sf::LineStrip);
        for (int i = 0; i < segmentos.getVertexCount(); ++i) {
            segmentos[i].position += sf::Vector2f(i * 5, i * 5); // Ajustamos la posición de cada vérticé
        }

        ListaDoble<sf::Text>;

        if (!font.loadFromFile("Fonts/BlackOpsOne-Regular.ttf"))
        {
            std::cerr << "Error al cargar la fuente" << std::endl;
            return -1;
        }


        sf::Texture texturaMapa;
        texturaMapa.loadFromFile("IMAGEN.IER/mapCR.bmp");
        std::string linea;
        while (std::getline(archivo, linea))
        {

            std::size_t comaPos = linea.find(",");
            if (comaPos != std::string::npos)
            {
                int x = std::stoi(linea.substr(0, comaPos));
                int y = std::stoi(linea.substr(comaPos + 1));

                // Delimitar las coordenadas dentro de los límites de la imagen del mapa
                const int xMin = 0;
                const int xMax = texturaMapa.getSize().x;
                const int yMin = 0;
                const int yMax = texturaMapa.getSize().y;

                if (x >= xMin && x <= xMax && y >= yMin && y <= yMax)
                {
                    segmentos.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Black));
                }

            }
            std::size_t voidRute = linea.find("");
            if (voidRute != std::string::npos) {
                segmentos.getVertexCount();
                RUTA;
            }
        }


        while (ventana.isOpen()) {
            sf::Event evento;

            while (ventana.pollEvent(evento)) {
                if (evento.type == sf::Event::Closed) ventana.close();
                else if (evento.type == sf::Event::MouseButtonPressed)
                {
                    if (evento.mouseButton.button == Mouse::Left)
                    {
                        double x = evento.mouseButton.x;
                        double y = evento.mouseButton.y;

                        // Delimitar las coordenadas dentro de los límites de la imagen del mapa
                        const int xMin = 0;
                        const int xMax = texturaMapa.getSize().x;
                        const int yMin = 0;
                        const int yMax = texturaMapa.getSize().y;



                        Vector2i posicionMouse = Mouse::getPosition(ventana);

                        if (botonAgregar.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {


                            cout << "Ingrese el nombre de la ruta: ";
                            //  std::cin >> RUTA;
                            std::getline(std::cin, RUTA);
                            for (char& c : RUTA) {
                                c = std::toupper(c);
                            }

                            lista.saveToFile("points.txt");



                        }

                        if (x >= xMin && x <= xMax && y >= yMin && y <= yMax) {
                            //  std::string name;
                            std::cout << "Ingrese el nombre del punto: ";
                            std::cin >> namePto;
                            float x = static_cast<float>(evento.mouseButton.x);
                            float y = static_cast<float>(evento.mouseButton.y);

                            lista.insert(x, y, namePto);
                            lista.saveToFile("points.txt");

                        }
                        else if (botonEliminar.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {
                            string n;
                            cout << "escribe el nombre del punto que deseas eliminar ";
                            cin >> n;  lista.erase(n);

                            if (x >= xMin && x <= xMax && y >= yMin && y <= yMax) {
                                segmentos.append(sf::Vertex(sf::Vector2f(x, y), colorSeleccionado));

                            }
                            ruta.eliminarRuta();

                        }
                        else if (botonEditar.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {
                            archivo.clear();

                            ruta.editarRuta();
                        }

                        else if (botonGuardar.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {

                            ruta.guardarDatos();
                        }
                        else if (botonCargar.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {
                            ruta.cargarDatos(ventana); goto refresh;
                        }
                        else if (botonFin.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {
                            lista.endRoute();

                            ruta.finRuta();

                        }
                        ////
                        if (evento.mouseButton.button == sf::Mouse::Left)
                        {
                            sf::Vector2i posicionMouse = sf::Mouse::getPosition(ventana);

                            if (redColor.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {
                                colorSeleccionado = redColor.getFillColor();
                                ruta.cambiarColorRuta(colorSeleccionado); cout << " -> Red." << endl;
                                // Cambiamos el color de los segmentos
                                for (int i = 0; i < segmentos.getVertexCount(); ++i) {
                                    segmentos[i].color = sf::Color::Red; 
                                }
                            }
                            else if (greenColor.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {

                                colorSeleccionado = greenColor.getFillColor();
                                ruta.cambiarColorRuta(colorSeleccionado); cout << " -> Green." << endl;

                                for (int i = 0; i < segmentos.getVertexCount(); ++i) {
                                    segmentos[i].color = sf::Color::Green; 
                                }
                            }
                            else if (blueColor.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {

                                colorSeleccionado = blueColor.getFillColor();
                                ruta.cambiarColorRuta(colorSeleccionado); cout << " -> Blue." << endl;
                                for (int i = 0; i < segmentos.getVertexCount(); ++i) {
                                    segmentos[i].color = sf::Color::Blue;
                                }
                            }
                            else if (yellowColor.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {

                                colorSeleccionado = yellowColor.getFillColor();
                                ruta.cambiarColorRuta(colorSeleccionado); cout << " -> Yellow." << endl;
                                for (int i = 0; i < segmentos.getVertexCount(); ++i) {
                                    segmentos[i].color = sf::Color::Yellow;
                                }
                            }
                            else if (pinkColor.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {
                                for (int i = 0; i < segmentos.getVertexCount(); ++i) {
                                    segmentos[i].color = sf::Color::Magenta;
                                }
                                colorSeleccionado = pinkColor.getFillColor();
                                ruta.cambiarColorRuta(colorSeleccionado); cout << " -> Magenta." << endl;
                            }
                            else if (cyanColor.getGlobalBounds().contains(posicionMouse.x, posicionMouse.y)) {
                                for (int i = 0; i < segmentos.getVertexCount(); ++i) {
                                    segmentos[i].color = sf::Color::Cyan;
                                }
                                colorSeleccionado = cyanColor.getFillColor();
                                ruta.cambiarColorRuta(colorSeleccionado); cout << " -> Cyan." << endl;
                            }
                        }
                      
                    }
                }
            }

            ventana.clear(sf::Color(91, 44, 111));
            ventana.draw(sf::Sprite(texturaMapa));

            ventana.draw(botonAgregar);
            ventana.draw(textoAgregar);


            //  paleta de colores //
            ventana.draw(redColor);
            ventana.draw(greenColor);
            ventana.draw(blueColor);
            ventana.draw(yellowColor);
            ventana.draw(pinkColor);
            ventana.draw(cyanColor);
            //-------------------//

            ventana.draw(botonEliminar);
            ventana.draw(textoEliminar);
            ventana.draw(botonEditar);
            ventana.draw(textoEditar);
            ventana.draw(botonGuardar);
            ventana.draw(textoGuardar);
            ventana.draw(botonCargar);
            ventana.draw(textoCargar);
            ventana.draw(botonFin);
            ventana.draw(textoFin);


            // Dibujar puntos al presionar la ventana
            Node<float>* current = lista.getPrimero();
            while (current != nullptr)
            {
                sf::CircleShape circle(5);
                circle.setFillColor(sf::Color::Red);
                circle.setPosition(current->point.x, current->point.y);
                ventana.draw(circle);

                sf::Text text;
                text.setString(current->point.rutaName);
                text.setFont(font);
                text.setCharacterSize(12);
                text.setFillColor(sf::Color::Black);
                text.setPosition(current->point.x + 10, current->point.y - 10);

                ventana.draw(text);
                current = current->next;

            }

            ventana.draw(segmentos); 

            sf::Text text(RUTA, font, 30);
            text.setFillColor(sf::Color::Black);
            text.setPosition(100, 670);
            ventana.draw(text);

            ventana.display();
        }
        archivo.close();
    }
    else  
        cout << "No se pudo abrir el archivo." << std::endl;
    

    return 0;
}