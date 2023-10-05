// homework20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    const int sidesOfCube{ 6 };
    const int diceQty{ 2 };
    const int playersQty{ 2 };
    const int movesQty{ 3 };
    const int pause{ 1300 };

    enum Player {USER, AI};
    int scores[playersQty]{};
    int totalScore[playersQty]{};
    char userInput{ 't' };
    bool lastThrow{ false };
    int scoreOfRound{ 0 };

    char star{ '*' };
    int size{ 3 };
    bool condition1{ false };
    bool condition2{ false };
    bool condition3{ false };
    bool condition4{ false };
    bool condition5{ false };
    
    srand(time(0));
    
    
    std::cout << "Welcome to the GAME of DICE\n\n" << "Do you want to play with me?\n" << "Y / N\n";
    std::cin >> userInput;

    do
    {

        for (int i{ 0 }; i < movesQty; i++)
        {
            do
            {
                std::cout << "Press 't' to throw dices\n";
                std::cin >> userInput;
            } while (userInput != 't');

            for (int p{ 0 }; p < playersQty; p++)
            {
                scoreOfRound = 0;
                std::cout << "Round " << i + 1 << ":\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(pause));
                for (int d{ 0 }; d < diceQty; d++)
                {
                    scores[p] = 1 + rand() % sidesOfCube;
                    for (int x{ 0 }; x < size; x++)
                    {
                        for (int y{ 0 }; y < size; y++)
                        {
                            condition1 = (x == 1) and (y == 1);
                            condition2 = (x == y);
                            condition3 = (x + y == size - 1);
                            condition4 = (x != 1);
                            condition5 = (y == 0 or y == 2);
                           
                            if (scores[p] == 1)
                            {
                                std::cout << (condition1 ? star : ' ');
                            }
                            else if (scores[p] == 2)
                            {
                                std::cout << ((condition2 and condition4) ? star : ' ');
                            }
                            else if (scores[p] == 3)
                            {
                                std::cout << (condition2 ? star : ' ');
                            }
                            else if (scores[p] == 4)
                            {
                                std::cout << ((condition2 and condition4) or (condition3 and condition4) ? star : ' ');
                            }
                            else if (scores[p] == 5)
                            {
                                std::cout << ((condition2 or condition3) ? star : ' ');
                            }
                            else
                            {
                                std::cout << (condition5 ? star : ' ');
                            }
                            std::cout << ' ';
                        }
                        std::cout << '\n';
                    }
                    totalScore[p] += scores[p];
                    scoreOfRound += scores[p];
                    //std::cout << "\tDice " << d + 1 << " - " << scores[p] << " point(s)\n";
                    std::cout << '\n';
                    lastThrow = (i == movesQty - 1) and (d == diceQty - 1);
                }
                std::cout << "Sum is " << scoreOfRound << " points.\n";
                std::cout << "Total Score = \t" << totalScore[p] << " points\n\n";
                std::cout << (!(lastThrow) ? (p) ? "Your turn\n" : "My Turn\n" : "");
            }
        }
        std::cout << "My total score is " << totalScore[Player::AI] << ", yours is " << totalScore[Player::USER] << ".\n";
        std::cout << ((totalScore[Player::USER] > totalScore[Player::AI]) ? "Congrats! You won!!!" : (totalScore[Player::USER] == totalScore[Player::AI])? "It's a draw!" : "I won!") << '\n';
        std::cout << "Want to play again?\n" << "Y / N\n";
        std::cin >> userInput;
    } while (userInput != 'n' and userInput !='N');
    
    std::cout << "Goodbye\n";

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
