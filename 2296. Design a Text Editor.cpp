class TextEditor {
public:
    
    list<char> l;
    list<char>::iterator i;
    
    TextEditor() {
        i = l.end();
    }
    
    void addText(string text) {
        for (auto c : text) {
            i = l.insert(i, c);
            ++i;
        }
    }
    
    int deleteText(int k) {
        int ans = 0;
        while (k-- && i!=l.begin()) {
            --i;
            i = l.erase(i);
            ++ans;
        }
        return ans;
    }
    
    string last(list<char>::iterator j) {
        string ans;
        int k = 10;
        while (k-- && j!=l.begin()) {
            --j;
            ans += *j;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string cursorLeft(int k) {
        while (k-- && i!=l.begin()) {
            --i;
        }
        return last(i);
    }
    
    string cursorRight(int k) {
        while (k-- && i!=l.end()) {
            ++i;   
        }
        return last(i);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */