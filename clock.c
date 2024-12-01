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

  printf("epoch: %d\n", (int)time(NULL));
  int now = (int)time(NULL) % (60 * 60 * 24);

  int hour = now / (60 * 60);
  float hour_angle = hour * (PI / 6) - (PI / 2);
  int minute = (now % (60 * 60)) / 60;
  float minute_angle = minute * (PI / 30) - (PI / 2);
  int second = now % 60;
  float second_angle = second * (PI / 30) - (PI / 2);

  printf("epoch: %d\n%d:%d:%d\n", now, hour, minute, second);

  int center = INIT_SIDE / 2;
  Vector2 centerV = {.x = center, .y = center};
  Vector2 endV;

  while (!WindowShouldClose()) {
    hour_angle += 1.0 / (60 * 60 * 6);
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
