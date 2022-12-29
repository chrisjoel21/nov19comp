#include <iostream>

using namespace std;

int main() {
    int n, time;
    cin >> n >> time;

    int i;
    int total = 0;
    for(i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        total += temp;
        if(total > time) {
            break;
        }
    }

    cout << i << endl;
}