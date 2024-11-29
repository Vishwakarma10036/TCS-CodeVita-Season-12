/*
String Obsession
Problem Description
Who knows the reason for why little Meera is so obsessed with strings and loves to spend her time analyzing them!?
Meera has an everlasting passion for strings. One day, she took a string (let us call it the main string) along with some substrings and decided to remove as many substrings from the main string as possible. Whenever a part is removed, the remaining portions of the string are joined together. For example, if the main string is "hello" and "el" is removed, it becomes "hlo." Note that she can remove one substring only once from the string.
Given the main string and the substrings, determine and print the maximum number of substrings that can be removed.

Constraints
1 <= length of main string <= 55
1 <= length of each substring <= 15
Both main and substrings will be having only lower-case alphabets only.

Input
First line consists of N, denoting the total number of substrings.
Next line consists of N space separated substrings.
Last line consists of the main string.

Output
Print a single integer denoting the maximum number of substrings that can be removed.
Time Limit (secs)
1
Examples
Example 1

Input
6
hd el llo wor ell lds
helloworlds
Output
4

Explanation

Given main string is - helloworlds
Remove llo, the string becomes heworlds
Remove wor, the string becomes helds
Remove el, the string becomes hds
Remove hd, the string becomes s. One cannot remove anything further.
Hence the maximum number of substrings we can remove is 4, print 4 as output.

Example 2
Input
7
ggc rm oo le glh oog ec
googlechrome

Output
3

Explanation

Given main string is - googlechrome
Remove oo, the string becomes gglechrome
Remove le, the string becomes ggchrome
Remove ggc, the string becomes hrome. One cannot remove anything further.
Second possibility can also be - removing ec,glh,oo resulting in grome, further reduction is impossible. In this case also only 3 substrings have been removed.
Hence the maximum number of substrings we can remove is 3, hence print 3 as output.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool removeSubstring(string& mainString, const string& sub) {
    size_t pos = mainString.find(sub);
    if (pos != string::npos) {
        mainString.erase(pos, sub.length()); 
        return true;
    }
    return false;
}
void findMaxRemovals(string mainString, const vector<string>& substrings, int count, int& maxCount) {
    maxCount = max(maxCount, count);
    
    for (const string& sub : substrings) {
        string tempString = mainString;
        if (removeSubstring(tempString, sub)) {
            findMaxRemovals(tempString, substrings, count + 1, maxCount);
        }
    }
}

int main() {
    int n; 
    cin >> n;
    vector<string> substrings(n);
    for (int i = 0; i < n; ++i) {
        cin >> substrings[i];
    }
    string mainString;
    cin >> mainString;
    int maxCount = 0; 
    findMaxRemovals(mainString, substrings, 0, maxCount);
    cout << maxCount; 
    return 0;
}
