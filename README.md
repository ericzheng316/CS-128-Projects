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
