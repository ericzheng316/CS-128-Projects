# CS 128 Projects 

# 📚 项目文档全集

Welcome to CS 128 Project. Here is Eric.

<details>
<summary>📂 <strong>recitation-comment-stats</strong></summary>

### Mission
Your team is launching a new social media platform, but there's one problem — there's currently no way to track user engagement in comments! To fix this, you have been tasked with adding functionality to scan comments for user mentions and compile key statistics.

For this problem, you will implement the function ```GenerateCommentStats```, which identifies and analyzes users mentioned in a given set of social media comments. This function should be implemented in the file src/solution.cc, and the function declaration should be in includes/solution.hpp.

You may only include the following headers in your solution:
```cpp
"solution.hpp"
"comment_stats.hpp"
<cctype>
<vector>
<string>
<map>
<set>
```
Function: GenerateCommentStats
Define the following function:

```cpp
CommentStats GenerateCommentStats(const std::vector<std::string>& comments);
```
Your implementation of GenerateCommentStats will return a CommentStats object, which includes a map of how many times each user was mentioned and the most popular user mentions. Users are considered popular if they were mentioned >= 2, and the order at which they are added does not matter. Usernames should be converted to lowercase before adding them to the output struct's members. The CommentStats struct is provided for you in "comment_stats.hpp":

```cpp
struct CommentStats { std::map<std::string, int> mention_frequencies; std::vector<std::string> popular_mentions; };
```
Important Notes
What constitutes a username?
It starts with @
The username goes until it reaches whitespace, ```punctuation (!, ?, ,, ., ', @)```, or the end of the comment
Usernames have a length of at least 1 non-terminating character
Usernames are not case-sensitive (e.g. ```@DogLover123``` is the same as``` @doglover123```)
You will likely find the function std::tolower from cctype helpful.
If the given vector comments is empty, return an empty CommentStats object
Examples
Example 1:
Given the vector comments containing the following ```std::strings:```

```cpp
{ 
  "Great job @Ashley11 and @TheRealNithin on the presentation!", 
  "What do you think about @_Mei_'s new post? It seems to rival @Victor22's content", 
  "I haven't seen that here before, you should tell @ashley11", 
  "@Victor22 have you seen the new @CatsFurever video? I think you would really like it!", 
  "@TheRealNithin @Victor22, you should collaborate more often!" 
}
```
The returned CommentStats object should contain the following two members:

mention_frequencies:
```{ {"@ashley11", 2}, {"@therealnithin", 2}, {"@_mei_", 1}, {"@victor22", 3}, {"@catsfurever", 1} }```
popular_mentions:
```{ "@victor22", "@ashley11", "@therealnithin" }```
The returned popular_mentions does not need to have any specific order

Example 2:
Given the vector comments containing the following ```std::strings:```

```cpp
{
  "Hey @@R0ckClimber and@ishaan4, what are your favorite gyms to go to?", 
  "@cupcak3Lover@MacaroonMania do you have any baking recommendations?", 
  "I think @ Samuel2 and @ishaan4 are in the same class" 
}
```
The returned CommentStats object should contain the following two members:

mention_frequencies:
```{ {"@r0ckclimber", 1}, {"@ishaan4", 2}, {"@cupcak3lover", 1}, {"@macaroonmania", 1} }```
popular_mentions:
```{ "@ishaan4" }```
Notice that @'s are only counted as mentions when at least 1 non-terminating character follows them.

How to compile and run driver.cc
To compile the executable, run the following command in the terminal that will create an executable named exec in your bin folder:

```$ make exec```

To run the executable, use:

```$ ./bin/exec```

How to compile and run tests.cc
To compile the tests, use the following command that will create an executable named tests in your bin folder:

```$ make tests```

To run the tests, use:

```$ ./bin/tests```
</details>


<details>
<summary>📂 <strong>starter-24c-student-record-reader-from-csv</strong></summary>

### Mission

You are given a comma-separated value (CSV) file containing information about students. Each line of the file contains the first name, last name (followed by a comma), UIN (an unsigned integer), a comma, and GPA (a floating-point number). For example,
```cpp
Pickles Whiskers, 1234, 4.0
Luna Coco, 5678, 3.67
Oliver Boots, 1357, 3.5
```
You will implement the function ```Student ReadStudentRecFromStream(std::istream& is)``` in ```solution.cc``` that reads a student's record from the passed input stream (```std::istream```), parses the data, and returns a Student object (see its definition in student.hpp) with the parsed information.

To call ```ReadStudentRecFromStream()``` you must first bind an input file to an std::ifstream and then pass that stream to your function. For example,
```cpp
std::ifstream ifs("./data/input.csv");
Student student = ReadStudentRecFromStream(ifs);
```
If the contents of ```"./data/input.csv" ``` are the example above, ```ReadStudentRecFromStream()``` will return a Student object containing the information for ```Pickles Whiskers, 1234, 4.0```.

Requirements:
The first and last names appear in the first column of each line in the input file, separated by a space. Since formatted reads in C++ are delimited by whitespace, you must perform two separate reads to extract the first and last names. Additionally, after reading it, you'll need to remove the comma at the end of the last name and then concatenate the first and last names into a single string, ensuring a space separates them.
After each formatted read, check if the read was successful by using ```is.fail()```. If this returns true, return an empty Student object (```return Student{};```). For example, ```is.fail()``` will return true if we attempt to read an int but the data type is ```char```:

```cpp
Oliver Boots, xyz, 3.5
If the input stream contains invalid data (e.g., missing commas, improperly formatted data), the function should return an empty Student object (return Student{};). For example,
Luna Coco, 5678? 3.67
```
The ```? ```following 5678 should be a comma. You can catch this formatting error by checking the value of the variable used to store the throwaway character after it is read.
```Oliver Boots! 1357, 3.5```
The ```!``` after Boots should be a comma. You can catch this error by checking the last character of the string used to store last name during the formatted read.
</details>

<details>
<summary>📂 <strong>starter-24c-starter-24c-buggy-tic-tac-toe</strong></summary>

### Mission  

In this assignment, you will debug and fix a simple Tic-Tac-Toe game written in C++. The provided code contains intentional bugs that you need to identify and correct to make the game function properly. You are required to use the visual debugger to step through the code, inspect variables, and uncover the issues.

