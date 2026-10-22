#ifndef INCLUDE_MODEL_SHAPES_OVAL_HPP_
#define INCLUDE_MODEL_SHAPES_OVAL_HPP_

#include "./shape.hpp"
#include <qicon.h>

class OvalShape : public Shape {
public:
  OvalShape() = default;
  OvalShape(Position aPos, Position bPos) : startPosition(aPos), endPosition(bPos) {};
  ~OvalShape() = default;
  OvalShape(const OvalShape& other) noexcept : startPosition(other.startPosition), endPosition(other.endPosition) {}
  OvalShape& operator=(OvalShape other) {
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
    static char shapeName[] { "Овал" };
    return shapeName;
  }

  uint8_t getShapeID() const noexcept override {
    return 4;
  }

  std::unique_ptr<Shape> createInstance() const noexcept override {
    return std::make_unique<OvalShape>();
  }

  void renderShape(QPainter& painter) const override {
    painter.setBrush(QColor(255, 255, 0));
    QPen pen;
    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);
    painter.setPen(pen);

    painter.drawEllipse(
        startPosition.x,
        startPosition.y,
        endPosition.x - startPosition.x,
        endPosition.y - startPosition.y
    );
  }

  void renderPhantomShape(QPainter& painter) const override {
    painter.setBrush(Qt::NoBrush);
    QPen pen;
    pen.setColor(QColor(255, 0, 0, 100));
    pen.setWidth(2);
    painter.setPen(pen);

    painter.drawEllipse(
        startPosition.x,
        startPosition.y,
        endPosition.x - startPosition.x,
        endPosition.y - startPosition.y
    );
  }

  void updateShapeConfig(const Position& dragStart, const Position& dragEnd) noexcept override {
    this->startPosition = dragStart;
    this->endPosition = dragEnd;
  }

  QIcon getToolbarIcon() noexcept override {
    return QIcon(":/icons/oval.png");
  }

private:
  Position startPosition { 0, 0 };
  Position endPosition { 0, 0 };
};

#endif
