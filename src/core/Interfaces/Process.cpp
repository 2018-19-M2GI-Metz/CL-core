//
//  Process.cpp
//  libgps
//
//  Created by Thomas Lemaire on 14/03/2019.
//  Copyright © 2019 Thomas Lemaire. All rights reserved.
//

#include "Process.hpp"

sharedPath Process::AStar(sharedPoint start, sharedPoint end) {
    
    std::map<int, sharedPoint> openList = std::map<int, sharedPoint>();
    std::map<int, sharedPoint> closedList = std::map<int, sharedPoint>();
    std::map<int, int> costs = std::map<int, int>();
    std::map<int, int> heuristics = std::map<int, int>();
    bool searchTerminated = false;

    costs[start->getId()] = 0;
    heuristics[start->getId()] = 0;

    openList[start->getId()] = start;
    
    while (openList.size() != 0) {
        sharedPoint current = nullptr;
        // choose point with best heuristic
        for (std::pair<int, sharedPoint> potential : openList) {
            if (current == nullptr || heuristics[potential.second->getId()] < heuristics[current->getId()]) {
                current = potential.second;
            }
        }
        
        // execute alorithm
        openList.erase(current->getId());
        if (current->getId() == end->getId()) {
            searchTerminated = true;
        }
        if (!searchTerminated) {
            for (sharedSegment segment : current->getSegments()) {
                sharedPoint next = (segment->getStartPointId() == current->getId()) ? segment->getEndPoint() : segment->getStartPoint();
                int cost = costs[current->getId()] + segment->getDistance();

                if (costs.find(next->getId()) == costs.end() || cost < costs[next->getId()]) {
                    costs[next->getId()] = cost;
                    heuristics[next->getId()] = cost + next->distanceFrom(*end);
                    openList[next->getId()] = next;
                }
            }
        }
        closedList[current->getId()] = current;
    }
    
    if (searchTerminated) {
        // getting all points involved
        
        std::vector<sharedPoint> points = std::vector<sharedPoint>();
        sharedPoint current = end;
        points.push_back(end);
        while (current != start) {
            sharedPoint next = nullptr;
            for (sharedPoint potential : current->getNextPoints()) {
                if (next == nullptr || costs[potential->getId()] < costs[next->getId()]) {
                    next = potential;
                }
            }
            points.push_back(next);
            current = next;
        }
        
        // create a path
        
        Path path = Path(true, true);
        for (sharedPoint point : points) {
            std::cout << point->getId() << std::endl;
            path.addPoint(point);
        }
        
        return std::make_shared<Path>(path);
    }
    
    return sharedPath();
}
