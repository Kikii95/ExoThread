#include <iostream>
#include "Thread.h"

void PrintNumbers() {
    Sleep(100);
    for (int i = 1; i <= 78; ++i) {
        std::cout << "Nombre: " << i << std::endl;
        Sleep(10);
    }
}

void PrintAlphabet() {
    Sleep(100);
    for (int i = 0; i < 1; ++i) {
        for (char c = 'A'; c <= 'Z'; ++c) {
            std::cout << "Lettre: " << c << std::endl;
            Sleep(10);
        }
    }
}


int main() {
    Thread* thread1 = new Thread();
    Thread* thread2 = new Thread();

    thread1->Start(PrintNumbers);
    thread2->Start(PrintAlphabet);

    while (thread1->IsRunning() || thread2->IsRunning()) {
        Sleep(1000);
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "Thread 1 : " << (thread1->IsRunning() ? "en cours" : "termine") << std::endl;
		std::cout << "Thread 2 : " << (thread2->IsRunning() ? "en cours" : "termine") << std::endl;
        std::cout << "------------------------------------------" << std::endl;

    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Programme termine." << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    return 0;
}


