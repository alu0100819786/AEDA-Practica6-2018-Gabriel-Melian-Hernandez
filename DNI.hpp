#include "common.hpp"

#pragma once

using namespace std;

class  DNI{
    
    private:
        
        
    public:
        
        string DNI_;
        DNI(void);
        DNI(string matricula_entrada);
        ~DNI(void);
        string get_DNI(void);
        void set_DNI(string DNI_entrada);
        void set_random(void);
        bool operator<(DNI& DNI_cp);
        bool operator>(DNI& DNI_cp);
        bool operator==(DNI& DNI_cp);
        friend ostream& operator<<(ostream& os, const DNI& DNI_salida);
        ostream& imprimir (ostream& os) const;
        operator unsigned long(void);
};