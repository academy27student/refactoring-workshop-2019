#pragma once

#include <list>

#include "SnakeInterface.hpp"
#include "SnakePosition.hpp"
#include "SnakeWorld.hpp"
#include "IPort.hpp"
#include "EventT.hpp"
namespace Snake
{

class Segments
{
public:
    Segments(Direction direction);

    bool isCollision(Position position) const;
    void addSegment(Position position);
    void addHead(Position position);
    Position nextHead() const;
    Position removeTail();
    void updateDirection(Direction newDirection);
    unsigned size() const;

    void updateSegmentsIfSuccessfullMove(Position position, World m_world, IPort &m_scorePort, IPort &m_displayPort, IPort &m_foodPort);
    void addHeadSegment(Position position, IPort &m_displayPort);
    void removeTailSegmentIfNotScored(Position position, World m_world, IPort &m_scorePort, IPort &m_foodPort, IPort &m_displayPort);
    void removeTailSegment(IPort &m_displayWorld);

private:
    Direction m_headDirection;
    std::list<Position> m_segments;
};

} // namespace Snake
