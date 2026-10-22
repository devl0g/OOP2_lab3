#include "mainWindow.hpp"
#include "../../utils/logger.hpp"
#include "../../config.hpp"
#include <QtWidgets/QMenuBar>
#include <string>

MainWindow::MainWindow(QWidget* parent) noexcept : 
  QMainWindow(parent) {

  initUI();
}

MainWindow::~MainWindow() noexcept {
  Logger::info("window closed");
}

// UI

void MainWindow::initUI() noexcept {
  setWindowTitle(tr(WINDOW_TITLE));

  canvas = new ShapesCanvas(this);
  setCentralWidget(canvas);

  menuBar()->addMenu(tr("&Файл"));
  shapesMenu = menuBar()->addMenu(tr("&Об'єкти"));
  menuBar()->addMenu(tr("&Довідка"));

  shapesToolbar = new QToolBar("Об'єкти", this);
  addToolBar(shapesToolbar);

  connect(shapesMenu, &QMenu::triggered, this, &MainWindow::shapeSelected);
  connect(shapesToolbar, &QToolBar::actionTriggered, this, &MainWindow::shapeSelected);
}

void MainWindow::updateShapesMenu() noexcept {
  shapesMenu->clear();

  for (const auto& shape : registeredShapes) {
    auto action = shapesMenu->addAction(tr(shape->getShapeName()));
    action->setData(shape->getShapeID());
  }
}

void MainWindow::changeShape(uint8_t shapeID) {
  for (const auto& shape : registeredShapes) {
    if (shape->getShapeID() == shapeID) {
      selectedShapeID = shapeID;
      canvas->setDrawingShape(std::move(shape->createInstance()));
      const auto newTitle = std::string("Обрано: ") + shape->getShapeName();
      setWindowTitle(tr(newTitle.c_str()));
    }
  }

  for (const auto& action : toolbarShapesButtons) {
    action.second->setChecked(false);
  }

  toolbarShapesButtons.at(shapeID)->setChecked(true);
}

// Slots

void MainWindow::shapeSelected(QAction* action) {
  const uint32_t data = action->data().toUInt();
  changeShape(data);
}