Objectives
Practice using the visual debugger to uncover and fix programming errors.
Enhance problem-solving skills by identifying and correcting logical and syntax errors.
Requirements
Clone the starter code in VS Code and open the project in the CS 128 development environment:
github.com/cs128-illinois/starter-24c-buggy-tic-tac-toe
Familiarize yourself with the code:
Read through the code to understand its structure and logic.
Note the functions used for game mechanics, such as displaying the board, checking for a win, and handling player input.
Are there any implementation details missing?
Identify bugs using the visual debugger:
Run the program and observe its behavior.
Use breakpoints to pause execution at critical points in the code.
Step through the code line by line to monitor variable values and program flow.
Watch for discrepancies between expected and actual behavior.
Fix the bugs:
Modify the code to correct the identified issues. You must not change any function signatures nor their return types. You must not change any error messages printed to standard output/error.
You will need to expand the code in certain cases to implement missing behavior.
Accordingly, ensure that:
Players can enter their moves correctly.
The game accurately detects win conditions for both players.
The game recognizes a draw when the board is full without a winner.
Invalid inputs are handled gracefully with appropriate error messages.
Test thoroughly:
Play multiple games to test all possible scenarios, including wins, draws, and invalid inputs.
Use the debugger to inspect the state of the game after each move.
Document your findings and fixes:
In comments within the code, explain the bugs you found and how you fixed them.
Describe how the visual debugger helped you identify each issue.
Constraints
Do not change any provided function signatures and return types.
The program should prompt players to enter their moves in the format: ```row column```.
Rows and columns are zero-indexed (from ```0``` to ```2```).
Game Logic:
Each player takes their turn; alternate turns between Player X and Player O.
Correctly implement win condition checks for rows, columns, and diagonals.
Detect a draw when all cells are occupied without a winner.
Your solution must compile with ```clang++``` using the ```c++20``` standard, without errors when using the flags: ```-Wall -Wextra -Werror -pedantic -Wunused-variable -Wuninitialized```.
You may only include the following headers in your solution:
```"functions.hpp" <iostream> <limits> <vector>```
Good luck, and happy debugging!
</details>

<details>
<summary>📂 <strong>hawaiian-words</strong></summary>

### Mission


#### Provided for you

For this first MP, we have provided you with function declarations and descriptions for each of the functions you will be writing. We have also provided most of the test cases from the autograder with instructions on how to run the tests below.

In future MPs, we will provide gradually fewer helper functions and test cases, and you will be required to make your own. For future MPs, you may want to reference this MP for help with structuring your code and writing good test cases, so we highly recommend that you think about why the functions and test cases are set up the way they are.

#### Background
Words from languages that we are unfamiliar with can be difficult to pronounce correctly. Phonetic pronunciation guides can help make them more accessible to us. For this problem, you will write a program that produces phonetic pronunciations for Hawaiian words.

##### Hawaiian Characters
There are 12 valid characters in the Hawaiian language: ```a, e, i, o, u, p, k, h, l, m, n```, and ```w```. In addition to the Hawaiian characters, spaces and apostrophes are valid. Each Hawaiian word passed into our program must be inspected to ensure that only these characters compose them, because if an invalid character presents, we don’t have a valid Hawaiian word.

The consonants in the Hawaiian language are pronounced similarly to the English versions, though ```w```’s are pronounced with a ```w``` or ```v``` sound.

The vowels in the Hawaiian language are a, e, i, o, and u. These are pronounced as ah, eh, ee, oh, and oo respectively.

Vowel groups are also present in the Hawaiian language and will require additional rules. This means we can’t simply replace all a’s with ah, all e’s with eh, etc. We will consider the following Hawaiian vowel groups for this assignment: ai, ae, ao, au, ei, eu, iu, oi, ou, ui.

The pronunciations for all the characters and vowel groups can be found in the tables below.

In cases where a combination of vowels (e.g. oa) is not represented in the “vowels groups” table, each vowel is pronounced as an individual vowel. Accordingly, oa would be pronounced as oh-ah.

These rules allow us to create phonetic guides for Hawaiian words. For instance, aloha is pronounced as ah-loh-hah. As an example of the use of vowel groups, the word keiki (child), with ei pronounced as ay, sounds like kay-kee. The island of Maui is pronounced as mow-ee. Notice that in writing the pronunciation, the placement of the hyphen comes after a vowel or vowel group.

Pronunciation Guide
|Consonants| pronunce|
|:---|:---|
|p, k, h, l, m, n	|Pronounced like the English versions.|
w — start of word /after the letter 'a' |Either pronounced as a w or a v sound. We shall pronounce it as a w sound.|
w — after ‘i’ or ‘e’|	Pronounced as a v sound.|
w — after ‘u’ or ‘o’|  Pronounced as a w sound.|


|Vowels| pronunce|
|:---|:---|
a|	sounds like ah. e.g., like that in “father” (f-ah-ther)|
e|	sounds like eh. e.g., like that in “egg” (eh-gg)|
i|	sounds like ee. e.g., like that in “bee”|
o|	sounds like oh. e.g., like that in “obey” (oh bay)|
u|	sounds like oo. e.g., like that in “mood” (m oo d)|


Vowel Groups| pronunce|
|:---|:---|
ai|	sounds like eye. e.g., like that in “ice“|
ae|	sounds like eye. same as ai|
ao|	sounds like ow. e.g., like that in “how”|
au|	sounds like ow. same as ao|
ei|	sounds like ay. e.g., like that in “hay”|
eu|	sounds like eh-oo.|
iu|	sounds like ew.|
oi| sounds like oy.|
ou|	sounds like ow.|
ui|	sounds like ooey. e.g., like that in “gooey”|


#### Requirements
Your program will compute the pronunciation of the Hawaiian word passed into the function ```GetPronunciation```. Your program will accept a single non-empty ```std::string```containing a potential Hawaiian word and will return an std::string containing the pronunciation. If the passed argument is invalid (contains a character not part of the Hawaiian language), ```throw``` an ```std::invalid_argument``` exception.

You already know how to throw and catch exceptions in Java from CS 124; we'll cover this topic in C++ in more detail later in semester. For this MP, all you have to know is how to throw an exception. The first thing you'll need to do is ```#include <stdexcept>```. After including this header file, you would then throw an exception the type ```std::invalid_argument``` as follows:

```cpp
if (exceptional_case) {
  throw std::invalid_argument("Description of Problem");
}
```
In Hawaiian words:

spaces are breaks and should be kept intact when you write out the phonetics
an apostrophe is a hard stop and should also be kept intact when you write out the phonetics
there should be a hyphen (dash) after every vowel group or vowel unless it is at the end of a word or before an apostrophe
all characters in the pronunciation must be lowercase. ```std::tolower``` in ```<cctype>``` might prove helpful
Tip: remember that, in addition to the Hawaiian characters, spaces and apostrophes are valid

We will have you implement a variety of functions in this assessment. These functions are designed to help you break the problem into smaller and more manageable pieces, so we recommend starting with the simpler functions at the beginning of the table.

