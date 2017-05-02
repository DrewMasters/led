#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctype.h>

using namespace std;

int main(int argc, char **argv){
	string input, filename, tmp, output[7];
	vector <string *> characters;
	vector <char> fnames;
	string *tmp_c;
	int i, j, k, l, pos;
	ifstream infile,tmpfile;

	if (argc !=2) {
		fprintf(stderr,"./generator input_string\n");
		exit(1);
	}
	input = string(argv[1]);
	if (input.size() > 100) {
		fprintf(stderr,"input string can only be up to 100 characters\n");
		exit(1);
	}
	
	/*
	 * read in all characters from files stored in
	 * the characters directory. They define how
	 * each character is to appear. They are all 7x10.
	 */

	infile.open("./filenames.txt",ios::in);
	while(getline(infile,filename)){
		tmpfile.open("characters/"+filename,ios::in);
		if (tmpfile.is_open()) {
			fnames.push_back(filename[0]);
			i=0;
			tmp_c = new string[7];
			while (getline(tmpfile,tmp)){
				tmp_c[i]=tmp;
				i++;
			}
			i=0;
			characters.push_back(tmp_c);

			tmpfile.close();
		}
		else cout << "file can't open\n";
	}
	infile.close();
	
	/*
	 * build the output line by line. Since characters span multiple
	 * lines of output you will have to build the first line with the first
	 * line of all the characters an repeat for all 7 lines
	 */
	for (i=0; i<7*input.size();i++){
		j = i/input.size();
		k = i%input.size();
	
		for (l=0; l<fnames.size();l++){
			if (input[k]!=' '){
			if (toupper(input[k])==fnames[l]){
				pos = l;
				break;
			}
			}
			else{
				pos = fnames.size()-1;
			}
		}

		output[j] = output[j] + characters[pos][j];
	}

	/* 
	 * output result of previous loop line by line
	 */

	for (i=0; i<7; i++){
		cout << output[i] << endl;
	}
}
