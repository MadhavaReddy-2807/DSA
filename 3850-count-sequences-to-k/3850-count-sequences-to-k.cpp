class freq
{
public:
    int two;
    int three;
    int five;
    freq()
    {
        two = 0;
        three = 0;
        five = 0;
    }
};

int spf(int n)
{
    if (n == 1) return 1;
    if (n % 2 == 0)
        return 2;
    for (int i = 3; 1LL * i * i <= n; i += 2)
    {
        if (n % i == 0)
            return i;
    }
    return n;
}

bool check(freq &numfreq, freq &denfreq, long long k)
{
    if (numfreq.two < denfreq.two ||
        numfreq.three < denfreq.three ||
        numfreq.five < denfreq.five)
        return false;

    int two = numfreq.two - denfreq.two;
    int three = numfreq.three - denfreq.three;
    int five = numfreq.five - denfreq.five;

    while (two && (k % 2 == 0))
    {
        k /= 2;
        two--;
    }

    while (three && (k % 3 == 0))
    {
        k /= 3;
        three--;
    }

    while (five && (k % 5 == 0))
    {
        k /= 5;
        five--;
    }

    return (spf(k) == 1 && two == 0 && three == 0 && five == 0);
}

void add(freq &a, freq &b)
{
    a.two += b.two;
    a.three += b.three;
    a.five += b.five;
}

void sub(freq &a, freq &b)
{
    a.two -= b.two;
    a.three -= b.three;
    a.five -= b.five;
}

unordered_map<int, freq> mp;
unordered_map<uint64_t, int> dp;

uint64_t getKey(int i, freq &numfreq, freq &denfreq)
{
    uint64_t key = i;

    key = key * 40 + numfreq.two;
    key = key * 20 + numfreq.three;
    key = key * 20 + numfreq.five;

    key = key * 40 + denfreq.two;
    key = key * 20 + denfreq.three;
    key = key * 20 + denfreq.five;

    return key;
}

int func(vector<int> &nums, int i, freq &numfreq, freq &denfreq, long long k)
{
    if (i == nums.size())
        return check(numfreq, denfreq, k);

    uint64_t key = getKey(i, numfreq, denfreq);

    auto it = dp.find(key);
    if (it != dp.end())
        return it->second;

    int ans = 0;

    // skip
    ans += func(nums, i + 1, numfreq, denfreq, k);

    // multiply
    add(numfreq, mp[nums[i]]);
    ans += func(nums, i + 1, numfreq, denfreq, k);
    sub(numfreq, mp[nums[i]]);

    // divide
    add(denfreq, mp[nums[i]]);
    ans += func(nums, i + 1, numfreq, denfreq, k);
    sub(denfreq, mp[nums[i]]);

    return dp[key] = ans;
}

freq find(int n)
{
    freq rough;

    while (n % 2 == 0)
    {
        rough.two++;
        n /= 2;
    }

    while (n % 3 == 0)
    {
        rough.three++;
        n /= 3;
    }

    while (n % 5 == 0)
    {
        rough.five++;
        n /= 5;
    }

    return rough;
}

class Solution
{
public:
    int countSequences(vector<int> &nums, long long k)
    {
        dp.clear();
        dp.reserve(1 << 20);

        mp.clear();
        mp.reserve(8);

        freq numfreq;
        freq denfreq;

        for (int i = 2; i <= 6; i++)
            mp[i] = find(i);

        return func(nums, 0, numfreq, denfreq, k);
    }
};