It might also be helpful to look at the diagram below to see how the functions fit together before starting to code your solution.

Your program must compile without warnings/errors when compiled with: clang++ using the -std=c++20 and the following flags -Wall -Wextra -Werror -pedantic

#### Functions to Implement

You must define each function below to spec, as your implementation of each function will be tested independently of the overall program.

|Function Signature	|Behavior Description|
|:---|:---|
```std::string StringToLower(const std::string& word)```|	This function takes in a string (word) and returns the result of making all characters in that word lowercase.|
```bool IsValidCharacter(const char& c)```|	This function takes in a lowercase character (c) and returns true if it’s a valid character in the Hawaiian language, false otherwise.|
```bool IsValidWord(const std::string& word)```	|This function takes in a lowercase string (word) and returns true if every character in word is a valid character in the Hawaiian language, false otherwise.|
```bool IsVowelGroup(const char& v1, const char& v2)```	|This function takes in two lowercase characters (v1 and v2) and returns true if the sequence v1 v2 is a vowel group according to the rules above, false otherwise.|
```bool IsVowel(const char& v)```|	This function takes in a lowercase character (v) and returns true if v is a vowel, false otherwise.|
```bool IsConsonant(const char& c)```|	This function takes in a lowercase character (c) and returns true if c is a consonant, false otherwise.|
```char ConsonantPronunciation(const char& c, const char& prev='\0')```	|This function takes in a valid lowercase consonant (c) and a valid lowercase character (prev) and returns the pronunciation for the consonant c, using prev if necessary (this will always be 1 character so it is returned as a char).|
```std::string VowelGroupPronunciation(const char& v1, const char& v2)```|	This function takes in two lowercase vowels that form a valid vowel group (v1 and v2) and returns the pronunciation for the vowel group made of the sequence v1 v2 (this will be more than 1 character so it is returned as a string).|
```std::string SingleVowelPronunciation(const char& v)```|	This function takes in a valid lowercase vowel (v) and returns the pronunciation for the vowel v (this will be more than 1 character so it is returned as a string).|
```std::string ProcessCharacter(const char& prev, const char& curr, const char& next)```	|This function takes in three valid lowercase characters (prev, curr, and next) and returns the pronunciation of the character curr using prev and next as necessary to determine what the pronunciation should be. The result is returned as a string without any dashes (unless there is one in the Pronunciation Guide, like for eu)|
```std::string Pronunciation(const std::string& word)```|	This function takes in a valid lowercase string (word) and returns the pronunciation of the input word in the Hawaiian language as a string, including dashes.|
```std::string GetPronunciation(const std::string& hawaiian_word)```	|This function takes in a string (hawaiian_word) and returns the pronunciation of hawaiian_word if it is a valid word in the Hawaiian language and throws an invalid_argument exception if it is not.|


Below is a diagram of the above functions outlining how they relate to each other. Each box represents a call to a function.

If a function box is inside another function, it is called inside that function
Ex: ```StringToLower``` is called inside of ```GetPronunciation```
If a function is below another function, it is called after that function
```IsValidWord``` is called after ```StringToLower```
If it is called below another function and indented with an arrow, it is only called after that function if the result of the previous function matches the label of the arrow
```VowelGroupPronunciation``` is called after ```IsVowelGroup``` only if ```IsVowelGroup``` returns ```true```
 <img width="512" height="420" alt="hawaiian-words-functions" src="https://github.com/user-attachments/assets/4b4271bc-4af3-41ac-a668-de86ca97c9cc" />

Hints
You will likely want to examine each character in the input ```std::string``` and build up the pronunciation guide from an empty ```std::string``` as you go. However, for this to work, some rules need access to the previous character (like 'w') and others to the next character (vowel groups), so you will need to record the current character as well as the previous and next characters inside your loop. Doing this safely requires some care, given that the previous and next characters are not always valid depending on where you are in the ```std::string```.

Usually you'll want to consume one character at a time. But when you find a vowel group, you'll need to make sure you skip the next character. For example, given the input "ai", you'll need to make sure you output only "eye" and not "eye-ee" or "ah-ee".

Finally, take care to insert dashes in the correct places. A pronunciation should never end in a dash, and there should not be dashes before spaces or apostrophes. The dashes should be handled in the ```Pronunciation``` function.


#### Constraints

Only the following header files are allowed to be #included in your solution files:
"cctype" "iostream" "map" "set" "stdexcept" "string" "vector" "functions.hpp"

More Examples: Hawaiian words and their pronunciation
|Hawaiian word (input)|	Pronunciation (output)|
|:---|:---|
aloha|	ah-loh-hah|
Kakahiaka|	kah-kah-hee-ah-kah|
MaHALO|	mah-hah-loh|
E komo mai|	eh koh-moh meye|
maui|	mow-ee|
kane|	kah-neh|
HOALOHA|	hoh-ah-loh-hah|
makua|	mah-koo-ah|
keikikane|	kay-kee-kah-neh|
humuhumunukunukuapua'a|	hoo-moo-hoo-moo-noo-koo-noo-koo-ah-poo-ah'ah|
keiki|	kay-kee|
Hoaloha|	hoh-ah-loh-hah|
kaiapuni|	keye-ah-poo-nee|
wahine|	wah-hee-neh|
iwa|	ee-vah|
Huaai|	hoo-ah-eye|
</details>

<details>
<summary>📂 <strong>DNA-analyze</strong></summary>

  
### Background


DNA encodes the genetic information found in all known organisms. Using four nitrogenous bases: Adenine (A), Thymine (T), Guanine (G), and Cytosine (C), DNA encodes for different proteins that are responsible for the organism's functionality. DNA profiling, the process of determining an individual's DNA characteristics, is commonly used in forensic science, parentage tests, and medical research. However, there are over 3 billion nitrogenous bases in a typical human genome, and comparing every possible alignment to each person being profiled would be too computationally expensive. So, how do we determine which person a given DNA sequence belongs to? We leverage that most of the human genome is relatively similar, and certain areas have high genetic diversity. So, instead of matching every person's DNA to the given DNA, we can compare these highly diverse regions. These regions contain Short Tandem Repeats (STR's), short DNA sequences that repeat consecutively.
<img width="612" height="90" alt="image" src="https://github.com/user-attachments/assets/c7ed39d7-0a97-4cc0-b1b0-b336c3ae28ac" />



Using multiple STRs, rather than just one, can improve the accuracy of DNA profiling. Suppose the probability that two people have the same number of repeats for a single STR is 5%, and the analyst looks at 10 different STRs. In that case, the probability that two DNA samples match purely by chance is about 1 in 1 quadrillion (assuming all STRs are independent). If two DNA samples match the number of repeats for each STR, the analyst can be confident they came from the same person.

