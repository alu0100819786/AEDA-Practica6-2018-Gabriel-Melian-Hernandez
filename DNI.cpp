#include "DNI.hpp"

DNI::DNI (void):
DNI_("000000000")
{
    for (int i = 0; i < 9; i++) {
        DNI_[i] = 0;
    }
}
        
DNI::DNI(string DNI_entrada)

{
    
   for (int i = 0; i < 9; i++) {
        DNI_[i]=DNI_entrada[i];
    }
}

DNI::~DNI(void){}

string DNI::get_DNI(void){
    return DNI_;
}

void DNI::set_DNI(string DNI_entrada){
    
    if(DNI_entrada < "00000000A" || DNI_entrada > "99999999Z"){
        	cout << "El DNI introducido no es válido. Se insertará uno aleatorio" << endl;
		    set_random();
    }
    else {
        DNI_=DNI_entrada;
    }
}

void DNI::set_random(void){
    
    for(int i=0;i<8;i++){
        
     DNI_[i] = rand() % 10 + 48;    // 10 porque vas de 0-9 y 48 donde empiezan los numeros en ASCII
    }
    
    for(int i=8;i<9;i++){
        DNI_[i] = rand() % 26 + 65; // 26 el tamaño del alfabeto y 65 donde empieza la letra A en ASCII
    }
    
    
        
}

bool DNI::operator<(DNI& DNI_cp){
    return DNI_ < DNI_cp.get_DNI();
}
bool DNI::operator>(DNI& DNI_cp){
    return DNI_ > DNI_cp.get_DNI();
}
bool DNI::operator==(DNI& DNI_cp){
    return DNI_ == DNI_cp.get_DNI();
}
ostream& operator<<(ostream& os, const DNI& DNI_salida)
{
    os << DNI_salida.DNI_;
    return os;
}

ostream& DNI::imprimir (ostream& os) const {
    char aux[8];
    for (int i = 0; i < 9; i++){
        aux[i] = DNI_[i];
        os << setw(9) << aux;
    }
    return os;
}

DNI::operator unsigned long (void)
{
    unsigned long aux = 0;
    for (int i = 0; i < 9; i++) {
        aux += DNI_[i] * (i + 1);
    }

    return aux;
}