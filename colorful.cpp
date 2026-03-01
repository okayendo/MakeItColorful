#include <iostream>
#include <cstdlib>
#include <windows.h>

int main()
{
    std::string player1, player2;
    int roll1, roll2;
    std::string status1 = "";
    std::string status2 = "";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    std::cout << "Enter Player1's name: ";
    std::getline(std::cin, player1);
    std::cout << "Enter Player2's name: ";
    std::getline(std::cin, player2);

    roll1 = rand() % 20 + 1;
    roll2 = rand() % 20 + 1;

    if (roll1 == 1)
        status1 = "Critical Failure";
    else if (roll1 == 20)
        status1 = "Critical Success";

    if (roll2 == 1)
        status2 = "Critical Failure";
    else if (roll2 == 20)
        status2 = "Critical Success";

    std::cout << "\n-Rolls\n";

    std::cout << player1 << " rolled: " << roll1;
    if (status1 != "")
    {
        if (status1 == "Critical Failure")
            SetConsoleTextAttribute(hConsole, 12);
        else if (status1 == "Critical Success")
            SetConsoleTextAttribute(hConsole, 10);

        std::cout << " (" << status1 << ")";
        SetConsoleTextAttribute(hConsole, 7);
    }
    std::cout << std::endl;

    std::cout << player2 << " rolled: " << roll2;
    if (status2 != "")
    {
        if (status2 == "Critical Failure")
            SetConsoleTextAttribute(hConsole, 12);
        else if (status2 == "Critical Success")
            SetConsoleTextAttribute(hConsole, 10);

        std::cout << " (" << status2 << ")";
        SetConsoleTextAttribute(hConsole, 7);
    }
    std::cout << std::endl;

    std::cout << "\n-Result\n";
    if (roll1 > roll2)
        std::cout << "Winner: " << player1 << std::endl;
    else if (roll2 > roll1)
        std::cout << "Winner: " << player2 << std::endl;
    else
        std::cout << "Tie!" << std::endl;

    return 0;
}