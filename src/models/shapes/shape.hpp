#ifndef INCLUDE_MODEL_SHAPES_SHAPE_HPP_
#define INCLUDE_MODEL_SHAPES_SHAPE_HPP_

#include <QPainter>

struct Position {
  int64_t x { 0 };
  int64_t y { 0 };
};

class Shape {
public:
  virtual ~Shape() noexcept = default;

  [[nodiscard]] virtual char* getShapeName() const noexcept = 0;
  [[nodiscard]] virtual uint8_t getShapeID() const noexcept = 0;
  [[nodiscard]] virtual std::unique_ptr<Shape> createInstance() const noexcept = 0;

  virtual void renderShape(QPainter& painter) const = 0;
  virtual void renderPhantomShape(QPainter& painter) const = 0;
  virtual void updateShapeConfig(const Position& dragStart, const Position& dragEnd) noexcept = 0;
  virtual QIcon getToolbarIcon() noexcept = 0;
};

#endif
