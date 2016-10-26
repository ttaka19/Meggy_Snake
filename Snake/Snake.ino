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
int xapple = random(8);
int yapple = random(8);
boolean gotApple = false;
Point p1 = {2,4};  //Create points
Point p2 = {3,4};
Point p3 = {4,4};
Point p4 = {5,4};
Point snakeArray[64] = {p1,p2,p3,p4};
int marker = 4;  //Index of the first empty segment of array
int direction = 0;
int binary = 0;
int speed = 160;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  updateSnake();
  DrawPx(xapple,yapple,Red);
  if (ReadPx(snakeArray[0].x,snakeArray[0].y) ==1)
  {
    binary = binary * 2 + 1;
    if (binary > 255)
    {
      binary = 0;
      Tone_Start(10000,400);
      speed = speed - 20;
    }
    Tone_Start(8000,300);
    xapple = random(8);
    yapple = random(8);
    gotApple = true;
  }
  drawSnake();           // Draw a dot at x=3, y=4, in yellow.
  SetAuxLEDs(binary);
  DisplaySlate();                  // Write the drawing to the screen.
  delay(speed);                  // waits for a second
  ClearSlate();
  CheckButtonsPress();
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
//Checks the direction and updates the x or y value.
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

void drawSnake()
// iterate entire array
{
  for (int i = 0; i < marker; i++)
  DrawPx(snakeArray[i].x,snakeArray[i].y,Yellow);           // Draw a dot at x=3, y=4, in yellow.
}


