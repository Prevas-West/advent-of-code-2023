#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <unordered_map>

static void part1(const std::string &input_filename) {
    std::ifstream f(input_filename);
    std::string line;
    unsigned long sum = 0;

    while (std::getline(f, line)) {
        const auto first = line.find_first_of("0123456789");
        const auto last = line.find_last_of("0123456789");
        if (first != line.npos) {
            sum += std::stoul(std::string{line[first]} + line[last]);
        }
    }

    std::cout << sum << std::flush;
}

static void part2(const std::string &input_filename) {
    auto replace = [](std::string line) {
        const std::unordered_map<char, std::string> numbers {
            { '0', "zero" },
            { '1', "one" },
            { '2', "two" },
            { '3', "three" },
            { '4', "four" },
            { '5', "five" },
            { '6', "six" },
            { '7', "seven" },
            { '8', "eight" },
            { '9', "nine" },
        };

        std::string replaced;

        for (std::string::size_type i = 0; i < line.length(); ++i) {
            if (line[i] >= '0' && line[i] <= '9') {
                replaced.push_back(line[i]);
            } else {
                for (const auto &num : numbers) {
                    if (line.find(num.second, i) == i) {
                        replaced.push_back(num.first);
                    }
                }
            }
        }

        return replaced;
    };


    std::string output_filename = "input_part2";

    {
        std::ifstream in(input_filename);
        std::ofstream out(output_filename);
        std::string line;
        while (std::getline(in, line)) {
            out << replace(std::move(line)) << std::endl;
        }
    }

    part1(output_filename);
}

int main() {
    part1("input");
    std::cout << ", ";
    part2("input");
    std::cout << std::endl;
}
