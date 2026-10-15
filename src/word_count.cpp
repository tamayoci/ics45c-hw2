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

std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
    map<string, int> counts;
    string word;

    while (document >> word) {
        to_lowercase(word);

        if (stopwords.find(word) == stopwords.end()) {
            counts[word]++;
        }
    }

    return counts;
}

void output_word_counts(const std::map<std::string, int>& word_counts,std::ostream& out) {
    for (const auto& pair : word_counts) {
        out << pair.first << " " << pair.second << '\n';
    }
}