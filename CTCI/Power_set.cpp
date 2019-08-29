// CTCI DP & Recursion

/*
 * Power Set: Write a method to return all subsets of a set.
 *  */
#include <bits/stdc++.h>
using namespace std;

void powerOfSet(int id, vector<int>& soFar, vector<int>& v)
{
    if(id >= v.size()) {
        for(auto x : soFar) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    // 2 Options take or not
    // 1) Not Take
    powerOfSet(id + 1, soFar, v);

    // 2) Take
    soFar.push_back(v[id]);
    powerOfSet(id + 1, soFar, v);
    soFar.pop_back();
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> soFar;
    powerOfSet(0, soFar, v);
}
