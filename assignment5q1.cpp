#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    cout << "Enter a sentence of up to 100 characters: " << endl;
    char next;
    string sentence;
    int num_char = 0;
    // Assuming sentence ends with period, iterate through the characters in the sentence until 100 characters or period is reached.
    while((next=cin.get())!='.'&&num_char<100) {
        num_char++;
        // Don't add whitespace if the next character and last character added to the new sentence are both whitespace
        if(!sentence.empty()&&iswspace(next)&&iswspace(sentence[sentence.size()-1])) {
            continue;
        }
        // If next character is new line, replace with space.
        if(next=='\n') {
            next=' ';
        }
        // Keep adding letters as lowercase
        sentence+=tolower(next);
    };
    // Remove whitespace at front of sentence
    if(iswspace(sentence[0])) {
        sentence.erase(0,1);
    }
    // Remove whitespace at end of sentence
    if(iswspace(sentence[sentence.size()-1])) {
        sentence.erase(sentence.size()-1,1);
    }
    // Captalize first letter in sentence
    sentence[0]=toupper(sentence[0]);
    // Add a period at the end of the sentence
    sentence+='.';
    // Output sentence
    cout<<'\n'<<sentence;
    return 0;
}
