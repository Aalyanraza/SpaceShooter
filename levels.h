# ifndef level_h
# define level_h

class Levels
{
public:
    int check1;
    int check2;
    int check3;
    int monbool;
    int dragbool;
    int** coordinates;
    virtual void wave1(Enemy*& attack)=0;
    virtual void wave2(Enemy*& attack)=0;
    virtual void wave3(Enemy*& attack)=0;
    void monster(Enemy*& attack)
    {
        attack= new Monster;   
    }
    void dragon(Enemy*& attack)
    {
        attack= new Dragon;   
    }    
};

class Level1: public Levels
{
public:
    Level1()
    {
        coordinates=nullptr;

        check1=0;
        check2=0;
        check3=0;
        monbool=0;
        dragbool=0;
    }

    void wave1(Enemy*& attack)
    {
        if (coordinates!=nullptr)
            delete[] coordinates;
        coordinates= new int* [10];
        for (int i=0; i<10; i++)
        {
            coordinates[i]=new int [2];
        }
        coordinates[0][0]=190; coordinates[0][1]=0;
        coordinates[1][0]=290; coordinates[1][1]=0;
        coordinates[2][0]=390; coordinates[2][1]=0;
        coordinates[3 ][0]=490; coordinates[3][1]=0;
        coordinates[4][0]=190; coordinates[4][1]=75;
        coordinates[5][0]=490; coordinates[5][1]=75;
        coordinates[6][0]=190; coordinates[6][1]=150;
        coordinates[7][0]=290; coordinates[7][1]=150;
        coordinates[8][0]=390; coordinates[8][1]=150;
        coordinates[9][0]=490; coordinates[9][1]=150;
        
        attack = new Alpha[10];
        for (int i=0; i<10; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+43;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+40;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    void wave2(Enemy*& attack)
    {
        if (coordinates!=nullptr)
            delete[] coordinates;    
        coordinates= new int* [9];
        for (int i=0; i<9; i++)
        {
            coordinates[i]=new int [2];
        }
        coordinates[0][0]=250; coordinates[0][1]=50;
        coordinates[1][0]=300; coordinates[1][1]=100;
        coordinates[2][0]=350; coordinates[2][1]=150;
        coordinates[3][0]=400; coordinates[3][1]=100;
        coordinates[4][0]=450; coordinates[4][1]=50;
        coordinates[5][0]=300; coordinates[5][1]=200;
        coordinates[6][0]=250; coordinates[6][1]=250;
        coordinates[7][0]=400; coordinates[7][1]=200;
        coordinates[8][0]=450; coordinates[8][1]=250;

        attack = new Alpha[9];
        for (int i=0; i<9; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+43;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+40;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    void wave3(Enemy*& attack)
    {
        if (coordinates!=nullptr)
            delete[] coordinates;
        coordinates= new int* [12];
        for (int i=0; i<12; i++)
        {
            coordinates[i]=new int [2];
        }
        coordinates[0][0]=350; coordinates[0][1]=50;
        coordinates[1][0]=300; coordinates[1][1]=100;
        coordinates[2][0]=400; coordinates[2][1]=100;
        coordinates[3][0]=250; coordinates[3][1]=150;
        coordinates[4][0]=450; coordinates[4][1]=150;
        coordinates[5][0]=200; coordinates[5][1]=200;
        coordinates[6][0]=500; coordinates[6][1]=200;
        coordinates[7][0]=150; coordinates[7][1]=250;
        coordinates[8][0]=250; coordinates[8][1]=250;
        coordinates[9][0]=350; coordinates[9][1]=250;
        coordinates[10][0]=450; coordinates[10][1]=250;
        coordinates[11][0]=550; coordinates[11][1]=250;    

        attack = new Alpha[12];
        for (int i=0; i<12; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+43;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+40;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    
};
class Level2: public Levels
{
public:
    Level2()
    {
        coordinates=nullptr;

        check1=0;
        check2=0;
        check3=0;
        monbool=0;
        dragbool=0;
    }

    void wave1(Enemy*& attack)
    {
        coordinates= new int* [12];
        for (int i=0; i<12; i++)
        {
            coordinates[i]=new int [2];
        } 
        coordinates[0][0]=375; coordinates[0][1]=50;
        coordinates[1][0]=295; coordinates[1][1]=75;
        coordinates[2][0]=235; coordinates[2][1]=120;
        coordinates[3][0]=200; coordinates[3][1]=180;
        coordinates[4][0]=235; coordinates[4][1]=240;
        coordinates[5][0]=295; coordinates[5][1]=285;
        coordinates[6][0]=375; coordinates[6][1]=310;
        coordinates[7][0]=455; coordinates[7][1]=285;
        coordinates[8][0]=515; coordinates[8][1]=240;
        coordinates[9][0]=550; coordinates[9][1]=180;
        coordinates[10][0]=515; coordinates[10][1]=120;
        coordinates[11][0]=455; coordinates[11][1]=75;
       
        attack = new Beta[12];
        for (int i=0; i<12; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+40;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+70;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    void wave2(Enemy*& attack)
    {
        coordinates= new int* [12];
        for (int i=0; i<12; i++)
        {
            coordinates[i]=new int [2];
        } 
        coordinates[0][0]=375; coordinates[0][1]=50;
        coordinates[1][0]=317; coordinates[1][1]=93;
        coordinates[2][0]=258; coordinates[2][1]=137;
        coordinates[3][0]=200; coordinates[3][1]=180;
        coordinates[4][0]=258; coordinates[4][1]=223;
        coordinates[5][0]=317; coordinates[5][1]=267;
        coordinates[6][0]=375; coordinates[6][1]=310;
        coordinates[7][0]=433; coordinates[7][1]=267;
        coordinates[8][0]=492; coordinates[8][1]=223;
        coordinates[9][0]=550; coordinates[9][1]=180;
        coordinates[10][0]=492; coordinates[10][1]=137;
        coordinates[11][0]=433; coordinates[11][1]=93;

        attack = new Beta[12];
        for (int i=0; i<12; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+40;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+70;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    void wave3(Enemy*& attack)
    {
        coordinates= new int* [12];
        for (int i=0; i<12; i++)
        {
            coordinates[i]=new int [2];
        } 
        coordinates[0][0]=360; coordinates[0][1]=100;
        coordinates[1][0]=300; coordinates[1][1]=40;
        coordinates[2][0]=240; coordinates[2][1]=50;
        coordinates[3][0]=190; coordinates[3][1]=100;
        coordinates[4][0]=210; coordinates[4][1]=170;
        coordinates[5][0]=280; coordinates[5][1]=225;
        coordinates[6][0]=360; coordinates[6][1]=270;
        coordinates[7][0]=440; coordinates[7][1]=225;
        coordinates[8][0]=510; coordinates[8][1]=180;
        coordinates[9][0]=540; coordinates[9][1]=100;
        coordinates[10][0]=480; coordinates[10][1]=50;
        coordinates[11][0]=420; coordinates[11][1]=40;

        attack = new Beta[12];
        for (int i=0; i<12; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+40;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+70;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
};
class Level3: public Levels
{
public:
    int check4;
    int check5;
    int check6;
    Level3()
    {
        coordinates=nullptr;

        check1=0;
        check2=0;
        check3=0;
        check4=0;
        check5=0;
        check6=0;
        monbool=0;
        dragbool=0;

    }

    void wave1(Enemy*& attack)
    {
        coordinates= new int* [10];
        for (int i=0; i<10; i++)
        {
            coordinates[i]=new int [2];
        } 
        coordinates[0][0]=190; coordinates[0][1]=0;
        coordinates[1][0]=290; coordinates[1][1]=0;
        coordinates[2][0]=390; coordinates[2][1]=0;
        coordinates[3][0]=490; coordinates[3][1]=0;
        coordinates[4][0]=190; coordinates[4][1]=75;
        coordinates[5][0]=490; coordinates[5][1]=75;
        coordinates[6][0]=190; coordinates[6][1]=150;
        coordinates[7][0]=290; coordinates[7][1]=150;
        coordinates[8][0]=390; coordinates[8][1]=150;
        coordinates[9][0]=490; coordinates[9][1]=150;
        attack = new Gamma[10];
        for (int i=0; i<10; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+40;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+50;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    void wave2(Enemy*& attack)
    {
        coordinates= new int* [9];
        for (int i=0; i<9; i++)
        {
            coordinates[i]=new int [2];
        }
        coordinates[0][0]=250; coordinates[0][1]=50;
        coordinates[1][0]=300; coordinates[1][1]=100;
        coordinates[2][0]=350; coordinates[2][1]=150;
        coordinates[3][0]=400; coordinates[3][1]=100;
        coordinates[4][0]=450; coordinates[4][1]=50;
        coordinates[5][0]=300; coordinates[5][1]=200;
        coordinates[6][0]=250; coordinates[6][1]=250;
        coordinates[7][0]=400; coordinates[7][1]=200;
        coordinates[8][0]=450; coordinates[8][1]=250;

        attack = new Gamma[9];
        for (int i=0; i<9; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+40;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+50;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    void wave3(Enemy*& attack)
    {
        coordinates= new int* [12];
        for (int i=0; i<12; i++)
        {
            coordinates[i]=new int [2];
        }
        coordinates[0][0]=350; coordinates[0][1]=50;
        coordinates[1][0]=300; coordinates[1][1]=100;
        coordinates[2][0]=400; coordinates[2][1]=100;
        coordinates[3][0]=250; coordinates[3][1]=150;
        coordinates[4][0]=450; coordinates[4][1]=150;
        coordinates[5][0]=200; coordinates[5][1]=200;
        coordinates[6][0]=500; coordinates[6][1]=200;
        coordinates[7][0]=150; coordinates[7][1]=250;
        coordinates[8][0]=250; coordinates[8][1]=250;
        coordinates[9][0]=350; coordinates[9][1]=250;
        coordinates[10][0]=450; coordinates[10][1]=250;
        coordinates[11][0]=550; coordinates[11][1]=250;    

        attack = new Gamma[12];
        for (int i=0; i<12; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+40;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+50;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    
    void wave4(Enemy*& attack)
    {
        coordinates= new int* [12];
        for (int i=0; i<12; i++)
        {
            coordinates[i]=new int [2];
        } 
        coordinates[0][0]=375; coordinates[0][1]=50;
        coordinates[1][0]=295; coordinates[1][1]=75;
        coordinates[2][0]=235; coordinates[2][1]=120;
        coordinates[3][0]=200; coordinates[3][1]=180;
        coordinates[4][0]=235; coordinates[4][1]=240;
        coordinates[5][0]=295; coordinates[5][1]=285;
        coordinates[6][0]=375; coordinates[6][1]=310;
        coordinates[7][0]=455; coordinates[7][1]=285;
        coordinates[8][0]=515; coordinates[8][1]=240;
        coordinates[9][0]=550; coordinates[9][1]=180;
        coordinates[10][0]=515; coordinates[10][1]=120;
        coordinates[11][0]=455; coordinates[11][1]=75;
       
        attack = new Gamma[12];
        for (int i=0; i<12; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+40;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+50;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    void wave5(Enemy*& attack)
    {
        coordinates= new int* [12];
        for (int i=0; i<12; i++)
        {
            coordinates[i]=new int [2];
        } 
        coordinates[0][0]=375; coordinates[0][1]=50;
        coordinates[1][0]=317; coordinates[1][1]=93;
        coordinates[2][0]=258; coordinates[2][1]=137;
        coordinates[3][0]=200; coordinates[3][1]=180;
        coordinates[4][0]=258; coordinates[4][1]=223;
        coordinates[5][0]=317; coordinates[5][1]=267;
        coordinates[6][0]=375; coordinates[6][1]=310;
        coordinates[7][0]=433; coordinates[7][1]=267;
        coordinates[8][0]=492; coordinates[8][1]=223;
        coordinates[9][0]=550; coordinates[9][1]=180;
        coordinates[10][0]=492; coordinates[10][1]=137;
        coordinates[11][0]=433; coordinates[11][1]=93;

        attack = new Gamma[12];
        for (int i=0; i<12; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+40;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+50;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
    void wave6(Enemy*& attack)
    {
        coordinates= new int* [12];
        for (int i=0; i<12; i++)
        {
            coordinates[i]=new int [2];
        } 
        coordinates[0][0]=360; coordinates[0][1]=100;
        coordinates[1][0]=300; coordinates[1][1]=40;
        coordinates[2][0]=240; coordinates[2][1]=50;
        coordinates[3][0]=190; coordinates[3][1]=100;
        coordinates[4][0]=210; coordinates[4][1]=170;
        coordinates[5][0]=280; coordinates[5][1]=225;
        coordinates[6][0]=360; coordinates[6][1]=270;
        coordinates[7][0]=440; coordinates[7][1]=225;
        coordinates[8][0]=510; coordinates[8][1]=180;
        coordinates[9][0]=540; coordinates[9][1]=100;
        coordinates[10][0]=480; coordinates[10][1]=50;
        coordinates[11][0]=420; coordinates[11][1]=40;

        attack = new Gamma[12];
        for (int i=0; i<12; i++)
        {
            attack[i].x=coordinates[i][0];
            attack[i].bomb->x=coordinates[i][0]+40;
            attack[i].y=coordinates[i][1];
            attack[i].bomb->y=coordinates[i][1]+50;
            attack[i].bomb->sprite.setPosition(attack[i].bomb->x,attack[i].bomb->y);
            attack[i].ensprite.setPosition(attack[i].x,attack[i].y);
        }
    }
};

#endif
