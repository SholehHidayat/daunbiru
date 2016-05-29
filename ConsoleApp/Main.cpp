#include<cmath>
#include<cstdio>
#include<iomanip>
#include<iostream>
#include<vector>
#include<string>
#include <fstream>

using namespace std;

bool fexists(const std::string& filename) {
  ifstream ifile(filename.c_str());
  return (bool)ifile;
}

string input_file;
string rv = "";
vector<unsigned int> squares;
vector<unsigned int> res_value;
int main(){
	for(int i = 0; i < 10000; i++)
			squares.push_back(i * i);

	cout << "Please enter file name as input: ";
	cin >> input_file;
	
	if(fexists(input_file)){
		ifstream file(input_file);
		string str; int i = 0;
		while (std::getline(file, str)){i++;}

		if(i != 1){
			cout << "Lines number of file is not valid";
		}
		else{
			bool isValid = true;
			for(unsigned int i = 0; i < str.length(); i++){
				isValid = !isalpha(str[i]);
			}

			if(!isValid){
				cout << "Parameter is not valid";
			}
			else{
				int n = stoi(str);
				if((n % 2 != 0) || (n > 8)){
					cout << "Parameter is not valid";
				}
				else{
					for(unsigned int i = 0; i < squares.size(); i++) {
						if(squares[i] >= (unsigned int) pow(10, n)) break;
						if(pow(squares[i] % (unsigned int) pow(10, n / 2) + squares[i] / (unsigned int) pow(10, n / 2), 2) == squares[i]) {
							res_value.push_back(squares[i]);
						}
					}

					if(n != 0)
					for(unsigned int i = 0; i < res_value.size(); i++){
						string s = string(n - to_string(res_value[i]).length(), '0') + to_string(res_value[i]);
						s += i == res_value.size() - 2 ? ", dan " : (i == res_value.size() - 1 ? "" : ", ");
						rv += s;
					}
					else{
						rv = to_string(res_value[0]);
					}

					cout << rv ;
					ofstream outputfile;
					outputfile.open ("output.txt");
					outputfile << rv;
					outputfile.close();
				}
			}
		}
	}
	else{
		cout << "File name is not valid";
	}

	while(true){/*do nothing..!!*/}
}

