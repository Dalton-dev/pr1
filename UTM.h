//
// Created by Dalton Gabriel Abambari on 25/9/23.
//

#ifndef PR1_UTM_H
#define PR1_UTM_H


class UTM {
private:
    float _latitud;
    float _longitud;
public:
    UTM();
    UTM(float latitud, float longitud);
    virtual ~UTM();

    float getLatitud() const;

    void setLatitud(float latitud);

    float getLongitud() const;

    void setLongitud(float longitud);
};


#endif //PR1_UTM_H
