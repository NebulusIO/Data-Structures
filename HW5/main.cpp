// main.cpp file for Cpt S 223 homework assignment
// DO NOT MODIFY THIS FILE

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <unordered_set>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Trees223.h"

// Converts a std::string to lower-case (English language)
std::string MakeLower(const std::string& str)
{
    std::string result;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            result += (char)(str[i] - 'A' + 'a');
        }
        else
            result += str[i];
    }
    return result;
}

// Comparison functions
int CompareInts(const int& first, const int& second) { return first - second; }
int CompareStrs(const std::string& A, const std::string& B)
{
    return A.compare(B);
}
int CompareStrsLower(const std::string& A, const std::string& B)
{
    return MakeLower(A).compare(MakeLower(B));
}

// "Conversion" functions
std::string UtilToStr(int value) { return std::to_string(value); }
std::string UtilToStr(const std::string& value) { return value; }

// ---- Begin: Structs related to test cases ----
struct TestCasePoints
{
    double Possible;
    double Earned;
    TestCasePoints(double p, double e) { Possible = p; Earned = e; }
};

template <typename T>
struct TestCase
{
    virtual TestCasePoints Exec(BST<T>& tree) const = 0;
    virtual ~TestCase() { }
};

// Class for test case for GetLevel functionality
template <typename T>
struct GetLevel_TC : public TestCase<T>
{
private:
    std::function<int(const T& first, const T& second)> m_compare;
    T m_value;
    int m_expected;
    
public:
    GetLevel_TC(std::function<int(const T& first, const T& second)> compare,
                const T& value, int expectedLevel)
                : m_compare(compare), m_value(value), m_expected(expectedLevel) { }
    
    TestCasePoints Exec(BST<T>& tree) const
    {
        auto testCmpFunc = [this](const T& val) { return m_compare(m_value, val); };
        int actualValue = tree.GetLevel(testCmpFunc);
        if (m_expected == actualValue)
        {
            std::cout << "OK: GetLevel for \"" << m_value << "\" returned ";
            std::cout << m_expected << std::endl;
            return TestCasePoints(1.0, 1.0);
        }
        
        std::cout << "FAIL: GetLevel for \"" << m_value << "\" returned ";
        std::cout << actualValue << ", when expected was ";
        std::cout << m_expected << std::endl;
        return TestCasePoints(1.0, 0.0);
    }
};

struct Remove_int_TC : public TestCase<int>
{
private: int m_toRemove; bool m_expectedRet; int m_expectedCount;
public:
    Remove_int_TC(int toRemove, bool expectedReturnValue, int expectedCountAfterRemoval)
    {
        m_toRemove = toRemove;
        m_expectedRet = expectedReturnValue;
        m_expectedCount = expectedCountAfterRemoval;
    }
    TestCasePoints Exec(BST<int>& tree) const
    {
        auto testCmpFunc = [this](const int& num) { return m_toRemove - num; };
        bool actualRet = tree.Remove(testCmpFunc);
        if (m_expectedRet == actualRet)
        {
            std::cout << "OK: Call to remove " << m_toRemove << " returned ";
            std::cout << (m_expectedRet ? "true" : "false") << std::endl;
        }
        else
        {
            std::cout << "FAIL: Call to remove " << m_toRemove;
            std::cout << " returned " << actualRet << ", when expected was ";
            std::cout << m_expectedRet << std::endl;
            return TestCasePoints(2.0, 0.0);
        }
        
        // Now verify the number of items in the tree
        int actualCount = tree.Count();
        if (m_expectedCount == actualCount)
        {
            std::cout << "OK: Number of items in tree after removal = ";
            std::cout << m_expectedCount << std::endl;
            return TestCasePoints(2.0, 2.0);
        }
        
        std::cout << "FAIL: Number of items in tree after removal = ";
        std::cout << actualCount << ", but expected was ";
        std::cout << m_expectedCount << std::endl;
        return TestCasePoints(2.0, 0.0);
    }
};

struct Remove_string_TC : public TestCase<std::string>
{
private: std::string m_toRemove; bool m_expectedRet;
public:
    Remove_string_TC(const std::string& toRemove, bool expectedReturnValue) : m_toRemove(toRemove)
    {
        m_expectedRet = expectedReturnValue;
    }
    TestCasePoints Exec(BST<std::string>& tree) const
    {
        auto testCmpFunc = [this](const std::string& s) { return m_toRemove.compare(s); };
        bool actualRet = tree.Remove(testCmpFunc);
        if (m_expectedRet == actualRet)
        {
            std::cout << "OK: Call to remove \"" << m_toRemove << "\" returned ";
            std::cout << (m_expectedRet ? "true" : "false") << std::endl;
            return TestCasePoints(2.0, 2.0);
        }
        
        std::cout << "FAIL: Call to remove \"" << m_toRemove;
        std::cout << "\" returned " << actualRet << ", when expected was ";
        std::cout << m_expectedRet << std::endl;
        return TestCasePoints(2.0, 0.0);
    }
};

