#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "VDinamico.h"
#include <algorithm>
#include "UTM.h"
#include "Aeropuerto.h"

int main(int argc, const char * argv[]) {

    VectorDinamico<Aeropuerto> aeropuerto; //Creamos un vector de aeropuertos
    std::cout << "Comienzo de lectura de un fichero " << endl;
    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    int contador=0;

    std::string id = "";
    std::string ident="";
    std::string tipo="";
    std::string nombre="";
    std::string latitud_str="";
    std::string longitud_str="";
    std::string continente="";
    std::string iso_pais="";

    float latitud, longitud;

    is.open("../aeropuertos.csv"); //carpeta de proyecto
    if ( is.good() ) {

        clock_t t_ini = clock();

        while ( getline(is, fila ) ) {

            //¿Se ha leído una nueva fila?
            if (fila!="") {

                columnas.str(fila);

                //formato de fila: id;ident;tipo;nombre;latitud;longitud;continente;iso_pais

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas,ident,';');
                getline(columnas,tipo,';');
                getline(columnas,nombre,';');
                getline(columnas,latitud_str,';');
                getline(columnas,longitud_str,';');
                getline(columnas,continente,';');
                getline(columnas,iso_pais,';');

                //  Transformamos la latitud y longitud a float
                latitud=std::stof(latitud_str);
                longitud=std::stof(longitud_str);

                fila="";
                columnas.clear();

                std::cout << ++contador
                          << " Aeropuerto: ( ID=" << id
                          << " ident=" << ident << " Tipo=" << tipo << " Nombre=" << nombre
                          << " Posicion=(" << latitud << ", " << longitud << ")"
                          << " Continente=" << continente << " Pais=" << iso_pais
                          << ")" << std::endl;
                //Creamos objeto tipo UTM
                UTM UTM1 = UTM(latitud,longitud);
            }
        }

        is.close();

        std::cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
    //Muestra los primeros 50 aeropuertos
    for( int i=0; i<50; i++ ){
        cout << "Numero " << i << ":" << endl;
        cout << "ID: " << aeropuerto[i].getId() << ",";
        cout << "Ident: " << aeropuerto[i].getIdent() << ",";
        cout << "Tipo: " << aeropuerto[i].getTipo() << ",";
        cout << "Nombre del Aeropuerto: " << aeropuerto[i].getNombre() << ",";
        cout << "Continente: " << aeropuerto[i].getContinente();
        cout << "IsoPais: " << aeropuerto[i].getIsoPais();
    }

    //Muestra las primeras 50 aeropuerto ordenadas de menor a mayor
    for( int i=0; i<50; i++ ){
        cout << "Numero " << i << ":" << endl;
        cout << "ID: " << aeropuerto[i].getId() << ",";
        cout << "Ident: " << aeropuerto[i].getIdent() << ",";
        cout << "Tipo: " << aeropuerto[i].getTipo() << ",";
        cout << "Nombre del Aeropuerto: " << aeropuerto[i].getNombre() << ",";
        cout << "Continente: " << aeropuerto[i].getContinente();
        cout << "IsoPais: " << aeropuerto[i].getIsoPais();
    }

    return 0;
}