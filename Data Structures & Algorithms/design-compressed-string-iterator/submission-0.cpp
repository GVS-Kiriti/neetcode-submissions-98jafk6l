class StringIterator {
public:
    vector<char>a;
    vector<int>b;
    int siz;
    int point = 0;
    StringIterator(string compressedString) {
        int len = compressedString.size();
        int p = 0;
        while(p<len){
            a.push_back(compressedString[p]);
            p++;
            string curr = "";
            while(p<len && compressedString[p]<='9' && compressedString[p]>='0'){
                curr+=compressedString[p];
                p++;
            }
            b.push_back(stoi(curr));
        }
        siz = a.size();
    }
    
    char next() {
        if(point>=siz)return ' ';
        char ret = a[point];
        b[point]--;
        if(b[point]==0)point++;
        return ret;
    }
    
    bool hasNext() {
        if(point>=siz)return false;
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