template <typename T>
struct InOrder_TC : public TestCase<T>
{
private:
    std::string m_expected;
public:
    InOrder_TC(const std::string& expectedFullOuput)
    {
        m_expected = expectedFullOuput;
    }
    TestCasePoints Exec(BST<T>& tree) const
    {
        std::string actual;
        auto visitFunc = [&](const T& value) { actual += (UtilToStr(value) + " "); };
        tree.InOrder(visitFunc);
        if (m_expected == actual)
        {
            std::cout << "OK: In-order traversal" << std::endl;
            return TestCasePoints(2.0, 2.0);
        }
        
        std::cout << "FAIL: In-order traversal. Expected \"" << m_expected;
        std::cout << "\" but got \"" << actual << "\"" << std::endl;
        return TestCasePoints(2.0, 0.0);
    }
};

template <typename T>
struct Count_TC : public TestCase<T>
{
private: int m_expectedCount;
public:
    Count_TC(int expectedCount)
    {
        m_expectedCount = expectedCount;
    }
    TestCasePoints Exec(BST<T>& tree) const
    {
        // Verify the number of items in the tree
        int actualCount = tree.Count();
        if (m_expectedCount == actualCount)
        {
            std::cout << "OK: Number of items in tree = ";
            std::cout << m_expectedCount << std::endl;
            return TestCasePoints(1.0, 1.0);
        }
        
        std::cout << "FAIL: Number of items in tree = ";
        std::cout << actualCount << ", but expected was ";
        std::cout << m_expectedCount << std::endl;
        return TestCasePoints(1.0, 0.0);
    }
};

template <typename T>
struct CountLevels_TC : public TestCase<T>
{
private: int m_expected;
public:
    CountLevels_TC(int expected) { m_expected = expected; }
    TestCasePoints Exec(BST<T>& tree) const
    {
        int actualValue = tree.CountLevels();
        if (m_expected == actualValue)
        {
            std::cout << "OK: CountLevels returned ";
            std::cout << m_expected << std::endl;
            return TestCasePoints(1.0, 1.0);
        }
        
        std::cout << "FAIL: CountLevels returned ";
        std::cout << actualValue << ", when expected value was ";
        std::cout << m_expected << std::endl;
        return TestCasePoints(1.0, 0.0);
    }
};

struct Add_int_TC : public TestCase<int>
{
private:
    int m_toAdd;
    bool m_expectedRet;
public:
    Add_int_TC(const int& toAdd, bool expectedRet) : m_toAdd(toAdd)
    {
        m_expectedRet = expectedRet;
    }
    TestCasePoints Exec(BST<int>& tree) const
    {
        bool actual = tree.Add(m_toAdd, CompareInts);
        if (m_expectedRet == actual)
        {
            std::cout << "OK: Add (" << m_toAdd << ") returned ";
            std::cout << (m_expectedRet ? "true" : "false") << std::endl;
            return TestCasePoints(2.0, 2.0);
        }
        
        std::cout << "FAIL: Add (" << m_toAdd << ") returned ";
        std::cout << (actual ? "true" : "false") << ", when expected value was ";
        std::cout << (m_expectedRet ? "true" : "false") << std::endl;
        return TestCasePoints(2.0, 0.0);
    }
};

struct AddRandInts_TC : public TestCase<int>
{
public:
    TestCasePoints Exec(BST<int>& tree) const
    {
        // This test creats a new tree and adds a bunch of random values just
        // to ensure that the tree holds up under "stress".
        BST<int> tree2;
        std::vector<int> valuesAdded;
        std::unordered_set<int> distinctValues;
        for (int i = 0; i < 100000; i++)
        {
            int value = rand();
            tree2.Add(value, CompareInts);
            valuesAdded.push_back(value);
            distinctValues.insert(value);
        }
        
        // Ensure that the number of distinct values matches up
        if (distinctValues.size() != tree2.Count())
        {
            std::cout << "FAIL: Failed to add " << distinctValues.size();
            std::cout << " random values." << std::endl;
            return TestCasePoints(10.0, 0.0);
        }
        
        std::cout << "OK: Added " << valuesAdded.size() << " random values (";
        std::cout << distinctValues.size() << " distinct). ";
        std::cout << "About to remove all values..." << std::endl;
        
        // Remove all values in the same order that they were added
        for (int i = 0; i < valuesAdded.size(); i++)
        {
            int valueToRemove = valuesAdded[i];
            auto testCmpFunc = [=](const int& num) { return valueToRemove - num; };
            tree.Remove(testCmpFunc);
        }
        std::cout << "OK: Removed all added values" << std::endl;
        return TestCasePoints(10.0, 10.0);
    }
};

