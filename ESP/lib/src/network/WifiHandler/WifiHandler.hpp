#pragma once
#ifndef WIFIHANDLER_HPP
#define WIFIHANDLER_HPP
#include <WiFi.h>
#include <memory>
#include <string>
#include <vector>
#include "data/StateManager/StateManager.hpp"
#include "data/config/project_config.hpp"
#include "data/utilities/Observer.hpp"
#include "data/utilities/helpers.hpp"

class WiFiHandler : public IObserver {
 public:
  WiFiHandler(ProjectConfig* configManager,
              StateManager<WiFiState_e>* stateManager,
              StateManager<LEDStates_e>* ledStateManger,
              const std::string& ssid,
              const std::string& password,
              uint8_t channel);
  virtual ~WiFiHandler();
  void begin();
  void update(ObserverEvent::Event event);

  ProjectConfig* configManager;
  StateManager<WiFiState_e>* stateManager;
  StateManager<LEDStates_e>* ledStateManager;

  bool _enable_adhoc;

 private:
  void setUpADHOC();
  void adhoc(const std::string& ssid,
             uint8_t channel,
             const std::string& password = std::string());
  bool iniSTA(const std::string& ssid,
              const std::string& password,
              uint8_t channel,
              wifi_power_t power);

  std::string ssid;
  std::string password;
  uint8_t channel;
  uint8_t power;
};
#endif  // WIFIHANDLER_HPP
