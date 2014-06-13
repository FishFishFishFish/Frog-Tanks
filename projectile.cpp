#include "projectile.h"

void PROJECTILES::fire(VECTOR _p, VECTOR _dp, short _type){
    p.push_back(_p);
    dp.push_back(_dp);
    type.push_back(_type);
}
void PROJECTILES::tick(){
    for (int i = 0; i < p.size(); i++) {
        p[i] += dp[i];
        dp[i].y += dpp;
        
        bool done = parent->terrain.isUnder(p[i]);
        
        int j;
        
        switch (type) {
            case P_CARPETBOMB:
                if (dp[i].y < 0){
                    dp[i].x -= .4;
                    for (j = 0; j < 5; j++){
                        dp[i].x += .2;
                        fire(p[i], dp[i], P_CARPETBOMBCARPET);
                    }
                }
            default:
                if (done){
                    //explode
                }
                break;
        }
    }
}
void PROJECTILES::render(){
    for (int i = 0; i < p.size(); i++) {
        
        switch (type) {
            case P_CARPETBOMB:
                break;
            default:
                break;
        }
    }
}