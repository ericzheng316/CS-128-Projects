#include <iostream>

#include "solution.hpp"

int main() {
  // std::vector<std::string> comments = {
  //     "Great job @Ashley11 and @TheRealNithin on the presentation!",
  //     "What do you think about @_Mei_'s new post? It seems to rival "
  //     "@Victor22's content",
  //     "I haven't seen that here before, you should tell @ashley11 ",
  //     "@Victor22 have you seen the new @CatsFurever video? I think you would
  //     " "really like it!",
  //     "@TheRealNithin @Victor22, you should collaborate more often!"};

  std::vector<std::string> comments = {
      "Hey @@R0ckClimber and@ishaan4, what are your favorite gyms to go to?",
      "@cupcak3Lover@MacaroonMania do you have any baking recommendations?",
      "I think @ Samuel2 and @ishaan4 are in the same class"};

  CommentStats test = GenerateCommentStats(comments);
  for (auto const& [user, mentions] : test.mention_frequencies) {
    std::cout << "User: " << user << " Mentions: " << mentions << std::endl;
  }
  std::cout << std::endl;
  for (auto const& user : test.popular_mentions) {
    std::cout << user << " ";
  }
  std::cout << std::endl;
}
