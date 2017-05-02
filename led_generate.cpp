#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
	string input, filename, tmp;
	vector <string *> characters;
	vector <string> fnames;
	string *tmp_c;
	int i, j;
	ifstream infile,tmpfile;

	if (argc !=2) fprintf(stderr,"./generator input_string\n");
	input = string(argv[1]);
	if (input.size() > 100) fprintf(stderr,"input string can only be up to 100 characters\n");

	infile.open("./filenames.txt",ios::in);
	while(getline(infile,filename)){
		tmpfile.open("characters/"+filename,ios::in);
		if (tmpfile.is_open()) {
			fnames.push_back(filename);
			i=0;
			tmp_c = new string[7];
			//for (i=0;i<70;i++)tmp_c[i]=0;
			while (getline(tmpfile,tmp)){
				/*for (i=0; i<10; i++){
					if (tmp[i]=='.') {
						tmp_c[j]=1;
					}
					else {
						tmp_c[j]=0;
					}
					j++;
				}*/
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

	cout << characters.size() << endl;

	for (i=0; i<characters.size();i++){
		cout << fnames[i] << endl;
		tmp_c = characters[i];
		for (j=0; j<7;j++){
			//for (int k=0; k<10; k++){
			//	cout << tmp_c[j*10+k];
			//}
			//cout << endl;
			cout << tmp_c[j] << endl;
		}
		cout << endl << endl;
	}
}
