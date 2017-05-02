#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctype.h>

using namespace std;

int main(int argc, char **argv){
	string input[7], filename, tmp, output[7];
	vector <string> characters;
	vector <char> fnames;
	string *tmp_c;
	int i, j, k, l, pos;
	ifstream infile,tmpfile;
	vector <string> p_input; //processed input

	i=0;
	while(cin){
		getline(cin,input[i]);
		i++;
	}

	if (argc !=1) {
		fprintf(stderr,"./reader\n");
		exit(1);
	}

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
			tmp="";
			for (i=0;i<7;i++) {
				if (tmp_c[i].size()!=10){
					cout << "line: " << i << " in " << filename[0] << endl;
				}
				tmp = tmp+tmp_c[i];
			}
			characters.push_back(tmp);
			tmp="";

			tmpfile.close();
		}
		else cout << "file can't open\n";
	}
	infile.close();
	tmp="";
	for (i=0;i<input[0].size();i=i+10){
		for (k=0;k<7;k++){
			tmp = tmp + input[k].substr(i,10);
		}
		p_input.push_back(tmp);
		tmp="";
	}

	//cout << p_input.size() << endl;;

	for (i=0; i<p_input.size();i++){
		for (j=0; j<characters.size(); j++){
			/*cout << p_input[i] << endl;
			cout << characters[j] << endl;
			cout << (p_input[i]==characters[j]) << endl;
			cout << p_input[i].size() << endl;
			cout << characters[j].size() << endl;
			cout << endl;
			*/
			if (p_input[i]==characters[j]) {
				pos = j;
				//cout << "pos: " << pos << endl;
				break;
			}
		}
		if (fnames[pos]=='s') cout << " ";
		else cout << fnames[pos];
		//cout << p_input[i] << endl;
	}
	cout << endl;
}
