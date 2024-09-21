#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    
    int t; cin >> t;
    while(t-->0) {
        
        int n; cin >> n;

        string curr = "", prediction;
        int response;

        while(curr.length() < n) {

            prediction = curr + "0";
            cout << "? " << prediction << endl;
            cout.flush();
            cin >> response;

            if (response == 1) {
                curr = prediction;
                continue;
            }

            prediction = curr + "1";
            cout << "? " << prediction << endl;
            cout.flush();
            cin >> response;
            if (response == 0) {
                break;
            }

            curr = prediction;
        }

        // after reaching to end, try adding in begging of curr
        while(curr.length() < n) {

            prediction = "0" + curr;
            cout << "? " << prediction << endl;
            cout.flush();
            cin >> response;

            if (response == 1) {
                curr = prediction;
                continue;
            }

            curr = "1" + curr;
        }

        cout << "! " << curr << endl;
        cout.flush();
    }
}