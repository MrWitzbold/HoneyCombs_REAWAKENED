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
            string amino_acids[25] = {"Phenylalanine", "Leucine", "Isoleucine", "Methionine", "Valine", "Serine", "Proline", "Threonine", "Alanine", "Tyrosine", "Stop (Ochre)", "Stop (Amber)", "Histidine", "Glutamine", "Asparagine", "Lysine", "Aspartic Acid", "Glutamic Acid", "Cysteine", "Stop (Opal)", "Tryptophan", "Arginine", "Serine", "Arginine", "Glycine"};
            int amino_acid_count[28] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int amino_acid_total = 0;
            string amino_acid_codons[25][6] = {{"UUU", "UUC"}, {"UUA", "UUG", "CUU", "CUC", "CUA", "CUG"}, {"AUU", "AUC", "AUA", "AUG"}, {"GUU", "GUC", "GUA", "GUG"}, {"UCU", "UCC", "UCA", "UCG"}, {"CCU", "UCG", "CCU", "CCC", "CCA", "CCG"}, {"ACU", "ACC", "ACA", "ACG"}, {"GCU", "GCC", "GCA", "GCG"}, {"UAU", "UAC"}, {"UAA"}, {"UAG"}, {"CAU", "CAC"}, {"CAA", "CAG"}, {"AAU", "AAC"}, {"AAA", "AAG"}, {"GAU", "GAC"}, {"GAA", "GAG"}, {"UGU", "UGC"}, {"UGA"}, {"UGG"}, {"CGU", "CGC", "CGA", "CGG"}, {"AGU", "AGC"}, {"AGA", "AGG"}, {"GGU", "GGC"}, {"GGA", "GGG"}};

            ifstream t("rna.txt");
            stringstream buffer;
            buffer << t.rdbuf();
            string rna = buffer.str();

            for(int i = 0; i < rna.length(); i+=3)
            {
                for(int j = 0; j < 25; j++)
                {
                    if(rna.substr(i, 3) == amino_acid_codons[j][0])
                    {
                        amino_acid_count[j]++;
                        amino_acid_total++;
                    }
                    else if(rna.substr(i, 3) == amino_acid_codons[j][1])
                    {
                        amino_acid_count[j]++;
                        amino_acid_total++;
                    }
                    else if(rna.substr(i, 3) == amino_acid_codons[j][2])
                    {
                        amino_acid_count[j]++;
                        amino_acid_total++;
                    }
                    else if(rna.substr(i, 3) == amino_acid_codons[j][3])
                    {
                        amino_acid_count[j]++;
                        amino_acid_total++;
                    }
                    else if(rna.substr(i, 3) == amino_acid_codons[j][4])
                    {
                        amino_acid_count[j]++;
                        amino_acid_total++;
                    }
                    else if(rna.substr(i, 3) == amino_acid_codons[j][5])
                    {
                        amino_acid_count[j]++;
                        amino_acid_total++;
                    }
                }
            }

            ofstream report;
            report.open("report.txt");
            report << "=================== Amino Acid Percentage =================== \n";
            for(int i = 0; i < 28; i++)
            {
                report << amino_acids[i] << ": " <<(double)amino_acid_count[i]/amino_acid_total*100 << "%\n\n";
                if(amino_acids[i] == "Glycine")
                {
                    break;
                }
            }
            report.close();
        }
    }
}
