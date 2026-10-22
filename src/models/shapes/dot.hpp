#ifndef INCLUDE_MODEL_SHAPES_DOT_HPP_
#define INCLUDE_MODEL_SHAPES_DOT_HPP_

#include "./shape.hpp"

class DotShape : public Shape {
public:
  DotShape() = default;
  DotShape(Position position) : position(position) {};
  ~DotShape() = default;
  DotShape(const DotShape& other) noexcept : position(other.position) {}
  DotShape& operator=(DotShape other) {
    this->position = other.position;
    return *this;
  }

  [[nodiscard]] Position getPosition() const {
    return position;
  }

  void setPosition(Position position) {
    this->position = position;
  }

  char* getShapeName() const noexcept override {
    static char shapeName[] { "Точка" };
    return shapeName;
  }

  uint8_t getShapeID() const noexcept override {
    return 1;
  }

  std::unique_ptr<Shape> createInstance() const noexcept override {
    return std::make_unique<DotShape>();
  }

  void renderShape(QPainter& painter) const override {
    painter.setBrush(QBrush(QColor(0, 0, 0)));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(position.x - 4, position.y - 4, 8, 8);
  }

  void renderPhantomShape(QPainter& painter) const override {
    painter.setBrush(QBrush(QColor(255, 0, 0, 100)));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(position.x - 4, position.y - 4, 8, 8);
  }

  void updateShapeConfig(const Position& drag_start, const Position& drag_end) noexcept override {
    this->position = drag_end;
  }

private:
  Position position { 0, 0 };
};

#endif
