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

</details>
