#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>

class Dungeon {
    int xmax, ymax, xsize, ysize;
    
    int* dungeon_map;
    long oldseed;
    
    enum {
        tileUnused = 0,
        tileWall,
        tileCorridor,
        tileDoor,
        tileChest,
        tileFloor
    };
    
    void setCell(int x, int y, int cellType) {
        dungeon_map[x + xsize * y] = cellType;
    }
    
    int getCell(int x, int y) {
        return dungeon_map[x + xsize * y];
    }
    
    int getRand(int min, int max) {
        time_t = seed;
        seed = time(NULL) + oldseed;
        oldseed = seed;
        
        srand(seed);
        int n = max - min + 1;
        int i = rand() % n;
        
        if (i < 0) { 
            i = -i;
        }
        
        return min + i;
    }
    
    void showDungeon() {
        for (int y = 0; y < ysize; ++y) {
            for (int x = 0; x < xsize; ++x) {
                switch(getCell(x,y)) {
                    case tileUnused:
                        cout << " ";
                        break;
                    case tileWall:
                        cout << "#";
                        break;
                    case tileCorridor:
                        cout << ".";
                        break;
                    case tileDoor:
                        cout << "+";
                        break;
                    case tileChest:
                        cout << "*";
                        break;
                    case tileFloor:
                        cout << ".";
                };
            }
        }
    }
    
    bool makeRoom(int x, int y, int xlength, int ylength, int direction) {
        //dimensions of the room. At least 4*4, so the walls can be built in, and the rest 
        //would be the ground, to walk.
        
        int xlen = getRand(4, xlength);
        int ylen = getRand(4, ylength);
        int floor = tileFloor;
        int wall = tileWall;
        int dir = 0;
        //Now we must choose the direction it's poiting at:
        if (direction > 0 && direction < 4) {
            dir = direction;
        }
        
        switch(dir) {
            case 0: //Let's say : North direction
                for (int ytmp = y; ytmp > (y-ylen); ytmp--) {
                    if (ytmp < 0 || ytmp > ysize) {
                        return false;
                    }
                    for (int xtmp = (x-xlen/2); xtmp < (x+(xlen+1)/2); xtmp ++) {
                        if (xtmp < 0 || xtmp > xsize) {
                            return false;
                        }
                        if (getCell(xtmp, ytmp) != tileUnused) {
                            return false; //there's no space left
                        }
                    }
                }
                //Building !
                for (int ytmp = y; ytmp > (y-ylen); ytmp--){
                    for (int xtmp = (x-xlen/2); xtmp < (x+(xlen+1)/2); xtmp++) {
                        //We build the walls all around the room
                        if (xtmp == (x-xlen/2)) {
                            setCell(xtmp, ytmp, wall);
                        } else if (xtemp == (x+(xlen-1)/2)) {
                            setCell(xtemp, ytemp, wall);
                        } else if (ytemp == y) {
                            setCell(xtemp, ytemp, wall);
					    } else if (ytemp == (y-ylen+1)) {
					        setCell(xtemp, ytemp, wall);
					    }
                    }
                }
            break;
        };
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
