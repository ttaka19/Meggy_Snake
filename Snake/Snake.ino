/*
  MeggyJr_Snake by Trevor Taka
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point //Declare structure
{
  int x;
  int y;
};
int xapple = random(8); //randomize x apple coords
int yapple = random(8); //randomize y apple coords
boolean gotApple = false;
boolean gameOver = false;
Point p1 = {2,4};  //Create point
Point snakeArray[64] = {p1};
int marker = 1;  //Index of the first empty segment of array
int direction = 0; //set direction to north
int binary = 0; //set default 0 lights on
int speed = 160; //set default speed

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  if (gameOver == false)
  {
    updateSnake();
    functionsApple();
    checkDeath();
    drawSnake();           // Draw a dot at x=3, y=4, in yellow.
    SetAuxLEDs(binary);     //set top lights
    DisplaySlate();                  // Write the drawing to the screen.
    delay(speed);                  // waits for a second
    ClearSlate();
    directionSnake();
  }
    else death();
}
//Checks the direction and updates the x or y value.
void directionSnake()
{
  CheckButtonsPress(); //change direction
      if (Button_Up)
      {
       direction = 0;
      }
      if (Button_Right)
      {
        direction = 90;
      }
      if (Button_Down)
      {
        direction = 180;
      }
      if (Button_Left)
      {
        direction = 270;
      }
}
void updateSnake()
{
  //Move body
  for (int i = marker - 1; i > 0; i--)
  {
    snakeArray[i] = snakeArray [i - 1];
  }
  //Move head
  if (direction == 0)
  {
    snakeArray[0].y = snakeArray[0].y + 1;      // Updates y.
  }
    if (snakeArray[0].y >7)      // Corects for out-of-bounds.
    {
      snakeArray[0].y = 0;
    }
  if (direction == 90)
  {
    snakeArray[0].x = snakeArray[0].x + 1;      // Updates y.
  }
    if (snakeArray[0].x >7)      // Corects for out-of-bounds.
    {
      snakeArray[0].x = 0;
    }
  if (direction == 180)
  {
    snakeArray[0].y = snakeArray[0].y - 1;      // Updates y.
  }
    if (snakeArray[0].y <0)      // Corects for out-of-bounds.
    {
      snakeArray[0].y = 7;
    }
  if (direction == 270)
  {
    snakeArray[0].x = snakeArray[0].x - 1;      // Updates y.
  }
    if (snakeArray[0].x <0)      // Corects for out-of-bounds.
    {
      snakeArray[0].x = 7;
    }
}

void drawSnake() //draws snake
// iterate entire array
{
  for (int i = 0; i < marker; i++)
  DrawPx(snakeArray[i].x,snakeArray[i].y,Yellow);           // Draw a dot at x=3, y=4, in yellow.
}

void functionsApple() //checks to see if apple eaten and does functions
{
  DrawPx(xapple,yapple,Red);
    if (ReadPx(snakeArray[0].x,snakeArray[0].y) == 1)
    {
      binary = binary * 2 + 1;
      if (binary > 255)
      {
        binary = 0;
        Tone_Start(10000,400); //plays tone
        speed = speed - 20; //increases speed
      }
      Tone_Start(8000,300); //plays tone
      xapple = random(8); //randomize apple x coords
      yapple = random(8); //randomize apple y coords
      addSegment();
    }
}

void addSegment() //adds segment to snake
{
  marker = marker + 1;
}

void checkDeath()
{
  for (int i = 1; i < marker; i++)
  if ((snakeArray[0].x == snakeArray[i].x) && (snakeArray[0].y == snakeArray[i].y))
  {
    ClearSlate();
    gameOver = true;
  }
}
void death() //if dead
{
  DrawPx(0,0,Red);
  DrawPx(1,1,Red);
  DrawPx(2,2,Red);
  DrawPx(3,3,Red);
  DrawPx(4,4,Red);
  DrawPx(5,5,Red);
  DrawPx(6,6,Red);
  DrawPx(7,7,Red);
  DrawPx(0,7,Red);
  DrawPx(1,6,Red);
  DrawPx(2,5,Red);
  DrawPx(3,4,Red);
  DrawPx(4,3,Red);
  DrawPx(5,2,Red);
  DrawPx(6,1,Red);
  DrawPx(7,0,Red);
  DisplaySlate();
  delay(3000);
  struct Point //Declare structure
{
  int x;
  int y;
};
int xapple = random(8); //randomize x apple coords
int yapple = random(8); //randomize y apple coords
boolean gotApple = false;
Point p1 = {2,4};  //Create point
Point snakeArray[64] = {p1};
int marker = 1;  //Index of the first empty segment of array
int direction = 0; //set direction to north
int binary = 0; //set default 0 lights on
int speed = 160; //set default speed
ClearSlate();
}

