#ifndef INCLUDE_UI_WINDOWS_MAIN_WINDOW_HPP_
#define INCLUDE_UI_WINDOWS_MAIN_WINDOW_HPP_

#include <QMainWindow>
#include <QtWidgets/QToolBar>
#include <cstdint>
#include <utility>
#include "../components/shapesCanvas.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = nullptr) noexcept;
  ~MainWindow() noexcept;

  template<std::derived_from<Shape> T>
  void registerShape() {
    std::unique_ptr<Shape> object = std::make_unique<T>();

    QAction* action = new QAction(this);
    action->setIcon(object->getToolbarIcon());
    action->setToolTip(tr(object->getShapeName()));
    action->setCheckable(true);
    action->setData(object->getShapeID());
    toolbarShapesButtons.emplace(object->getShapeID(), action);
    shapesToolbar->addAction(action);

    registeredShapes.push_back(std::move(object));
    updateShapesMenu();
  }

private:
  QMenu* shapesMenu;
  QToolBar* shapesToolbar;
  ShapesCanvas* canvas;
  uint64_t selectedShapeID { 0 };
  std::vector<std::unique_ptr<Shape>> registeredShapes;
  std::map<uint8_t, QAction*> toolbarShapesButtons;

  void initUI() noexcept;
  void updateShapesMenu() noexcept;
  void changeShape(uint8_t shapeID);

signals:
private slots:
  void shapeSelected(QAction* action);
};

#endif
