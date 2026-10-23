#ifndef INCLUDE_MODEL_SHAPES_RECTANGLE_HPP_
#define INCLUDE_MODEL_SHAPES_RECTANGLE_HPP_

#include "./shape.hpp"
#include <qicon.h>
#include <qnamespace.h>

class RectangleShape : public Shape {
public:
  RectangleShape() = default;
  RectangleShape(Position centerPos, Position cornerPos) : centerPosition(centerPos), cornerPosition(cornerPos) {};
  ~RectangleShape() = default;
  RectangleShape(const RectangleShape& other) noexcept : centerPosition(other.centerPosition), cornerPosition(other.cornerPosition) {}
  RectangleShape& operator=(RectangleShape other) {
    this->centerPosition = other.centerPosition;
    this->cornerPosition = other.cornerPosition;
    return *this;
  }

  [[nodiscard]] Position getCenterPosition() const {
    return centerPosition;
  }

  void setCenterPosition(Position position) {
    this->centerPosition = position;
  }

  [[nodiscard]] Position getCornerPosition() const {
    return cornerPosition;
  }

  void setCornerPosition(Position position) {
    this->cornerPosition = position;
  }

  char* getShapeName() const noexcept override {
    static char shapeName[] { "Прямокутник" };
    return shapeName;
  }

  uint8_t getShapeID() const noexcept override {
    return 3;
  }

  std::unique_ptr<Shape> createInstance() const noexcept override {
    return std::make_unique<RectangleShape>();
  }

  void renderShape(QPainter& painter) const override {
    painter.setBrush(Qt::NoBrush);
    QPen pen;
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);
    painter.setPen(pen);

    Position half_size { 
      std::abs(centerPosition.x - cornerPosition.x),
      std::abs(centerPosition.y - cornerPosition.y)
    };

    painter.drawRect(
        centerPosition.x - half_size.x,
        centerPosition.y - half_size.y,
        half_size.x * 2,
        half_size.y * 2
    );
  }

  void renderPhantomShape(QPainter& painter) const override {
    painter.setBrush(Qt::NoBrush);
    QPen pen;
    pen.setColor(QColor(255, 0, 0, 100));
    pen.setWidth(2);
    painter.setPen(pen);

    Position half_size { 
      std::abs(centerPosition.x - cornerPosition.x),
      std::abs(centerPosition.y - cornerPosition.y)
    };

    painter.drawRect(
        centerPosition.x - half_size.x,
        centerPosition.y - half_size.y,
        half_size.x * 2,
        half_size.y * 2
    );
  }

  void updateShapeConfig(const Position& dragStart, const Position& dragEnd) noexcept override {
    this->centerPosition = dragStart;
    this->cornerPosition = dragEnd;
  }

  QIcon getToolbarIcon() noexcept override {
    return QIcon(":/icons/rectangle.png");
  }

private:
  Position centerPosition { 0, 0 };
  Position cornerPosition { 0, 0 };
};

#endif
