#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Lista.h"

using namespace std;
using namespace sf;

const string NOMBRE_ARCXHIVO = "points.txt";

class RutaMapa : public Drawable, public Transformable//, public ListaDoble<T> 
{
private:
    Color colorSeleccionado;
    std::vector<sf::Vertex> m_ruta;
    Vector2f origen, destino;
    string nombre;
public:
    RutaMapa();

    /* RutaMapa(const sf::Vector2f& origen, const sf::Vector2f& destino, const sf::Color& color,string nom) : origen(origen), destino(destino), color(color), nombre(nom){}*/

    ~RutaMapa();
    void agregarPunto(sf::Vector2f punto);
    void guardarRuta(const std::string& nombreArchivo);
    void cargarRuta(const std::string& nombreArchivo);
    void limpiarRuta();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void agregarRuta(string nameRUTA);
    void eliminarRuta();

    void editarRuta();

    void guardarDatos();

    void cargarDatos(RenderWindow& window);
    void finRuta();

    // Función para cambiar el color de la ruta
    void cambiarColorRuta(sf::Color color);

    // Función para obtener el color seleccionado
    sf::Color getColorSeleccionado();

};

   