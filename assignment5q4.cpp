#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Void method answerQuestion uses input stream and gets answer from specified input file
void answerQuestion(ifstream&input){
    bool exit=false;
    string question, answer;
    // While the user hasn't entered exit, get answer line and output
    while(!exit){
        cout << "What is your question? (Type 'exit' to quit)" << endl;
        getline(cin, question);
        if(question=="exit") {
            exit=true;
            continue;
        }
        getline(input, answer);
        cout<<answer<<endl;
    }
}

int main(){
    // Declare file stream and open the file
    ifstream inStream;
    inStream.open("C:\\Users\\andre\\CLionProjects\\untitled3\\answers.txt");
    answerQuestion(inStream);
    return 0;
}
