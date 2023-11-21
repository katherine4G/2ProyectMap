#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

template <typename T>
struct Point {
    string rutaName;
    T x;
    T y;
    std::string name;
    Point() = default;
};


struct Ruta {

    std::string Name;
    Ruta() = default;

};

template <typename T>
struct Node {

    Point<T> point;
    Node<T>* prev;
    Node<T>* next;

};

template <typename T>
class ListaDoble {
private:
    Ruta ruta;
    //  Node<T> ruta;
    Node<T>* head;
    Node<T>* tail;
    std::string filename;

public:
   
    ~ListaDoble() {}
    ListaDoble(const std::string& file) 
    {
        ruta;
        head = nullptr;
        tail = nullptr;
        filename = file;
    }
  
    string guardarNombreRuta(string n) {
     
        ruta.Name = n;
        return n;

    }

    void insert(T x, T y, const string& name) {
        Point<T> newPoint;
        newPoint.x = x;
        newPoint.y = y;
        newPoint.rutaName = name;

        Node<T>* newNode = new Node<T>{ newPoint, nullptr, nullptr };

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void erase(const std::string& name) {
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->point.rutaName == name) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                }
                else if (current == tail) {
                    tail = current->prev;
                    if (tail != nullptr) {
                        tail->next = nullptr;
                    }
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete current;
                return;
            }

            current = current->next;
        }

        std::cout << "El punto con nombre " << name << " no se encontró en la lista." << std::endl;
    }

    void saveToFile(const string& nombreArchivo) {
        std::ofstream archivo(nombreArchivo);


        if (archivo.is_open()) {

            Node<T>* actual = head;
            while (actual != nullptr) {
                archivo << actual->point.name << " ";
                archivo << actual->point.x << "," << actual->point.y << "," << actual->point.rutaName << endl;

                actual = actual->next;

            }
            cout << endl;
            archivo.close();
            // std::cout << "Direcciones guardadas en el archivo: " << nombreArchivo << std::endl;
        }
        else {
            std::cout << "No se pudo abrir el archivo." << std::endl;
        }
    }

    void cerrarArchivo(const string file) {
        std::ofstream fileName(file);
        fileName.close();
    }
    void endRoute() {

        saveToFile(filename);
        display();
        head = nullptr;
        tail = nullptr;
        cerrarArchivo(filename);

    }
    void display() {
        Node<T>* current = head;

        while (current != nullptr) {
            std::cout << "Punto (" << current->point.x << ", " << current->point.y << ") - Nombre: " << current->point.rutaName << std::endl;
            current = current->next;
        }
        std::cout << "RUTA: " << ruta.Name << std::endl;
    }

    Node<T>* getPrimero()
    {
        return head;
    }

    Node<T>* getUltimo()
    {
        return tail;
    }


};