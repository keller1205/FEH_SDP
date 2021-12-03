#include <FEHLCD.h>
//#include <FEHIO.h>
#include <FEHUtility.h>



//Function Prototypes
 void drawMenu();

 int difficultyButtons();

 int move_user(int i);

 

 //Class Game
 class Game
 {
     public:
        Game(int default_score = 0, int default_lives = 0);
        int getScore();
        void setScore(int*);
        int getLives();
        void setLives(int*);
        void playGame(int);
        

     private:
        int score;
        int lives;
 };

  Game::Game(int default_score, int default_lives)
{
    score = default_score;
    lives = default_lives;
}

 

int main() {
    // Clear background
    LCD.Clear();

    //Declare Variables
    int menu_open = 1;
    int difficulty;
    float xTouch, yTouch;
    int game_open = 1;
    

   
    
    
    drawMenu();
    while(game_open == 1)
    {
        while(menu_open == 1)
        {
         if(LCD.Touch(&xTouch, &yTouch))
        {
            if((xTouch > 100 && xTouch < 220) && (yTouch > 80 && yTouch < 110))
            {
                LCD.Clear();
                menu_open = 0;
                Sleep(0.1);
                difficulty = difficultyButtons();
                Game spaceJunk;
                spaceJunk.playGame(difficulty);
                

                int A =2;

                while(1)
                {
                 A = move_user(A);   
                }
                


            }
             if((xTouch > 100 && xTouch < 220) && (yTouch > 120 && yTouch < 150))
            {
                LCD.Clear();
                LCD.WriteAt("Stats: ", 10, 10);
                Sleep(8.0);
                LCD.Clear();
                drawMenu();
            }
            if((xTouch > 80 && xTouch < 250) && (yTouch > 160 && yTouch < 190))
            {
                LCD.Clear();
                LCD.WriteAt("Made by Ashton Keller and",10,10);
                LCD.WriteAt("Landon Beckley",10,30);
                LCD.WriteAt("Rules:",10,50);
                LCD.WriteAt("Tap the X's to move.",10,70);
                LCD.WriteAt("Block the incoming debris",10,90);
                LCD.WriteAt("From hitting your ship",10,110);
                LCD.WriteAt("If you take too many hits,",10,130);
                LCD.WriteAt("You lose",10,150);
                Sleep(5.0);
                LCD.Clear();
                drawMenu();
            }
            if((xTouch > 100 && xTouch < 220) && (yTouch > 200 && yTouch < 230))
            {
                LCD.Clear();
                LCD.WriteAt("Thanks for Playing!",0,10);
                Sleep(3.0);
                menu_open = 0;
                game_open = 0;
            }
        }
        }
        LCD.Update();
    }
    return 0;
}







//Function Definitions
void drawMenu()
{
     //Draw the Menu
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    
    LCD.WriteAt("Space Junk", 100, 40);

    LCD.DrawRectangle(100,80,120,30);
    LCD.WriteAt("Play",130,85);

    LCD.DrawRectangle(100,120,120,30);
    LCD.WriteAt("Stats", 130, 125);

    LCD.DrawRectangle(80,160,170,30);
    LCD.WriteAt("Rules/Credits", 85, 165);

    LCD.DrawRectangle(100,200,120,30);
    LCD.WriteAt("Quit", 130, 205);
}

int difficultyButtons()
{
    float xTouch, yTouch;
    int difficulty;
    int buttonsOpen = 1;
    LCD.WriteAt("Select Difficulty", 60, 40);

    LCD.DrawRectangle(100,80,120,30);
    LCD.WriteAt("Easy",130,85);

    LCD.DrawRectangle(100,120,120,30);
    LCD.WriteAt("Hard", 130, 125);
    while(buttonsOpen == 1)
    {
        if(LCD.Touch(&xTouch, &yTouch))
            {
                if((xTouch > 100 && xTouch < 220) && (yTouch > 80 && yTouch < 110))
                {
                    difficulty = 1;
                    LCD.Clear();
                    buttonsOpen = 0;
                }
                if((xTouch > 100 && xTouch < 220) && (yTouch > 120 && yTouch < 150))
                {
                    difficulty = 2;
                    LCD.Clear();
                    buttonsOpen = 0;
                }
            }   
    }
    LCD.Update();
    return difficulty;
}

void Game::playGame(int d)
{
    LCD.Clear();
    LCD.SetFontColor(GRAY);
    LCD.DrawRectangle(0,0,40,239);
    LCD.FillRectangle(0,0,40,239);

    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(70,105,30,30);
    LCD.FillRectangle(70,105,30,30);

    if(d == 1)
    {
        LCD.SetFontColor(RED);
        LCD.DrawCircle(300,20,10);
        LCD.FillCircle(300,20,8);
        LCD.DrawCircle(270,20,10);
        LCD.FillCircle(270,20,8);
        LCD.DrawCircle(240,20,10);
        LCD.FillCircle(240,20,8);

        LCD.SetFontColor(WHITE);
        LCD.WriteAt("X", 78, 50);
        LCD.WriteAt("X", 78, 105);
        LCD.WriteAt("X", 78, 170);

    }
    else if(d == 2)
    {
        LCD.SetFontColor(RED);
        LCD.DrawCircle(300,20,10);
        LCD.FillCircle(300,20,8);

        LCD.SetFontColor(WHITE);
        LCD.WriteAt("X", 78, 50);
        LCD.WriteAt("X", 78, 105);
        LCD.WriteAt("X", 78, 170);
        
    }
 


}


