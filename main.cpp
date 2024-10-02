#include "TetrisModel.h"
#include "TetrisView.h"
#include "TetrisController.h"
#include <thread>

int main() {
    TetrisModel model(12, 18);
    TetrisView view(80, 30);
    TetrisController controller(model, view);

    while (true) {
        controller.HandleInput();
        controller.UpdateGame();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Réduire la vitesse
    }

    return 0;
}