Suppose we have 3 people (Michael, Reese, and Nathan), with STR counts for<font color="red">ATTA AATG</font> and <font color="red">TATC</font>. Suppose Michael has 15 consecutive occurrences of ATTA, 10 consecutive occurrences of AATG, and 12 consecutive occurrences of TATC. Similarly, Reese has 4 consecutive occurrences of ATTA, 6 consecutive occurrences of AATG, 2 consecutive occurrences of TATC and Nathan has 10 consecutive occurrences of ATTA, 4 consecutive occurrences of AATG, and 2 consecutive occurrences of TATC.

Now, suppose you're given the following DNA Strand:

```ATTAATTAATTAATTAAATGAATGAATGAATGAATGAATGTATCTATCATTAAATGTATC```
Well, imagine that you looked through the DNA sequence for the longest consecutive sequence of repeated ATTAs and found that the longest sequence was 4 repeats long. If you then find that the longest sequence of AATGs is 6 repeats long, and the longest sequence of TATC is 2 repeats long, that would provide pretty good evidence that the DNA was Reese's. Notice that the longest consecutive sequence is not simply the overall count of the STR in the strand.

Of course, it's also possible that once you take the counts for each of the STRs, it doesn't match anyone in your DNA database, in which case you have no match. If you were given the DNA strand:

```ATTAATTAATTAATTAATTA```
then there would be No match as none of the persons have only 5 ATTA’s in a row.

### Assignment


You will complete the DNA profiling task by implementing ```ProfileDNA()```, which you will define in functions.cc. ```ProfileDNA()``` will take as arguments the absolute path to a DNA STR database (as described below) and the DNA sequence under evaluation as strings. The function will return the person's name to whom the sequence matches, or "No match" (case sensitive).

You must implement your solution to this problem in ```ProfileDNA()```. This function should be written at a single level of abstraction. Therefore, use the step-down rule to create additional functions that together implement the prescribed behavior```ProfileDNA()```.

Your program will be given as command line arguments the name of a DNA database file and a string representation of the DNA sequence, we would like to determine to whom it belongs. These arguments will be used to invoke ```ProfileDNA()```.

#### DNA database files

DNA database files can vary from one another in the number of STRs and number of people they contain. You can assume that a The DNA database file will have at least one STR and one person present. You cannot assume that all DNA databases contain exactly the same number of STRs (e.g., 3).

To begin the analysis, your first task is to write a program that reads into memory the DNA database. In this assignment, the DNA database will be encoded as a CSV file, where each row corresponds to an individual and each column corresponds to an STR. For example,

```
Names,ATTA,AATG,TATC
Michael,15,10,12
Reese,4,6,2
Nathan,10,4,2
```
The DNA database encoded as a CSV file in this manner communicates three important pieces of information. First, the STRs that we will be using in our analysis ```(ATTA,AATG,TATC)```. Second, the names``` (Michael, Reese, Nathan)``` of the individuals involved in our study. Finally, the number of times each individual has a specific STR repeated consecutively in her/his DNA. Michael has ATTA repeated 15 times consecutively somewhere in his DNA, AATG 10 times, and TATC 12 times. Reese has ATTA repeated 4 times consecutively somewhere in his DNA, AATG 6 times, and TATC 2 times. Nathan has ATTA repeated 10 times consecutively somewhere in his DNA, AATG 4 times, and TATC 2 times.

All information stored in the DNA database must be read into memory. We recommend that you read the database line-by-line into your program using std::getline until there are no more lines to be read. For example, if we would like to read each line from the file example.dat, we could write something like this:

```
std::ifstream ifs{"example.dat"};
for(std::string line; std::getline(ifs, line); line = "")
  std::cout << "line = \"" << line << '\"' << std::endl;
```
What's happening? We attempt to extract a line from the input file stream ifs and store it in line. This is the conditional of our for-statement. If this operation succeeds, we enter the loop body. That is, if a line is successfully extracted from ifs, we enter the loop body and (in this example) put the line to standard out. After each iteration of the loop body, the line is "reset" to the empty string, and we attempt to extract another line from ifs. This process continues until there are no more lines to get, at which point getline will fail to extract, and the conditional will evaluate to false, terminating the loop.

Always assume that the first row of any DNA database will be the column names. The first column will not always be Names — for instance, if the dataset were French, it might read Nom — though the remaining columns will always be the STRs. Therefore, in our example, std::getline would read Names,ATTA,AATG,TATC into a single std::string. To help you obtain the different "columns", we have provided you the function utilities::GetSubstrs that can produce a std::vector<std::string> {"Names", "ATTA", "AATG", "TATC"}. After reading the first row from the file, each additional row will correspond to an individual, and each column will correspond to the number of consecutive times a particular STR repeats in their DNA. Once we begin reading str counts, notice that the integer values from the file are stored in std::string form. This goes against our preference since an std::string has different behaviors than an integer. Therefore, it is advisable to convert those numbers into integer values. You should perform the conversion using std::stoi from the <string> facilities. Here's an example:

```
std::string number_as_string = "8";
int number_as_int = std::stoi(number_as_string);
/* OK, since number_as_string constitutes valid int. */
```

```
std::string string_as_string = "Howdy";
int string_as_int = std::stoi(string_as_string);
/* ERROR: terminating with uncaught exception of type std::invalid_argument: stoi: no conversion. */
```
Analyzing the DNA Sequence
Now, we direct our attention to the DNA sequence under analysis. For each of the STRs from the DNA database, you compute and record the longest consecutive run of repeats for that STR in the DNA sequence. Subsequently, you compare these counts to each individual's counts. Should the STR counts in the DNA sequence match exactly one person from the database, ```ProfileDNA()``` must return the name of the matched individual. Otherwise, ProfileDNA() should return No match (case sensitive).

#### Example
Given the DNA STR database file with the following contents:
```
Names,AGATG,AATG,TAT
Casey,5,2,8
Amani,3,7,4
Blair,6,1,5
The DNA sequence
```

```AGACGGGTTACCATGACTATTATTATTATTATTATTATTATACGTACGTACGTATGAGATGAGATGAGATGAGATGAGATGCCTCGACTTCGATCGCAATGAATGCCAATAGACAAAA```
would map to ```Casey```,

```TATTATTATTATAACCCTGCGCGCGCGCGATCCAGCATTAGCTAGCATCAAGATGAGATGAGATGGAATTTCGAAATGAATGAATGAATGAATGAATGAATG```
to ```Amani```, and

