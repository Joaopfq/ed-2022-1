#include <iostream>

using namespace std;

int enter(string& text, int cursor){
    text.insert(cursor, "\n");
    return ++cursor;
}

int backspace(string& text, int cursor){
    if(cursor == 0)
        return 0;

    text.erase(cursor - 1, 1);
    return --cursor;
}

void erase(string& text, int cursor){
    if(cursor == (int)text.size())
        return;
        
    text.erase(cursor, 1);
}

int add(string& text, int cursor, char c){
    text.insert(cursor, 1, c);
    return ++cursor;
}

int right(string& text, int cursor){
    if(cursor == (int)text.size())
        return cursor;

    return ++cursor;
}

int left(int cursor){
    if(cursor == 0)
        return cursor;

    return --cursor;
}

int main(){
    string text{}, alt{};
    cin >> text;
    int cursor = text.size();

    while(true){
        cin >> alt;
        for(char letter : alt){
            if(letter == 'R')
                cursor = enter(text, cursor);
            else if(letter == 'B'){
                cursor = backspace(text, cursor);
            }
            else if(letter == 'D'){
                erase(text, cursor);
            }
            else if(letter == '>'){
                cursor = right(text, cursor);
            }
            else if(letter == '<'){
                cursor = left(cursor);
            } else{        
                cursor = add(text, cursor, letter);
            }
        }

        text.insert(cursor, 1, '|');
        cout << text << endl;
        text.erase(cursor, 1);
        
    }
}