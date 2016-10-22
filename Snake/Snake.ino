/*
  MeggyJr_Snake.pde
 
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

struct Point
{
  int x;
  int y;
};
int xapple = random(8);
int yapple = random(8);
boolean gotApple = false;
Point p1 = {3,4};
int direction = 0;
int binary = 0;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  updateSnake();
  DrawPx(xapple,yapple,Red);
  if (ReadPx(p1.x,p1.y) ==1)
  {
    Tone_Start(8000,300);
    binary = binary * 2 + 1;
    if (binary > 255)
    {
      binary = 1;
    }
    xapple = random(8);
    yapple = random(8);
  }
  drawSnake();           // Draw a dot at x=3, y=4, in yellow.
  SetAuxLEDs(binary);
  DisplaySlate();                  // Write the drawing to the screen.
  delay(150);                  // waits for a second
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
  if (direction == 0)
  {
    p1.y = p1.y + 1;      // Updates y.
  }
    if (p1.y >7)      // Corects for out-of-bounds.
    {
      p1.y = 0;
    }
  if (direction == 90)
  {
    p1.x = p1.x + 1;      // Updates y.
  }
    if (p1.x >7)      // Corects for out-of-bounds.
    {
      p1.x = 0;
    }
  if (direction == 180)
  {
    p1.y = p1.y - 1;      // Updates y.
  }
    if (p1.y <0)      // Corects for out-of-bounds.
    {
      p1.y = 7;
    }
  if (direction == 270)
  {
    p1.x = p1.x - 1;      // Updates y.
  }
    if (p1.x <0)      // Corects for out-of-bounds.
    {
      p1.x = 7;
    }
}

void drawSnake()
{
  DrawPx(p1.x,p1.y,Yellow);           // Draw a dot at x=3, y=4, in yellow.
}

