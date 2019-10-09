///////////////////////////////////////////////////////////////////////////////
// Generates a text pyramid. Only considers alphabetical and numerical
// characters.
//
// Author: PotatoMaster101
// Date:   09/10/2019
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>    // std::for_each()
#include <cctype>       // std::isalnum()
#include "textpym.hpp"

// Initiates the pyramid.
void textpym::init() {
    for (const auto& ch : original_)
        if (std::isalnum(ch))
            letters_++;

    if (letters_ > 0)
        gen();
    else
        pym_.push_back(original_);
}

// Generates the pyramid.
void textpym::gen() {
    std::size_t i = 0, j = 0;
    while (j < (letters_ - 1)) {        // first half
        if (std::isalnum(original_[i])) {
            pym_.push_back(original_.substr(0, i + 1));
            j++;
        }
        i++;
    }

    pym_.push_back(original_);      // middle and second half
    for (i = 2; i <= letters_; i++)
        pym_.push_back(pym_[letters_ - i]);
}

// Operator <<.
std::ostream& operator<<(std::ostream& os, const textpym& t) {
    std::for_each(t.pym_.begin(), t.pym_.end(),
            [&os](const auto& str){ os << str << std::endl; });
    return os;
}

