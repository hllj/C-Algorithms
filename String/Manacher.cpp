#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a;
int n;

string preProcess(string s, int &n) {
    string res;
    if (n == 0) return "$#";
    res = "$";
    for (int i = 0; i < n; i++)
        res += "#" + s.substr(i, 1);
    res += "#$";
    n = res.length();
    return res;
}
string LongestPalindrome(string s, int n) {
    int* f = new int[n];
    int R = 0, C = 0, maxLen = 0;
    for (int i = 1; i < n - 1; i++) {
        int j = 2 * C - i;
        f[i] = (R > i) ? min(f[j], R - i) : 0;
        while (i + 1 + f[i] < n && i - 1 - f[i] >= 0 && s[i + 1 + f[i]] == s[i - 1 - f[i]]) 
            f[i]++;
        if (i + f[i] > R) {
            C = i;
            R = i + f[i];
        }
    }
    int CenterIndex = -1;
    for (int i = 1; i < n - 1; i++) 
        if (f[i] > maxLen) {
            maxLen = f[i];
            CenterIndex = i;
        }
    return a.substr((CenterIndex - 1 - maxLen) / 2, maxLen);
}
int main() {
    a = "dcabacdeca";
    n = a.length();
    string s = preProcess(a, n);
    cout << LongestPalindrome(s, n);
    return 0;
}