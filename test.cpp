// Autor: Adam Czubak
// Testy jednostkowe do programu.

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "worker.h"
#include "worker.cpp"
#include "squad.cpp"
#include "squad.h"
#include "bank.cpp"
#include "bank.h"

TEST_CASE("Worker - get id!")
{
    Worker worker(1, 4500.00);
    REQUIRE(worker.get_id() == 1);
}

TEST_CASE("Worker - set id!")
{
    Worker worker(1, 4500.00);
    worker.set_id(2);
    REQUIRE(worker.get_id() ==2);
}

TEST_CASE("Worker - get salary!")
{
    Worker worker(1, 4500.00);
    REQUIRE(worker.get_salary() == 4500.00);
}

TEST_CASE("Worker - set salary!")
{
    Worker worker(1, 4500.00);
    worker.set_salary(5000.00);
    REQUIRE(worker.get_salary() == 5000.00);
}

TEST_CASE("Squad - get list!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    std::vector<Worker> squad_to_create = {worker1, worker2, worker3};
    Squad squad(squad_to_create);
    std::vector<Worker> list = {worker1, worker2, worker3};
    REQUIRE(squad.get_worker_list() == list);
}

TEST_CASE("Squad - set list!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    std::vector<Worker> squad_to_set = {worker1, worker2, worker3};
    std::vector<Worker> empty_list = {};
    Squad squad(empty_list);
    squad.set_worker_list(squad_to_set);
    REQUIRE(squad.get_worker_list() == squad_to_set);
}

TEST_CASE("Squad - add worker!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    std::vector<Worker> pre_squad = {worker1, worker2};
    std::vector<Worker> post_squad = {worker1, worker2, worker3};
    Squad squad(pre_squad);
    squad.add_worker(worker3);
    REQUIRE(squad.get_worker_list() == post_squad);
}

TEST_CASE("Squad - remove worker!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    std::vector<Worker> pre_squad = {worker1, worker2, worker3};
    std::vector<Worker> post_squad = {worker1, worker2};
    Squad squad(pre_squad);
    squad.remove_worker(worker3);
    REQUIRE(squad.get_worker_list() == post_squad);
}

TEST_CASE("Squad - get squad salary!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    std::vector<Worker> pre_squad = {worker1, worker2, worker3};
    Squad squad(pre_squad);
    REQUIRE(squad.get_squad_salary() == 12500.00);
}

TEST_CASE("Squad - exception while removing worker!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    Worker worker4(4, 6000.00);
    std::vector<Worker> squad_list = {worker1, worker2, worker3};
    Squad squad(squad_list);
    REQUIRE_THROWS_WITH(squad.remove_worker(worker4), "No such worker in squad!");
}

TEST_CASE("Bank - get list!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    Worker worker4(4, 4000.00);
    Squad squad1({worker1,worker2});
    Squad squad2({worker3,worker4});
    Bank bank({squad1,squad2});
    std::vector<Squad> list = {squad1,squad2};
    REQUIRE(bank.get_squad_list() == list);
}

TEST_CASE("Bank - set list!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    Worker worker4(4, 4000.00);
    Squad squad1({worker1,worker2});
    Squad squad2({worker3,worker4});
    Bank bank({squad1});
    std::vector<Squad> list = {squad1,squad2};
    bank.set_squad_list(list);
    REQUIRE(bank.get_squad_list() == list);
}

TEST_CASE("Bank - add squad!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    Worker worker4(4, 4000.00);
    Squad squad1({worker1,worker2});
    Squad squad2({worker3,worker4});
    Bank bank({squad1});
    std::vector<Squad> list = {squad1,squad2};
    bank.add_squad(squad2);
    REQUIRE(bank.get_squad_list() == list);
}

TEST_CASE("Bank - remove squad!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    Worker worker4(4, 4000.00);
    Squad squad1({worker1,worker2});
    Squad squad2({worker3,worker4});
    Bank bank({squad1, squad2});
    std::vector<Squad> list = {squad1};
    bank.remove_squad(squad2);
    REQUIRE(bank.get_squad_list() == list);
}

TEST_CASE("Bank - get bank salary!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    Worker worker4(4, 4000.00);
    Squad squad1({worker1,worker2});
    Squad squad2({worker3,worker4});
    Bank bank({squad1, squad2});
    REQUIRE(bank.get_bank_salary() == 16500.00);
}

TEST_CASE("Bank - exception while removing squad!")
{
    Worker worker1(1, 3000.00);
    Worker worker2(2, 4500.00);
    Worker worker3(3, 5000.00);
    Worker worker4(4, 4000.00);
    Squad squad1({worker1});
    Squad squad2({worker3});
    Squad squad3({worker2, worker4});
    Bank bank({squad1, squad2});
    REQUIRE_THROWS_WITH(bank.remove_squad(squad3), "No such squad in bank!");
}