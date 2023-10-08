//
// Created by Dalton Gabriel Abambari on 25/9/23.
//

#include "Aeropuerto.h"

Aeropuerto::Aeropuerto() = default;

Aeropuerto::Aeropuerto(const std::string &id, const std::string &ident, const std::string &tipo,
                       const std::string &nombre, const std::string &continente, const std::string &isoPais) : _id(id),
                                                                                                               _ident(ident),
                                                                                                               _tipo(tipo),
                                                                                                               _nombre(nombre),
                                                                                                               _continente(
                                                                                                                       continente),
                                                                                                               _iso_pais(isoPais) {
    _id=id;
    _ident=ident;
    _tipo=tipo;
    _nombre=nombre;
    _continente=continente;
    _iso_pais=isoPais;
}

Aeropuerto::Aeropuerto(const Aeropuerto &orig) {
    this->_id = orig._id;
    this->_ident = orig._ident;
    this->_tipo = orig._tipo;
    this->_nombre = orig._nombre;
    this->_continente = orig._continente;
    this->_iso_pais = orig._iso_pais;

}

Aeropuerto &Aeropuerto::operator=(const Aeropuerto &f)
{
    _id = f._id;
    _ident = f._ident;
    _tipo = f._tipo;
    _nombre = f._nombre;
    _continente = f._continente;
    _iso_pais = f._iso_pais;
    return *this;
}


Aeropuerto::~Aeropuerto() {

}

const std::string &Aeropuerto::getId() const {
    return _id;
}

void Aeropuerto::setId(const std::string &id) {
    _id = id;
}

const std::string &Aeropuerto::getIdent() const {
    return _ident;
}

void Aeropuerto::setIdent(const std::string &ident) {
    _ident = ident;
}

const std::string &Aeropuerto::getTipo() const {
    return _tipo;
}

void Aeropuerto::setTipo(const std::string &tipo) {
    _tipo = tipo;
}

const std::string &Aeropuerto::getNombre() const {
    return _nombre;
}

void Aeropuerto::setNombre(const std::string &nombre) {
    _nombre = nombre;
}

const std::string &Aeropuerto::getContinente() const {
    return _continente;
}

void Aeropuerto::setContinente(const std::string &continente) {
    _continente = continente;
}

const std::string &Aeropuerto::getIsoPais() const {
    return _iso_pais;
}

void Aeropuerto::setIsoPais(const std::string &isoPais) {
    _iso_pais = isoPais;
}


