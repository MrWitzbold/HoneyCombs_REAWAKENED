# DNA → RNA → Amino-Acid Report 🧬

A tiny C++ bioinformatics experiment that takes a DNA sequence, transcribes it into RNA, and then tries to count the amino-acid codons it finds.

In other words: give it a text file full of genetic letters, press `1`, press `2`, and let a small command-line program play molecular biologist.

**Educational project, not a validated genetics tool.** The code is a snapshot of learning how to work with strings, files, loops, and biological lookup tables in C++.

## What it does

The program keeps showing a menu until you decide to close it the old-fashioned way: stop the program.

### `1` — Transcribe DNA into RNA

- Reads `dna.txt`.
- Processes the sequence one character at a time.
- Writes the resulting sequence to `rna.txt`.
- Prints the generated RNA directly to the terminal, because apparently the molecules wanted a live performance.

The substitutions in the code are:

| DNA base | Output |
|---|---|
| `A` | `U` |
| `T` | `A` |
| `G` | `C` |
| `C` | `G` |

This is the program's transcription rule set. It expects the input to use uppercase letters and does not currently validate the file or clean up unexpected characters.

### `2` — Generate an amino-acid report

- Reads `rna.txt`.
- Splits the sequence into consecutive groups of three letters (codons).
- Compares each codon against a hard-coded lookup table.
- Writes percentages to `report.txt`.

The report is intended to show how often each listed amino-acid category appears among the codons the program recognizes.

## Files in the experiment

```text
.
├── main.cpp     # The C++ program
├── dna.txt      # Input DNA sequence (you provide this)
├── rna.txt      # RNA sequence produced by option 1
└── report.txt   # Codon-count percentage report produced by option 2
```

`rna.txt` is an intermediate file, so run option `1` before option `2` if you want the report to use the latest transcription.

## Build and run

You need a C++ compiler such as `g++`.

```bash
g++ main.cpp -o dna-rna
./dna-rna
```

On Windows, run the resulting executable from the folder containing `dna.txt`.

Example input file (`dna.txt`):

```text
ATGCGT
```

Then choose `1` in the menu to create `rna.txt`, and choose `2` to attempt the report.

## A few important scientific footnotes

This is a learning project, and the current implementation has some rough edges worth knowing about before trusting its output:

- **The lookup table needs correction.** Some codons are missing, duplicated, or assigned to the wrong categories, and the amino-acid names do not line up reliably with the codon table.
- **The report loop has an array-bounds bug.** `amino_acids` has 25 entries, but the code attempts to access up to 28. That can cause undefined behavior.
- **Percentages can be invalid.** If no codons are recognized, the total is zero and the percentage calculation divides by zero.
- **Input is assumed to be tidy.** Lowercase letters, whitespace, invalid bases, missing files, and incomplete final codons are not handled robustly.
- **It counts codons, not a complete translated protein.** There is no start-codon search, reading-frame selection, or stop-codon termination. It simply checks chunks of three characters from the beginning of the file.
- **The transcription is a simplified rule.** Real biological workflows involve more context than a character-by-character substitution, and this program should not be used for research or medical interpretation.

These are not reasons to throw the project into the nearest biohazard bin. They're a useful checklist for the next version.

## Ideas for a sequel

- Validate that the input contains only expected DNA bases.
- Ignore whitespace and support lowercase input.
- Use one well-tested codon-to-amino-acid map instead of parallel arrays.
- Correct the standard genetic code, including all stop codons.
- Report unknown or incomplete codons clearly.
- Handle missing files and empty sequences gracefully.
- Add tests using short sequences with known expected results.

## The vibe

This is a small, early C++ experiment at the intersection of programming and biology: file I/O, string processing, nested loops, and a hard-coded genetic code all in one place.

It is best treated as a learning artifact rather than a scientific instrument. The DNA is real enough to need careful handling; the report, for now, needs a little lab supervision.
