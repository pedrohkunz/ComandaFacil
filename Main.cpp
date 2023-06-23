#include <iostream>
#include <windows.h>

using namespace std;

#include "include/MenuLogin.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    MenuLogin menuLogin = MenuLogin();

    menuLogin.menuLogin();
}

