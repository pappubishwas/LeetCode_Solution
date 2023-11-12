#include <iostream>
#include <vector>
#include <string>



class Solution {
public:
    std::vector<std::string> findHighAccessEmployees(std::vector<std::vector<std::string>>& access_times) {
        std::unordered_map<std::string, std::vector<int>> accessMap;

        // Step 1: Create a map to store access times for each employee
        for (const auto& access : access_times) {
            std::string employee = access[0];
            int time = convertToMinutes(access[1]);
            accessMap[employee].push_back(time);
        }

        std::vector<std::string> result;

        // Step 2: Iterate through each employee's access times
        for (auto& entry : accessMap) {
            // Step 3: Sort the access times
            std::sort(entry.second.begin(), entry.second.end());

            // Step 4: Check for high-access employees
            for (int i = 2; i < entry.second.size(); ++i) {
                if (entry.second[i] - entry.second[i - 2] < 60) {
                    result.push_back(entry.first);
                    break;  // Move to the next employee
                }
            }
        }

        return result;
    }

private:
    // Helper function to convert time to minutes
    int convertToMinutes(const std::string& time) {
        int hours = std::stoi(time.substr(0, 2));
        int minutes = std::stoi(time.substr(2, 2));
        return hours * 60 + minutes;
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::vector<std::vector<std::string>> access_times = {
        {"a", "0549"},
        {"b", "0457"},
        {"a", "0532"},
        {"a", "0621"},
        {"b", "0540"}
    };

    std::vector<std::string> result = solution.findHighAccessEmployees(access_times);

    std::cout << "High-Access Employees: ";
    for (const auto& employee : result) {
        std::cout << employee << " ";
    }
    std::cout << std::endl;

    return 0;
}
