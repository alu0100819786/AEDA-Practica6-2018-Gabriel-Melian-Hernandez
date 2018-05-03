
#include "common.hpp"
#include "DNI.hpp"
#include "insercion.hpp"
#include "nodo.hpp"
#include "arbol.hpp"



using namespace std;

unsigned opc_demo =4;

//Metodo error para indicar que se ha seleccionado una opcion errónea.
void error(void){
	cin.ignore();
	cout << endl << "La opcion introducida no es valida. Presione enter e introduzca otra.";
	cin.ignore();
	
}

//Metodo para calcular en el modo estadístico los minimos, medios y maximos de insercion y busqueda.
void calcular_cp(vector<float> &com, vector<vector<float>> &v, float sm, unsigned int modo_){
	
	insercion<float>(com,1);

	v[modo_][0] = com.front();
	v[modo_][1] = ((com.front()+com.back())/2);
	v[modo_][2] = com.back();
}

int main (void){
	
	srand(time(NULL));

	unsigned opc = 3;
	int ct_pruebas = 300;
	int tam_arbol, num_rep;
//Conseguimos el modo de operacion.
	while (opc != 0 && opc != 1 && opc != 2){
		cout << "================ " << "ABB" << " =================" << endl;
		cout << "Seleccione el modo con el que desea trabajar: " << endl;
		cout << "0. Modo demostración" << endl;
		cout << "1. Modo estadisticas" << endl;
		cout << "2. Abandonar" << endl;
		cout << "Introduzca una opcion: ";
		cin >> opc;
		if (opc != 0 && opc != 1 && opc != 2)
			error();
	}
//Si elegimos el Modo demostracion
	if (opc==0){
		arbol<int> arbol_demo;
		do{
		while (opc_demo != 0 && opc_demo != 1 && opc_demo != 2 && opc_demo != 3){ 
			write(1,"\033[H\033[2J",7);
			cout << "============= " << "MODO DEMOSTRACIÓN" << " =============" << endl;
			cout << "0. Insertar Clave" << endl;
			cout << "1. Eliminar Clave" << endl;
			cout << "2. Mostrar Árbol" << endl;
			cout << "3. Abandonar" << endl;
			cout << "Introduzca una opcion: ";
			cin >> opc_demo;
			if (opc_demo != 0 && opc_demo != 1 && opc_demo != 2 && opc_demo != 3)
				error();
		}
		
//Switch para el modo demostracion en el que podremos insertar y eliminar claves, mostrar el árbol o salir del programa.
		switch (opc_demo){
			case 0:{
			
				int mat;
				
				cout << "============= " << "MODO DEMOSTRACIÓN CON INT" << " =============" << endl;
				cout << "Introduzca el número a insertar en el árbol: ";
				cin >> mat;//Conseguimos el numero a insertar
				arbol_demo.insertar(mat);//insertamos el numero en el arbol
				cout << "El numero insertado es " << mat << endl;
				cin.ignore(); cin.ignore();
				opc_demo = 4;
				break;
			}
			
			case 1:{
				
				int mat;
			
				cout << "============= " << "MODO DEMOSTRACIÓN CON INT" << " =============" << endl;
				cout << "Introduzca el número a eliminar en el árbol: ";
				cin >> mat;
				arbol_demo.eliminar(mat);//Eliminamos un numero del arbol
				cout << "El numero eliminado es " << mat << endl;
				cin.ignore(); cin.ignore();
				opc_demo = 4;
				break;
			}
			case 2:{
					
				
				cout << "============= " << "MODO DEMOSTRACIÓN CON INT" << " =============" << endl;
				arbol_demo.nivel_orden();//Mostramos el arbol
				cin.ignore(); cin.ignore();
				opc_demo = 4;
				break;
			}
			case 3:{
				cout << "=============" << "SALIENDO" << "=============" << endl;
				return 0;
				break;
			}

		}
		}while(opc_demo != 3);
	}
	else if (opc==1){
//Si elegimos el modo estadistica, pasamos al programa un tamaño de arbol y un numero de repeticiones y el se encargará de llenar el arbol de random numeros y realizar los calculos.	
		cout << "============= " << "MODO ESTADÍSTICA" << " =============" << endl;
		cout << "Introduzca el tamaño del arbol a analizar: ";
		cin >> tam_arbol;
		cout << "Introduzca la cantidad de veces que quiera que se repitan las pruebas: ";
		cin >> num_rep;
		cout << endl << "                               NUMERO DE COMPARACIONES" << endl;
		cout << "                            Minimo -  Promedio  -   Maximo" << endl;

		vector<DNI> vector_DNI(tam_arbol);
		vector<vector<float>> resultados(2, vector<float>(3));
		vector<float> comp(vector_DNI.size());
		float suma = 0, suma_intermedia =0;
//Llevamos a cabo las comparaciones de insercion.
			for (int j=0; j<num_rep; j++){
			arbol<DNI> arbol_esta;
			for (int k=0;k<vector_DNI.size();k++)
				vector_DNI[k].set_random();
			for (int k=0;k<vector_DNI.size();k++){
				comp[k] = arbol_esta.insertar(vector_DNI[k]);
			}
		}

					calcular_cp(comp, resultados, suma, 0);

					cout << "Comparaciones insercion: " << setw(12) << resultados[0][0] << setw(12) << resultados[0][1] << setw(12) << resultados[0][2] << endl;
					suma=0;
					
					vector<DNI> vector_DNI_2(tam_arbol*2);
					vector<float> comp_2(vector_DNI_2.size());
//Llevamos a cabo las comparaciones de busqueda.
		for (int j=0; j<num_rep; j++){
			for (int k=0;k<vector_DNI_2.size();k++)
				vector_DNI_2[k].set_random();
				arbol<DNI> arbol_esta;
			for (int k=0;k<vector_DNI_2.size()/2;k++){
				arbol_esta.insertar(vector_DNI_2[k]);
			}
			for (int k=0;k<vector_DNI_2.size()/2;k++){
				 arbol_esta.buscar(vector_DNI_2[k]);
				 comp_2[k] = arbol_esta.get_esta();
			}
			for (int k=vector_DNI_2.size()/2; k<vector_DNI_2.size(); k++){
				arbol_esta.buscar(vector_DNI_2[k]);
				comp_2[k] += arbol_esta.get_esta();
			}
		}

		calcular_cp(comp_2, resultados, suma, 0);

		cout << "Comparaciones búsqueda:  " << setw(12) << resultados[0][0] << setw(12) << resultados[0][1] << setw(12) << resultados[0][2] << endl;
		suma=0;

	}
else{
	cout << endl << "Abandonando.." << endl;
	return 0;
}

return 0;

				
}