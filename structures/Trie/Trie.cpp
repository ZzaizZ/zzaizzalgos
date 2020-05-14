#include <bits/stdc++.h>

using namespace std;

/**
 * @brief The TrieNode struct
 * Структура, описывающая узел префиксного дерева
 */
struct TrieNode
{
    TrieNode() :
        end(false)
    {}
    /**
     * @brief m
     * Структура, хранящяя соответствие:
     * текущий символ -> дочерний узел
     */
    unordered_map<char, TrieNode*> m;
    /**
     * @brief end
     * Является ли текущий узел концом слова
     */
    bool end;
};

/**
 * @brief The Trie class
 * Класс префиксного дерева. Построен на указателях
 * Такая реализация выигрывает по памяти у реализации на векторах.
 * TODO: по хорошему только надо ещё в деструкторе все узлы подчищать.
 */
class Trie {
public:
    /** Initialize your data structure here. */
    Trie()
    {}

    /** Inserts a word into the trie. */
    void insert(const string word) {
        TrieNode* aux = &root;
        for (char c : word)
        {
            if (!aux->m[c])
                aux->m[c] = new TrieNode();
            aux = aux->m[c];
        }
        aux->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* aux = &root;
        for (char c : word)
        {
            if (!aux->m[c])
                return false;
            aux = aux->m[c];
        }
        if (!aux->end)
            return false;
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* aux = &root;
        for (char c : prefix)
        {
            if (!aux->m[c])
                return false;
            aux = aux->m[c];
        }
        return true;
    }
private:
    TrieNode root;
};

int main()
{
    Trie t;

    t.insert("apple");
    printf("apple: %i, app: %i, startsWith(app): %i\n", t.search("apple"), t.search("app"), t.startsWith("app"));
    t.insert("app");
    printf("app: %i, lol: %i\n", t.search("app"), t.search("lol"));
    t.insert("lol");
    printf("lol: %i\n", t.search("lol"));

    return 0;
}
