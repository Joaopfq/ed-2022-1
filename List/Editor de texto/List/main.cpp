#include <iostream>
#include <list>

using namespace std;

list<char>::iterator enter(list<char>& text, list<char>::iterator cursor){
    text.insert(cursor, '\n');
    return cursor;
}

list<char>::iterator backspace(list<char>& text, list<char>::iterator cursor){
    if(cursor == text.begin())
        return text.begin();

    return text.erase(--cursor);
}

list<char>::iterator dell(list<char>& text, list<char>::iterator cursor){
    if(cursor == text.end())
        return text.end();
        
    return text.erase(cursor);
}

list<char>::iterator add(list<char>& text, list<char>::iterator cursor, char c){
    text.insert(cursor, c);
    return cursor;
}

list<char>::iterator right(list<char>& text, list<char>::iterator cursor){
    if(cursor == text.end())
        return cursor;

    return ++cursor;
}

list<char>::iterator left(list<char>& text, list<char>::iterator cursor){
    if(cursor == text.begin())
        return cursor;

    return --cursor;
}

void show(list<char> text){
    for(char letter : text){
        cout << letter;
    }
    cout << endl;
}

int main(){
    list<char> text{};
    string alt{};
    list<char>::iterator cursor = text.begin();

    cin >> alt;
    for(char letter : alt){
        
        if(letter == 'R')
            cursor = enter(text, cursor);
        else if(letter == 'B'){
            cursor = backspace(text, cursor);
        }
        else if(letter == 'D'){
            cursor = dell(text, cursor);
        }
        else if(letter == '>'){
            cursor = right(text, cursor);
        }
        else if(letter == '<'){
            cursor = left(text, cursor);
        } else{        
            cursor = add(text, cursor, letter);
        }
    }
        text.insert(cursor, '|');
        show(text);
}