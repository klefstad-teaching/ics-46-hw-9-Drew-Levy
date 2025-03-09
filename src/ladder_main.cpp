#include "ladder.h"
#include <iostream>

int main() {
    // Test Case 1: Simple word ladder
    {
        set<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
        string start_word = "hit";
        string end_word = "cog";
        vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
        cout << "Test Case 1: hit -> cog" << endl;
        print_word_ladder(ladder);
        cout << endl;
    }

    // Test Case 2: No possible ladder
    {
        set<string> word_list = {"hot", "dot", "dog", "lot", "log"};
        string start_word = "hit";
        string end_word = "cog";
        vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
        cout << "Test Case 2: hit -> cog (no ladder)" << endl;
        print_word_ladder(ladder);
        cout << endl;
    }

    // Test Case 3: Start and end words are the same
    {
        set<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
        string start_word = "hit";
        string end_word = "hit";
        cout << "Test Case 3: hit -> hit (same word)" << endl;
        verify_word_ladder();
        cout << endl;
    }

    // Test Case 4: End word not in dictionary
    {
        set<string> word_list = {"hot", "dot", "dog", "lot", "log"};
        string start_word = "hit";
        string end_word = "cog";
        cout << "Test Case 4: hit -> cog (end word not in dictionary)" << endl;
        verify_word_ladder();
        cout << endl;
    }

    // Test Case 5: Longer word ladder
    {
        set<string> word_list = {"cat", "cot", "cog", "dog", "dot", "hot", "hat", "bat", "bag", "big", "bit"};
        string start_word = "cat";
        string end_word = "bit";
        vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
        cout << "Test Case 5: cat -> bit" << endl;
        print_word_ladder(ladder);
        cout << endl;
    }

    // Test Case 6: Using words.txt file
    {
        cout << "Test Case 6: Using words.txt file" << endl;
        verify_word_ladder();
    }

    return 0;
}