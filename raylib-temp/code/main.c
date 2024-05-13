#include "raylib/raylib.h"

#include "utils/utils.h"
#include "config.h"

i32 main() {
  InitWindow(WID, HEI, TITLE);
  SetTargetFPS(FPS);

  while (!(WindowShouldClose() && !IsKeyDown(KEY_ESCAPE))) {

    BeginDrawing(); {
      ClearBackground(BLACK);
    } EndDrawing();
  }

  CloseWindow();

  return 0;
}
