//
// Created by katya on 20/04/18.
//

#include <iostream>
using namespace std;
 int program(){
     class Animal{
         Animal();
         virtual ~Animal();
     private:
     public:
         float health;
         void move();
     protected:


     };
     class Wolf: public Animal{
     private:
     public:
         float health;
         void move(){

         }
         void TryToEatOrDie();

     protected:

     };
     class Rabbit: public Animal{
     private:
     public:
         void move();
         void spread();

     protected:

     };
     class Wolf_M: public Animal{
     private:
     public:
         float health;
         void move();
         void TryToEatOrDie();

     protected:

     };
     class Wolf_W: public Animal{
     private:
     public:
         float health;
         void move();
         void TryToEatOrDie();
         void TryToMakeOffspring();

     protected:

     };
     class Cell{
     public:
         int coordinates[2];
         Wolf_M wolf_m[];
         Wolf_W wolf_w[];
         Rabbit rabbit[];
         int fence[7];

     private:
     protected:
     };

     class Field{
     public:
         Cell * cells[400];

     };
 }