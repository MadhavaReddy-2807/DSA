class Encrypter {
public:
map<char,int>key_map;
vector<char>keys;
vector<string>values;
map<string,vector<int>>value_map;
unordered_set<string>dict;
unordered_map<string, int> encryptedCount;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++)
        {
            key_map[keys[i]]=i;
        }
        this->keys=keys;
        this->values=values;
        for(auto s:dictionary)
        {
            this->dict.insert(s);
        }
        for(int i=0;i<values.size();i++)
        {
            value_map[values[i]].push_back(i);
        }
    // In constructor:
    for (auto& word : dictionary) {
        string enc = encrypt(word);
        if(enc!="")
        {
        encryptedCount[enc]++;
        }
    }
    }
    
    string encrypt(string word1) {
        string res="";
        for(int i=0;i<word1.length();i++)
        {
            if(key_map.count(word1[i]))
            {
            int index=key_map[word1[i]];
            res+=values[index];
            }
            else
            {
                return "";
            }
        }
        return res;
    }
    int func(int index,string&word,map<string,vector<int>>&value_map,string&s,vector<char>&keys)
    {
        if(index>=word.length())
        {
            if(dict.find(s)!=dict.end())
            {
                return 1;
            }
            return 0;
        }
        string rough="";
         rough+=word[index];
        rough+=word[index+1];
        vector<int>indices=value_map[rough];
        int ans=0;
        for(int i=0;i<indices.size();i++)
        {
            s.push_back(keys[indices[i]]);
            ans+=func(index+2,word,value_map,s,keys);
            s.pop_back();
        }
        return ans;
    }
    int decrypt(string word) {
        
       return encryptedCount[word];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */