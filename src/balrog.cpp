//~Isbah
#include "balrog.h"
#include<iostream>
using namespace std;

#define IS_IDLE (curr_state == AnimationState::idle)

sf::IntRect Balrog::idle_frames[6];
sf::IntRect Balrog::move_frames[6];
sf::IntRect Balrog::light_punch_frames[3];
sf::IntRect Balrog::medium_punch_frames[3];
sf::IntRect Balrog::heavy_punch_frames[3];
sf::IntRect Balrog::alt_light_punch_frames[3];
sf::IntRect Balrog::alt_medium_punch_frames[5];
sf::IntRect Balrog::alt_heavy_punch_frames[5];
sf::IntRect Balrog::jump_frames[7];
sf::IntRect Balrog::jump_punch_frames[9];
sf::IntRect Balrog::crouch_light_punch_frames[5];
sf::IntRect Balrog::crouch_medium_punch_frames[5];
sf::IntRect Balrog::special_move1[9];
sf::IntRect Balrog::special_move2[11];
sf::IntRect Balrog::medium_hit_taken_body_frames[3];
sf::IntRect Balrog::knockout_frames[12];
sf::IntRect Balrog::forward_light_punch_frames[3];
sf::IntRect Balrog::forward_medium_punch_frames[5];
sf::IntRect Balrog::forward_heavy_punch_frames[5];
sf::IntRect Balrog::victory1_frames[5];
sf::IntRect Balrog::victory2_frames[5];
sf::IntRect Balrog::shirt_frames[4]; //good name - its fitting

Balrog::Balrog() {
    if (!image.loadFromFile("assets/players/Balrog.png")) {
        cerr << "Err loading character";
        exit(EXIT_FAILURE);
    }//spritesheet
    image.createMaskFromColor(sf::Color(149, 155, 149));
    texture.loadFromImage(image);
    player.setTexture(texture);
    shirt_right.setTexture(texture);

    idle_frames[0] = sf::IntRect(15, 220, 63, 112);
    idle_frames[1] = sf::IntRect(85, 220, 63, 112);
    idle_frames[2] = sf::IntRect(155, 220, 63, 112);
    idle_frames[3] = sf::IntRect(225, 220, 63, 112);
    idle_frames[4] = sf::IntRect(295, 220, 63, 112);
    idle_frames[5] = sf::IntRect(365, 220, 63, 112);

    move_frames[0] = sf::IntRect(15, 370,63, 112);
    move_frames[1] = sf::IntRect(85, 370, 63, 112);
    move_frames[2] = sf::IntRect(155, 370, 63, 112);
    move_frames[3] = sf::IntRect(225, 370, 63, 112);
    move_frames[4] = sf::IntRect(295, 370, 63, 112);
    move_frames[5] = sf::IntRect(365, 370, 63, 112);

    light_punch_frames[0] = sf::IntRect(14, 1297, 67, 111);
    light_punch_frames[1] = sf::IntRect(86, 1297, 83, 111);
    light_punch_frames[2] = sf::IntRect(14, 1297, 67, 111);

    medium_punch_frames[0] = sf::IntRect(15, 1148, 92, 111);
    medium_punch_frames[1] = sf::IntRect(113, 1128, 113, 131);
    medium_punch_frames[2] = sf::IntRect(15, 1148, 92, 111);

    heavy_punch_frames[0] = sf::IntRect(412, 833, 115, 107);
    heavy_punch_frames[1] = sf::IntRect(525, 833, 145, 107);
    heavy_punch_frames[2] = sf::IntRect(412, 833, 115, 107);

    alt_light_punch_frames[0] = sf::IntRect(15, 540, 79, 112);
    alt_light_punch_frames[1] = sf::IntRect(98, 540, 115, 112);
    alt_light_punch_frames[2] = sf::IntRect(15, 540, 79, 112);

    alt_medium_punch_frames[0] = sf::IntRect(368, 1148, 68, 111);
    alt_medium_punch_frames[1] = sf::IntRect(442, 1148, 90, 111);
    alt_medium_punch_frames[2] = sf::IntRect(538, 1148, 146, 111);
    alt_medium_punch_frames[3] = sf::IntRect(442, 1148, 90, 111);
    alt_medium_punch_frames[4] = sf::IntRect(368, 1148, 68, 111);

    alt_heavy_punch_frames[0] = sf::IntRect(344, 540, 89, 112);
    alt_heavy_punch_frames[1] = sf::IntRect(436, 540, 115, 112);
    alt_heavy_punch_frames[2] = sf::IntRect(550, 518, 145, 134);
    alt_heavy_punch_frames[3] = sf::IntRect(436, 540, 115, 112);
    alt_heavy_punch_frames[4] = sf::IntRect(344, 540, 89, 112);

    jump_frames[0] = sf::IntRect(14, 1975, 67, 97);
    jump_frames[1] = sf::IntRect(84, 1971, 67, 100);
    jump_frames[2] = sf::IntRect(154, 1925, 67, 80);
    jump_frames[3] = sf::IntRect(224, 1925, 67, 66);
    jump_frames[4] = sf::IntRect(154, 1925, 67, 80);
    jump_frames[5] = sf::IntRect(84, 1971, 67, 100);
    jump_frames[6] = sf::IntRect(14, 1975, 67, 97);

    jump_punch_frames[0] = sf::IntRect(14, 2112, 67, 97);
    jump_punch_frames[1] = sf::IntRect(84, 2108, 67, 101);
    jump_punch_frames[2] = sf::IntRect(155, 2130, 80, 78);
    jump_punch_frames[3] = sf::IntRect(404, 2125, 100, 84);
    jump_punch_frames[4] = sf::IntRect(340, 2125, 60, 88);
    jump_punch_frames[5] = sf::IntRect(404, 2125, 100, 84);
    jump_punch_frames[6] = sf::IntRect(155, 2130, 80, 78);
    jump_punch_frames[7] = sf::IntRect(84, 2108, 67, 101);
    jump_punch_frames[8] = sf::IntRect(14, 2112, 67, 97);

    crouch_light_punch_frames[0] = sf::IntRect(12, 1805, 57, 80);
    crouch_light_punch_frames[1] = sf::IntRect(74, 1805, 75, 80);
    crouch_light_punch_frames[2] = sf::IntRect(154, 1805, 140, 80);
    crouch_light_punch_frames[3] = sf::IntRect(74, 1805, 75, 80);
    crouch_light_punch_frames[4] = sf::IntRect(12, 1805, 57, 80);

    crouch_medium_punch_frames[0] = sf::IntRect(480, 1805, 67, 80);
    crouch_medium_punch_frames[1] = sf::IntRect(546, 1798, 92, 87);
    crouch_medium_punch_frames[2] = sf::IntRect(642, 1753, 115, 132);
    crouch_medium_punch_frames[3] = sf::IntRect(546, 1798, 92, 87);
    crouch_medium_punch_frames[4] = sf::IntRect(480, 1805, 67, 80);

    special_move1[0] = sf::IntRect(14, 2270, 90, 108);
    special_move1[1] = sf::IntRect(110, 2270, 101, 108);
    special_move1[2] = sf::IntRect(214, 2283, 190, 95);
    special_move1[3] = sf::IntRect(410, 2267, 90, 111);
    special_move1[4] = sf::IntRect(506, 2267, 68, 111);
    special_move1[5] = sf::IntRect(617, 2270, 72, 108);
    special_move1[6] = sf::IntRect(690, 2270, 117, 108);
    special_move1[7] = sf::IntRect(808, 2248, 132, 130);
    special_move1[8] = sf::IntRect(946, 2270, 93, 108);

    special_move2[0] = sf::IntRect(14, 2425, 56, 103);
    special_move2[1] = sf::IntRect(72, 2425, 64, 103);
    special_move2[2] = sf::IntRect(140, 2430, 80, 98);
    special_move2[3] = sf::IntRect(225, 2445, 91, 83);
    special_move2[4] = sf::IntRect(322, 2425, 53, 103);
    special_move2[5] = sf::IntRect(380, 2423, 76, 105);
    special_move2[6] = sf::IntRect(461, 2420, 93, 108);
    special_move2[7] = sf::IntRect(555, 2420, 101, 108);
    special_move2[8] = sf::IntRect(663, 2433, 187, 95);
    special_move2[9] = sf::IntRect(855, 2415, 89, 113);
    special_move2[10] = sf::IntRect(952, 2415, 67, 113);
    
    medium_hit_taken_body_frames[0] = sf::IntRect(400, 2737, 68, 98);
    medium_hit_taken_body_frames[1] = sf::IntRect(770, 2737, 72, 98);
    medium_hit_taken_body_frames[2] = sf::IntRect(400, 2737, 68, 98);

    knockout_frames[0] = sf::IntRect(14, 2717, 68, 118);
    knockout_frames[1] = sf::IntRect(202, 2717, 75, 118);
    knockout_frames[2] = sf::IntRect(14, 3044, 75, 100);
    knockout_frames[3] = sf::IntRect(95, 3088, 113, 55);
    knockout_frames[4] = sf::IntRect(214, 3088, 113, 55);
    knockout_frames[5] = sf::IntRect(95, 3088, 113, 55);
    knockout_frames[6] = sf::IntRect(214, 3088, 113, 55);
    knockout_frames[7] = sf::IntRect(570, 3088, 130, 52);
    knockout_frames[8] = sf::IntRect(740, 3240, 150, 75);
    knockout_frames[9] = sf::IntRect(890, 3240, 130, 75);
    knockout_frames[10] = sf::IntRect(14, 1639, 65, 76);

    forward_light_punch_frames[0] = sf::IntRect(14, 833, 110, 111);
    forward_light_punch_frames[1] = sf::IntRect(127, 833, 122, 111);
    forward_light_punch_frames[2] = sf::IntRect(14, 833, 110, 111);
    
    forward_medium_punch_frames[0] = sf::IntRect(14, 979, 78, 110);
    forward_medium_punch_frames[1] = sf::IntRect(97, 979, 110, 110);
    forward_medium_punch_frames[2] = sf::IntRect(212, 979, 139, 110);
    forward_medium_punch_frames[3] = sf::IntRect(97, 979, 110, 110);
    forward_medium_punch_frames[4] = sf::IntRect(14, 979, 78, 110);

    forward_heavy_punch_frames[0] = sf::IntRect(15, 683, 82, 112);
    forward_heavy_punch_frames[1] = sf::IntRect(102, 683, 112, 111);
    forward_heavy_punch_frames[2] = sf::IntRect(217, 683, 190, 111);
    forward_heavy_punch_frames[3] = sf::IntRect(102, 683, 112, 111);
    forward_heavy_punch_frames[4] = sf::IntRect(15, 683, 82, 112);

    victory1_frames[0] = sf::IntRect(130, 4210, 65, 110);
    victory1_frames[1] = sf::IntRect(197, 4210, 85, 110);
    victory1_frames[2] = sf::IntRect(285, 4190, 105, 130);
    victory1_frames[3] = sf::IntRect(395, 4190, 143, 130);
    victory1_frames[4] = sf::IntRect(545, 4190, 100, 130);

    victory2_frames[0] = sf::IntRect(130, 4210, 65, 110);
    victory2_frames[1] = sf::IntRect(197, 4210, 85, 110);
    victory2_frames[2] = sf::IntRect(165, 4356, 105, 130);
    victory2_frames[3] = sf::IntRect(275, 4356, 143, 130);
    victory2_frames[4] = sf::IntRect(425, 4356, 100, 130);

    shirt_frames[0] = sf::IntRect(569, 4450, 50, 40);
    shirt_frames[1] = sf::IntRect(623, 4450, 40, 40);
    shirt_frames[2] = sf::IntRect(663, 4450, 40, 40);
    shirt_frames[3] = sf::IntRect(700, 4450, 40, 40);

    shirt_left.setTexture(texture);
    shirt_left.setTextureRect(shirt_frames[0]);
    shirt_left.setScale(PLAYER_SPRITE_X_SCALE, PLAYER_SPRITE_Y_SCALE);
    shirt_left.setPosition(-100, -100);
    player.setTextureRect(idle_frames[0]);
    player.setScale(PLAYER_SPRITE_X_SCALE, PLAYER_SPRITE_Y_SCALE);
    shirt_right.setScale(-PLAYER_SPRITE_X_SCALE, PLAYER_SPRITE_Y_SCALE);
    curr_state = AnimationState::idle;
}

