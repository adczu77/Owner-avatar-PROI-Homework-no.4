// Autor: Adam Czubak.
// Definicja atrybutów i metod klasy Squad.

#ifndef SQUAD_H
#define SQUAD_H
#include "worker.h"
#include <vector>

class Squad : public Worker
{
    protected:
        std::vector<Worker> worker_list;
    public:
        Squad(std::vector<Worker> worker_list = {});
        // Zwraca listę pracowników w składzie.
        std::vector<Worker> get_worker_list();
        // Ustawia listę pracowników w składzie.
        void set_worker_list(std::vector<Worker> new_worker_list);
        // Dodaje pracownika do składu.
        void add_worker(Worker worker);
        // Usuwa pracownika ze składu.
        void remove_worker(Worker worker);
        // Zwraca sumę pensji wszystkich pracowników w składzie.
        double get_squad_salary();
        // Umożliwia porównanie obiektów.
        bool operator==(const Squad& new_squad) const;
};

#endif