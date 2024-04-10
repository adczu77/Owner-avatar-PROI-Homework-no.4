// Autor: Adam Czubak.
// Implementacja metod klasy Bank.

#include "bank.h"
#include "squad.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <memory>

Bank::Bank(std::vector<Squad> squad_list) : squad_list(squad_list){}

std::vector<Squad> Bank::get_squad_list()
{
    std::unique_ptr<std::vector<Squad>>squad_list_pointer = std::make_unique<std::vector<Squad>>(squad_list);
    return *squad_list_pointer;
}

void Bank::set_squad_list(std::vector<Squad> new_squad_list)
{   
    std::unique_ptr<std::vector<Squad>>squad_list_pointer = std::make_unique<std::vector<Squad>>(new_squad_list);
    squad_list = *squad_list_pointer;
}

void Bank::add_squad(Squad squad)
{
    std::unique_ptr<Squad>squad_pointer = std::make_unique<Squad>(squad);
    squad_list.push_back(*squad_pointer);
}

void Bank::remove_squad(Squad squad)
{
    std::unique_ptr<Squad>squad_pointer = std::make_unique<Squad>(squad);
    auto index = std::find(squad_list.begin(), squad_list.end(), *squad_pointer);
    if (index != squad_list.end())
    {
        squad_list.erase(index);
    }
    else
    {
        throw std::invalid_argument("No such squad in bank!");
    }
}

double Bank::get_bank_salary()
{
    std::unique_ptr<std::vector<Squad>>squad_list_pointer = std::make_unique<std::vector<Squad>>(squad_list);
    double sum = 0;
    for(auto element: squad_list)
    {
        sum += element.get_squad_salary();
    }
    return sum;
}

bool Bank::operator==(const Bank& new_bank) const
{
    return (salary == new_bank.salary) && (id == new_bank.id) && (worker_list == new_bank.worker_list) && (squad_list == new_bank.squad_list);
}