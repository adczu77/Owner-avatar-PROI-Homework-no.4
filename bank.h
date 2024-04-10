// Autor: Adam Czubak.
// Definicja atrybutów i metod klasy Bank.

#ifndef BANK_H
#define BANK_H
#include "squad.h"
#include <vector>
#include <algorithm>

class Bank : public Squad
{
    private:    
        std::vector<Squad> squad_list;
    public:
        Bank(std::vector<Squad> squad_list = {});
        // Zwraca listę skład zawartych w banku.
        std::vector<Squad> get_squad_list();
        // Ustawia listę skład zawartych w banku.
        void set_squad_list(std::vector<Squad> new_list);
        // Dodaje skład do banku.
        void add_squad(Squad squad);
        // Usuwa skład z banku.
        void remove_squad(Squad squad);
        // Zwraca sumę pensji wszystkich składów w banku.
        double get_bank_salary();
        // Umożliwia porównanie obiektów.
        bool operator==(const Bank& new_bank) const;
};

#endif