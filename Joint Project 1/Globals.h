// Contains the game globals
#pragma once
#include "MyVector3.h"

//The direction the sprite is moving in
const int static WEST = 1;
const int static EAST = 2;
const int static NORTH = 3; // direction north
const int static SOUTH = 4;


const float SCREEN_WIDTH = 400;   // the size of the screen in pixels used in the game
const float SCREEN_HEIGHT = 320;

const float LEFT_BOARDER = 20;
const float RIGHT_BOARDER = 360;
const float BOTTOM_BOARDER = 280;
const float TOP_BOARDER = 80;
const float CENTER_OF_CIRCLE = 38;

const int MAX_ARCHERS = 4;

const int SPRITE_WIDTH = 18;
const int SPRITE_HEIGHT = 25;

const float ARROW_WIDTH = 15;
const float ARROW_HEIGHT = 15;

const int MAX_HEALTH = 4;

const int ENEMY_HIT = 100;

const MyVector3 RESPAWN = { 200,80,0 };
const MyVector3 MAX_ENEMY_SPEED = { 2,2,0 };