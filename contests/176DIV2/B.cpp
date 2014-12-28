
#include <iostream>
#include <stdlib.h>

long long n, k;

using namespace std;

long long get(int x) {
    return (k * 2 - 1 - x) * x >>1;
}

long long ans() {
    long long low = 0;
    long long top = k;
    long long mid;
    while (low < top) {
        mid = (low +top) >> 1;
        if (get(mid) < n - 1) {
            low = mid + 1;
        }
        else if (get(mid) > n - 1){
            top = mid;
        }
        else 
            return mid;
    }
    return mid;
}

int main() {
    cin >> n >> k;
    long long t = ans();
    //cout << t  << "  " << get(t)<< endl;
    if (get(t) >= n - 1) 
        cout << t << endl;
    else if (get(t +1) >= n -1) 
        cout << t +1 << endl;
    else 
        cout << -1 << endl;

    return 0;
}

