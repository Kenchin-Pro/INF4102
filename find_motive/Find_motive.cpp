#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
	string file_path = argv[1];
	string motive = argv[2];
	ifstream Fichier_ouvert;
	Fichier_ouvert.open(file_path);
	int nombre_de_motif = 0;

	if (Fichier_ouvert)
	{
		string ligne;
		while (getline(Fichier_ouvert, ligne))
		{
			istringstream iss(ligne);
			do
			{
				string subs;
				iss >> subs;
				if (subs.find(motive) != std::string::npos)
				{
					nombre_de_motif++;
				}
			} while (iss);
		}
	}
	else
	{
		cout << "The file " << file_path << " could not be opened." << endl;
	}
	Fichier_ouvert.close();
	cout << "The file " << file_path << " contains " << nombre_de_motif << " words containing the motive " << motive << "." << endl;
	return 0;
}