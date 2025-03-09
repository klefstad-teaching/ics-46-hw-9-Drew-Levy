#include "ladder.h"
#include <iostream>

using namespace std;

int main() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");

    // Test case 1: "work" -> "play"
    vector<string> ladder1 = generate_word_ladder("work", "play", word_list);
    cout << "Test case 1: work -> play" << endl;
    print_word_ladder(ladder1);
    cout << "Expected ladder size: 6" << endl;
    cout << "Actual ladder size: " << ladder1.size() << endl;
    cout << "-----------------------------" << endl;

    // Test case 2: "sleep" -> "awake"
    vector<string> ladder2 = generate_word_ladder("sleep", "awake", word_list);
    cout << "Test case 2: sleep -> awake" << endl;
    print_word_ladder(ladder2);
    cout << "Expected ladder size: 8" << endl;
    cout << "Actual ladder size: " << ladder2.size() << endl;
    cout << "-----------------------------" << endl;

    // Test case 3: "awake" -> "sleep"
    vector<string> ladder3 = generate_word_ladder("awake", "sleep", word_list);
    cout << "Test case 3: awake -> sleep" << endl;
    print_word_ladder(ladder3);
    cout << "Expected ladder size: 8" << endl;
    cout << "Actual ladder size: " << ladder3.size() << endl;
    cout << "-----------------------------" << endl;

    // Test case 4: "car" -> "cheat"
    vector<string> ladder4 = generate_word_ladder("car", "cheat", word_list);
    cout << "Test case 4: car -> cheat" << endl;
    print_word_ladder(ladder4);
    cout << "Expected ladder size: 4" << endl;
    cout << "Actual ladder size: " << ladder4.size() << endl;
    cout << "-----------------------------" << endl;

    // Test case 5: "apple" -> "bapple" (edit distance within 1)
    cout << "Test case 5: apple -> bapple (edit distance within 1)" << endl;
    bool is_within_distance = edit_distance_within("apple", "bapple", 1);
    cout << "Expected result: true" << endl;
    cout << "Actual result: " << (is_within_distance ? "true" : "false") << endl;
    cout << "-----------------------------" << endl;

    // Test case 6: "apple" -> "bapple" (is adjacent)
    cout << "Test case 6: apple -> bapple (is adjacent)" << endl;
    bool is_adj = is_adjacent("apple", "bapple");
    cout << "Expected result: true" << endl;
    cout << "Actual result: " << (is_adj ? "true" : "false") << endl;
    cout << "-----------------------------" << endl;

    // Test case 7: "awake" -> "sleep" (full ladder)
    cout << "Test case 7: awake -> sleep (full ladder)" << endl;
    vector<string> ladder7 = generate_word_ladder("awake", "sleep", word_list);
    print_word_ladder(ladder7);
    cout << "Expected ladder: awake aware ware were wee see seep sleep" << endl;
    cout << "-----------------------------" << endl;

    // Test case 8: Print word ladder format
    cout << "Test case 8: Print word ladder format" << endl;
    vector<string> test_ladder = {"awake", "aware", "ware", "were", "wee", "see", "seep", "sleep"};
    print_word_ladder(test_ladder);
    cout << "Expected output: Word ladder found: awake aware ware were wee see seep sleep" << endl;
    cout << "-----------------------------" << endl;

    return 0;
}