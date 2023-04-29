module;
#include <iostream>
#include <fstream>
#include <ranges>
#include <regex>
#include <string>
#include <vector>
#include <filesystem>

export module Wordle:scoreboard;

export class Scoreboard {
private:
    std::string filepath_;

public:
    Scoreboard(std::string filepath) : filepath_{ std::move(filepath) } {}

    void addRecord(int score, char shouldAddRecord) {
        if (shouldAddRecord == '1') {
            std::cout << "Please enter your nickname (without spaces): " << std::endl;
            std::string nick;
            std::getline(std::cin >> std::ws, nick);

            // sprawdzanie, czy nazwa u¿ytkownika zawiera spacje
            std::regex pattern("\\s");
            if (std::regex_search(nick, pattern)) {
                std::cout << "Invalid nickname. Please try again without spaces." << std::endl;
                addRecord(score, shouldAddRecord);
                return;
            }

            std::ofstream file(filepath_, std::ios_base::app);
            file << nick << ' ' << score << '\n';
        }
    }

    void showRecords(char input) {
        if (input == '1')
        {
            
        
        std::ifstream file(filepath_);
        std::vector<std::pair<std::string, int>> records;
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string nick;
            int score;
            if (iss >> nick >> score) {
                records.emplace_back(nick, score);
            }
        }

        std::sort(records.begin(), records.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
            });

        auto sorted_records = records | std::views::transform([](auto record) {
            return std::make_pair(record.second, record.first);
            }) | std::views::reverse;

        std::cout << "Scoreboard:\n";
        int rank = 1;
        for (const auto& record : sorted_records) {
            std::cout << rank << ". " << record.second << ": " << record.first << '\n';
            ++rank;
        }
        }
    }
};
