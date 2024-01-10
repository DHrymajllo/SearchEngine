# Advanced Search Engine in C++

This C++ application demonstrates an advanced search engine functionality that performs searches across different datasets efficiently using an inverted index.

## Overview

The program implements the following functions:

- `buildInvertedIndex`: Builds an inverted index for a given dataset, mapping words to their respective positions in the dataset.
- `search`: Conducts searches using the inverted index across multiple datasets and displays the matching results.

## Functionality

### Datasets Available

- **Fruits**: Contains a list of fruit names.
- **Animals**: Contains a list of animal names.
- **Countries**: Contains a list of country names.
- **Numbers**: Contains a list of numerical values.

### Predefined Search Terms

- Users can search for predefined terms such as fruits (e.g. apple), animals (e.g. cat), countries (e.g. usa), and numbers (e.g. 1).

## Usage

1. Compile the code using a C++ compiler (e.g., g++ compiler).
2. Run the compiled executable.
3. The program prompts the user to enter a search query.
4. Results matching the query from different datasets will be displayed.
5. To exit the program, enter 'exit' when prompted for a search query.

## Code Structure

The C++ code comprises several functions:

- `buildInvertedIndex`: Constructs an inverted index for each dataset.
- `search`: Conducts a search across datasets based on user input.
- `displaySearchStats`: Shows statistics related to the search results.
- `main`: Contains the main program logic, including user interaction and result display.
