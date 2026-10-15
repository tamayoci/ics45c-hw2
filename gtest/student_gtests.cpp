// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the word_count module. It is graded: the autograder runs it
// against a correct implementation and against several with one bug each. A test is worth
// something only when it passes on the correct implementation and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for to_lowercase, load_stopwords, count_words
// and output_word_counts, and for the edges: an empty document, a document that is all stop
// words, stop words written in mixed case, and the same word in several cases.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>
#include <sstream>

#include "word_count.hpp"

using namespace std;

TEST(WordCountTests, StopwordsAreLoadedCaseInsensitively) {
    std::stringstream stopwords{"The OVER\n"};
    const auto loaded = load_stopwords(stopwords);
    EXPECT_TRUE(loaded.contains("the"));
    EXPECT_TRUE(loaded.contains("over"));
}

TEST(WordCountTests, WordsAreCountedCaseInsensitively) {
    std::stringstream document{"Apple apple APPLE pear"};
    const auto counts = count_words(document, {});
    EXPECT_EQ(counts.at("apple"), 3);
    EXPECT_EQ(counts.at("pear"), 1);
}

// ADD YOUR TESTS HERE:

TEST(WordCount, ToLowercase) {
    string s = "HeLLo123!";
    to_lowercase(s);
    EXPECT_EQ(s, "hello123!");
}

TEST(WordCount, LoadStopWords) {
    istringstream input("The aN AnD");
    auto stopwords = load_stopwords(input);

    EXPECT_TRUE(stopwords.count("the"));
    EXPECT_TRUE(stopwords.count("an"));
    EXPECT_TRUE(stopwords.count("and"));
    EXPECT_EQ(stopwords.size(), 3);
}

TEST(WordCount, CountWords) {
    istringstream doc("Apple apple banana THE");
    istringstream stop_input("the");

    auto stopwords = load_stopwords(stop_input);
    auto counts = count_words(doc, stopwords);

    EXPECT_EQ(counts["apple"], 2);
    EXPECT_EQ(counts["banana"], 1);
    EXPECT_EQ(counts.count("the"), 0); // should be ignored
}

TEST(WordCount, OutputWordCounts) {
    map<string, int> counts;
    counts["apple"] = 2;
    counts["banana"] = 1;

    ostringstream out;
    output_word_counts(counts, out);

    EXPECT_STREQ(out.str().c_str(),
                 "apple 2\nbanana 1\n");
}