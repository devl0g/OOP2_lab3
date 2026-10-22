#include "shapesCanvas.hpp"
#include <QPaintEvent>
#include <algorithm>
#include <cstdint>

void ShapesCanvas::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event);

  QPainter painter(this);
    
  painter.setRenderHint(QPainter::Antialiasing);
  painter.fillRect(rect(), QColor(255, 255, 255));

  for (uint64_t shapeIndex = 0; shapeIndex < shapesCount; ++shapeIndex) {
    canvasShapes[shapeIndex]->renderShape(painter);
  }

  if (drawingShape) {
    drawingShape->renderPhantomShape(painter);
  }
}

void ShapesCanvas::mousePressEvent(QMouseEvent* event) {
  if (event->button() == Qt::MouseButton::LeftButton) {
    const auto position = event->pos();

    mouseState.isDragging = true;
    mouseState.dragStartX = position.x();
    mouseState.dragStartY = position.y();
    mouseState.dragEndX = position.x();
    mouseState.dragEndY = position.y();

    if (currentShapeType) {
      drawingShape = currentShapeType->createInstance();
      drawingShape->updateShapeConfig({ mouseState.dragStartX, mouseState.dragStartY }, { mouseState.dragEndX, mouseState.dragEndY });
    }
  }
}

void ShapesCanvas::mouseMoveEvent(QMouseEvent* event) {
  const auto position = event->pos();

  mouseState.dragEndX = position.x();
  mouseState.dragEndY = position.y();

  if (drawingShape) {
    drawingShape->updateShapeConfig({ mouseState.dragStartX, mouseState.dragStartY }, { mouseState.dragEndX, mouseState.dragEndY });
    update();
  }
}

void ShapesCanvas::mouseReleaseEvent(QMouseEvent* event) {
  if (event->button() == Qt::MouseButton::LeftButton && mouseState.isDragging) {
    mouseState.isDragging = false;

    if (drawingShape) {
      const uint64_t newShapesCount = std::min(shapesCount + 1, MAX_CANVAS_SHAPES);
      canvasShapes[newShapesCount - 1] = std::move(drawingShape);
      shapesCount = newShapesCount;
    }

    update();
  }
}
