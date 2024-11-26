#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

#include "hash_v3.h"

hash_v3 hashv3;
int degree[20];
// int index = 0;
// String content = "";
// char character;

String data;

void setup() {
  Serial.begin(9600);

  while(!Serial) {
  }

  hashv3.init_hash();
  hashv3.initial_position();
}

void loop() {
  int     size_ = 0;
  String  payload;
  while ( !Serial.available()  ){}
  if ( Serial.available() )
    payload = Serial.readStringUntil( '\n' );
  StaticJsonDocument<512> doc;

  DeserializationError error = deserializeJson(doc, payload);
  if (error) {
    Serial.println(error.c_str()); 
    return;
  }
  if (doc["operation"] == "sequence") {
     Serial.println("{\"Success\":\"True\"}");
  }
  else {
      Serial.println("{\"Success\":\"False\"}");
   }
  delay(20);


  String movement = "test";
  int repeats = 0;
  int speed = 0;

  if(movement == "say_hi"){
    hashv3.say_hi(repeats, speed);
  }
  else if(movement == "hands_up"){
    hashv3.hands_up(repeats, speed);
  }
  else if(movement == "forward"){
    hashv3.forward(repeats, speed);
  }
  else if(movement == "turn_right"){
    hashv3.turn_right(repeats, speed);
  }
  else if(movement == "turn_left"){
    hashv3.turn_left(repeats, speed);
  }
  else if(movement == "move_right"){
    hashv3.move_right(repeats, speed);
  }
  else if(movement == "move_left"){
    hashv3.move_left(repeats, speed);
  }
  else if(movement == "ball_kick_right"){
    hashv3.ball_kick_right(repeats, speed);
  }
  else if(movement == "ball_kick_left"){
    hashv3.ball_kick_left(repeats, speed);
  }
  else if(movement == "max_sit"){
    hashv3.max_sit(repeats, speed);
  }
  else if(movement == "bow"){
    hashv3.bow(repeats, speed);
  }
  else if(movement == "right_bow"){
    hashv3.right_bow(repeats, speed);
  }
  else if(movement == "left_bow"){
    hashv3.left_bow(repeats, speed);
  }
  else if(movement == "ape_move"){
    hashv3.ape_move(repeats, speed);
  }
  else if(movement == "clap"){
    hashv3.clap(repeats, speed);
  }
  else if(movement == "right_leg_up"){
    hashv3.right_leg_up(repeats, speed);
  }
  else if(movement == "left_leg_up"){
    hashv3.left_leg_up(repeats, speed);
  }
  else if(movement == "hip_pose"){
    hashv3.hip_pose(repeats, speed);
  }
  else if(movement == "right_leg_balance"){
    hashv3.right_leg_balance(repeats, speed);
  }
  else if(movement == "left_leg_balance"){
    hashv3.left_leg_balance(repeats, speed);
  }
  else if(movement == "flying_action"){
    hashv3.flying_action(repeats, speed);
  }
  else if(movement == "hand_sit_zigzak"){
    hashv3.hand_sit_zigzak(repeats, speed);
  }
  else if(movement == "side_shake"){
    hashv3.side_shake(repeats, speed);
  }
  else if(movement == "hip_shake"){
    hashv3.hip_shake(repeats, speed);
  }
  else if(movement == "bend_up "){
    hashv3.bend_up (repeats, speed);
  }
  else if(movement == "push_up"){
    hashv3.push_up(repeats, speed);
  }
}