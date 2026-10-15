#include "word_count.hpp"
#include <iostream>
#include <cctype>

using namespace std;

void to_lowercase(std::string& str) {
    for (char& c : str) {
        c = tolower(c);
    }
}

std::set<std::string> load_stopwords(std::istream& stopwords) {
    set<string> result;
    string word;

    while (stopwords >> word) {
        to_lowercase(word);
        result.insert(word);
    }

    return result;
}
