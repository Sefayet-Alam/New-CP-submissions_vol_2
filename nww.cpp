#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct Category {
  string name;
  vector<string> words;
};

class WordRouletteGame {
  private:
    vector<Category> categories;
    int difficulty;
    int score;

  public:
    WordRouletteGame() {
      categories = {
        Category{"Biology", {"cell", "DNA", "gene", "organism", "evolution"}},
        Category{"Solar System", {"Sun", "Earth", "Moon", "Mars", "Jupiter"}},
        Category{"Mathematics", {"addition", "subtraction", "multiplication", "division", "algebra"}},
        Category{"C++ Programming Language", {"class", "function", "variable", "loop", "conditional"}},
        Category{"Animals", {"dog", "cat", "bird", "fish", "insect"}}
      };
      difficulty = 1; // Easy
      score = 0;
    }

    void setDifficulty(int difficulty) {
      this->difficulty = difficulty;
    }

    int getDifficulty() {
      return difficulty;
    }

    int getScore() {
      return score;
    }

   void startGame() {
  // Randomly select a category
  int categoryIndex = rand() % categories.size();
  Category category = categories[categoryIndex];

  // Display the category to the user
  cout << "Category: " << category.name << endl;

  // Generate a random word from the category
  int wordIndex = rand() % category.words.size();
  string word = category.words[wordIndex];

  // Ask the user to guess the word
  cout << "Guess the word: ";
  string guess;
  cin >> guess;

  // Check if the user guessed correctly
  int guesses = 1;
  while (guess != word) {
    guesses++;
    cout << "Incorrect. Guess again: ";
    cin >> guess;
  }

  // Award points based on the number of guesses
  int points = 10 - guesses;
  score += points;

  cout << "Correct! You scored " << points << " points." << endl;
}

};

int main() {
  WordRouletteGame game;

  // Ask the user for the difficulty level
  cout << "Select a difficulty level (1 = easy, 2 = medium, 3 = hard): ";
  int difficulty;
  cin >> difficulty;
  game.setDifficulty(difficulty);

  // Start the game
  game.startGame();

  // Display the final score
  cout << "Your final score is " << game.getScore() << "." << endl;

  return 0;
}
