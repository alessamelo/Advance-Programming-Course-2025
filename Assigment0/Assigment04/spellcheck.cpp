#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
    Corpus tokens;
    
    // Step 1: Find all whitespace positions (including boundaries)
    auto whitespace_positions = find_all(source.begin(), source.end(), ::isspace);
    
    // Step 2: Generate tokens between consecutive whitespace positions
    std::transform(
        whitespace_positions.begin(), whitespace_positions.end() - 1,
        whitespace_positions.begin() + 1,
        std::inserter(tokens, tokens.end()),
        [&source](auto begin, auto end) {
            return Token(source, begin, end);
        }
    );
    
    // Step 3: Remove empty tokens
    for (auto it = tokens.begin(); it != tokens.end(); ) {
        if (it->content.empty()) {
            it = tokens.erase(it);
        } else {
            ++it;
        }
    }
    
    return tokens;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
    std::set<Mispelling> result;
    
    // Step 1: Find misspelled words
    for (const auto& token : source) {
        if (dictionary.find(token.content) == dictionary.end()) {
            // Step 2: Find suggestions
            std::set<std::string> suggestions;
            for (const auto& word : dictionary) {
                if (levenshtein(token.content, word) == 1) {
                    suggestions.insert(word);
                }
            }
            
            // Step 3: Only add if there are suggestions
            if (!suggestions.empty()) {
                result.insert(Mispelling{token, suggestions});
            }
        }
    }
    
    return result;
}

/* Helper methods */

#include "utils.cpp"