//movements
void Balrog::moveRight(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::move_right;
        limit = bound;
    }
}
void Balrog::flippedMoveRight(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::flipped_move_right;
        limit = bound;
    }
}
void Balrog::moveLeft(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 5;
        curr_state = AnimationState::move_left;
        limit = bound;
    }
}
void Balrog::flippedMoveLeft(float bound) {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::flipped_move_left;
        limit = bound;
    }
}
bool Balrog::jump() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::jump;
        return true;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::jump_forward;
        return true;
    }
    else if (curr_state == AnimationState::move_left) {
        curr_frame = 0;
        curr_state = AnimationState::jump_backward;
        return true;
    }
    return false;
}
bool Balrog::crouch() {
    if (curr_state == AnimationState::idle) {
        curr_state = AnimationState::crouching;
        player.setTextureRect(sf::IntRect(14, 1639, 65, 76));
        player.setPosition(player.getPosition().x - 20, BOTTOMY - player.getGlobalBounds().height);
        return true;
    }
    return false;
}
bool Balrog::uncrouch() {
    if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[curr_frame]);
        player.setPosition(player.getPosition().x + 20, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::idle;
        return true;
    }
    return false;
}
//hits dealt
bool Balrog::punch1() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::light_punch_right;
        return true;
    }
    else if (curr_state == AnimationState::light_punch_right) {
        combo = true;
        return true;
    }
    else if (curr_state == AnimationState::jump && curr_frame <= 1) { // cant have them jump punching at apex of jump must be at/near start
        curr_state = AnimationState::jump_punch;
        return true;
    }
    else if (curr_state == AnimationState::jump_forward && curr_frame <= 1) { // cant have them jump punching at apex of jump must be at/near start
        curr_state = AnimationState::forward_jump_punch;
        return true;
    }
    else if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        curr_state = AnimationState::crouch_light_punch;
        return true;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::forward_light_punch;
        return true;
    }
    return false;
}
bool Balrog::punch2() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::medium_punch_right;
        return true;
    }
    else if (curr_state == AnimationState::medium_punch_right) {
        combo = true;
        return true;
    }
    else if (curr_state == AnimationState::crouching) {
        curr_frame = 0;
        curr_state = AnimationState::crouch_medium_punch;
        return true;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::forward_medium_punch;
        return true;
    }
    return false;
}
bool Balrog::punch3() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::heavy_punch_right;
        return true;
    }
    else if (curr_state == AnimationState::heavy_punch_right) {
        combo = true;
        return true;
    }
    else if (curr_state == AnimationState::move_right) {
        curr_frame = 0;
        curr_state = AnimationState::forward_heavy_punch;
        return true;
    }
    return false;
}
bool Balrog::specialMove1() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::special_move1;
        return true;
    }
    return false;
}
bool Balrog::specialMove2() {
    if (curr_state == AnimationState::idle) {
        curr_frame = 0;
        curr_state = AnimationState::special_move2;
        return true;
    }
    return false;
}
void Balrog::victory(int type) {
    curr_frame = 0;
    switch (type) {
    case 1:
        curr_state = AnimationState::victory_1;
        return;// true;
    case 2:
        curr_state = AnimationState::victory_2;
        return;// true;
    }
    return;// false;
}
void Balrog::knockout(){
    knockout(2);
}
void Balrog::knockout(int type) {
    switch (type) {
    case 1:
        curr_frame = 0;
        curr_state = AnimationState::knockout;
        break;
    case 2:
        curr_frame = 0;
        if(player.getScale().x < 0)
            curr_state = AnimationState::defeat_enemy;
        else
            curr_state = AnimationState::defeat_player;
        break;
    }
}
void Balrog::update(float time) {
    time_elapsed += time;
    if (time_elapsed >= IDLE_TIME && curr_state == AnimationState::idle) {
        curr_frame = curr_frame + incr_to_next_frame;
        player.setTextureRect(idle_frames[curr_frame]);
        if (!curr_frame)
            incr_to_next_frame = 1;
        else if (curr_frame == 5)
            incr_to_next_frame = -1;
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        else {
            if (curr_frame > 0 && curr_frame < 4)
                    setPosition(player.getPosition().x, player.getPosition().y - 50);
            else if (curr_frame > 3 && curr_frame < 7)
                    setPosition(player.getPosition().x, player.getPosition().y + 50);
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump_forward) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        
        else {
            if (curr_frame > 0 && curr_frame < 4){
                if (player.getPosition().x + 25 <= 570)
                    setPosition(player.getPosition().x + 25, player.getPosition().y - 50);
                else
                    setPosition(player.getPosition().x, player.getPosition().y - 50);
            }
            else if (curr_frame > 3 && curr_frame < 7){
                if (player.getPosition().x + 50 <= 570)
                  setPosition(player.getPosition().x + 50, player.getPosition().y + 50);
                else
                  setPosition(player.getPosition().x, player.getPosition().y + 50);
            }
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::move_right) {
        if (curr_frame == 6) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x + 10 <= limit)
                setPosition(player.getPosition().x + 10, player.getPosition().y);
            player.setTextureRect(move_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::flipped_move_right) {
        if (curr_frame == 6) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x + 10 <= limit)
                setPosition(player.getPosition().x + 10, player.getPosition().y);
            player.setTextureRect(move_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::move_left) {
        if (curr_frame == -1) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x - 10 >= limit)
                setPosition(player.getPosition().x - 10, player.getPosition().y);
            player.setTextureRect(move_frames[curr_frame--]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::flipped_move_left) {
        if (curr_frame == 6) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (player.getPosition().x - 10 >= limit)
                setPosition(player.getPosition().x - 10, player.getPosition().y);
            player.setTextureRect(move_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::light_punch_right) {
        if (curr_frame == 3) {
            if (combo) {
                curr_frame = 0;
                combo = false;
                curr_state = AnimationState::alt_light_punch;
                player.setTextureRect(alt_light_punch_frames[curr_frame++]);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
            }
        }
        else
            player.setTextureRect(light_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::heavy_punch_right) {
        if (curr_frame == 3) {
            if (combo) {
                curr_frame = 0;
                combo = false;
                curr_state = AnimationState::alt_heavy_punch;
                player.setTextureRect(alt_heavy_punch_frames[curr_frame++]);
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
            }
        }
        else {
            player.setTextureRect(heavy_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_light_punch) {
        if (curr_frame == 3) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            player.setTextureRect(forward_light_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_heavy_punch) {
    if (curr_frame == 5) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        curr_state = AnimationState::idle;
    }
    else
        player.setTextureRect(forward_heavy_punch_frames[curr_frame++]);
    time_elapsed = 0;
    return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::medium_punch_right) {
        if (curr_frame == 3) {
            if (combo) {
                curr_frame = 0;
                combo = false;
                curr_state = AnimationState::alt_medium_punch;
                player.setTextureRect(alt_medium_punch_frames[curr_frame++]);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                curr_state = AnimationState::idle;
            }
        }
        else {
            player.setTextureRect(medium_punch_frames[curr_frame++]);
            //cout << player.getGlobalBounds().left << endl;
            //scout << player.getPosition().x << endl;
            player.setPosition(player.getPosition().x,BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::alt_light_punch) {
        if (curr_frame == 3) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            player.setTextureRect(alt_light_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::alt_heavy_punch) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(alt_heavy_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::alt_medium_punch) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else
            player.setTextureRect(alt_medium_punch_frames[curr_frame++]);
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_medium_punch) {
        if (curr_frame == 5) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(forward_medium_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::crouch_light_punch) {
        if (curr_frame == 5)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                player.setTextureRect(sf::IntRect(14, 1639, 65, 76));
                player.setPosition(player.getPosition().x - 30, BOTTOMY - player.getGlobalBounds().height);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
                curr_state = AnimationState::idle;
            }
        else {
            player.setTextureRect(crouch_light_punch_frames[curr_frame++]);
            if(curr_frame == 1)
                player.setPosition(player.getPosition().x + 30, BOTTOMY - player.getGlobalBounds().height);
            if (curr_frame == 3)
                player.setPosition(player.getPosition().x - 18, player.getPosition().y);
            if (curr_frame == 4)
                player.setPosition(player.getPosition().x + 18, player.getPosition().y);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::crouch_medium_punch) {
        if (curr_frame == 5)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                curr_state = AnimationState::crouching;
                player.setTextureRect(sf::IntRect(14, 1639, 65, 76));
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            }
            else {
                curr_frame = 0;
                incr_to_next_frame = 1;
                player.setTextureRect(idle_frames[0]);
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
                curr_state = AnimationState::idle;
            }
        else {
            player.setTextureRect(crouch_medium_punch_frames[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump_punch) {
    if (curr_frame == 9) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        curr_state = AnimationState::idle;
        player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
    }
    else {
        if (curr_frame > 0 && curr_frame < 4)
            setPosition(player.getPosition().x, player.getPosition().y - 40);
        else if (curr_frame > 4 && curr_frame < 8)
            setPosition(player.getPosition().x, player.getPosition().y + 40);
        player.setTextureRect(jump_punch_frames[curr_frame++]);
    }
    time_elapsed = 0;
    return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::forward_jump_punch) {
    if (curr_frame == 9) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        curr_state = AnimationState::idle;
        player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
    }
    else {
        if (curr_frame > 0 && curr_frame < 4){
            if (player.getPosition().x + 25 <= 570)
                setPosition(player.getPosition().x + 25, player.getPosition().y - 50);
            else
                setPosition(player.getPosition().x, player.getPosition().y - 50);
        }
        else if (curr_frame > 4 && curr_frame < 8){
            if (player.getPosition().x + 50 <= 570)
                setPosition(player.getPosition().x + 50, player.getPosition().y + 50);
            else
                setPosition(player.getPosition().x, player.getPosition().y + 50);
        }
        player.setTextureRect(jump_punch_frames[curr_frame++]);
    }
    time_elapsed = 0;
    return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::jump_backward) {
        if (curr_frame == 7) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            curr_state = AnimationState::idle;
        }
        else {
            if (curr_frame > 0 && curr_frame < 4){
                if (player.getPosition().x - 50 >= 0)
                    setPosition(player.getPosition().x - 50, player.getPosition().y - 50);
                else
                    setPosition(player.getPosition().x, player.getPosition().y - 50);
            }
            else if (curr_frame > 3 && curr_frame < 7){
                if (player.getPosition().x - 25 >= 0)
                    setPosition(player.getPosition().x - 25, player.getPosition().y + 50);
                else
                    setPosition(player.getPosition().x, player.getPosition().y + 50);
            }
            player.setTextureRect(jump_frames[curr_frame++]);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::medium_hit_taken_body) {
    if (curr_frame == 3) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        curr_state = AnimationState::idle;
        player.setPosition(player.getPosition().x +30, BOTTOMY - player.getGlobalBounds().height);
    }
    else {
        player.setTextureRect(medium_hit_taken_body_frames[curr_frame++]);
        if (curr_frame == 1)
            player.setPosition(player.getPosition().x - 30, BOTTOMY - player.getGlobalBounds().height);
        else
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
    }
    time_elapsed = 0;
    return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::special_move1) {
        if (curr_frame == 9) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            player.setTextureRect(special_move1[curr_frame++]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            //if (curr_frame == 4)
           //     player.setPosition(player.getPosition().x + 80, BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::special_move2) {
    if (curr_frame == 11) {
        curr_frame = 0;
        incr_to_next_frame = 1;
        player.setTextureRect(idle_frames[0]);
        player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        curr_state = AnimationState::idle;
    }
    else {
        player.setTextureRect(special_move2[curr_frame++]);
        player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
        if (curr_frame == 1)
            player.setPosition(player.getPosition().x - 13, BOTTOMY - player.getGlobalBounds().height);
        else if(curr_frame == 2)
            player.setPosition(player.getPosition().x - 15, BOTTOMY - player.getGlobalBounds().height);
        else if(curr_frame == 3)
            player.setPosition(player.getPosition().x - 58, BOTTOMY - player.getGlobalBounds().height);
        else if(curr_frame == 4)
            player.setPosition(player.getPosition().x - 18, BOTTOMY - player.getGlobalBounds().height);
        else if(curr_frame == 7)
            player.setPosition(player.getPosition().x + 35, BOTTOMY - player.getGlobalBounds().height);
        else if (curr_frame == 10)
            player.setPosition(player.getPosition().x + 80, BOTTOMY - player.getGlobalBounds().height);
    }
    time_elapsed = 0;
    return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::victory_1) {
        if (curr_frame == 5) {
            curr_state = AnimationState::still;
        }
        else {
            player.setTextureRect(victory1_frames[curr_frame++]);
            if (curr_frame == 1 || curr_frame == 2 || curr_frame == 3)
                setPosition(player.getPosition().x - 10, BOTTOMY - player.getGlobalBounds().height);
            if (curr_frame == 4)
                setPosition(player.getPosition().x - 35, BOTTOMY - player.getGlobalBounds().height);
            else if (curr_frame == 5)
                setPosition(player.getPosition().x + 45, BOTTOMY - player.getGlobalBounds().height);
            else
                setPosition(player.getPosition().x,BOTTOMY - player.getGlobalBounds().height);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::victory_2) {
        if (curr_frame == 5 && shirt_frame  == 4) {
            curr_state = AnimationState::still;
        }
        else {
            if (curr_frame < 5) {
                player.setTextureRect(victory2_frames[curr_frame++]);
                if (curr_frame == 1 || curr_frame == 2 || curr_frame == 3)
                    setPosition(player.getPosition().x - 10, BOTTOMY - player.getGlobalBounds().height);
                if (curr_frame == 4) {
                    shirt_frame = 0;
                    setPosition(player.getPosition().x - 35, BOTTOMY - player.getGlobalBounds().height);
                }
                else if (curr_frame == 5)
                    setPosition(player.getPosition().x + 45, BOTTOMY - player.getGlobalBounds().height);
                else
                    setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            }
            if (shirt_frame >= 0 && shirt_frame < 4)
            {
                if (!shirt_frame) {
                    shirt_left.setPosition(player.getPosition().x - 40, player.getPosition().y + 70);
                    shirt_right.setPosition(player.getPosition().x + player.getGlobalBounds().width + 40, player.getPosition().y + 70);
                }
                else if (shirt_frame > 0 && shirt_frame < 3) {
                    shirt_left.setPosition(shirt_left.getPosition().x - 20, shirt_left.getPosition().y + 40);
                    shirt_right.setPosition(shirt_right.getPosition().x + 20, shirt_right.getPosition().y + 40);

                }
                else {
                    shirt_left.setPosition(shirt_left.getPosition().x - 20, BOTTOMY - 80);
                    shirt_right.setPosition(shirt_right.getPosition().x + 20, BOTTOMY - 80);
                }
                shirt_left.setTextureRect(shirt_frames[shirt_frame]);
                shirt_right.setTextureRect(shirt_frames[shirt_frame++]);
            }
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::knockout) {
        if (curr_frame == 11) {
            curr_frame = 0;
            incr_to_next_frame = 1;
            player.setTextureRect(idle_frames[0]);
            player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);
            curr_state = AnimationState::idle;
        }
        else {
            float back = 60;
            player.setTextureRect(knockout_frames[curr_frame++]);
            if (curr_frame == 1)
                back = 30;
            else if (curr_frame == 3 || curr_frame == 6)
                player.setPosition(player.getPosition().x, player.getPosition().y - 40);
            else if (curr_frame == 4)
                back = 100;
            else
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);

            if (player.getPosition().x - back >= 0)
                player.setPosition(player.getPosition().x - back, player.getPosition().y);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::defeat_player) {
        if (curr_frame == 8) {
            curr_state = AnimationState::still;
        }
        else {
            float back = 60;
            player.setTextureRect(knockout_frames[curr_frame++]);
            if (curr_frame == 1)
                back = 30;
            else if (curr_frame == 3 || curr_frame == 6)
                player.setPosition(player.getPosition().x, player.getPosition().y - 40);
            else if (curr_frame == 4)
                back = 100;
            else
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);

            if (player.getPosition().x - back >= 0)
                player.setPosition(player.getPosition().x - back, player.getPosition().y);
        }
        time_elapsed = 0;
        return;
    }
    else if (time_elapsed >= MOVE_TIME && curr_state == AnimationState::defeat_enemy) {
        if (curr_frame == 8) {
            curr_state = AnimationState::still;
        }
        else {
            float back = 60;
            player.setTextureRect(knockout_frames[curr_frame++]);
            if (curr_frame == 1)
                back = 30;
            else if (curr_frame == 3 || curr_frame == 6)
                player.setPosition(player.getPosition().x, player.getPosition().y - 40);
            else if (curr_frame == 4)
                back = 100;
            else
                player.setPosition(player.getPosition().x, BOTTOMY - player.getGlobalBounds().height);

            if (player.getPosition().x + back <= WINDOW_WIDTH)
                player.setPosition(player.getPosition().x + back, player.getPosition().y);
        }
        time_elapsed = 0;
        return;
    }
}
void Balrog::bodyHit(){
    curr_frame = 0;
    curr_state = AnimationState::medium_hit_taken_body;
}
void Balrog::render(sf::RenderWindow& window) {
    window.draw(player);
    window.draw(shirt_left);
    window.draw(shirt_right);
}
bool Balrog::isIdle() {
    return IS_IDLE;
}
bool Balrog::isAttacking(){
    return (curr_state==AnimationState::alt_heavy_punch || curr_state==AnimationState::alt_light_punch || curr_state==AnimationState::alt_medium_punch || curr_state==AnimationState::crouch_light_punch || curr_state==AnimationState::crouch_medium_punch || curr_state==AnimationState::forward_heavy_punch || curr_state==AnimationState::forward_jump_punch || curr_state==AnimationState::forward_light_punch || curr_state==AnimationState::forward_medium_punch || curr_state==AnimationState::heavy_punch_right || curr_state==AnimationState::jump_punch || curr_state==AnimationState::light_punch_right || curr_state==AnimationState::medium_punch_right || curr_state==AnimationState::special_move1 || curr_state==AnimationState::special_move2);
}
bool Balrog::isSuffering(){
    return (curr_state==AnimationState::medium_hit_taken_body);
}
Balrog::~Balrog() {
}