#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class constancias
{
private:
    string nombre;
    string carrera;
    int aprobadas;
    float promedio;
public:
    constancias(){
        nombre=" ";
        carrera=" ";
        aprobadas=0;
        promedio=0;
    };

    constancias(string nombre, string carrera, int aprobadas, float promedio)
    {
        nombre=nombre;
        carrera=carrera;
        aprobadas=aprobadas;
        promedio=promedio;
    }

    friend istream& operator>>(istream& i, constancias& c)
    {
        cout<<"Dame el nombre: ";
        i>>c.nombre;
        cout<<"Dame la carrera: ";
        i>>c.carrera;
        cout<<"Dame las materias aprobadas: ";
        i>>c.aprobadas;
        cout<<"Dame el promedio general: ";
        i>>c.promedio;
        cout<<"-----------------------"<<endl;
        cout<<"Se agreco correctamente";
    }

    friend ostream& operator<<(ostream& o, constancias& c)
    {
        o<<"Nombre: "<<c.nombre<<endl;
        o<<"Carrera: "<<c.carrera<<endl;
        o<<"Materias aprobadas: "<<c.aprobadas<<endl;
        o<<"Promedio: "<<c.promedio<<endl;
        return o;
    }

};

const int TAM=5;

class cola
{
private:
    constancias datos[TAM];
    int ult;

    bool elimina(int pos)
    {
        if(vacia() || pos<0 || pos>ult)
        {
            cout<<"Error de eliminacion";
            return true;
        }
        int i=pos;
        while(i<ult)
        {
            datos[i]=datos[i+1];
            i++;
        }
        ult--;
        return false;
    }

    int inserta(constancias elem, int pos)
    {
        if(llena()|| pos<0 || pos>ult+1)
        {
            cout<<"Error de insercion";
            return 0;
        }
        int i=ult+1;
        while(i>pos)
        {
            datos[i]=datos[i-1];
            i--;
        }
        datos[pos]=elem;
        ult++;
        return 1;
    }
public:
    cola():ult(-1) {}

    bool vacia()const
    {
        if(ult==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool llena()const
    {
        if(ult==TAM-1)
            return true;
        return false;
    }

    int ultimo()const
    {
        return ult;
    }


    void encolar(constancias& elem)
    {
        inserta(elem,ultimo()+1);
    }

    constancias& desencolar()
    {
        if(vacia()){
            cout<<"------------------------"<<endl;
            cout<<"La cola esta vacia :("<<endl;
            cout<<"------------------------"<<endl;
            return datos[ult+1];
        }
        else{
            ult--;
            return datos[ult+1];
        }
    }


//Sobre Carga
    friend ostream& operator<<(ostream& o, cola& c)
    {
        int i=0;
        cout<<"\n";
        while(i<=c.ultimo())
        {
            o<<c.datos[i];
            i++;
        }
        return o;
    }

};

int main()
{
    constancias consti;
    cola colita;
    int opcion;

    do
    {
        cout << "MENU:" << endl;
        cout << "1. Dar de alta" << endl;
        cout << "2. Elaborar constancia" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su eleccion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            cout<<"---Dar de alta---"<<endl;
            cin>>consti;
            colita.encolar(consti);
            getch();
            system("cls");
            break;
        case 2:
            cout <<"---Elaborar constancia---"<<endl;
            cout<<colita.desencolar();
            getch();
            system("cls");
            break;
        case 3:
            cout << "Adios :)" << endl;
            return 0;
        default:
            cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
        }
    }
    while(opcion!=3);
    return 0;
}
