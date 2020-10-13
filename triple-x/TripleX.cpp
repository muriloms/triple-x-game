#include <iostream>
#include <ctime>

using namespace std;

// Function for introduction text
void PrintIntroduction(int Difficulty)
{
    cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    cout << " secure server room ...\n Enter the correct code to continue...\n\n";
}

// Functior for the game logic
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Generate Code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;


    // Print player guess
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // CHeck if the player guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\n*** Well done agent ! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        cout << "\n*** You entered the wrong code ! Careful agent! Try again! ***";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty) // loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear(); // clears any errors
        cin.ignore(); // discards the buffer

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    cout << "\n*** Great work agent! You got all the files ! Now get out of there! **\n";

    return 0;
}