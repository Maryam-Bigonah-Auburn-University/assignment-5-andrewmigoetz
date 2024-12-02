#include <iostream>
#include <cstring>
#include <string>

using namespace std;     // Standard namespace

int main() {
    // Take in the input line
    cout<<"Enter a line of text: "<< endl;
    string input;
    getline(cin, input);
    string output;
    string word;
    bool capital=false;

    // For every character in the input, execute the following:
    for (size_t i=0;i<=input.size();++i){
        // If character is a letter, add it to string
        if(isalpha(input[i])){
            // If the character is a capital letter, set the bool capital to true
            if(word.empty()&&isupper(input[i])){
                capital=true;
            }
            word+=input[i];
        }
        // If character is the end of a word (a space or punctuation), evaluate the full word
        else{
            if(!word.empty()){
                // Replace all four letter words with "Love" or "love" depending on capital bool
                if(word.size()==4){
                    if(capital){
                        output+="Love";
                    }
                    else{
                        output+="love";
                    }
                }
                // Add word to output
                else{
                    output+=word;
                }
                // Reset word string and capital bool
                word.clear();
                capital = false;
            }
            //Add space or punctuation to output
            if(i<input.size()){
                output+=input[i];
            }
        }
    }
    // Return new output sentence
    cout << output << endl;
    return 0;
}
