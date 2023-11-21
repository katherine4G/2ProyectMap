#include "Ruta.h"


RutaMapa::RutaMapa()
{
}

RutaMapa::~RutaMapa()
{
}
void RutaMapa::agregarPunto(sf::Vector2f punto)
{
    sf::Vertex nuevoPunto(punto, sf::Color::Red);
    m_ruta.push_back(nuevoPunto);
}
void RutaMapa::guardarRuta(const std::string& nombreArchivo)
{
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        for (const sf::Vertex& punto : m_ruta)
        {
            archivo << punto.position.x << " " << punto.position.y << std::endl;
        }
        archivo.close();
    }
}
void RutaMapa::cargarRuta(const std::string& nombreArchivo)
{
    limpiarRuta();
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        float x, y;
        while (archivo >> x >> y)
        {
            agregarPunto(sf::Vector2f(x, y));
        }
        archivo.close();
    }
}
void RutaMapa::limpiarRuta()
{
    m_ruta.clear();
}
void RutaMapa::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(&m_ruta[0], m_ruta.size(), sf::Points, states);
}
void RutaMapa::agregarRuta(string nameRUTA) {

    //    std::cout << "Funcion de agregar ruta" << std::endl;

    cout << "Ingrese el nombre de la ruta: ";
    cin >> nameRUTA;
    std::cout << "Ruta " << nameRUTA << " creada." << std::endl;


}
// D
void RutaMapa::eliminarRuta() {
    std::cout << "Función de eliminar ruta" << std::endl;
}

void RutaMapa::editarRuta() {
    std::cout << "Función de editar ruta" << std::endl;

}

void RutaMapa::guardarDatos() {
    std::cout << "Función de guardar datos" << std::endl;
}

void RutaMapa::cargarDatos(RenderWindow& window) {
    std::cout << "Función de cargar datos" << std::endl;
}
void RutaMapa::finRuta() {
    std::cout << "Función de finalizar" << std::endl;
}


// Función para cambiar el color de la ruta
void RutaMapa::cambiarColorRuta(sf::Color color) {
    cout << "cambiar color ";
}

// Función para obtener el color seleccionado
sf::Color  RutaMapa::getColorSeleccionado() {
    cout << "cambiar color seleccionado ";

    return colorSeleccionado;
}
