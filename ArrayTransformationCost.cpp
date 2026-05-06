#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    long long K;
    cin >> K;

    for (int i = 1; i < N; i++) {
        if ((A[i] % K) != (A[0] % K)) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = A[i] / K;
    }

   
    sort(B.begin(), B.end());
    long long median = B[N / 2];

    long long operations = 0;
    for (int i = 0; i < N; i++) {
        operations += abs(B[i] - median);
    }

    cout << operations << endl;
}