#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

/**
 * Редакторское расстояние (или расстояние Левинштейна) показывает наименьшее число операций
 * добавления/удаления/замены для первой строки, что бы она превратилась во вторую.
 * Иными словами, это расстояние характеризует схожесть строк.
 *
 * Один из вариантов нахождения этого расстояния - рекурсия + ДП.
 * Рассмотрим крайние случаи:
 * 1. s1 = "aaa", s2 = ""
 *      В этом случае достаточно из первой строки удалить 3 символа
 *      D(s1, s2) = 3
 * 2. s1 = "", s2 = "aaa"
 *      В этом случае нужно добавить 3 символа в строку
 *      D(s1, s2) = 3
 * 3. s1 = "a", s2 = "b"
 *      В этом случае нужно заменить символ a в первой строке
 *      D(s1, s2) = 1
 * 4. s1 = "ab", s2 = "bb"
 *      В этом случае последние символы равны, значит, можно перейти к анализу подстрок,
 *      которые не включают последние символы.
 *      А расстояние между этими подстроками равно 1 (см. п.3)
 *      D(s1, s2) = D(s1[0:-1], s2[0:-1]) = 1
 * В остальных случаях, нужно рекурсивно проверять случаи добавления/удаления/замены символа.
 * Смотреть, какой вариант даёт меньше операций и брать его.
 *
 * Реализация возможна чисто на рекурсии, но её глубина может быть большая. Поэтому используется
 * ДП. Запоминается редакторское расстояние между подстроками 0..i 0..j.
 *
 * Сложность: O(n*m) по времени, O(n*m) по памяти.
 */
int edit(const string& s1, const string& s2, int i, int j, vector<vector<int>>& dp)
{
    if (dp[i][j] > -1)
        return dp[i][j];

    if (min(i, j) == 0)
    {
        dp[i][j] = max(i, j);
        return dp[i][j];
    }

    if (s1[i-1] == s2[j-1])
    {
        dp[i][j] = edit(s1, s2, i-1, j-1, dp);
        return dp[i][j];
    }

    dp [i][j] = min(
                min(edit(s1, s2, i-1, j, dp) + 1,
                    edit(s1, s2, i, j-1, dp) + 1),
                edit(s1, s2, i-1, j-1, dp) + 1);
    return dp[i][j];
}

int editDP(const string& s1, const string& s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return edit(s1, s2, n, m, dp);
}

struct TestCase
{
    string s1;
    string s2;
    int ans;
};

int main()
{
    vector<TestCase> tests = {
        {"LOVE", "MOVIE", 2},
        {"dinitrophenylhydrazine", "acetylphenylhydrazine", 6},
        {"dinitrophenylhydrazine", "benzalphenylhydrazone", 7},
    };

    for (const auto& test : tests)
    {
        int dist = editDP(test.s1, test.s2);
        printf("ANS: %i - %s (%i)\n", dist, dist == test.ans ? "OK" : "WRONG ANSWER", test.ans);
    }

    return 0;
}
