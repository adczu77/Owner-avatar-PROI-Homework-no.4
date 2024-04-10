// Autor: Adam Czubak.
// Implementacja metod klasy Worker.

#include "worker.h"
#include <memory>

Worker::Worker(unsigned int id, double salary) : id(id), salary(salary){}

unsigned int Worker::get_id()
{
    std::unique_ptr<unsigned int>id_pointer = std::make_unique<unsigned int>(id);
    return *id_pointer;
}

void Worker::set_id(unsigned int new_id)
{
    std::unique_ptr<unsigned int>id_pointer = std::make_unique<unsigned int>(new_id);
    id = *id_pointer;
}

double Worker::get_salary()
{
    std::unique_ptr<double>salary_pointer = std::make_unique<double>(salary);
    return *salary_pointer;
}

void Worker::set_salary(double new_salary)
{
    std::unique_ptr<unsigned int>salary_pointer = std::make_unique<unsigned int>(new_salary);
    salary = *salary_pointer;
}

bool Worker::operator==(const Worker& other_worker) const
{
    return (id == other_worker.id) && (salary == other_worker.salary);
}