#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <iomanip>

// Function to build an inverted index for a dataset
std::unordered_map<std::string, std::vector<int>> buildInvertedIndex(const std::vector<std::string>& data) {
    std::unordered_map<std::string, std::vector<int>> invertedIndex;

    for (int i = 0; i < data.size(); ++i) {
        std::istringstream iss(data[i]);
        std::string word;
        while (iss >> word) {
            // Convert word to lowercase for case-insensitive search
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            invertedIndex[word].push_back(i);
        }
    }

    return invertedIndex;
}

// Function to perform a search using an inverted index
std::vector<std::pair<std::string, std::string>> search(const std::unordered_map<std::string, std::vector<int>>& invertedIndex, const std::string& query, const std::vector<std::string>& data, const std::string& datasetName) {
    std::vector<std::pair<std::string, std::string>> results;
    std::string lowercaseQuery = query;
    std::transform(lowercaseQuery.begin(), lowercaseQuery.end(), lowercaseQuery.begin(), ::tolower);

    if (invertedIndex.find(lowercaseQuery) != invertedIndex.end()) {
        for (int idx : invertedIndex.at(lowercaseQuery)) {
            results.push_back({ data[idx], datasetName });
        }
    }

    return results;
}

int main() {
    // Sample data for four different datasets
    std::vector<std::string> fruits = {
        "apple", "banana", "orange", "grapes", "watermelon", "kiwi", "pineapple"
    };

    std::vector<std::string> animals = {
        "dog", "cat", "elephant", "lion", "tiger", "zebra", "giraffe"
    };

    std::vector<std::string> countries = {
        "usa", "canada", "france", "germany", "japan", "india", "australia"
    };

    std::vector<std::string> numbers = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"
    };

    // Build inverted index for each dataset
    std::unordered_map<std::string, std::vector<int>> fruitsIndex = buildInvertedIndex(fruits);
    std::unordered_map<std::string, std::vector<int>> animalsIndex = buildInvertedIndex(animals);
    std::unordered_map<std::string, std::vector<int>> countriesIndex = buildInvertedIndex(countries);
    std::unordered_map<std::string, std::vector<int>> numbersIndex = buildInvertedIndex(numbers);

    // Predefined search terms text
    std::cout << "Predefined search terms:  fruits (e.g. apple), animals (e.g. cat), countries (e.g. usa), and numbers (e.g. 1)." << std::endl;

    while (true) {
        std::cout << "Enter search query (or 'exit' to quit): ";
        std::string query;
        std::getline(std::cin, query);

        if (query == "exit") {
            break;
        }

        // Perform search across all datasets
        std::vector<std::pair<std::string, std::string>> searchResults;
        std::vector<std::pair<std::string, std::string>> fruitResults = search(fruitsIndex, query, fruits, "Fruits");
        std::vector<std::pair<std::string, std::string>> animalResults = search(animalsIndex, query, animals, "Animals");
        std::vector<std::pair<std::string, std::string>> countryResults = search(countriesIndex, query, countries, "Countries");
        std::vector<std::pair<std::string, std::string>> numberResults = search(numbersIndex, query, numbers, "Numbers");

        // Concatenate results from all datasets
        searchResults.insert(searchResults.end(), fruitResults.begin(), fruitResults.end());
        searchResults.insert(searchResults.end(), animalResults.begin(), animalResults.end());
        searchResults.insert(searchResults.end(), countryResults.begin(), countryResults.end());
        searchResults.insert(searchResults.end(), numberResults.begin(), numberResults.end());

        // Display results
        if (searchResults.empty()) {
            std::cout << "No results found for '" << query << "'." << std::endl;
        }
        else {
            std::cout << "Search results for '" << query << "':" << std::endl;
            for (const auto& result : searchResults) {
                std::cout << "- " << std::setw(12) << result.second << ": " << result.first << std::endl;
            }
        }
    }

    return 0;
}
