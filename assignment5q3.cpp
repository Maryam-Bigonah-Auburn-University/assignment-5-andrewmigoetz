#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Void function merges input files file1 and file2 into output file file3
void merge(ifstream &file1, ifstream &file2, ofstream &file3){
    int num1, num2;
    // Variables done1 and done2 are set to false until the files are done being read
    bool done1=false, done2=false;
    //Store the current numbers from each file
    done1=!(file1>>num1);
    done2=!(file2>>num2);

    // While both files haven't been read fully, execute the following:
    while(!done1||!done2){
        //If the number from file1 is less than the number from file2 or file2 is done, add num1 to file 3
        if(!done1&&(done2||num1<=num2)){
            file3<<num1<<" ";
            done1=!(file1>>num1);
        }
        // Otherwise, if num2<num1 or file1 is done, add num2 to file3
        else if(!done2&&(done1||num2<num1)) {
            file3<<num2<< " ";
            done2=!(file2>>num2);
        }
    }
}

int main() {
    // Open the input and output files using absolute path directory
    ifstream file1("C:\\Users\\andre\\CLionProjects\\untitled3\\file1.txt");
    ifstream file2("C:\\Users\\andre\\CLionProjects\\untitled3\\file2.txt");
    ofstream file3("C:\\Users\\andre\\CLionProjects\\untitled3\\file3.txt");
    // Use the merge function
    merge(file1, file2, file3);
    return 0;
}
