#include <bits/stdc++.h>
#include <string.h>
#define MAXN 100

using namespace std;

class Candidate
{
    private:
        string code, date, name;
        float math,literature, english;
    public:
        void Input();
        float Average();
        void Output();
};
class TestCandidate
{
    private:
        int n;
        Candidate sum[MAXN];
    public:
        void Import();
        void Export();
};
