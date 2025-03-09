#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "Error: " << msg << " (" << word1 << " -> " << word2 << ")" << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length(), len2 = str2.length();
    if (abs(len1 - len2) > d) return false;
    
    int i = 0, j = 0, diff = 0;
    while (i < len1 && j < len2) {
        if (str1[i] != str2[j]) {
            if (++diff > d) return false;
            if (len1 > len2) ++i;
            else if (len1 < len2) ++j;
            else { ++i; ++j; }
        } else { ++i; ++j; }
    }
    return (diff + abs(len1 - len2) <= d);
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    unordered_set<string> visited;
    ladder_queue.push({begin_word});
    visited.insert(begin_word);
    
    while (!ladder_queue.empty()) {
        int level_size = ladder_queue.size();
        unordered_set<string> new_visited;
        
        for (int i = 0; i < level_size; ++i) {
            vector<string> ladder = ladder_queue.front();
            ladder_queue.pop();
            string last_word = ladder.back();
            
            for (const string& word : word_list) {
                if (is_adjacent(last_word, word) && !visited.count(word)) {
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) return new_ladder;
                    ladder_queue.push(new_ladder);
                    new_visited.insert(word);
                }
            }
        }
        for (const auto& w : new_visited) visited.insert(w);
    }
    return {};
}

void load_words(set<string>& word_list, const string& file_name) {
    ifstream file(file_name);
    string word;
    while (file >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No word ladder found." << endl;
    } else {
        cout << "Word ladder found: ";
        for (size_t i = 0; i < ladder.size(); ++i) {
            cout << ladder[i];
            if (i != ladder.size() - 1) cout << " -> ";
        }
        cout << "\n";
    }
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    string start_word, end_word;
    cout << "Enter start word: ";
    //cin >> start_word;
    cout << "Enter end word: ";
    //cin >> end_word;
    if (start_word == end_word) {
        error(start_word, end_word, "Start and end words must be different");
        return;
    }
    transform(start_word.begin(), start_word.end(), start_word.begin(), ::tolower);
    transform(end_word.begin(), end_word.end(), end_word.begin(), ::tolower);
    if (!word_list.count(end_word)) {
        error(start_word, end_word, "End word must be in the dictionary");
        return;
    }
    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
    print_word_ladder(ladder);
}
