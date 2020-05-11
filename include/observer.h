#pragma once


#include <vector>
#include <map>


enum EventType {
  PlayerVictory,
  PlayerDefeat
};


class Listener {
public:
  virtual ~Listener() = default;
  virtual void getNotification(EventType) { };
};


class Observer {
public:
  void addListener(EventType event, Listener* listener);
  void notify(EventType event);
private:
  std::map<EventType, std::vector<Listener*>> listeners;
};

