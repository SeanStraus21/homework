#include<string>
using namespace std;

class tex{
public:
	GLfloat data[160][160][3];
	tex(){
	}
};

tex get_texture(string path){
	float input;
	tex output;
	ifstream myfile;
	myfile.open(path);
	if (myfile.is_open()){
		for (int i = 0; i < 160; i++)
		{
			for (int j = 0; j < 160; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					myfile >> input;
					output.data[i][j][k] = input / 255;
				}
			}
		}
		myfile.close();
	}else{
		cout<<"unable to open file" <<endl;
	}
	return output;
}

