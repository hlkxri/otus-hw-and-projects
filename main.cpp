#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
int main() {
    const std::string high_scores_filename = "high_scores.txt";

    int incoming_number;
    std::string username;
    std::cout << "Hello, pc is thinking a number from 1 to 100" << std::endl;
    std::cout << "Write down your username" << std::endl;
    std::cin >> username;
    std::cout << "Welcome," << username << "!" << std::endl;


    std::cout << "Let's start the game, write your number" << std::endl;
    std::srand(std::time(nullptr));
    int a = 1 + rand() % 100;
    do {
        std::cin >> incoming_number;

        if (a < incoming_number)
            std::cout << "the number is too high" << std::endl;


        else if (a > incoming_number) {
            std::cout << "the number is too low" << std::endl;;

        } else {
            std::cout << "Congratulations, you win!" << std::endl;;

        }
    } while (incoming_number != a);
    {
        system("pause");

    }

    int attempts_count = 0;
    std::cout <<"Write your high score!"<< std::endl;
    std::cin >> attempts_count;
    if(std::cin.fail()){
        std::cout<<"incorrect value!" << std::endl;
        return -1;
    }

    std::ofstream out_file{high_scores_filename, std::ios_base::app};
    if(!out_file.is_open()){
        std::cout<< "Failed to open the file for write "<< high_scores_filename << std::endl;
        return -1;
    }
    out_file << username << " ";
    out_file << attempts_count;
    out_file << std::endl;

    std::ifstream in_file{high_scores_filename};
    if (!in_file.is_open()){
        std::cout << "Failed to open the file for reading" << high_scores_filename <<std::endl;
        return -1;
    }



    std::cout << "High scores table:" << std::endl;

    int high_score = 0;
    while (true) {
        in_file >> username;
        in_file >> high_score;
        in_file.ignore();

        if (in_file.fail()) {
            break;
        }

        std::cout << username << '\t' << high_score << std::endl;
    }
}
