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
