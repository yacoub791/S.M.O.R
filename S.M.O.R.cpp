#include <iostream>
#include <ctime> 

void PrintIntroduction(int Difficulty)
{
    //Print welcome messages to the terminal
    std::cout << "\n\nYou are a S.M.O.R operator trying to hack into a level" << Difficulty;
    std::cout << " secure data room in the enemies base....\nYou must enter the correct inputs to bypass the security\n\n";   
}

bool Playgame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC; 
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    //Store the players guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nMission Successful Get ready for the next round!";
        return true;
    }
    else
    {
        std::cout << "\nMission Failed we'll get them next time";
        return false; 
    }    
}

int main()
    {
        srand(time(NULL));
        int LevelDifficulty = 1;
        int const MaxDifficulty = 100;

        while (LevelDifficulty <= MaxDifficulty)
        {
         bool bLevelComplete = Playgame(LevelDifficulty); 
         std::cin.clear();//Clear any errors 
         std::cin.ignore();// Discards the buffer

         if (bLevelComplete)
         {
            ++LevelDifficulty; 
         }
         
        }
        std::cout << "\n+++Good Work Agent youre headed back to base +++\n"; 
        
        return 0;
    
    } 
