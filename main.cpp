#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    while(true)
    {
        string command;
        cout << "\n\nPress 1 to convert dna.txt into rna.txt\n: ";
        cin >> command;

        if(command == "1") // CONVERT DNA INTO RNA
        {
            string rna = "";
            cout << "Converting dna.txt into rna.txt\n";
            ifstream t("dna.txt");
            stringstream buffer;
            buffer << t.rdbuf();

            string dna = buffer.str();
            string to_add;

            for(int i = 0; i< dna.length(); i++)
            {
                if(dna[i] == 'A')
                {
                    to_add = 'U';
                }
                else if(dna[i] == 'T')
                {
                    to_add = 'A';
                }
                else if(dna[i] == 'G')
                {
                    to_add = 'C';
                }
                else if(dna[i] == 'C')
                {
                    to_add = 'G';
                }

                rna += to_add;
                cout << to_add;
            }
            ofstream rna_file;
            rna_file.open("rna.txt");
            rna_file << rna;
            rna_file.close();
        }
    }
}
