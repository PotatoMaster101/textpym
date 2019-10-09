///////////////////////////////////////////////////////////////////////////////
// Generates a text pyramid. Only considers alphabetical and numerical
// characters.
//
// Author: PotatoMaster101
// Date:   09/10/2019
///////////////////////////////////////////////////////////////////////////////

#ifndef TEXTPYM_HPP
#define TEXTPYM_HPP
#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

// The text pyramid.
class textpym {
public:
    // Constructors.
    textpym() = default;
    textpym(const std::string& str) :
        pym_(), original_(str), letters_(0) { init(); }

    // Rule of five.
    textpym(const textpym& t) = default;
    textpym& operator=(const textpym& t) = default;
    textpym(textpym&& t) = default;
    textpym& operator=(textpym&& t) = default;
    ~textpym() = default;

    // Returns the pyramid size.
    std::size_t size() const noexcept { return pym_.size(); }
    std::size_t length() const noexcept { return pym_.size(); }

    // Returns the letter/number count.
    std::size_t letters() const noexcept { return letters_; }

    // Returns the original string.
    const std::string& original() const noexcept { return original_; }

    // Operator [].
    inline const std::string& operator[](std::size_t i) const noexcept
    { return pym_[i]; }

    // Operator <<.
    friend std::ostream& operator<<(std::ostream& os, const textpym& t);

private:
    // List of text pyramid strings.
    std::vector<std::string> pym_;
    // The original string.
    std::string original_;
    // The letter count.
    std::size_t letters_;

    // Initiates the pyramid.
    void init();

    // Generates the pyramid.
    void gen();
};

#endif

