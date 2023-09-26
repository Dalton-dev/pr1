//
// Created by Dalton Gabriel Abambari on 25/9/23.
//

#include "UTM.h"

UTM::UTM() {}

UTM::UTM(float latitud, float longitud) : _latitud(latitud), _longitud(longitud) {}

UTM::~UTM() {

}

float UTM::getLatitud() const {
    return _latitud;
}

void UTM::setLatitud(float latitud) {
    _latitud = latitud;
}

float UTM::getLongitud() const {
    return _longitud;
}

void UTM::setLongitud(float longitud) {
    _longitud = longitud;
}
