#include "./raylib.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define INIT_SIDE 720
#define TITLE "saat"

void ending_pos(Vector2 *v, float angle, int center, float len);

int main(void) {

  InitWindow(INIT_SIDE, INIT_SIDE, TITLE);

  SetTargetFPS(1);

  // Timestamp for 2 December 2024 13:59:59 = 1733147999
  int timestamp = (int)time(NULL); // (int)time(NULL) for the real timestamp
  int now = timestamp % (60 * 60 * 24);

  printf("timestamp: %d\n", timestamp);
  printf("epoch: %d\n", now);

  // The hour angle shoud {PI / (60 * 60 * 6)} per second. - PI/2 for the start on the top.
  // The minute angle shoud {PI / (30 * 60)} per second. - PI/2 for the start on the top.
  // The second angle shoud {PI / 30} per second. - PI/2 for the start on the top.
  float hour_angle = now * (PI / (60 * 60 * 6)) - (PI / 2);
  float minute_angle = now * PI / (30 * 60) - (PI / 2);
  float second_angle = now * (PI / 30) - (PI / 2);

  int center = INIT_SIDE / 2;
  Vector2 centerV = {.x = center, .y = center};
  Vector2 endV;

  while (!WindowShouldClose())
  {
    hour_angle += PI / (60 * 60 * 6);
    minute_angle += PI / (30 * 60);
    second_angle += PI / 30;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircleLines(center, center, (float)center, BLACK);
    ending_pos(&endV, hour_angle, center, 1.0 / 2);
    DrawLineEx(centerV, endV, 2, DARKGRAY);
    ending_pos(&endV, minute_angle, center, 2.0 / 3);
    DrawLineEx(centerV, endV, 2, DARKGRAY);
    ending_pos(&endV, second_angle, center, 3.0 / 4);
    DrawLineV(centerV, endV, DARKGRAY);
    EndDrawing();
  }

  return 0;
}

void ending_pos(Vector2 *v, float angle, int center, float len) {
  v->x = center + cos(angle) * (float)center * len;
  v->y = center + sin(angle) * (float)center * len;
}
