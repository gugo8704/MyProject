//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#pragma once

#include "veins/veins.h"

#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "veins/modules/mobility/traci/TraCIScenarioManager.h"
#include "veins/modules/mobility/traci/TraCIScenarioManagerLaunchd.h"
#include "veins/modules/mobility/traci/TraCICommandInterface.h"
#include "veins/modules/mobility/traci/TraCIMobility.h"
#include "veins/modules/application/traci/TraCIDemo11p.h"
#include "veins/modules/application/traci/TraCIDemo11pMessage_m.h"
#include "veins/modules/messages/EmergencyVehicle_m.h"
#include "veins/modules/messages/RSU_m.h"
using namespace omnetpp;
using namespace std;
#include <list>
namespace veins {

/**
 * @brief
 * This is a stub for a typical Veins application layer.
 * Most common functions are overloaded.
 * See MyVeinsApp.cc for hints
 *
 * @author David Eckhoff
 *
 */

class VEINS_API MyVeinsApp : public DemoBaseApplLayer {
public:
    void initialize(int stage) override;
    //void finish() override; commenting function finish()

protected:
    simtime_t lastDroveAt;
    bool sentMessage;
    int currentSubscribedServiceId;

protected:
    void onBSM(DemoSafetyMessage* bsm) override;
    void onWSM(BaseFrame1609_4* wsm) override;
    void onWSA(DemoServiceAdvertisment* wsa) override;

    void handleSelfMsg(cMessage* msg) override;
    void handlePositionUpdate(cObject* obj) override;
    //void handleLowerMsg(cMessage* msg) override; // adding handleLowerMsg()
    void finish() override; //uncommented this function
    static bool stopTheVehicle; //class scope. //To use this line 69 have to write code on line 77
    int count = 0;
    Coord cJunctioncoord; //parameter declaration to calculate junction Coords
    //Junction myjunction;  //parameter declaration
    //TraCICommandInterface::Junction myjunction = junctionId;

    cMessage* initMsg; //can two pointers "initMsg" and "phaseMsg" be of same type.
    cMessage* phaseMsg;

    void print(std::list<std::string>, std::string);
    //void print(std::list<std::string> const &list);
};
    bool MyVeinsApp::stopTheVehicle; //way to define static variable
    //A variable/static member is defined outside the class, so a variable can be accessed and get associated with the class. 
    // static keyword is not written outside the class definition, but it's written inside the class definition.
    //one single copy of the object is created, and is not available as separate copy with each object, like other non-static data member.
    
} // namespace veins
