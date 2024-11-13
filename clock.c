#include "./raylib.h"
#include <math.h>
#include <stdio.h>
#include <time.h>

#define INIT_SIDE 720
#define TITLE "saat"

int main(void) {

  InitWindow(INIT_SIDE, INIT_SIDE, TITLE);

  SetTargetFPS(1);

  int now = (int)time(NULL) % (60 * 60 * 24);

  int hour = now % (60 * 60 * 24);
  float hour_angle = hour * (PI / 6) - (PI / 2);
  int minute = (now % (60 * 60)) / 60;
  float minute_angle = minute * (PI / 30) - (PI / 2);
  int second = now % 60;
  float second_angle = second * (PI / 30) - (PI / 2);

  printf("epoch: %d\n%d:%d:%d\n", now, hour, minute, second);

  int center = INIT_SIDE / 2;

  while (!WindowShouldClose()) {
    hour_angle += 1.0 / (60 * 60 * 6);
    minute_angle += PI / (30 * 60);
    second_angle += PI / 30;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircleLines(center, center, (float)center, BLACK);
    DrawLine(center, center, center + cos(hour_angle) * ((float)center / 2),
             center + sin(hour_angle) * ((float)center / 2), DARKGRAY);
    DrawLine(center, center,
             center + cos(minute_angle) * (((float)center * 2) / 3),
             center + sin(minute_angle) * (((float)center * 2) / 3), DARKGRAY);
    DrawLine(center, center,
             center + cos(second_angle) * (((float)center * 3) / 4),
             center + sin(second_angle) * (((float)center * 3) / 4), DARKGRAY);
    EndDrawing();
  }

  return 0;
}
