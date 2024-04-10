// Autor: Adam Czubak.
// Przykładowe zademonstrowanie wzroca kompozytu.

#include <iostream>
#include "worker.h"
#include "bank.h"
#include "squad.h"
#include "worker.cpp"
#include "bank.cpp"
#include "squad.cpp"

using namespace std;

int main()
{
    Worker worker1(1, 3000);
    Worker worker2(2, 1500);
    Worker worker3(3, 6000);
    Worker worker4(4, 6000);
    Squad squad1({worker1, worker2});
    Squad squad2({worker3, worker4});
    Bank bank({squad1,squad2});
    cout << squad1.get_squad_salary() << endl;
    cout << squad2.get_squad_salary() << endl;
    cout << bank.get_bank_salary() << endl;
    return 0;
}