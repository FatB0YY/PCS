#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Sum()
{
    thread::id id = this_thread::get_id();
    for (size_t i = 0; i < 5; i++)
    {
        cout << "ID = " << id << " | i = " << i << "Sum" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    thread th(Sum); // потоки

    thread::id id = this_thread::get_id();
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID = " << id << " | i = " << i << "MAIN" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();

    return 0;
}