```GGTACAGATGGCAAAGATGAGATGAGATGGTCGTCGAGCAATCGTTTCGATAATGAATGAATGAATGAATGAATGAATGACACACGTCGATGCTAGCGGCGGATCGTATATTATAACCCCTAG```
to ```No match```.

### Requirements

Accept the assignment via the "GitHub Classroom" green button at the top of this page, and clone the repository into your development environment.
You will perform the DNA profiling task in your application by implementing the behavior described above in the function signature ProfileDNA(const std::string& dna_database,const std::string& dna_sequence) with return type std::string (define in functions.cc).
Each person's name will be unique in the DNA database: you do not need to consider duplicate names.
Your program must consider each STR independent of the other STRs. For example, if you had a function that returned the longest consecutive sequence of an STR in a given DNA sequence (we recommend this), that function would be called once per STR!
When looking for an STR in the strand, you cannot reuse characters for one match to create another match for the same STR; you cannot overlap characters for matches of the same STR. Accordingly, upon finding an STR match in the sequence, you would continue scanning for other matches from the character in the strand that follows directly after the characters comprising the match. For example,
<img width="542" height="447" alt="image" src="https://github.com/user-attachments/assets/4d382268-9f1c-4f78-a17c-1bbfa01f1b51" />

__Kindly understand that the longest consecutive sequence is not simply the overall count of the STR in the strand. The longest consecutive sequence is the longest consecutive "count" or "run" of an STR side-by-side itself in the strand.__ In contrast, the overall count of an STR is the total number of times the STR is in the strand.
The first comma-separated entry on the first line of the DNA Database will always be a string, but you cannot assume that that string will always be Names.
DNA database input files will vary in the number of STRs. You can assume that the DNA database input file will have at least one STR. You cannot assume that our test input files contain only three STRs.  


You should create your own STR DNA database input files and DNA strands to test your application  


    STR DNA database
Do not create these in Excel. Instead, create a new file in VS code while connected to your container/VM  
Compose this STR DNA database file such that it follows the format specified in this prompt
Name the file using any extension (e.g., .dat, .csv, etc.); what's important is the format of the file's contents  

    DNA sequences
You should compose multiple DNA sequences for testing  


We recommend having strands that place the longest consecutive sequence of the STR in different positions relative to shorter consecutive sequences of the same STR
Remember, it is the longest consecutive sequence of STRs that matters  

Compile your source code to an executable named exec in the bin folder. We've configured a workflow to do this for you:  


In the terminal window, from the project's root directory, execute make exec. Provided compilation succeeds, you will find an executable named exec in the bin folder.
After you've made changes and are ready to compile again, we suggest executing make clean before make exec to delete the older (and not outdated) executables.  

To run the program from the command line, ensure you're in the project's root directory, then execute ./bin/exec "arg1" "arg2", where arg1 is the absolute path to the DNA STR database and arg2 is the DNA sequence under evaluation.  

    Program Usage
Your program must accept as command-line arguments the absolute path to the DNA STR database and the DNA sequence to analyze.  

Your program will write the string returned by ProfileDNA() to standard output and subsequently terminate.  

Note: if you're running your program with our visual debugger, please provide the absolute path to the input file. For example, if you're developing in ~/src/mp-dna-forensics-michaelrnowak/ and your test case is in ./tests/input-test-1.dat relative to that directory, the absolute path to input-test-1.dat would look something similar to /home/vagrant/src/mp-dna-forensics-michaelrnowak/tests/input-test-1.dat. The absolute path to the tests directory could be found by cd into tests and executing pwd.  


Your program must compile without warnings/errors when compiled with: clang++ using the -std=c++20 and the following flags -Wall -Wextra -Werror -pedantic
We've also included the PrairieLearn test cases in the starter code repository for this MP. We will not provide our test cases on subsequent MPs (for real, this time!). To compile your solution against the test suite,  


In the terminal window, from the project's root directory, execute make tests. Provided compilation succeeds, you will find an executable named tests in the bin folder.
run the test suite by executing ./tests from the project's root directory.  


Academic IntegrityYou must derive/generate your solution using string manipulation, iteration, and other language features.
We provide you with almost all the test cases we will use during grading.  

Some students may be tempted to circumvent the spirit of this assignment by mapping the input to outputs directly.
Doing this will violate academic integrity and will result in a FAIR referral.  

#### Important: Use LF (Linux) Line Endings  

To ensure your code works correctly with our tests, your test files must use LF line endings, not Windows' CRLF. To confirm that your test files are using LF endings, in Visual Studio Code, check the bottom-right corner of the window. You should see either LF or CRLF.  


If it says CRLF: Click it and select LF to change the encoding.  

If it says LF: Your file is correctly configured.  

Please make this change for all your input files.  


### Constraints

Only the following header files are allowed to be #included in your solution files:

```<cassert> <fstream> <iostream> <map> <stdexcept> <string> <vector> "functions.hpp" "utilities.hpp"```
### Hints

Be sure to define helper functions to facilitate the comparisons, etc. otherwise you will end up with spaghetti code
Look into std::stoi from <string> to convert strings to integers.
No match happens when none of the people matches the DNA or when more than one person matches the DNA sequence under evaluation.

</details>

<details>
<summary>📂 <strong>starter-25a-io-shpping-list</strong></summary>

### Mission

You are developing a program to simplify reading and managing grocery shopping data. Your goal is to parse a text file containing a list of items, where each line has the format:

```item_name quantity price```
For example:
```cpp
Apples 10 5.99
Tomatoes 5 3.99
```
Each entry corresponds to the following ```Item ```struct:
```cpp
struct Item {
  std::string item_name;
  int quantity;
  double price;
};
```
#### Implementation Details:

Implement a function named ```LoadShoppingItemsFromFile``` that takes a filename as input, opens the file, and performs formatted reads of each shopping list item's name, quantity, and price. Each set of values should be stored in an ```Item``` object, which is then added to an ```std::vector<Item>``` and returned to the caller.

##### File Format

Each line contains an item name (string), a quantity (integer), and a price (double).
Example line: ```Apples 10 5.99```
##### Error Handling

If the file cannot be opened, throw an appropriate exception.
If the file is empty, throw an appropriate exception.
If a formatted read fails—for example, if ```Quantity``` is not an integer or ```Price``` is not a double—throw an exception.
Given an ```std::ifstream ifs```, ```ifs.fail()``` returns true if a read operation on ifs did not succeed—for example, if the data was in the wrong format. This allows you to verify whether the last operation read valid data and if the stream remains usable for further reads. In this activity, check ```fail()``` on your ```std::ifstream``` immediately after each read. If it returns ```true```, you should ```throw``` an exception and expect the caller to handle it appropriately.
##### Output

