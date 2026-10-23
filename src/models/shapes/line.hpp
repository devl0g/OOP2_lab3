#ifndef INCLUDE_MODEL_SHAPES_LINE_HPP_
#define INCLUDE_MODEL_SHAPES_LINE_HPP_

#include "./shape.hpp"
#include <qicon.h>

class LineShape : public Shape {
public:
  LineShape() = default;
  LineShape(Position aPos, Position bPos) : startPosition(aPos), endPosition(bPos) {};
  ~LineShape() = default;
  LineShape(const LineShape& other) noexcept : startPosition(other.startPosition), endPosition(other.endPosition) {}
  LineShape& operator=(LineShape other) {
    this->startPosition = other.startPosition;
    this->endPosition = other.endPosition;
    return *this;
  }

  [[nodiscard]] Position getStartPosition() const {
    return startPosition;
  }

  void setStartPosition(Position position) {
    this->startPosition = position;
  }

  [[nodiscard]] Position getEndPosition() const {
    return endPosition;
  }

  void setEndPosition(Position position) {
    this->endPosition = position;
  }

  char* getShapeName() const noexcept override {
    static char shapeName[] { "Лінія" };
    return shapeName;
  }

  uint8_t getShapeID() const noexcept override {
    return 2;
  }

  std::unique_ptr<Shape> createInstance() const noexcept override {
    return std::make_unique<LineShape>();
  }

  void renderShape(QPainter& painter) const override {
    painter.setBrush(Qt::NoBrush);
    QPen pen;
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(startPosition.x, startPosition.y, endPosition.x, endPosition.y);
  }

  void renderPhantomShape(QPainter& painter) const override {
    painter.setBrush(Qt::NoBrush);
    QPen pen;
    pen.setColor(QColor(255, 0, 0, 100));
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(startPosition.x, startPosition.y, endPosition.x, endPosition.y);
  }

  void updateShapeConfig(const Position& dragStart, const Position& dragEnd) noexcept override {
    this->startPosition = dragStart;
    this->endPosition = dragEnd;
  }

  QIcon getToolbarIcon() noexcept override {
    return QIcon(":/icons/line.png");
  }

private:
  Position startPosition { 0, 0 };
  Position endPosition { 0, 0 };
};

#endif
