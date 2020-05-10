#include "observer.h"


void Observer::addListener(EventType event, Listener* listener) {
  listeners[event].push_back(listener);
}

void Observer::notify(EventType event) {
  for (Listener* l : listeners[event]) {
    l->getNotification(event);
  }
}

