#include <FEHLCD.h>
//#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHRandom.h>



//Function Prototypes
 void drawMenu();

 int difficultyButtons();

 

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
        int move_user(int i);

     private:
        int score;
        int lives;
 };

  Game::Game(int default_score, int default_lives)
{
    score = default_score;
    lives = default_lives;
}





//Class Enemy
class Enemy
{
    public:
        Enemy(int default_x = 0, int default_y = 0, int default_r = 0);
        int* getR();
        void genR(int *);
        void initialize();
        void move();

    private:
        int x,y,r;

};

Enemy::Enemy(int default_x, int default_y, int default_r)
{
    x = default_x;
    y = default_y;
    r = default_r;
}

 

int main() {
    // Clear background
    LCD.Clear();
    

    //Declare Variables
    int menu_open = 1;
    int difficulty;
    float xTouch, yTouch;
    int game_open = 1;
    int back_button = 1;
    

   
    
    
    drawMenu();
    
    while(game_open == 1)
    {
        while(menu_open == 1)
        {

            Sleep(100);
            LCD.ClearBuffer();

         if(LCD.Touch(&xTouch, &yTouch))
        {

            
            if((xTouch > 100 && xTouch < 220) && (yTouch > 45 && yTouch < 75))
            {
                LCD.Clear();
                menu_open = 0;
                Sleep(0.1);
                difficulty = difficultyButtons();
             




                if (difficulty != 0)
                {
                    Game spaceJunk;
                    spaceJunk.playGame(difficulty);
                

                   // int A = 2;

                   /* while(1)
                    {
                        A = spaceJunk.move_user(A);   
                    }*/

                }

                else if (difficulty == 0)
                {
                    menu_open = 1;


                    LCD.Clear();
                    drawMenu();
                    Sleep(100);
                    LCD.ClearBuffer();

                }


            }


            else if((xTouch > 100 && xTouch < 220) && (yTouch > 85 && yTouch < 115))
            {
                
                LCD.Clear();
                menu_open = 0;
                back_button = 1;
                Sleep(0.1);



                LCD.WriteAt("Stats: ", 10, 10);

                LCD.DrawRectangle(200,195,80,30);
                LCD.WriteAt("Back", 215, 200);

                /*Include functions to display statistics*/
                //
                //
                ///////////////////////////////////////////



                
                Sleep(100);
                LCD.ClearBuffer();

                while (back_button == 1)
                {
                    while (!LCD.Touch(&xTouch, &yTouch)) {}

                    if((xTouch > 200 && xTouch < 280) && (yTouch > 195 && yTouch < 225))
                    {

                        
                        back_button = 0;
                        menu_open = 1;

                        LCD.Clear();
                        drawMenu();
                        Sleep(300);
                        LCD.ClearBuffer();

                    }

                }

                
             
            }



            else if((xTouch > 80 && xTouch < 250) && (yTouch > 125 && yTouch < 155))
            {
                LCD.Clear();
                menu_open = 0;
                back_button = 1;


                
                LCD.WriteAt("Rules:",10,20);
                LCD.WriteAt("Tap the X's to move.",10,40);
                LCD.WriteAt("Block the incoming debris",10,60);
                LCD.WriteAt("From hitting your ship",10,80);
                LCD.WriteAt("If you take too many hits,",10,100);
                LCD.WriteAt("You lose",10,120);

                LCD.DrawRectangle(200,195,80,30);
                LCD.WriteAt("Back", 215, 200);

                      
                Sleep(100);
                LCD.ClearBuffer();

                while (back_button == 1)
                {
                    while (!LCD.Touch(&xTouch, &yTouch)) {}

                    if((xTouch > 200 && xTouch < 280) && (yTouch > 195 && yTouch < 225))
                    {

                        
                        back_button = 0;
                        menu_open = 1;

                        LCD.Clear();
                        drawMenu();
                        Sleep(300);
                        LCD.ClearBuffer();

                    }

                }


            }




            else if((xTouch > 80 && xTouch < 250) && (yTouch > 165 && yTouch < 185))
            {
                LCD.Clear();
                menu_open = 0;
                back_button = 1;


                LCD.WriteAt("Made by Ashton Keller and",10,10);
                LCD.WriteAt("Landon Beckley",10,30);

                LCD.DrawRectangle(200,195,80,30);
                LCD.WriteAt("Back", 215, 200);


               
                while (back_button == 1)
                {
                    while (!LCD.Touch(&xTouch, &yTouch)) {}

                    if((xTouch > 200 && xTouch < 280) && (yTouch > 195 && yTouch < 225))
                    {

                        
                        back_button = 0;
                        menu_open = 1;

                        LCD.Clear();
                        drawMenu();
                        Sleep(300);
                        LCD.ClearBuffer();

                    }

                }

                
            }



            else if((xTouch > 100 && xTouch < 220) && (yTouch > 205 && yTouch < 235))
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

    
    LCD.WriteAt("Space Junk", 100, 15);

    LCD.DrawRectangle(100,45,120,30);
    LCD.WriteAt("Play",130,50);

    LCD.DrawRectangle(100,85,120,30);
    LCD.WriteAt("Stats", 130, 90);

    LCD.DrawRectangle(100,125,120,30);
    LCD.WriteAt("Rules", 130, 130);

    LCD.DrawRectangle(100,165,120,30);
    LCD.WriteAt("Credits", 120, 170);

    LCD.DrawRectangle(100,205,120,30);
    LCD.WriteAt("Quit", 130, 210);
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

    LCD.DrawRectangle(100,160,120,30);
    LCD.WriteAt("Back", 130, 165);




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

                if((xTouch > 100 && xTouch < 220) && (yTouch > 160 && yTouch < 180))
                {
                    
                    difficulty = 0;    ///escape
                    LCD.Clear();
                    buttonsOpen = 0;
                    
                }





            }   
    }
    LCD.Update();
    return difficulty;
}

/*void Game::playGame(int d)
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

       


}*/

int Game::move_user(int i)

{

    LCD.ClearBuffer();

    //sets variables for user position
    float x_user, y_user;


    float time; 
    float time_critical = 0.1;
    time = TimeNow();
    //waits while there is no touch to the screen
    //while (!LCD.Touch(&x_user, &y_user)){}

    while ((TimeNow() - time < time_critical)&&!LCD.Touch(&x_user, &y_user))
    {
        

    }

    //Accepts user input
    if (LCD.Touch(&x_user, &y_user))
    {

       //teleport feature
           if ( (y_user > 50 && y_user < 80) || (y_user > 105 && y_user < 135) || (y_user > 170 && y_user < 200))
           {
              if(x_user > 70 && x_user < 100)  
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
            LCD.ClearBuffer();
        
        }//third section of grid structure


        return i;
    }//touch if
    


}




/*Added stuff below*//////////////////////////////////////////////////////////////////////
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

    Enemy enemy1;
    int *enemy1R = enemy1.getR();
    enemy1.genR(enemy1R);
    enemy1.initialize();

    int A = 2;

    

    while(1)
    {
        

        
            enemy1.move();

            A = move_user(A);

            Sleep(2);
        

    }
 
   
   
    while(true)
    {
        LCD.Update();
    }

}



int* Enemy::getR()
{
    return &r;
}


void Enemy::genR(int *a)
{
   
    *a = (Random.RandInt() % 3) + 1;
}

void Enemy::initialize()
{
    if(r == 1)
    {
        x = 270;
        y = 55;
        LCD.DrawRectangle(x,y,20,5);
    }
    else if (r == 2)
    {
        x = 270;
        y = 110;
        LCD.DrawRectangle(x,y,20,5);
    }
    else if (r == 3)
    {
        x = 270;
        y = 175;
        LCD.DrawRectangle(x,y,20,5);
    }
}

void Enemy::move()
{
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(x,y,20,5);
    x = x - 1;
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(x,y,20,5);
    LCD.WriteAt("X", 78, 50);
    LCD.WriteAt("X", 78, 105);
    LCD.WriteAt("X", 78, 170);
}