struct Add_string_TC : public TestCase<std::string>
{
private:
    std::string m_toAdd;
    bool m_expectedRet;
    bool m_caseIns;
public:
    Add_string_TC(const std::string& toAdd, bool expectedRet, bool caseInsensitive = false)
        : m_toAdd(toAdd), m_caseIns(caseInsensitive), m_expectedRet(expectedRet) { }
    
    TestCasePoints Exec(BST<std::string>& tree) const
    {
        bool actual = tree.Add(m_toAdd, m_caseIns ? CompareStrsLower : CompareStrs);
        if (m_expectedRet == actual)
        {
            std::cout << "OK: Add (\"" << m_toAdd << "\") returned ";
            std::cout << (m_expectedRet ? "true" : "false") << std::endl;
            return TestCasePoints(2.0, 2.0);
        }
        
        std::cout << "FAIL: Add returned ";
        std::cout << (actual ? "true" : "false") << ", when expected value was ";
        std::cout << (m_expectedRet ? "true" : "false") << std::endl;
        return TestCasePoints(2.0, 0.0);
    }
};

// ---- End: Structs related to test cases ----

// ExecTreeTests - executes unit tests on BST
// Frees each test case after execution and clears the vector of test cases at the end
template <typename T>
void ExecTreeTests(std::vector<const TestCase<T>*>& testCases, double& totalPoints, double& earnedPoints)
{
    // Create the tree
    BST<T> tree;
    
    // Execute all test cases
    for (auto test : testCases)
    {
        auto points = test->Exec(tree);
        delete test;
        
        totalPoints += points.Possible;
        earnedPoints += points.Earned;
        
        // DEBUG: Show tree contents after each test
        //std::cout << "DEBUG (tree contents in order): ";
        //tree->InOrder([](const int& num) { std::cout << num << " "; });
        //std::cout << std::endl;
    }
    testCases.clear();
}

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));
    double totalPoints = 0.0, earnedPoints = 0.0;
    
    // Initialize a set of test cases for an integer tree
    std::vector<const TestCase<int>*> testCases = {
        // First batch of tests just adds values to the tree
        new Add_int_TC(10, true),
        new Add_int_TC(50, true),
        new Add_int_TC(20, true),
        new Add_int_TC(30, true),
        new Add_int_TC(40, true),
        new Add_int_TC(10, false),
        new Add_int_TC(50, false),
        new Add_int_TC(70, true),
        new Add_int_TC(80, true),
        new Add_int_TC(2, true),
        new Add_int_TC(99, true),
        new Add_int_TC(66, true),
        new Add_int_TC(44, true),
        new Add_int_TC(10, false),
        new Add_int_TC(99, false),
        new Add_int_TC(98, true),
        new Add_int_TC(12345, true),
        new Add_int_TC(-761, true),
        new Add_int_TC(-11, true),
        new Add_int_TC(77, true),
        
        // Next batch analyzes the tree and does some alterations as well
        new InOrder_TC<int>("-761 -11 2 10 20 30 40 44 50 66 70 77 80 98 99 12345 "),
        new Count_TC<int>(16),
        new GetLevel_TC<int>(CompareInts, 5, -1),
        new GetLevel_TC<int>(CompareInts, 66, 3),
        new GetLevel_TC<int>(CompareInts, 10, 0),
        new GetLevel_TC<int>(CompareInts, -500, -1),
        new GetLevel_TC<int>(CompareInts, -761, 2),
        new GetLevel_TC<int>(CompareInts, 40, 4),
        new GetLevel_TC<int>(CompareInts, 50, 1),
        new CountLevels_TC<int>(6),
        new GetLevel_TC<int>(CompareInts, 44, 5),
        new Remove_int_TC(-11, true, 15),
        new CountLevels_TC<int>(6),
        new Remove_int_TC(44, true, 14),
        new Remove_int_TC(98, true, 13),
        new Remove_int_TC(12345, true, 12),
        new CountLevels_TC<int>(5),
        new Remove_int_TC(10, true, 11),
        new CountLevels_TC<int>(5),
        new InOrder_TC<int>("-761 2 20 30 40 50 66 70 77 80 99 "),
        new Remove_int_TC(761, false, 11),
        new Remove_int_TC(80, true, 10),
        new InOrder_TC<int>("-761 2 20 30 40 50 66 70 77 99 "),
        
        new AddRandInts_TC()
    };
    // Execute tests
    ExecTreeTests(testCases, totalPoints, earnedPoints);
    
    // Initialize a set of test cases for a string tree
    std::vector<const TestCase<std::string>*> strCases = {
        // First batch of tests just adds strings to the tree
        new Add_string_TC("Thor", true),
        new Add_string_TC("Iron Man", true),
        new Add_string_TC("Black Widow", true),
        new Add_string_TC("Hawkeye", true),
        new Add_string_TC("Hulk", true),
        new Add_string_TC("Captain America", true),
        new Add_string_TC("thor", true),
        new Add_string_TC("Hulk", false),
        new Add_string_TC("Loki", true),
        new Add_string_TC("Star Lord", true),
        
        // Next batch analyzes the tree
        new InOrder_TC<std::string>("Black Widow Captain America Hawkeye Hulk Iron Man Loki Star Lord Thor thor "),
        new Count_TC<std::string>(9),
        new CountLevels_TC<std::string>(5),
        new GetLevel_TC<std::string>(CompareStrs, "Thor", 0),
        new GetLevel_TC<std::string>(CompareStrs, "thor", 1),
        new GetLevel_TC<std::string>(CompareStrs, "Hulk", 4),
        new GetLevel_TC<std::string>(CompareStrs, "Captain America", 4),
        new GetLevel_TC<std::string>(CompareStrs, "Black Window", -1),
        new GetLevel_TC<std::string>(CompareStrs, "Black Widow", 2),
        new GetLevel_TC<std::string>(CompareStrs, "Loki", 2),
        new GetLevel_TC<std::string>(CompareStrs, "Iron Man", 1),
        new GetLevel_TC<std::string>(CompareStrs, "Hawkeye", 3),
        new GetLevel_TC<std::string>(CompareStrs, "Star Lord", 3),
        new GetLevel_TC<std::string>(CompareStrs, "star lord", -1),
        
        // Final batch alters and further analyzes the tree
        new Remove_string_TC("captain america", false),
        new Count_TC<std::string>(9),
        new CountLevels_TC<std::string>(5),
        new Remove_string_TC("Captain America", true),
        new Count_TC<std::string>(8),
        new CountLevels_TC<std::string>(5),
        new Remove_string_TC("Hawkeye", true),
        new Count_TC<std::string>(7),
        new CountLevels_TC<std::string>(4),
        new InOrder_TC<std::string>("Black Widow Hulk Iron Man Loki Star Lord Thor thor "),
        new GetLevel_TC<std::string>(CompareStrs, "Hlk", -1),
        new GetLevel_TC<std::string>(CompareStrs, "Hulk", 3),
        new GetLevel_TC<std::string>(CompareStrs, "Loki", 2),
        new Remove_string_TC("Iron Man", true),
        new Count_TC<std::string>(6),
        new CountLevels_TC<std::string>(4),
        new GetLevel_TC<std::string>(CompareStrs, "Iron Man", -1),
        new GetLevel_TC<std::string>(CompareStrs, "Loki", 1),
        new GetLevel_TC<std::string>(CompareStrs, "Star Lord", 2),
        new Add_string_TC("Vision", true),
        new Count_TC<std::string>(7),
        new CountLevels_TC<std::string>(4),
        new GetLevel_TC<std::string>(CompareStrs, "Vision", 2),
        new GetLevel_TC<std::string>(CompareStrs, "thor", 1),
        new Remove_string_TC("Hulk", true),
        new Count_TC<std::string>(6),
        new CountLevels_TC<std::string>(3),
        new GetLevel_TC<std::string>(CompareStrs, "Black Widow", 2),
        new InOrder_TC<std::string>("Black Widow Loki Star Lord Thor Vision thor ")
    };
    // Execute tests for BST with strings
    ExecTreeTests(strCases, totalPoints, earnedPoints);
    
    // Initialize a set of test cases for a string tree with case-insensitive comparisons
    std::vector<const TestCase<std::string>*> strLwrCases = {
        new Add_string_TC("Red", true, true),
        new Add_string_TC("Green", true, true),
        new Add_string_TC("Blue", true, true),
        new Add_string_TC("red", false, true),
        new Add_string_TC("green", false, true),
        new Add_string_TC("blue", false, true),
        new Add_string_TC("YELLOW", true, true),
        new GetLevel_TC<std::string>(CompareStrsLower, "yellow", 1),
        new GetLevel_TC<std::string>(CompareStrsLower, "ReD", 0),
        new GetLevel_TC<std::string>(CompareStrsLower, "BLUE", 2),
        new GetLevel_TC<std::string>(CompareStrsLower, "gREEN", 1)
    };
    // Execute tests for BST with strings
    ExecTreeTests(strLwrCases, totalPoints, earnedPoints);
    
    // Display the final score
    double finalPercentScore = earnedPoints / totalPoints * 100.0;
    std::cout << "Final score: " << finalPercentScore << "%" << std::endl;

    return 0;
}
