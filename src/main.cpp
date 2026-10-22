#include "models/shapes/dot.hpp"
#include "models/shapes/line.hpp"
#include "models/shapes/oval.hpp"
#include "models/shapes/rectangle.hpp"
#include "utils/logger.hpp"
#include "ui/windows/mainWindow.hpp"
#include <QApplication>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  MainWindow window;

  window.registerShape<DotShape>();
  window.registerShape<LineShape>();
  window.registerShape<OvalShape>();
  window.registerShape<RectangleShape>();

  window.show();

  Logger::info("window initiation");
  return app.exec();
}