Return an ```std::vector<Item>``` containing all successfully parsed items only if the entire file is read correctly and no formatted read errors occur.
### Getting started

Since our interactive playground does not support input/output, you must clone the starter code repository, work locally on this assignment in our development container, and then upload the requested files to this webpage for submission.

__address: https://github.com/cs128-illinois/starter-25a-io-shopping-list__
</details>

<details>
<summary>📂 <strong>recitation-log-parser</strong></summary>

https://github.com/ericzheng316/CS-128-Projects/blob/main/recitation-log-parser/README.md

</details>

<details>
<summary>📂 <strong>recitation-comment-stats</strong></summary>

  
## Background
  
In this MP, you are writing and testing code that will read in elevation data, process it, and then print out a grayscale topological image map. This map will have multiple potential paths drawn in red, with the best path in green. Descriptions of how to implement each of these parts are described below. You got this!

### Elevation Dataset

In this MP, you will read elevation data in the form of a white-space delimited list of integer values. This is consistent with how the NOAA(National Oceanic and Atmospheric Administration) provides elevation data. Each integer represents the average elevation in a cell's meters in the topological data grid. The list of integers maps directly onto a rectangular grid to represent the elevation of an area of land. For instance, the following topological data of a 2 by 5 area of land:

col 0	col 1	col 2	col 3	col 4
row 0	10	20	30	40	35
row 1	25	20	15	18	20
Could be given to you in the format of:
10	20	30	40	35	25	20	15	18	20
The first 5 integers encode the numbers for the first row (i.e., row 0), and the next five integers for the second row (i.e., row 1):

The above example is a simplified example used for explanation. In the actual data provided by NOAA, each integer represents the average elevation of a 700-meter by 700-meter square of land. We suggest you formulate some fictional, simple samples by hand for testing purposes.

A goal in this assignment is to translate the file representation of a data sample into an ElevationDataset object. The data in the file will be given as a continuous stream of numbers -- there may or may not be any line breaks in the file. Notice that the constructor of this object takes the path to the plain-text file to be read, as well as the composition of the dataset (i.e., width and height) that it describes (the width and height are not provided in the data file).

During the construction of an ElevationDataset object, you must initialize the width_ and height_ members with the values stored in their corresponding parameters. You will write the elevation data to ElevationDataset object's data_ member in row-major form [row, col]. During this process, you should be recording the minimum and maximum elevation datum values observed in the dataset in min_ele_ and max_ele_, respectively.
While translating the file to matrix form, you should validate the input from the user. The number of elevation points in the file should be exactly width * height. You must throw an exception if there are too many data points or too few in the file. Furthermore, you must throw an exception if an error results from a formatted-read failure. An std::runtime_error with an adequate description of the exceptional case is sufficient.

Instructor's recommendation: I would encourage you to initialize the data_ vector as a pre-allocated vector of height "rows" with width "columns" to save run-time(see Two-dimensional vectors lesson). You can then use a nested for-statement to attempt to read width_ * height_ data values into the proper index in the two-dimensional vector. For example,

initialize data_ as pre-allocated two-dimensional vector of height_ rows, width_ columns
for i in 0 until height_ {
  for j in 0 until width_ {
    attempt to read from the file
    if read fails
      throw exception // too little data in a file or format read error
    else
      assign data_.at(i).at(j) the value read from file
  }
}
check the file for too much data
Grayscale topological image map formulation
The next step is constructing a grayscale topological image from the elevation data. We do this by scaling our elevation data to construct an image where high-brightness areas represent high elevations and dark regions have low elevations. In translating to this representation, we will encode an elevation datum as a grayscale color using the RGB color model. This model blends red, green, and blue components to construct colors. When this model presents a grayscale color, the red, green, and blue components take on the same integer value between 0-255 (i.e., the valid color component range, inclusive).

Therefore, to calculate the shade of gray for an elevation datum, we must scale that elevation point between 0 and 255. This scaling requires us to leverage the maximum value elevation datum observed in the dataset as well as the lowest. With this information, the shade of gray of any elevation point is calculated as

shade_of_gray = std::round((elevation_point - min_ele) / (max_ele - min_ele) * 255)
You should use std::round defined in header <cmath> to perform the rounding. Pay special attention to the types you are dividing otherwise information will be lost in the computation.

If the denominator in this equation evaluates to 0 (i.e., max_ele == min_ele), the shade_of_gray should take on 0. The grayscale RGB value for the elevation value's grid will take on shade_of_gray for the R, G, and B components of the RGB color model. We create a Color object to represent a color in our program. For the grayscale image, we construct a GrayscaleImage object that encodes the topological map by housing a std::vector<std::vector<Color>>. For example, given the following data_ from an ElevationDataset object,

0	1	2	3	4
0	10	20	30	40	35
1	25	20	15	18	20
A GrayscaleImage object’s image_ would take on the following composition -- after scaling the elevation data between 0 and 255:

0	1	2	3	4
0	Color(0,0,0)	Color(85,85,85)	Color(170,170,170)	Color(255,255,255)	Color(213,213,213)
1	Color(128,128,128)	Color(85,85,85)	Color(43,43,43)	Color(68,68,68)	Color(85,85,85)
which represents the following colors for each grid position:

0	1	2	3	4
0					
1					
Grayscale topological image map overlaid with colored paths
Imagine you are hiking in the Colorado Rockies and would like to know the path of least elevation change (i.e., the path of least resistance) from one side of the mountain to the other. Given the topological data for the region that you are in, one can calculate the path of least resistance from one side of the topological image map to the other. In this assignment, a PathImage object will be initialized with the topological image map, elevation data, and the width and height of the dataset. Starting from each data cell in the first (0th) column, a greedy least-elevation-change walk will be calculated from the first column to the last. The path found from each row will be encoded as a Path object and stored in the PathImage object's paths_ collection. This will result in a height number of paths stored in the PathImage object. During construction, the PathImage object's path_image_ is initialized with a copy of the argument passed to the parameter image. Before construction of the PathImage object has finished, each path will be painted across path_image_ in red [RGB(252,25,63)], with the path of least overall resistance colored in green [RGB(31,253,13)]. If there are paths of equal least overall resistance, color green, the path begins from the lowest "row" number.

For instance, given a GrayscaleImage object’s image_ encoding the following topological image map:


The PathImage object’s path_image_ derived from the GrayscaleImage object’s image_ shown above would encode:


Notice that exactly one path starts from each row in the zeroth column spanning the topological image map. While paths can merge, each is considered independent from another and will have its own observed elevation change stored in its representation (Path object). To emphasize, the path with the least overall total change in elevation is colored in green.

