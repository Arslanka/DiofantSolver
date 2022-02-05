#include <algorithm>
#include <numeric>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <map>
#include <iomanip>

// @author: Arslanka


using namespace std;
vector<vector<int>> gcd_rep;
int a, b, c;
void linear_rep(int a, int b){
    if (a < b)
        swap(a, b);
    while (a != 0 && b != 0) {
        vector<int> tupple(4);
        tupple[0] = a, tupple[1] = b, tupple[2] = a / b, tupple[3] = a % b;
        a = b, b = tupple[0] % b;
        gcd_rep.emplace_back(tupple);
    }
}
void diofant_solve(int a1, int b1, int c1) {
    int g = gcd(a1, b1);
    if (c1 % g != 0) {
        cout << "There is no solution of this equation\n";
        return;
    }
    a1 /= g, b1 /= g, c1 /= g;
    linear_rep(a, b);
    int xk = 1, yk = 0;
    for (int i = gcd_rep.size() - 2; i >= 0; --i) {
        swap(xk, yk);
        xk = (-1 * yk * gcd_rep[i][2] + xk);
    }
    xk *= c1, yk *= c1;
    cout << "Your solution is\n" << "x = " << xk << " + t * " << a / g << '\n' << "y = " << yk << " - t * " << b / g << '\n';
}

void solve() {
    cin >> a >> b >> c;
    diofant_solve(a, b, c);
}

signed main() {
    solve();
}
