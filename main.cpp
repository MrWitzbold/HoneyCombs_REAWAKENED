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
        cout << "Press 2 to generate report.txt on amino-acids (needs rna.txt)\n: ";
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
        else if(command == "2") // GENERATE AMINO-ACID PERCENTAGES
        {
            string amino_acids[28] = {"Phenylysine", "Leucine", "Isoleucine", "Methionine", "Valine", "Serine", "Threonine", "Alanine", "Tyrosine", "Tryptophan", "Histidine", "Glutamine", "Asparagine", "Lysine", "Aspartic acid", "Glutamic acid", "Arginine", "Cysteine", "Proline", "Glutamine", "Arginine", "Histidine", "Glutamine", "Glutamine", "Glutamine", "Glutamine", "Glutamine", "Glutamine"};
            string amino_acid_codons[25][6] = {{"UUU", "UUC", "", "", "", ""}, {"UUA", "UUG", "CUU", "CUC", "CUA", "CUG"}, {"AUU", "AUC", "AUA", "", "", ""}, {"GUU", "GUC", "GUA", "GUG", "", ""}, {"UCU", "UCC", "UCA", "UCG", "AGU", "AGC"}, {"CCU", "CCC", "CCA", "CCG", "", ""}, {"ACU", "ACC", "ACA", "ACG", "", ""}, {"GCU", "GCC", "GCA", "GCG", "", ""}, {"UAU", "UAC", "", "", "", ""}, {"CAU", "CAC", "", "", "", ""}, {"AAU", "AAC", "", "", "", ""}, {"GAU", "GAC", "", "", "", ""}, {"UGU", "UGC", "", "", "", ""}, {"CGU", "CGC", "CGA", "CGG", "AGA", "AGG"}, {"GGU", "GGC", "GGA", "GGG", "", ""}, {"UAA", "UAG", "UGA", "", "", ""}, {"CAA", "CAG", "", "", "", ""}, {"AAA", "AAG", "", "", "", ""}, {"GAA", "GAG", "", "", ""}, {"CGU", "CGC", "CGA", "CGG", "AGA", "AGG"}, {"GGU", "GGC", "GGA", "GGG", "", ""}, {"GGU", "GGC", "GGA", "GGG", "", ""}, {"GGU", "GGC", "GGA", "GGG", "", ""}, {"GGU", "GGC", "GGA", "GGG", "", ""}, {"GGU", "GGC", "GGA", "GGG", "", ""}};
        }
    }
}