int move_user(int i)
{

    LCD.ClearBuffer();

    //sets variables for user position
    float x_user, y_user;

    //waits while there is no touch to the screen
    while (!LCD.Touch(&x_user, &y_user)){}

    //Accepts user input
    if (LCD.Touch(&x_user, &y_user))
    {

        if (((x_user > 70 && x_user < 100) && (y_user > 50 && y_user < 80))||((x_user > 70 && x_user < 100) && (y_user > 105 && y_user < 135))||((x_user > 70 && x_user < 100) && (y_user > 170 && y_user < 200)))
           {
            switch (i)
            {
                case 1:
                    LCD.SetFontColor(PURPLE);
                    LCD.DrawRectangle(70,50,30,30);
                    LCD.FillRectangle(70,50,30,30);
                    LCD.Update();
                    Sleep(100);

                    LCD.SetFontColor(BLACK);
                    LCD.DrawRectangle(70,50,30,30);
                    LCD.FillRectangle(70,50,30,30);
                    LCD.Update();
                    break;

                case 2:
                    LCD.SetFontColor(PURPLE);
                    LCD.DrawRectangle(70,105,30,30);
                    LCD.FillRectangle(70,105,30,30);
                    LCD.Update();
                    Sleep(100);

                    LCD.SetFontColor(BLACK);
                    LCD.DrawRectangle(70,105,30,30);
                    LCD.FillRectangle(70,105,30,30);
                    LCD.Update();
                    break;

                case 3:
                    LCD.SetFontColor(PURPLE);
                    LCD.DrawRectangle(70,170,30,30);         
                    LCD.FillRectangle(70,170,30,30);
                    LCD.Update();
                    Sleep(100);

                    LCD.SetFontColor(BLACK);
                    LCD.DrawRectangle(70,170,30,30);
                    LCD.FillRectangle(70,170,30,30);
                    LCD.Update();
                    break;
            }
           }




        if((x_user > 70 && x_user < 100) && (y_user > 50 && y_user < 80))
        {
            i=1;    

            //draws black rectangles in other locations
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(70,105,30,30);
            LCD.FillRectangle(70,105,30,30);

            LCD.DrawRectangle(70,170,30,30);
            LCD.FillRectangle(70,170,30,30);

            //Draws white x user locations
            LCD.SetFontColor(WHITE);
            LCD.WriteAt("X", 78, 105);
            LCD.WriteAt("X", 78, 170);

            //Moves user block
            LCD.SetFontColor(WHITE);
            LCD.DrawRectangle(70,50,30,30);
            LCD.FillRectangle(70,50,30,30);

            //updates LCD
            LCD.Update();

        
        }//first section of grid structure

        if((x_user > 70 && x_user < 100) && (y_user > 105 && y_user < 135))
        {
            i=2;

            //draws black rectangles in other locations
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(70,50,30,30);
            LCD.FillRectangle(70,50,30,30);

            LCD.DrawRectangle(70,170,30,30);
            LCD.FillRectangle(70,170,30,30);

            //Draws white x user locations
            LCD.SetFontColor(WHITE);
            LCD.WriteAt("X", 78, 50);
            LCD.WriteAt("X", 78, 170);

            //Moves user block
            LCD.SetFontColor(WHITE);
            LCD.DrawRectangle(70,105,30,30);
            LCD.FillRectangle(70,105,30,30);

            //updates LCD
            LCD.Update();

        
        }//second section of grid structure

        if((x_user > 70 && x_user < 100) && (y_user > 170 && y_user < 200))
        {
            i=3;

            //draws black rectangles in other locations
            LCD.SetFontColor(BLACK);
            LCD.DrawRectangle(70,50,30,30);
            LCD.FillRectangle(70,50,30,30);

            LCD.DrawRectangle(70,105,30,30);
            LCD.FillRectangle(70,105,30,30);

            //Draws white x user locations
            LCD.SetFontColor(WHITE);
            LCD.WriteAt("X", 78, 50);
            LCD.WriteAt("X", 78, 105);

            //Moves user block
            LCD.SetFontColor(WHITE);
            LCD.DrawRectangle(70,170,30,30);
            LCD.FillRectangle(70,170,30,30);

            //updates LCD
            LCD.Update();

        
        }//third section of grid structure


        return i;
    }//touch if
    


}