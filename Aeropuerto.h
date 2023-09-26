//
// Created by Dalton Gabriel Abambari on 25/9/23.
//

#ifndef PR1_AEROPUERTO_H
#define PR1_AEROPUERTO_H
#include <string>
#include "UTM.h"

class Aeropuerto {
private:
    std::string _id;
    std::string _ident;
    std::string _tipo;
    std::string _nombre;
    std::string _continente;
    std::string _iso_pais;
public:
    Aeropuerto();

    Aeropuerto(const std::string &id, const std::string &ident, const std::string &tipo, const std::string &nombre,
               const std::string &continente, const std::string &isoPais);

    virtual ~Aeropuerto();

    const std::string &getId() const;
    void setId(const std::string &id);

    const std::string &getIdent() const;
    void setIdent(const std::string &ident);

    const std::string &getTipo() const;
    void setTipo(const std::string &tipo);

    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);

    const std::string &getContinente() const;
    void setContinente(const std::string &continente);

    const std::string &getIsoPais() const;
    void setIsoPais(const std::string &isoPais);

};


#endif //PR1_AEROPUERTO_H
