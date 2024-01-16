class RandomizedSet
{
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (search(val))
            return false;
        s.push_back(val);
        m.insert({val, s.size() - 1});
        return true;
    }

    bool remove(int val)
    {
        if (!search(val))
            return false;
        auto it = m.find(val);
        s[it->second] = s[s.size() - 1];
        s.pop_back();
        m[s[it->second]] = it->second;
        m.erase(val);
        return true;
    }

    int getRandom()
    {
        return s[rand() % s.size()];
    }

private:
    std::unordered_map<int, int> m;
    std::vector<int> s;

    bool search(int val)
    {
        return (m.find(val) != m.end());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */