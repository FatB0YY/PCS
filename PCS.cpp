#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int Sum(int a, int b)
{
    // thread::id id = this_thread::get_id();
    // for (size_t i = 0; i < 5; i++) {
    //     cout << "ID = " << id << " | i = " << i << "DOWORK" << endl;
    //     this_thread::sleep_for(chrono::milliseconds(1000));
    // }

    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "=================\t"
         << "Sum STARTED\t================" << endl;
    // cout << "a + b = " << a + b << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "=================\t"
         << "Sum STOPPED\t================" << endl;

    return a + b;
}

// void Sum(int &a) {
//     thread::id id = this_thread::get_id();
//
//     this_thread::sleep_for(chrono::milliseconds(1000));
//
//     cout << "ID = " << id << "=================\t" << "Sum STARTED\t================" << endl;
//
//     this_thread::sleep_for(chrono::milliseconds(5000));
//
//     a = a * 2;
//
//     this_thread::sleep_for(chrono::milliseconds(3000));
//
//     cout << "ID = " << id << "=================\t" << "Sum STOPPED\t================" << endl;
//
// }

int main()
{
    // thread th(Sum, 2, 3); // передача параметров

    // int a = 2;
    // thread th(Sum, std::ref(a)); // передача по ссылке

    int result;
    thread th([&result]()
              { result = Sum(2, 5); });

    thread::id id = this_thread::get_id();
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID = " << id << " | i = " << i << "MAIN" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();
    // cout << "a = " << a << endl;

    return 0;
}