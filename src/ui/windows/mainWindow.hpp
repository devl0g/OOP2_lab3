#ifndef INCLUDE_UI_WINDOWS_MAIN_WINDOW_HPP_
#define INCLUDE_UI_WINDOWS_MAIN_WINDOW_HPP_

#include <QMainWindow>
#include <cstdint>
#include "../components/shapesCanvas.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = nullptr) noexcept;
  ~MainWindow() noexcept;

  template<std::derived_from<Shape> T>
  void registerShape() {
    registeredShapes.push_back(std::make_unique<T>());
    updateShapesMenu();
  }

private:
  QMenu* shapesMenu;
  ShapesCanvas* canvas;
  uint64_t selectedShapeID { 0 };
  std::vector<std::unique_ptr<Shape>> registeredShapes;

  void initUI() noexcept;
  void updateShapesMenu() noexcept;
  void changeShape(uint8_t shapeID);

signals:
private slots:
  void shapeSelected(QAction* action);
};

#endif
