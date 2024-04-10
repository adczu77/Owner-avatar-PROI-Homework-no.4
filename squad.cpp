// Autor: Adam Czubak.
// Implementacja metod klasy Squad.

#include "squad.h"
#include "worker.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <memory>

Squad::Squad(std::vector<Worker> worker_list) : worker_list(worker_list){}

std::vector<Worker> Squad::get_worker_list()
{
    std::unique_ptr<std::vector<Worker>>list_pointer = std::make_unique<std::vector<Worker>>(worker_list);
    return *list_pointer;
}

void Squad::set_worker_list(std::vector<Worker> new_worker_list)
{
    std::unique_ptr<std::vector<Worker>>list_pointer = std::make_unique<std::vector<Worker>>(new_worker_list);
    worker_list = *list_pointer;
}

void Squad::add_worker(Worker worker)
{
    std::unique_ptr<Worker>worker_pointer = std::make_unique<Worker>(worker);
    worker_list.push_back(*worker_pointer);
}

void Squad::remove_worker(Worker worker)
{
    std::unique_ptr<Worker>worker_pointer = std::make_unique<Worker>(worker);
    auto index = std::find(worker_list.begin(), worker_list.end(), *worker_pointer);
    if (index != worker_list.end())
    {
        worker_list.erase(index);
    }
    else
    {
        throw std::invalid_argument("No such worker in squad!");
    }
}

double Squad::get_squad_salary()
{
    std::unique_ptr<std::vector<Worker>>worker_list_pointer = std::make_unique<std::vector<Worker>>(worker_list);
    double sum = 0;
    for(auto element: *worker_list_pointer)
    {
        sum += element.get_salary();
    }
    return sum;
}

bool Squad::operator==(const Squad& new_squad) const
{
    return (id == new_squad.id) && (salary == new_squad.salary) && (worker_list == new_squad.worker_list);
}