Calculating paths: a greedy walk across the image (read carefully!)
We will calculate height_ number of paths through our elevation dataset, ultimately drawing each path upon the topological image map to create a path_image_. To calculate a path, we will "walk" across the elevation data, starting at the cell on the left-most edge (column 0) and proceeding forward by taking a "step" into one of the 3 adjacent cells (if valid -- current_row, current_row + 1, current_row -1) in the next column over (column 1). As we traverse the image, each step will always be in the next column; however, the row we end up in may differ from the one we started our "step" from.

Let's briefly consider directionality. The top-left corner of our image is at (0, 0) in the vector and bottom-right at (height-1, width-1). North is towards row 0, south towards row height-1. West is towards column 0, east is towards column width-1. Therefore, a southeast move is towards the bottom-right corner of the image.

Let's talk specifics about the greedy walk through the image. We will always choose the cell with the least elevation change. In the case of a tie with the straight-forward position (east direction), choose to go straight forward. If there is a tie between the two non-forward locations, always choose the southeast movement. The following diagrams illustrate a few of these rules:


Case 1: smallest change is 5, go fwd-down	Case 2: smallest change is (3, go fwd	Case 3: smallest change is a tie (3), fwd is an option, so go fwd	Case 4: smallest change is a tie (4), go fwd-down
How do we define the least elevation change? During our walk, the total elevation change "experienced" by a person walking this path needs to be maintained and is considered the absolute value of the change in each step summed across the total path. This value will be stored in the Path object's ele_change_ data member and will be compared against other Path object values when determining the best path amongst all the paths. How do we encode the path? Using a Path object, of course. Given the following image,


we would construct a Path object encoding this traversal as:

2	1	2	3	4	4
Explanation: path_.at(0) says our path starts at row 2 of col 0 in the image; path_.at(1) tells us our row location for col 1 => row 1; path_.at(2) => row 2; path_.at(3) => row 3; path_.at(4) => row 4; path_.at(5) => row 4.

Recall that there will be a height_ number of Path objects contained in the PathImage object's paths_ collection (one for each row of the dataset). Again, we will use these objects to "paint" paths across the PathImage object's path_image_. Don't skip creating the path objects: we test that you have satisfactorily computed them.

Notice that our approach in formulating a path constitutes a greedy approach. Each step taken during our walk is simply chosen as the one that seems best. This can take us to regions of topography that are rather expensive to traverse, with large elevation changes. This could have been avoided by considering every path from a given row through our dataset. Such an approach becomes expensive rather quickly: if we must step into width_ columns to traverse the region, the number of possible paths is close to 3width_. Searching for a solution this way does not scale very well, especially considering that we must calculate height_ number of paths. The greedy solution is a lot simpler, albeit with absolutely no guarantee that its solution is the least expensive one (here, in terms of least elevation change).

Writing PPM images
PathImage and GrayscaleImage objects both have behaviors that write out PPM images. PPM stands for Portable Pixel Map and is an image encoding scheme used to represent images using the RGB color model. Its simplicity makes it suitable for this assignment, though it is inefficient (does not apply data compression, etc.) and is not widely used in practice.

A plain PPM file has the following format:

A "magic number" for identifying the file type, followed by a new line.
We will use "P3" in this assignment to identify a plain PPM file
The width followed by the height of the image in pixels. Both are integers separated by a space.
On its own line, the maximum color value, which must be between 0 and 65536, exclusive.
For our assignment, this value will be 255.
Each line represents each pixel's R, G, and B values.
Include an empty line at the end of the file.
For example, given a GrayscaleImage object whose image_ takes on the following composition:

0	1	2	3	4
0	Color(0,0,0)	Color(85,85,85)	Color(170,170,170)	Color(255,255,255)	Color(213,213,213)
1	Color(128,128,128)	Color(85,85,85)	Color(43,43,43)	Color(68,68,68)	Color(85,85,85)
We would write out the PPM file for this object's image_ as:

P3
5 2
255
0 0 0 85 85 85 170 170 170 255 255 255 213 213 213
128 128 128 85 85 85 43 43 43 68 68 68 85 85 85


Viewing PPM images
Mac users -- open the ppm file you've created using the "Preview" application.
Windows/Linux users -- as necessary, use an online free tool to convert your PPM file into a format that your system can natively read (jpg, png, etc.)
Assignment
Starter code
Acquire the starter code by clicking the "GitHub Classroom" button at this page's top.

Deliverables
### Implementation

__class ElevationDataset__
Function Signature	Behavior Description
ElevationDataset(const std::string& filename, size_t width, size_t height)	Initializes the primitive data members with their respective values as read from the file; populates the two-dimensional std::vector<std::vector<int>> with elevation data from file. Sets width_ and height_ appropriately. Records max_ele_ and min_ele_ observed.
size_t Width() const	Returns the “width” of the dataset
size_t Height() const	Returns the “height” of the dataset
int MaxEle() const	Returns the maximum elevation value observed in the dataset
int MinEle() const	Returns the minimum elevation value observed in the dataset
int DatumAt(size_t row, size_t col) const	Returns the value recorded for (row, col)
const std::vector<std::vector<int> >& GetData() const	Returns reference to const to data_.
Data Member	Description
std::vector<std::vector<int> > data_	Houses the elevation data read from the file.
size_t width_	"Width" of the dataset as read from the file.
size_t height_	"Height" of the dataset as read from the file.
int max_ele_	Maximum elevation datum read from the file.
int min_ele_	Minimum elevation datum read from the file.
__class GrayscaleImage__
Function Signature	Behavior Description
GrayscaleImage(const ElevationDataset& dataset)	Initializes the primitive data members with their respective values as read from the dataset; populates the two-dimensional std::vector<std::vector<Color>> with Color representation of each elevation datum. Sets width_ and height_ appropriately.
GrayscaleImage(const std::string& filename, size_t width, size_t height)	filename contains elevation data. It is reasonable to create an ElevationDataset object in this function and use it to implement the desired behavior of this constructor. This constructor initializes the primitive data members with their respective values as read from the file; populates the two-dimensional std::vector<std::vector<Color>> with translated Color representation from each read elevation datum. Sets width_ and height_ appropriately.
size_t Width() const	Returns the width of the image
size_t Height() const	Returns the height of the image
unsigned int MaxColorValue() const	Returns the value stored in kMaxColorValue
const Color& ColorAt(int row, int col) const	Returns the Color at row col by reference to const
const std::vector<std::vector<Color> >& GetImage() const	Returns reference to const to image_.
void ToPpm( const std::string& name ) const	Writes out image_ in plain PPM format; filename is name.
Data Member	Description
std::vector<std::vector<Color> > image_	Image representation of converted elevation data stored as Color values
size_t height_	Height of the image
size_t width_	Width of the image
static const int kMaxColorValue = 255;	Maximum possible grayscale value for the image; shared across all instances of this type.

__class PathImage__
Function Signature	Behavior Description
PathImage(const GrayscaleImage &image, const ElevationDataset &dataset)	Initializes the primitive data members with their respective values read from image; populates the two-dimensional std::vector<std::vector<Color>> with values from the image's image_. Calculates and stores all paths through the image; you may wish to maintain the row of the best path in a variable best_path_row_.
size_t Width() const	Returns the width of the image
size_t Height() const	Returns the height of the image
unsigned int MaxColorValue() const	Returns the value stored in kMaxColorValue
const std::vector<Path>& Paths() const	Returns reference to const to paths_.
const std::vector<std::vector<Color> >& GetPathImage() const	Returns reference to const to path_image_.
void ToPpm(const std::string& name) const	Writes out path_image_ in plain PPM format; filename is name.
Data Member	Description
std::vector<Path> paths_	Vector storing the paths traversals calculated on image_ from each row; paths_.at(0) yields the Path object encoding the traversal across the image starting from row 0; paths_.at(1) yields that from row 1; etc.
std::vector<std::vector<Color> > path_image_	Original image overlaid with paths: the best path is colored green [RGB(31,253,13)]; every other path is red [RGB(252,25,63)].
size_t height_	Height of the image
size_t width_	Width of the image
static const int kMaxColorValue = 255	Maximum possible grayscale value for the image; shared across all instances of this type.
__class Path__
Function Signature	Behavior Description
Path(size_t length, size_t starting_row)	Initializes the primitive data members with their respective values from arguments; initializes path_ std::vector<size_t> of length elements.
size_t Length() const	Returns the length_.
size_t StartingRow() const	Returns the starting_row_.
unsigned int EleChange() const	Returns the ele_change_.
void IncEleChange(unsigned int value)	Increments ele_change_ by value (must be positive).
const std::vector<size_t>& GetPath() const	Returns reference to const to path_
void SetLoc( size_t col, size_t row )	Assigns the value of row (path_.at(col) will evaluate to row)
Data Member	Description
std::vector<size_t> path_	1 row by length_ columns. This std::vector<int> encodes the path starting at row starting_row across the image (from "left" to "right"). Each "index" of path_ represents a column and stores the row index of the path as it traverses that column.
For example, given the following image, we could construct a Path object describing our traversal across it (from left to right, column 0 to column width-1) from row 2 (traversals from any row always start at column 0):as:
2	1	2	3	4	4
Explanation: path_.at(0) says our path starts at row 2 of col 0 in the image; path_.at(1) tells us our row location for column 1 (returns 1 representing row 1); path_.at(2) => row 2; path_.at(3) => row 3, path_.at(4) => row 4, path_.at(5) => row 4.
size_t length_	Number of columns in path_.
size_t starting_row_	Row that this path begins from.
unsigned int ele_change_	Total elevation change "experienced" by a person walking the path.

__class Color__
Function Signature	Behavior Description
Color()	Assigns each data member its zero value.
Color(int r, int g, int b)	Initializes a new Color object, ensuring the values assigned to red_, green_, and blue_ are each within the range 0 to 255 inclusive. Throw an exception if any of the arguments are outside that range.
int Red() const	Returns value stored in red_.
int Blue() const	Returns value stored in blue_.
int Green() const	Returns value stored in green_.
Data Member	Description
static constexpr int kColorValueMin = 0	Minimum value that a color component can take on.
static constexpr int kColorValueMax = 255	Maximum value that a color component can take on.
int red_	Red component of color; invariant: value in range 0-255 inclusive.
int green_	Green component of color; invariant: value in range 0-255 inclusive.
int blue_	Blue component of color; invariant: value in range 0-255 inclusive.

### Test cases

We require you to take a test-driven approach when implementing your solution. Accordingly, you must write sufficient unit tests for each behavior afforded by the public interface.

You are required to create small test files for each of the cases under the "Calculating paths" section of this document. If you need help with this, please attend office hours on MONDAY. We will only provide support during office hours once you have made an honest effort to compose these test files.

To get you started, we have provided some examples of test files inside the example-data. The all-tie-row1-2w-3h.dat inside input_data provides an example for one of the test files under the "Calculating paths" section of this document. It would help if you created additional test cases similar to this for the other test cases. RememberDon't to write test cases where you begin calculating a path from start in row 0 and row size-1. Making moves from these rows requires careful consideration since only some potential moves are valid.

Here's how you should use these test files. First, create your input test files. Calculate the expected output files for each stage by hand when going from elevation data to path image. Implement ElevationDataset and exercise with your test input files. Does the input data get into the correct locations in the multi-dimensional vector? Are the data members maintaining the width and height set properly? Once you are confident this class has been implemented correctly, you move on to GrayscaleImage and begin a similar testing process there. Finally, PathImage should be implemented and tested accordingly.

You should also satisfactorily exercise the supporting classes Path and Color.

### Visual debugging

Note: if you're running your program with our visual debugger, please provide the absolute path to the input file. For example, if you're developing in ~/some/where/mp-mountain-paths-michaelrnowak/ and your test case is in ./example-data/ex_input_data/input-test-1.dat relative to that directory, you will need to find the absolute path to input-test-1.dat. The absolute path to the tests directory can be found by cd into ./example-data/ex_input_data/ and executing pwd.

### Constraints

You cannot create additional data members (e.g., size_, etc.): we break encapsulation to set data members to specific values and then test your implemented behaviors. We only update the data members specified in our prompt during that process.
All functions of the public interface will be used in testing, so it is CRUCIAL that their signatures and return types are not altered (and that you implement them).
Your program must compile without warnings/errors when compiled with: ```clang++ using the -std=c++20 and the following flags -Wall -Wextra -Werror -pedantic```
Only the following header files are allowed to be #included in your solution files:
```"color.hpp" "elevation_dataset.hpp" "grayscale_image.hpp" "path_image.hpp" "path.hpp" "stdexcept" "cassert" "iostream" "fstream" "limits" "cstdlib" "string" "vector" "cmath" "utility"```

### Submitting your work

You will submit the following header and source files to PrairieLearn for grading: 
```color.cc, color.hpp, elevation_dataset.cc, elevation_dataset.hpp, grayscale_image.cc, grayscale_image.hpp, path_image.cc, path_image.hpp, path.cc, path.hpp.```


</details>
