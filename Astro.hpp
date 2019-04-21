#ifndef ASTRO_H
#define ASTRO_H
#include <string>

class Astro{
    public:
        int getRaio();
        int getTempMedia();
        float getGravidade();
        std::string getNome();
        bool isGasoso();
        std::string getOrbitando();
        void setRaio(int);
        void setTempMedia(int);
        void setGravidade(float);
        void setNome(std::string);
        void setGasoso(bool);
        void setOrbita(std::string);
        
    protected:
        int raio=0;
        int tempMedia=0;
        float gravidade=0.0;
        std::string nome="";
        bool gasoso=false;
        std::string orbita="";
    
};
#endif