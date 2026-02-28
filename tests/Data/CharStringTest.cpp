// #### Google Gemini ####
// #### ALL AI-Based Generation noted ####


#include <gtest/gtest.h>
#include "../../src/Data/CharString.h"
#define MAX_STRING_SIZE 1000000000

// Test Case 1: Ensure the constructor handles a standard string correctly
TEST(CharStringTest, ConstructorInitializesCorrectly) {
    CharString myStr("Hello");

    EXPECT_EQ(myStr.getSize(), 5);
    EXPECT_STREQ(myStr.get(), "Hello");
}

// Test Case 2: Test empty string behavior
TEST(CharStringTest, HandlesEmptyString) {
    CharString emptyStr("");

    EXPECT_EQ(emptyStr.getSize(), 0);
    EXPECT_TRUE(emptyStr.isEmpty());
}

// Test Case 3: Test bounds/overflow (The "Conformative" Safety Test)
TEST(CharStringTest, HandlesLargeInput) {
    std::string largeInput(1000, 'a'); // 1000 'a's
    CharString myStr(largeInput.c_str());

    // If your CharString has a fixed limit, test that it truncates safely
    // instead of crashing (Buffer Overflow Protection).
    EXPECT_LE(myStr.getSize(), MAX_STRING_SIZE);
}

// Test Case 4: Test Modification
TEST(CharStringTest, AppendsCorrectly) {
    CharString myStr("Eternia");
    myStr.concatb("Lib");

    EXPECT_STREQ(myStr.get(), "EterniaLib");
    EXPECT_EQ(myStr.getSize(), 10);
}


/**
 * VULNERABILITY: Classic Buffer Overflow (CWE-120)
 * EXPLOIT: Overwriting adjacent stack/heap memory.
 * TEST: Ensure the library truncates or throws when input exceeds capacity.
 */
TEST(CharStringExploitTest, BufferOverflowProtection) {
    const int MAX = MAX_STRING_SIZE;
    std::string maliciousInput(MAX + 100, 'X');

    CharString str(maliciousInput.c_str());

    // Conformity check: The library must not allow its internal
    // buffer to exceed its defined capacity.
    EXPECT_LE(str.getSize(), MAX);
    EXPECT_EQ(str.get()[MAX], '\0'); // Ensure no overflow at the boundary
}

/**
 * VULNERABILITY: Missing Null-Terminator (CWE-170)
 * EXPLOIT: Information disclosure (reading past the buffer) or crashes.
 * TEST: Pass an array that is NOT null-terminated.
 */
TEST(CharStringExploitTest, UnterminatedInputSafety) {
    char rawData[5] = {'A', 'B', 'C', 'D', 'E'}; // No \0 here

    // A safe library should require a length parameter if the input
    // might not be null-terminated.
    CharString str(rawData, 5);

    EXPECT_EQ(str.getSize(), 5);
    EXPECT_EQ(str.get()[5], '\0'); // The library MUST add its own terminator
}

/**
 * VULNERABILITY: Off-by-One Error (CWE-193)
 * EXPLOIT: Overwriting the very next byte (often the null terminator of another string).
 * TEST: Fill the buffer exactly to its capacity.
 */
TEST(CharStringExploitTest, OffByOneBoundary) {
    const int MAX = MAX_STRING_SIZE;
    std::string boundaryInput(MAX, 'A');

    CharString str(boundaryInput.c_str());

    EXPECT_EQ(str.getSize(), MAX);
    // Crucial: The N+1 byte must be \0, not 'A'
}

/**
 * VULNERABILITY: Improper Sanitization / Format String (CWE-134)
 * EXPLOIT: Reading/writing memory via printf-style %n or %s tokens.
 */
TEST(CharStringExploitTest, FormatStringNeutralization) {
    CharString str("%s%s%n%x");

    // If EterniaLib has a print() or log() function, ensure
    // it treats these as literal characters, not instructions.
    // This is tested by ensuring the string contents remain literal.
    EXPECT_STREQ(str.get(), "%s%s%n%x");
}
