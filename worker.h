// Autor: Adam Czubak.
// Definicja atrybutów i metod klasy Worker.

#ifndef WORKER_H
#define WORKER_H
#include <memory>

class Worker
{
    protected:
        unsigned int id;
        double salary;
    public:
        Worker(unsigned int id=0, double salary=0);
        // Zwraca id.
        unsigned int get_id();
        // Ustawia id.
        void set_id(unsigned int new_id);
        // Zwraca pensję.
        double get_salary();
        // Ustawia pensję.
        void set_salary(double new_salary);
        // Umożliwia porównanie obiektów.
        bool operator==(const Worker& other_worker) const;
};

#endif