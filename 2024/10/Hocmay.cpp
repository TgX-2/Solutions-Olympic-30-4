cmap<int, bool> checkSquare, checkCube;

bool checkCase2(const int &x) { return checkSquare[x]; }
bool checkCase3(const int &x) { return checkCube[x]; }

bool checkCase4(const int &x) {
    for(int i = 1; i * i <= x; i++) {
        int a = i * i;
        int b = x - i * i;
        if (checkCase2(b)) return 1;
    }
    return 0;
}

int poww(int a, int b) {
    int ans = 1;
    FOR(i, 1, b) 
        ans *= a;
    return ans;
}

bool checkCase5(const int &x) {
    for(int i = 1; poww(i, 5) <= x; i++)
        if (poww(i, 5) == x) return 1;
    for(int i = 1; poww(i, 3) <= x; i++) {
        int a = x - poww(i, 3);
        if (checkCase2(a)) return 1;
    }
    return 0;
}


bool checkCase6(const int &x) {
    for(int i = 1; poww(i, 6) <= x; i++)
        if (poww(i, 6) == x) return 1;

    for(int i = 1; poww(i, 4) <= x; i++) {
        int a = x - poww(i, 4);
        if (checkCase2(a)) return 1;
    }

    for(int i = 1; poww(i, 3) <= x; i++) {
        int a = x - poww(i, 3);
        if (checkCase3(a)) return 1;
    }

    int a = x;
    while(a % 4 == 0) a /= 4;
    return (a % 8 != 7);
}

bool checkCase7(const int &x) {
    for(int i = 1; poww(i, 7) <= x; i++)
        if (poww(i, 7) == x) return 1;

    for(int i = 1; poww(i, 5) <= x; i++) {
        int a = x - poww(i, 5);
        if (checkCase2(a)) return 1;
    }

    for(int i = 1; poww(i, 4) <= x; i++) {
        int a = x - poww(i, 3);
        if (checkCase3(a)) return 1;
    }

    for(int i = 1; i <= poww(i, 3); i++) {
        int cur1 = poww(i, 3);
        for(int j = 1; poww(j, 2) <= x - cur1; j++) {
            int cur2 = x - cur1 - poww(j, 2);
            if (checkCase2(cur2)) return 1;
        }
    }

    return 0;
}

void process() {
    int t; cin >> t;

    for(int i = 1; i * i <= 1e9; i++)
        checkSquare[i * i] = 1;
    for(int i = 1; i * i * i <= 1e9; i++)
        checkCube[i * i * i] = 1;

    while(t--) {
        int x; cin >> x;
        if (checkCase2(x)) cout << 2 __ ;
        else if (checkCase3(x)) cout << 3 __ ;
        else if (checkCase4(x)) cout << 4 __ ;
        else if (checkCase5(x)) cout << 5 __ ;
        else if (checkCase6(x)) cout << 6 __ ;
        else if (checkCase7(x)) cout << 7 __ ;
        else cout << 8 __ ;
    }
}
